
//inclue ROS libraries
#include <ros.h>
#include <status/status_msg.h>


void master_status_cb(const status::status_msg& msg);
int toggle_force_sensor(bool ON, bool set);
int toggle_solenoids(bool ON, bool set);
float read_force_sensor(); 


//Arduino PWM Speed Control：


 #define VERBOSE    // UNCOMMENT FOR STATS

const short SOL1_EN = 5;
const short SOL1_DIR = 4;

const short SOL2_EN = 6;
const short SOL2_DIR = 7;

const short FORCE_RES = A0;
const short FORCE_TOG = 8;

const bool ON     = true;
const bool OFF    = false;

const bool SET    = true;
const bool READ   = false;

const float RELEASE_BOUNDARY   = 3.75;     // V
const int RELEASE_PERIOD = 5000;            // mS

const int LOOP_PERIOD = 10;         // mS
int past_time;

int toggle_force_sensor(bool ON, bool set);
float read_force_sensor();

int toggle_solenoids(bool set);


ros::NodeHandle nh;

status::status_msg fs_status_msg;

ros::Publisher fs_status_pub("/fs_controller/force/status", &fs_status_msg);
ros::Subscriber<status::status_msg> master_status_sub("/master/SystemStatus", master_status_cb );

void setup()
{
    // SETUP SOLENOID 1
    pinMode(SOL1_DIR, OUTPUT);
    digitalWrite(SOL1_DIR, LOW);

    pinMode(SOL1_EN, OUTPUT);

    // SETUP SOLENOID 2
    pinMode(SOL2_DIR, OUTPUT);
    digitalWrite(SOL2_DIR, LOW);

    pinMode(SOL2_EN, OUTPUT);


    // ENABLE FORCE RESISTOR
    pinMode(FORCE_TOG, OUTPUT);
    toggle_force_sensor(ON, SET);


    // SETUP INPUT PIN
    pinMode(FORCE_RES, INPUT);


    // SETUP DIRECTOINS
    digitalWrite(SOL2_DIR, HIGH);
    digitalWrite(SOL1_DIR, LOW);


    toggle_solenoids(ON, SET);
    Serial.begin(57600);

    past_time = millis();
  
    nh.initNode();
    nh.subscribe(master_status_sub);
    nh.advertise(fs_status_pub);
}


bool released = false;
int state = 0;
long release_time;

void loop()
{

  float FSR = read_force_sensor();
  if (FSR > RELEASE_BOUNDARY) state = 0;

  

  if(state == 0)  {
    released = true;
    toggle_solenoids(OFF, SET);

    release_time = millis();
    state = 1;
  }
  else if(state == 1) {
    released = true;
    toggle_solenoids(OFF, SET);

    if(millis() - release_time >= RELEASE_PERIOD) state = 2;
  }
  else if(state == 2) {
    released = false;
    toggle_solenoids(ON, SET);
  }
  else {
    Serial.println("ERROR: UNKOWN STATE");
  }
  

  #ifdef VERBOSE
  Serial.print("FSR: ");
  Serial.print(FSR);
  Serial.print("\tSOL: ");
  Serial.print(toggle_solenoids(OFF, READ));
  Serial.print("\tSTATE: ");
  (state == 0 || state == 1) ? Serial.println("RELEASED") : Serial.println("ENGAGED");
  #endif // VERBOSE

  // Toggle autonomous depending on released state

  if(released)  fs_status_msg.status.data = status::status_msg::FATAL;
  else          fs_status_msg.status.data = status::status_msg::HEALTHY;

  fs_status_pub.publish(&fs_status_msg);
  nh.spinOnce();

  while(millis()-past_time < LOOP_PERIOD) {}
  past_time = millis();
}


// Call to update the toggle for the force resistor
// Only reads if set = false (which case ON is ignored)

int toggle_force_sensor(bool ON, bool set) {
  static int force_tog_val;
  
  if(set) {
    force_tog_val = (ON) ? HIGH : LOW;
    digitalWrite(FORCE_TOG, force_tog_val);
  }
  
  return force_tog_val;
}


// Call to update toggle power to solenoids
// Only read if set = false (which case ON is ignored)

int toggle_solenoids(bool ON, bool set) {
  static int solenoid_tog_val;  
  if(set) {
    solenoid_tog_val = (ON) ? 255 : 0;
      analogWrite(SOL1_EN, solenoid_tog_val);
      analogWrite(SOL2_EN, solenoid_tog_val);
  }

  return solenoid_tog_val;
}


// OUTPUT FSR READING IN VOLTS
float read_force_sensor() {
  return (float)analogRead(FORCE_RES)*5.0/1023.0;
}


void master_status_cb(const status::status_msg& msg) {
  // HANDLE SYSTEM FAIL
}
