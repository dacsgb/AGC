/*
   Author:    Max DeSantis
   Contact:   max.desantis@okstate.edu
   Purpopse:  Basic test of steering wheel electromagnet circuit on AGC
   Output:    Solenoids will toggle on and off every 3 seconds.
*/

//Solenoid 1 pins //! PLACEHOLDER VALUES
const int sol1_en = 5;
const int sol1_dir = 4;

//Solenoid 2 pins //! PLACEHOLDER VALUES
const int sol2_en = 6;
const int sol2_dir = 7;

bool toggle = false;
void toggle_solenoids();

void setup() {

  //Solenoid 1 setup
  pinMode(sol1_dir, OUTPUT);
  digitalWrite(sol1_dir, LOW);
  pinMode(sol1_en, LOW);

  //Solenoid 2 setup
  pinMode(sol2_dir, OUTPUT);
  digitalWrite(sol2_dir, OUTPUT);
  pinMode(sol2_en, LOW);

  Serial.begin(9600);

  //Solenoid direction setup
  digitalWrite(sol2_dir, HIGH);
  digitalWrite(sol1_dir, LOW);

  //Initiallly disable solenoids
  analogWrite(sol1_en, 0);
  analogWrite(sol2_en, 0);
}

//Toggle solenoids every three seconds
void loop() {
  delay(3000);
  toggle_solenoids();
  delay(3000);
  toggle_solenoids();
}

//Toggles solenoids on and off.
void toggle_solenoids() {

  toggle = !toggle;

  if (toggle) {
    analogWrite(sol1_en, 255);
    analogWrite(sol2_en, 255);
  }
  else {
    analogWrite(sol1_en, 0);
    analogWrite(sol2_en, 0);
  }
  Serial.print("Toggled at "); Serial.println(millis());
  Serial.print("toggle: "); Serial.println(toggle);

}
