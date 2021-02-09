#include <SPI.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

//Encoder interupt attachments
int EncoderR_A = 0;  //pin 2
int EncoderR_B = 5;  //pin 18
int EncoderL_A = 1;  //pin 3
int EncoderL_B = 4;  //pin 19
volatile int CountR = 0;
volatile int CountL = 0;
float CountAvg = 0;

//sampling rate
int T = 10; //(millisecond)

//diameters in inch
float EncRatio = 3.400166; //ratio of wheel revolutions to encoder revolutions through calibration
float CircumWheel = 1.372; //(m)

//speeds
float rpmEnc = 0; //(rpm)
float rpmWheel = 0; //(rpm)
float cartSpeed = 0; //(m/s)

//PID control variables
float desired;
float control;
float kp = 30;
float ki = 60;
float kd = 0.5;

//kP = 30; kI = 60; kD = 0.5
float prev = 0;
float integral;
float t;
float data;

//get speed from python variables
float sp;

//Output to motor variables
byte address = 0x00;
int chipsel = 10;

//ros setup
ros::NodeHandle nh;



float _map(float input, float in_low, float in_high, float out_low, float out_high);


// initiating the callback function for the subscriber
void messageCb( const geometry_msgs::Twist& msg){
  //data=msg.linear.x; //uncomment to circumvent controller and comment line below
  
  desired=msg.linear.x;

  if (desired > 5) desired = 5;
  else if (desired < 0) desired = 0;
}

//attaching the subscriber and publisher
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );
geometry_msgs::Twist str_msg;
ros::Publisher chatter("actual_speed", &str_msg);



void setup() {
  //setup ISR for encoders
  attachInterrupt(EncoderR_A, ISRR, RISING);
  attachInterrupt(EncoderL_A, ISRL, RISING);

  //setup motor communication (digital potentiometer)
  pinMode(13, OUTPUT);
  Serial.begin(115200); 
  pinMode(chipsel, OUTPUT);
  SPI.begin();

  // ROS setup 
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter); 
  //Serial.println("Ready");
}

void loop() {

  sp = motor_control(); //call motor control function to get new input speed
  
  if(desired > 1.5){
    control = sp;
  }
  else{
    control = 1.8*_map(desired,0,5,0,175);
  }
  
  writeToMotor(_map(desired, 0.0, 5.0, 0.0, 175.0));  //uncomment to circumvent controller and comment line below
 
 
  // storing the actual speed and publishing it on ROS
  str_msg.linear.x= cartSpeed;
  //str_msg.linear.x= _map(desired, 0.0, 5.0, 0.0, 175.0);    
  chatter.publish( &str_msg );

  //rest
  nh.spinOnce();
  
}

void writeToMotor(float a){
    digitalWrite(chipsel, LOW);
      SPI.transfer(address);
      SPI.transfer((int) a);           //write a to motor
      digitalWrite(chipsel, HIGH);
}

float motor_control(){
  float actual = measure();
  //Serial.println(actual,4);
  float error = desired-actual;
  float dt = millis()/1000.0-t;
  integral = integral + error*dt;
  float der = (error-prev)/dt;
  

  int control = kp*error + ki*integral + kd*der;
  prev = error;
  t = millis()/1000.0;
                              //Off Ground         solenoid::On::Jump::High  
  //MCP4151 IC is 7-bit: 0-127   limits: 16 to 17 to 81 to 100
  //MCP4151 IC is 8-bit: 0-255   limits: 30 to 37 to 175     (This is what we're using)

  // control limits
  if (control > 175){   //81 is where the jump from low to high speed takes place
    control = 175;
    integral = integral - error*dt;
  }
  else if (control < 0){
    control = 0;
    integral = integral - error*dt;
  }

  //if ( integral > (175-35)/3) {
  //  integral = mid;
  //}
   
  return control;
}

float measure(){
  CountR = 0;
  CountL = 0;
  delay(T);
  CountAvg = (CountR+CountL)/2;
  //Serial.print(CountAvg);
  rpmEnc =(CountAvg/1024.0)/(T/1000.0);
  rpmWheel = rpmEnc/(EncRatio);
  cartSpeed = rpmWheel*CircumWheel; 
  return cartSpeed;
}
 
//ISR for left and right wheel
void ISRL() {
 CountL++;
}

void ISRR(){
  CountR++;
}

float _map(float input, float in_low, float in_high, float out_low, float out_high) {
  return ((out_high-out_low)/(in_high-in_low)*(input-in_low)+out_low);
}
