#include <SPI.h>
#include <ros.h>
#include "pid_controller.hpp"


// -------------------------------------- Actuators ---------------------------------------------------

// Drive Motor
#define MOTOR_SS 53
#define CLOCK 13
#define address 0x00

// Brake Motor
#define BRAKES_DRIVE 4
#define BRAKES_INHIBIT 5

// Steering Motor
#define STEERING_DRIVE 6
#define STEERING_INHIBIT 7

// Gear Selector
#define FORWARD 8
#define BACKWARDS 9

// Electromagnets
#define ELECTROMAGNETS 10

// -------------------------------------- Sensors ---------------------------------------------------

// Steering Potentiometer
#define STEERING_FB A0
float phi_meas;
unsigned long steering_time;
const float steeringFB_bounds[2] = {362,520};

// Speed Encoder
#define ENCODER_IN 2
#define Ratio 38.4
volatile int Count;
unsigned long speed_time[2];
float v_meas;

// Steering Wheel 
#define STEERING_WHEEL_IN 3

// -------------------------------------- Controllers ---------------------------------------------------

// Supervisor
bool autonomy = false;

// Steering Controller
const float steeringU_bounds[2] = {-30,30};
float phi_sp = 0;
PIDController Steering(1,4,2);
Steering.setControllerLimits(steeringU_bounds[0],steeringU_bounds[1]);

// Speed Controller
const int motor_bounds[2] = {51,200};
const float speed_bounds[2][2] = {{0, 3.0},{-0.5,0}};
float v_sp = 0;
float brake_sp = 0;
float v_thresh = -0.5;


// ROS Setup
ros::NodeHandle nh;
ros::Subscriber<INSERT TOPIC TYPE HERE> sub(INSERT TOPIC NAME HERE, commandCB);
ros::Publisher pub("llc\feedback", &msg);


void commandCB(const INSERT_MESSAGE_TYPE& msg){
    autonomy = msg.INSERT_FIELD_HERE;
    V_sp = msg.INSERT_FIELD_HERE;
    phi_sp = msg.INSERT_FIELD_HERE;
}


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
    pinMode(ENCODER_IN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENCODER_IN),SPEED,CHANGE);

    // Steering Wheel Interrupt Setup
    pinMode(STEERING_WHEEL_IN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENCODER_IN),DISENGAGE,CHANGE);

    // Electromagnet Setup
    pinMode(ELECTROMAGNETS,OUTPUT);
    electromagnet(true);
    
   // Start ROS
    nh.initNode();
    nh.subsribe(sub);
    nh.advertise(pub);
}

void loop(){
    if(autonomy){
        // Measure sensor values
        measureSteering();
        measureSpeed();

        // Actuate system
        actuateSteering();
        actuateSpeed();
    }
    // Send Feedback to ROS
    feedback();
    nh.spinOnce();
}

void measureSteering(){
    steering_time = millis();
    phi_meas = map(analogRead(STEERING_FB),steeringFB_bounds[0],steeringFB_bounds[1],steeringU_bounds[0],steeringU_bounds[1])
}

void measureSpeed(){
    speed_time[1] = millis();
    v_meas = (Count*Ratio)/(speed_time[1]-speed_time[0]);
    speed_time[0] = speed_time[1];
}

void actuateSteering(){
    Steering.computeControl(phi_sp,phi_meas,steering_time)
    digitalWrite(STEERING_INHIBIT, LOW);
    analogWrite(STEERING_DRIVE, int(Steering.control));
}

void actuateSpeed(){
    if((v_sp - v_meas + v_thresh) > 0){
        // Accelerating or coasting
        actuateMotor(v_sp);
    }
    else if ((v_sp-v_meas + v_thresh) < 0 ){
        //Braking
        actuateMotor(v_sp);
        actuateBrake();
    }
}

// TODO: Add reverse mapping and gear selection
void actuateMotor(float u){
    u = map(u,V_bounds[0],V_bounds[1],Pot_bounds[0],Pot_bounds[1]);
    V_sp = max(V_bounds[0],min(V_bounds[1],V));
    digitalWrite(MOTOR, LOW);
    SPI.transfer(address);
    SPI.transfer(int(V_sp));
    digitalWrite(MOTOR, HIGH);
}

void actuateBrake(float u){
    digitalWrite(BRAKES_INHIBIT,LOW);
    analogWrite(BRAKES_DRIVE,int(u));
}

void electromagnet(bool state){
    digitalWrite(ELECTROMAGNETS,state);
}

void halt(){
    digitalWrite(BRAKES_INHIBIT,HIGH);
    analogWrite(BRAKES_DRIVE,int(0));
    
    digitalWrite(STEERING_INHIBIT, HIGH);
    analogWrite(STEERING_DRIVE, int(127.5));
}

void feedback(){
    pub.publish(&msg);
}

void SPEED(){
    Count++;
}

void DISENGAGE(){
    autonomy = false;
    electromagnet(false);
}