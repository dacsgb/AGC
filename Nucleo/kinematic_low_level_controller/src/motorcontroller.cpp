// DEPRECATED CLASS - WILL BE REMOVED AFTER TRANSITIONED TO VELOCITYCONTROLLER
//(also full of errors because I've deleted some important things)

// ####################################################################################
// 
//   Author  -   Max DeSantis
//   Email   -   max.desantis@okstate.edu
//   Alg     -   Motor Driver SOURCE
//   Date    -   07-6-2020
//
//  *NOTES*
//   -Designed to store pin information and output PWM signals to relevant motors.
//   -Creates instances of PIDController and potentiometer/tachometer to generate measurements.
//
// ####################################################################################

#include <mbed.h>
#include "motorcontroller.hpp"

#define POT_TICKS_PER_DEG 3.7067;
#define HALF_OF_PWM 0.5

namespace low_level {
    namespace nucleo {

        /* -------------------------------------------------------------------------------------------------------- */
        /* MotorController related */

        MotorController::MotorController(PinName pwmPin, us_timestamp_t startTime, float KP, float KI, float KD) {
            this->pwmPin = new PwmOut(pwmPin);
            controller = new PIDController(startTime, KP, KI, KD);
        }

        /* -------------------------------------------------------------------------------------------------------- */
        /* SteeringController related */

        SteeringController::SteeringController(ros::NodeHandle &nh, PinName pwmPin, PinName inhibitPin, PinName potPin, us_timestamp_t startTime, float KP, float KI, float KD) : MotorController(pwmPin, startTime, KP, KI, KD) {
            this->inhibitPin = new DigitalOut(inhibitPin, 1);
            
            //Orient wheels straight upon startup. Use angle of 0.0
            DriveMotor(0.0, startTime);
        }

        SteeringController::~SteeringController() {
            delete controller;
            delete pwmPin;
            delete inhibitPin;
        }

        void SteeringController::DriveMotor(float actualAngle, float desiredAngle, us_timestamp_t executionTime) {
            float desiredPotVal = desiredAngle * POT_TICKS_PER_DEG;
            float actualPotVal = (potentiometer->readAverageDegrees()) * POT_TICKS_PER_DEG;

            float control = HALF_OF_PWM - (controller->CalculateControl(actualPotVal, desiredPotVal, executionTime));

            inhibitPin->write(0);
            pwmPin->write(control);
        }

        /* -------------------------------------------------------------------------------------------------------- */
        /* SpeedController related */

        SpeedController::SpeedController(PinName pwmPin, PinName tachPinA, PinName tachPinB, us_timestamp_t startTime, float KP, float KI, float KD) : MotorController(pwmPin, startTime, KP, KI, KD) {
            tacho = new Tachometer(tachPinA, tachPinB);
        }

        SpeedController::~SpeedController() {
            delete tacho;
            delete controller;
            delete pwmPin;
        }

        void SpeedController::DriveMotor (float actualVel, float desiredVel, us_timestamp_t executionTime) {
            float actualVel = tacho->readVelocity();

            float control = controller->CalculateControl(actualVel, desiredVel, executionTime);
            pwmPin->write(control);
        }

        /* -------------------------------------------------------------------------------------------------------- */
        /* BrakeController related */


    }
}