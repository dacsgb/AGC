#include <SPI.h>
#include <ros.h>

// Encoder Variables
#define ENCODER 2
#define Ratio 38.4
volatile int Count = 0;
unsigned long time[2] = {0.0,0.0};
const float speed_bounds[2] = {-0.5, 3.0};

// Motor Variables
#define MOTOR 10
#define address 0x00
const int motor_bounds[2] = {51,200};
float v_sp = 0;
float v_meas = 0;

// Brake Variables
#define BRAKES 5
float brakeTorque = 0;

// Steering Variables
#define STEERING 7
#define STEERING_FB A0
const float steeringFB_bounds[2] = {362,520};
float phi_sp = 0;
float phi_meas = 0;
float phi_dot = 0;

// ROS Setup
ros::NodeHandle nh;
ros::Subscriber<INSERT TOPIC TYPE HERE> sub(INSERT TOPIC NAME HERE, commandCB);
ros::Publisher chatter("llc\feedback",INSERT MESSAGE HERE);


void commandCB(const INSERT_MESSAGE_TYPE msg){
    V_sp = msg.INSERT_FIELD_HERE;
    phi_sp = msg.INSERT_FIELD_HERE;
}


void setup(){
    // Start ROS
    nh.initNode();
    nh.subsribe();
}

void loop(){
    // Steering Control
    phi_meas = measureSteering();

    // Velocity Control

}

void measureSpeed(){
    time[1] = millis();
    v_meas = (Count*Ratio)/(time[1]-time[0]);
    time[0] = time[1];
    
}

float measureSteering(){
    return analogRead(STEERING_FB);
}

void actuateSteering(){
    phi_dot = 127.5 * (phi_sp- phi_meas);
    digitalWrite(Inhibit, LOW);
    analogWrite(STEERING, int(phi_dot));
}

void actuateMotor(float u){
    digitalWrite(MOTOR, LOW);
    SPI.transfer(address);
    V_sp = map(u,V_bounds[0],V_bounds[1],Pot_bounds[0],Pot_bounds[1]);
    V_sp = max(V_bounds[0],min(V_bounds[1],V));
    SPI.transfer(int(V_sp));
    digitalWrite(MOTOR, HIGH);
}

void actuateBrake(float u){
    analogWrite(BRAKES,map(u,0,1,0,255));
}

void countEncoder(){
    Count++;
}