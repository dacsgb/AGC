//include ROS libraries
#include <ros.h>
#include <geometry_msgs/Twist.h>
//#include <geometry_msgs/TwistStamped.h>

//Motor and feedback setup
int Step_Pin = 6;
int Dir_Pin = 5;
int Feedback_Pin = A0;

//Position Variables
float sum = 0;
float brakeOff=870;
float brakeOn=590;
int Pos_des=brakeOff;
float Pos_des_given = 1;
float curr_spd = 0;
float err = 0;
int margin = 7;

//ros setup
ros::NodeHandle nh;

// initiating the callback function for the subscriber
void messageCb( const geometry_msgs::Twist& msg){
  Pos_des_given = msg.linear.z;
}
//void fb_cb(const geometry_msgs::TwistStamped& msg) {
  //curr_spd = msg.twist.linear.x;
//}

//attaching the subscriber and publisher
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );
//ros::Subscriber<geometry_msgs::TwistStamped> sub("cmd_vel_fb", fb_cb);
geometry_msgs::Twist str_msg;
ros::Publisher chatter("actual_brake", &str_msg);


void setup() 
{
  Serial.begin(9600);
  pinMode(Step_Pin, OUTPUT);
  pinMode(Dir_Pin, OUTPUT);
  pinMode(Feedback_Pin, INPUT);
  //pinMode(EBrake,OUTPUT);
  //digitalWrite(EBrake,LOW);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 180;
  OCR2B = 50;
  
  // ROS setup 
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter); 
}

void loop() 
{
 
  //Calculate position variables  
  int Pos_des=map(Pos_des_given, 0, 100, brakeOff, brakeOn);
  int Pos_act=measure();
  int Pos_des_high = Pos_des + margin;
  int Pos_des_low = Pos_des - margin;

  // storing the actual percentage applied and publishing it on ROS
  str_msg.linear.z = map(Pos_act, brakeOff, brakeOn, 0.0, 100.0);   
  chatter.publish( &str_msg );
  
  err = Pos_des - Pos_act;
  Serial.println(Pos_act);
 

  //Check for bounds
  
  if (Pos_act>brakeOff){
    digitalWrite(Dir_Pin,LOW);
    analogWrite(Step_Pin,127);
    }
  else if (Pos_act<brakeOn){
    digitalWrite(Dir_Pin,HIGH);
    analogWrite(Step_Pin,127);
    } 
  else if (Pos_act < brakeOff && Pos_act > brakeOn){
    digitalWrite(Dir_Pin,LOW);
    analogWrite(Step_Pin,0);

  // travel to position  
  if (Pos_des<= brakeOff && Pos_des>= brakeOn){
    
    if (abs(err) <= margin){
        analogWrite(Step_Pin,0);
      }

    else if (err<0){
        digitalWrite(Dir_Pin,LOW);
        analogWrite(Step_Pin,127);
      }
    
    else if (err>0){
        digitalWrite(Dir_Pin,HIGH);
        analogWrite(Step_Pin,127);
      }
    }
    

  }
      
  //rest
  nh.spinOnce();
 }

float measure()
{
  sum = 0;
  for (int i = 0; i <= 50; i++){
    sum += analogRead(Feedback_Pin);
  }
  sum = sum / 50;
  return sum;

  
}
