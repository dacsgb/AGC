#include <SPI.h>

// ----------------- Actuators

// Drive Motor
#define MOTOR_SS 53
#define CLOCK 13
#define address 0x00

// Brake Motor
#define BRAKES_DRIVE 4
#define BRAKES_INHIBIT 5

// ----------------- Sensors

// Speed Encoder
#define ENCODER_IN 2
#define Ratio 38.4
volatile int Count;
unsigned long speed_time[2];
float v_meas;

// ----------------- Test Parameters

float v_sp = 0.0;
int spi_val = 0;
float tau_sp = 0.0;
bool done = false;

void setup(){
    Serial.begin(115200);

    // Drive Motor Setup
    pinMode(CLOCK, OUTPUT);
    pinMode(MOTOR_SS,OUTPUT);
    SPI.begin();

    // Brake Motor Setup
    pinMode(BRAKES_DRIVE,OUTPUT);
    pinMode(BRAKES_INHIBIT,OUTPUT);
    digitalWrite(BRAKES_INHIBIT,HIGH);

    // Encoder Setup
    pinMode(ENCODER_IN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENCODER_IN),ENCODER,CHANGE);
}

void loop (){
    
    while (done != true){
        measureSpeed();
        actuateSpeed(v_sp);
        Serial.print("Estimated speed:\t");
        Serial.println(v_meas);
        if (abs(v_meas - v_sp) >= 0.05){
            done = true;
            delay(0.3);
            Count = 0;
        }
    }
    while(done == true){
        Serial.print("Breaking distance:\t");
        Serial.println(Ratio*Count);
        actuateBrake(tau_sp);
    }
}

void measureSpeed(){
    speed_time[1] = millis()/1000.0;
    v_meas = (Count*Ratio)/(speed_time[1]-speed_time[0]);
    speed_time[0] = speed_time[1];
}

void actuateMotor(float u){
    spi_val = ;
    digitalWrite(MOTOR, LOW);
    SPI.transfer(address);
    SPI.transfer(spi_val);
    digitalWrite(MOTOR, HIGH);
}

void actuateBrake(float u){
    digitalWrite(BRAKES_INHIBIT,LOW);
    analogWrite(BRAKES_DRIVE,int(u));
}

void ENCODER(){
    Count++;
}