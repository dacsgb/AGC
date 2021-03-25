#include <SPI.h>

// ----------------- Actuators

// Drive Motor
#define MOTOR_SS 53
#define CLOCK 13
#define address 0x00

// ----------------- Sensors

// Speed Encoder
#define ENCODER_IN 2
const float Ratio = 0.005623;
volatile int Count = 0;
unsigned long speed_time[2] = {0, 0};
float v_meas;

// ----------------- Test Parameters

float v_sp = 0.0;
int spi_val = 0;


void setup(){
    Serial.begin(115200);

    // Drive Motor Setup
    pinMode(CLOCK, OUTPUT);
    pinMode(MOTOR_SS,OUTPUT);
    SPI.begin();

    // Encoder Setup
    pinMode(ENCODER_IN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENCODER_IN),ENCODER,CHANGE);
}

void loop (){
    measureSpeed();
    Serial.print("SPI:\t");
    Serial.print(spi_val);
    Serial.print("Speed:\t");
    Serial.println(v_meas);
    delay(100);
}

void measureSpeed(){
    speed_time[1] = millis();
    v_meas = 1000.0*(Count/187)/(float(speed_time[1]-speed_time[0]));
    speed_time[0] = speed_time[1];
    Count = 0;
}

void actuateMotor(float u){
    //spi_val = ;
    digitalWrite(MOTOR_SS, LOW);
    SPI.transfer(address);
    SPI.transfer(spi_val);
    digitalWrite(MOTOR_SS, HIGH);
}

void ENCODER(){
    Count++;
}
