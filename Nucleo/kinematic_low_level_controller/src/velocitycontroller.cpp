/**************************************************************************************

    Author  -   Max DeSantis
    Email   -   max.desantis@okstate.edu
    Alg     -   Velocity Controller SOURCE
    Date    -   08-27-2020

    class VelocityController
        VelocityController(ros::NodeHandle &nh, Parameters params, char* controller_pub_topic_name, char* controller_sub_topic_name);

        void ROSUpdate(const geometry_msgs::Twist& msg);
        void GatherMeasurements();
        void SpeedControl();
        void SteeringControl();
        void BrakeControl();
        
        void DirectDrive(float speedVal);
        void DirectBrake(float brakeVal);

    *NOTES*
    -Manages speed, steering, and braking controllers.
    -Measures actual speed and actual steering angle.
    -Receives desired speed and desired steering angle.
    -Sets behavior using a finite state machine. Behaviors are: accelerating, coasting, braking, and stopped.
    -Velocity is handled in m/s and angle is handled in degrees

    *USE*
    -A fleshed out Parameters struct must be created and passed to the constructor before using the class.

**************************************************************************************/

#include <mbed.h>
#include <ros.h>
#include "geometry_msgs/Twist.h"

#include "tachometer.hpp"
#include "potentiometer.hpp"
#include "pidcontroller.hpp"
#include "velocitycontroller.hpp"

#define M_PI 3.14159265358979323846

/* Timings */
const int   EXEC_RATE       = 10000;    //Loop execution times. Unit: microseconds
const int   MEASURE_PERIOD  = 10000;
const int   SPEED_PERIOD    = 10000;
const int   STEERING_PERIOD = 10000;
const int   BRAKE_PERIOD    = 10000;
const int   MSG_PERIOD      = 100000;   //ROS msg frequency. Unit: microseconds

const float MAX_ACCEL       = 1.0;      //Maximum cart acceleration. Unit: m/s
const float MAX_VEL_CHANGE  = MAX_ACCEL / MSG_PERIOD;
const float ACCEL_LOW_LIMIT = -0.5;
const float BRAKE_UP_LIMIT  = -1.5;
const float HALF_OF_PWM     = 0.5;


/* Potentiometer limits and conversions */
const int   LEFT_POS        = 900;
const int   RIGHT_POS       = 600;
const int   MID_POS         = (LEFT_POS + RIGHT_POS) / 2;
const float POT_TICKS_PER_DEG = 3.7067;
const float POT_TICKS_PER_RAD = POT_TICKS_PER_DEG * 180 / M_PI;

namespace low_level {
    namespace nucleo {

        VelocityController::VelocityController(ros::NodeHandle &nh, Parameters params, char* controller_pub_topic_name, char* controller_sub_topic_name)
            
            /* Initialize ROS subscriber and publisher */
            : controller_pub(controller_pub_topic_name, &str_msg),
            controller_sub(controller_sub_topic_name, &VelocityController::ROSUpdate, this),

            /* Initialize measuring components */
            tacho(params.tachPinA, params.tachPinB),
            pot(nh, params.potPin, MID_POS, LEFT_POS),

            /* Initialize controllers with provided coefficients */
            speedController(params.speedKP, params.speedKI, params.speedKD),
            steeringController(params.steeringKP, params.steeringKI, params.steeringKD),
            brakeController(params.brakeKP, params.brakeKI, params.brakeKD),
            
            /* Iniitalize controller pins */
            speedPin(params.speedPin),
            steeringPin(params.steeringPin),
            steeringInhibitPin(params.inhibitPin),
            brakePin(params.brakePin)
            {
            
            /* Center steering before futher instruction */
            currentState = stopping;
            desiredPotVal = 0;

            GatherMeasurements();

            /* Interrupt timers for low-level controllers and measurements */
            measurementLoop.attach_us(callback(this, &VelocityController::GatherMeasurements), MEASURE_PERIOD);
            speedLoop.attach_us(callback(this, &VelocityController::SpeedControl), SPEED_PERIOD);
            steeringLoop.attach_us(callback(this, &VelocityController::SteeringControl), STEERING_PERIOD);
            brakeLoop.attach_us(callback(this, &VelocityController::BrakeControl), BRAKE_PERIOD);

            nh.subscribe(controller_sub);
            nh.advertise(controller_pub);
        }

        void VelocityController::GatherMeasurements() {
            /* Gather measurements */
            actualSpeed = tacho.readVelocity(MEASURE_PERIOD);
            actualAngle = pot.readAverageDegrees();

            /* Convert steering angle now to speed up SteeringControl loop */
            actualPotVal = actualAngle * POT_TICKS_PER_DEG;

            /* Publish information to ROS */
            str_msg.linear.x = actualSpeed;
            str_msg.angular.z = actualAngle * (M_PI / 180);
            controller_pub.publish(&str_msg);
        }

        void VelocityController::SpeedControl() {
            float control = HALF_OF_PWM - speedController.CalculateControl(actualSpeed, desiredSpeed, SPEED_PERIOD);
            speedPin.write(control);
            return;
        }

        void VelocityController::SteeringControl() {
            float control = HALF_OF_PWM - steeringController.CalculateControl(actualPotVal, desiredPotVal, STEERING_PERIOD);
            steeringPin.write(control);
            return;
        }

        void VelocityController::BrakeControl() {
            /* Only activate brake when FSM says we're braking */
            if(currentState == State::braking) {
                float control = brakeController.CalculateControl(actualSpeed, desiredSpeed, BRAKE_PERIOD);
                brakePin.write(control);
            }
            else {
                DirectBrake(0);
            }
            return;
        }

        void VelocityController::DirectDrive(float speedVal) {
            /* Disable brake */
            DirectBrake(0);

            /* Pass command directly to on-board speed controller as PWM percentage */
            speedPin.write(speedVal);
            return;
        }

        void VelocityController::ROSUpdate(const geometry_msgs::Twist& msg) {
            float newDesiredSpeed  = msg.linear.x;
            float prevPotVal       = desiredPotVal;
            desiredAngle           = msg.angular.z; //Angle in radians.
            desiredPotVal          = desiredAngle * POT_TICKS_PER_RAD;

            /* Maintain current desired angle if new angle is unlawful. */
            if(desiredPotVal >= LEFT_POS && desiredPotVal <= RIGHT_POS) {
                desiredPotVal = prevPotVal;
            }

            /* Calculate acceleration for latest message in m/s */
            float acceleration = (newDesiredSpeed - actualSpeed) / (MSG_PERIOD * 1E-6);

            /* Regulate maximum acceleration between new ROS messages */
            if(fabs(acceleration) <= MAX_ACCEL) {
                desiredSpeed = newDesiredSpeed;
            }
            else if(acceleration > 0) {
                /* Desired speed is too high compared to actualSpeed. Limit change. */
                desiredSpeed = actualSpeed + MAX_VEL_CHANGE;
            }
            else {
                /* Desired speed is too low compared to actual speed. Limit change. */
                desiredSpeed = actualSpeed - MAX_VEL_CHANGE;
            }
            
            /* Determine what state we need to be in. */
            if(fabs(desiredSpeed) <= 0.01) {
                currentState = State::stopping;
            }
            else if(acceleration >= ACCEL_LOW_LIMIT) {
                currentState = State::accelerating;
            }
            else if(acceleration < ACCEL_LOW_LIMIT && acceleration >= BRAKE_UP_LIMIT) {
                currentState = State::coasting;
            }
            else if(acceleration < BRAKE_UP_LIMIT) {
                currentState = State::braking;
            }

            return;
        }
    }
}