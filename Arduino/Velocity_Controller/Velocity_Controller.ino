// -------------------------------------- Libraries ---------------------------------------------------

#include <SPI.h>
#include <ros.h>
#include <agc/AGC.h>
#include <agc/Auto.h>

// -------------------------------------- Actuators ---------------------------------------------------

// Drive Motor
#define MOTOR_SS 53
#define CLOCK 13
#define address 0x00

// Brake Motor
#define BRAKES_DRIVE 4
#define BRAKES_INHIBIT 5

// Steering Motor
#define STEERING_DRIVE 10
#define STEERING_INHIBIT 11

// Gear Selector
#define FORWARD 8
#define BACKWARDS 9

// Electromagnets
#define ELECTROMAGNETS 12

// Drive selector and SSR
#define DS 23
#define SSR 13

// -------------------------------------- Sensors ---------------------------------------------------

// Steering Potentiometer
#define STEERING_FB A0
int potMeas;
const float potBounds[2] = {370,600};

// Speed Encoder
#define EnA 3
#define EnB 2
#define Ratio 38.4
volatile int CtT;
unsigned long speed_time[2];
float vMeas;

// Steering Wheel 
#define STEERING_WHEEL_IN 19

// -------------------------------------- Controllers ---------------------------------------------------

// Supervisor
bool autonomy = true;

// Steering Controller
float potSP = 512;
float steeringKp = 2;

// Speed Controller
const int motor_bounds[2] = {51,200};
const float speed_bounds[2][2] = {{0, 3.0},{-0.5,0}};
float vSp = 0;
float brake_sp = 0;
float v_thresh = -0.5;

// -------------------------------------- ROS Setup ---------------------------------------------------
/*
void commandCB(const agc::AGC& msg){
    autonomy = msg.autonomous;
    potSP = max(potBounds[0],min(4.325*(msg.steering_angle) + 513.2,potBounds[1]));
    v_sp = msg.speed;
}

agc::AGC fb_msg;
agc::Auto auto_msg;

ros::NodeHandle nh;
ros::Subscriber<agc::AGC> cmdSub("/supervisor/cmd", commandCB);
ros::Publisher fbPub("/llc/feedback", &fb_msg);
ros::Publisher autoPub("/llc/autonomy", &auto_msg);
*/
// -------------------------------------- Arduino Setup ---------------------------------------------------

void setup(){
    Serial.begin(115200);

    // Drive Motor Setup
    pinMode(CLOCK, OUTPUT);
    pinMode(MOTOR_SS,OUTPUT);
    SPI.begin();

    // Steering Motor Setup
    pinMode(STEERING_DRIVE,OUTPUT);
    pinMode(STEERING_INHIBIT,OUTPUT);
    digitalWrite(STEERING_INHIBIT,HIGH);            

    // Brake Motor Setup
    pinMode(BRAKES_DRIVE,OUTPUT);
    pinMode(BRAKES_INHIBIT,OUTPUT);
    digitalWrite(BRAKES_INHIBIT,HIGH);

    // Steering Potentiometer Setup
    pinMode(STEERING_FB,INPUT);

    // Gear Selector Setup
    pinMode(FORWARD,OUTPUT);
    pinMode(BACKWARDS,OUTPUT);

    // Encoder Setup
    pinMode(EnA,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(EnA),CountA,CHANGE);

    pinMode(EnB,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(EnB),CountB,CHANGE);

    // Steering Wheel Interrupt Setup
    pinMode(STEERING_WHEEL_IN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(STEERING_WHEEL_IN),DISENGAGE,CHANGE);

    // Electromagnet Setup
    pinMode(ELECTROMAGNETS,OUTPUT);

    // SSR Setup
    pinMode(SSR,OUTPUT);

    // DS Setup
    pinMode(DS, OUTPUT);
    
    // Start ROS
    /*
    nh.initNode();
    h.subscribe(cmdSub);
    nh.advertise(fbPub);
    nh.advertise(autoPub);
    */
}

//  -------------------------------------- Main Loop ---------------------------------------------------

void loop(){
    measureSteering();
    //measureSpeed();
    //feedback();
    
    actuateElectromagnet(autonomy);

    if(autonomy){
        digitalWrite(SSR, autonomy);
        digitalWrite(DS, autonomy);
        actuateSteering(potSP, potMeas, steeringKp);
        //actuateSpeed(vSp, vMeas);
        actuateMotor(150);
    }
    else{
        digitalWrite(DS, autonomy);
        digitalWrite(SSR,autonomy);
        halt();
    }

    //nh.spinOnce();
}

// -------------------------------------- Helper Functions ---------------------------------------------------

void measureSteering(){
    long cumAvg = 0;
    for(int i = 0; i< 100; i++){cumAvg += analogRead(STEERING_FB);}
    potMeas = cumAvg/100;
}

void measureSpeed(){
    speed_time[1] = millis();
    vMeas = (CtT*Ratio)/(speed_time[1]-speed_time[0]);
    speed_time[0] = speed_time[1];
    CtT = 0;
}

void actuateSteering(float sp, float est, float kp){
    float u = 127 + kp*map((sp-est),potBounds[0] - potBounds[1],potBounds[1] - potBounds[0],-120,120);
    
    digitalWrite(STEERING_INHIBIT, LOW);
    analogWrite(STEERING_DRIVE, int(u));
}


void actuateSpeed(float sp, float est){
    digitalWrite(SSR, HIGH);
    if((sp - est + v_thresh) > 0){
        // Accelerating or coasting
        actuateMotor(sp);
    }
    else{
        //Braking
        actuateMotor(sp);                                                                                     
        //actuateBrake(20);
    }
}

// TODO: Add reverse mapping and gear selection

void actuateMotor(float u){
    u = max(0,min(u,255));
    digitalWrite(MOTOR_SS, LOW);
    SPI.transfer(address);
    SPI.transfer(int(u));
    digitalWrite(MOTOR_SS, HIGH);
}

void actuateBrake(float u){
    digitalWrite(BRAKES_INHIBIT,LOW);
    analogWrite(BRAKES_DRIVE,int(255*u));
}

void actuateElectromagnet(bool state){
    digitalWrite(ELECTROMAGNETS,state);
}

void halt(){
    digitalWrite(BRAKES_INHIBIT,HIGH);
    analogWrite(BRAKES_DRIVE,int(0));
    
    digitalWrite(STEERING_INHIBIT, HIGH);
    analogWrite(STEERING_DRIVE, int(127.5));
}


void feedback(){
    //fbPub.publish(&fb_msg);
    //autoPub.publish(&auto_msg);

    Serial.print("Measured Pot Value: ");
    Serial.print("\t");
    Serial.println(potMeas);
    
}

void DISENGAGE(){
    autonomy = false;
    actuateElectromagnet(false);
}

void CountA(){
    bool EnA_status = digitalRead(EnA);
    bool EnB_status = digitalRead(EnB);
    if(EnB_status == LOW){
        if(EnA_status == HIGH){CtT --;}
        else{CtT++;}
    }
    else{
        if(EnA_status == HIGH){CtT++;}
        else{CtT--;}
    }
}

void CountB(){
    bool EnA_status = digitalRead(EnA);
    bool EnB_status = digitalRead(EnB);
    if(EnA_status == LOW){
        if(EnB_status == HIGH){CtT ++;}
        else{CtT--;}
    }
    else{
        if(EnB_status == HIGH){CtT--;}
        else{CtT++;}
    }
}
