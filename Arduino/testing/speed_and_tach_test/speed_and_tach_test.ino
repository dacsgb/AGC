/*
   Author:    Diego Colon, Max DeSantis
   Contact:   max.desantis@okstate.edu
   Purpopse:  Basic test of drive motor SPI functionality and tachometer reading
   Output:    Solenoids will toggle on and off every 3 seconds.

   Note:      Much of this was ripped from speedCalibration.ino from the NAS
*/

#include <SPI.h>

//Potentiometer constants
const byte address  = 0x00;
const int chipsel   = 10;
const int POT_max   = 255;

//Encoder constants
const int EnA       = 2; //Encoder input
const float conv    = 37.4; // [pulse/m]

//Encoder variables
volatile int CT     = 0;
unsigned long tnew  = 0;
unsigned long told  = 0;

void setup() {

  //Pin setup
  pinMode(chipsel, OUTPUT);     //SPI pin
  pinMode(A0, INPUT);           //Analog read
  pinMode(EnA, INPUT_PULLUP);   //Encoder input
  attachInterrupt(digitalPinToInterrupt(EnA), Count, RISING);

  Serial.begin(115200);
  SPI.begin();

  //Serial headers
  Serial.print("Velocity_sp");
  Serial.print("\t");
  Serial.println("Velocity_meas");

  //Begin stepping of motor
  for(int i = 0; i < POT_max; i += 5) {
    writeVelocity(i);
    delay(5000);
    Serial.print(i);
    Serial.print("\t");
    Serial.println(measureVelocity(), 4);
  }
  writeVelocity(0);

}

//Unused
void loop() {}

void writeVelocity(int b) {
    // Intiate data transfer
    digitalWrite(chipsel, LOW);
    // Select chip
    SPI.transfer(address);
    // Transfer control command
    SPI.transfer(b);
    // End data transfer
    digitalWrite(chipsel, HIGH);
    return;
}

float measureVelocity() {
  tnew = millis();
  float est = (1000.0 * CT) / (conv * (tnew - told));
  told = tnew;
  CT = 0;
  return est;
}

void Count(){
    CT += 1;
}
