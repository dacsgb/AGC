// Include Libraries
#include <SPI.h>

// Define Constants
#define pi 3.141572

// Drive Motor Variables
#define motorAddress 0x00
#define motorSS  10
#define CLOCK 13
#define relayPin  4

// Brake Motor Variables
#define brakeA 5
#define brakeB 6
#define brakeEN 7

// Encoder Variables
#define ENA 2
#define ENB 3
#define EncRatio 0.0001292
volatile long Ct = 0;
unsigned long time[2] = {0,0};
float speed = 0.0;

// Test Variables
int spiSP = 120;
int brakeSP = 0;
float v = 0;
float s = 0;
int dt = 10;
bool done = false;

void setup(){
    Serial.begin(115200);

    pinMode(CLOCK, OUTPUT);
    pinMode(motorSS, OUTPUT);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin,LOW);
    SPI.begin();

    pinMode(brakeA,OUTPUT);
    pinMode(brakeB,OUTPUT);
    pinMode(brakeEN,OUTPUT);
    digitalWrite(brakeEN,LOW);

    pinMode(ENA,INPUT_PULLUP);
    pinMode(ENB,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENA),CountA,CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENB),CountB,CHANGE);
    delay(3000);
}

void loop(){
/*
    if(done == false){
        motorInterface(spiSP);
        while(true){
            v = measureSpeed();
            Report(v,s);
            if(time[1]/1000.0 > dt){
                break;
            }
        }
        done = true;
        //brakeInterface(75);
        //delay(1000);
    }
*/
for(int i = 0; i <= 255; i+=5){
  motorInterface(i);
  Serial.println(i);
  delay(250);
}

}

void motorInterface(float u){
    if(u> 0){
        digitalWrite(relayPin,HIGH);
        digitalWrite(motorSS, LOW);
        SPI.transfer(motorAddress);
        SPI.transfer((int) u);
        digitalWrite(motorSS, HIGH);
    }
    else{
        digitalWrite(relayPin,LOW);
        digitalWrite(motorSS, LOW);
        SPI.transfer(motorAddress);
        SPI.transfer(0);
        digitalWrite(motorSS, HIGH);
    }
}

void brakeInterface(int u){
    if(u>0){
        digitalWrite(brakeEN,HIGH);
        analogWrite(brakeB,map(u,0,100,0,255));
    }
    else{
        digitalWrite(brakeEN,LOW);
        analogWrite(brakeB,0);
    }
}

float measureSpeed(){
    time[1] = millis();
    float speed = (Ct*EncRatio)*(1000.0/(time[1]- time[0]));
    time[0] = time[1];
    Ct = 0;
    return speed;
}

void measureDist(){
    s = Ct*EncRatio;
}

void Report(float v, float s){
    Serial.print("Speed: \t");
    Serial.print(v,4);
    Serial.print("Distance: \t");
    Serial.println(s,4);
}

void CountA(){
  bool EnA_status = digitalRead(ENA);
  bool EnB_status = digitalRead(ENB);
  if(EnB_status == LOW){
    if(EnA_status == HIGH){
      Ct --;
    }
    else{
      Ct++;
    }
  }
  else{
    if(EnA_status == HIGH){
      Ct++;
    }
    else{
      Ct--;
    }
  }
}

void CountB(){
  bool EnA_status = digitalRead(ENA);
  bool EnB_status = digitalRead(ENB);
  if(EnA_status == LOW){
    if(EnB_status == HIGH){
      Ct ++;
    }
    else{
      Ct--;
    }
  }
  else{
    if(EnB_status == HIGH){
      Ct--;
    }
    else{
      Ct++;
    }
  }
}
