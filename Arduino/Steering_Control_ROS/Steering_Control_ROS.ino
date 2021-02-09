//inclue ROS libraries
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <status/status_msg.h>

const int8_t Drive_Pin = 3;
const int8_t Inhibit_Pin = 5;
const int8_t Feedback_Pin = A0;

const int left = 900;
const int right = 600;
const int POS_MID = (left + right) / 2;

//int Pos_des = (left+right)/2;
//int Pos_act;
int angle = 0;
//int error;
//int PWM;
//int error_PWM;

const float kp = 1.75;

int pastPos = 0;
long pastTime = 0;

// ROS setup
ros::NodeHandle nh;

// Declare helper functions
int Pot_pos();
int Error();
int measure();
void Drive_Error();
void Out_of_Range();
void master_status_cb(const status::status_msg& msg);

// Declare the callback function for the subscriber
void messageCb( const geometry_msgs::Twist& msg);

// Declare ROS Subscribers and Publishers
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", messageCb );
ros::Subscriber<status::status_msg> master_status_sub("/master/SystemStatus", master_status_cb );

geometry_msgs::Twist str_msg;

ros::Publisher chatter("actual_angle", &str_msg);

void setup()
{
  Serial.begin(115200);
  pinMode(Drive_Pin, OUTPUT);
  pinMode(Inhibit_Pin, OUTPUT);
  pinMode(Feedback_Pin, INPUT);

  // INITIALIZE TIMER2 FOR FAST PWM (~1kHz)
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 180;
  OCR2B = 50;

  // CENTER THE STEERING BEFORE CONTINUING
  int Pos_act = measure();
  int Pos_des = Pot_pos();
  while ((Pos_act - Pos_des) != 0) {
    int error_PWM = Error(Pos_act, Pos_des);
    Pos_act = measure();
    Pos_des = Pot_pos();

    if ( right <= Pos_des && Pos_des <= left && right <= Pos_act && Pos_act <= left) {
      Drive_Error(error_PWM);
    }
  }

  // ROS setup
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(master_status_sub);
  nh.advertise(chatter);

  pastTime = millis();
}

void loop()
{
  int Pos_des   = Pot_pos();
  int Pos_act   = measure();
  int error_PWM = Error(Pos_act, Pos_des);

  int change  = pastPos - Pos_act;
  float dt    = ((float)millis() - (float)pastTime) / 1000;
  float omega = (float)change / (float)dt;

  pastPos   = Pos_act;
  pastTime = millis();

  // Publish to ROS
  str_msg.linear.y  = ((Pos_act - POS_MID) / (3.7067)) * PI / 180;
  str_msg.angular.y = omega * PI / 180;

  chatter.publish( &str_msg );

  if    (right <= Pos_des && Pos_des <= left && right <= Pos_act && Pos_act <= left) Drive_Error(error_PWM);
  else  Out_of_Range(Pos_act, Pos_des);

  nh.spinOnce();                        // Rest
}


// ---------------| BEGIN HELPER FUNCTIONS |--------------- //

// HANDLE INPUT FROM ROS TOPIC
void messageCb( const geometry_msgs::Twist& msg) {
  angle = msg.angular.z * 180 / M_PI;
}

void master_status_cb(const status::status_msg& msg) {
  // HANDLE SYSTEM FAIL
}


// CONVERT DESIRED ANGLE -> DESIRED POTENTIOMETER VALUE
int Pot_pos()
{
  return 3.7067 * angle + POS_MID;
}

// MAP THE THE POSITIONAL ERROR TO [-120, 120]
int Error(int Pos_act, int Pos_des)
{
  int error_PWM = map((Pos_act - Pos_des), (right - left), (left - right), -120, 120);
  return error_PWM;
}

// TAKE AN AVERAGE OVER 100 READINGS OF THE POTENTIOMETER
int measure()
{
  float avg = 0;
  int N = 100;                          // Number of readings
  for (int i = 0; i < N; i++)
  {
    avg += analogRead(Feedback_Pin);
  }
  return avg / N;
}

// GENERATE AND TRANSMIT THE OUTPUT PWM SIGNAL
void Drive_Error(int error_PWM)
{
  int PWM = 127.5 - kp * error_PWM;
  digitalWrite(Inhibit_Pin, LOW);
  analogWrite(Drive_Pin, PWM);
}

// DISABLE THE MOTOR IF ACTUAL OR DESIRED POSITIONS ARE OUT OF RANGE
void Out_of_Range(int Pos_act, int Pos_des)
{
  if      (right >= Pos_des || Pos_des >= left)      digitalWrite(Inhibit_Pin, LOW);
  else if (right <= Pos_act || Pos_act <= left)      digitalWrite(Inhibit_Pin, LOW);
}
