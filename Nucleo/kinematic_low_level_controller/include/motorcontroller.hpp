// DEPRECATED CLASS - WILL BE REMOVED AFTER TRANSITIONED TO VELOCITYCONTROLLER

// ####################################################################################
// 
//   Author  -   Max DeSantis
//   Email   -   max.desantis@okstate.edu
//   Alg     -   Motor Controller INCLUDE
//   Date    -   07-11-2020
//
//   class MotorController
//      MotorController(PinName pwmPin, us_timestamp_t startTime, float KP, float KI, float KD);
//
//   class SteeringController : MotorController      
//      SteeringController(ros::NodeHandle &nh,PinName pwmPin, PinName inhibitPin, PinName potPin, us_timestamp_t startTime, float KP, float KI, float KD)
//      void SetInhibitPin(PinName inhibitPin);
//      void DriveMotor(float desiredAngle, us_timestamp_t executionTime)
//
//   class SpeedController : MotorController 
//      SpeedController(PinName pwmPin,  PinName tachPinA, PinName tachPinB, us_timestamp_t startTime, float KP, float KI, float KD);
//      void DriveMotor(float desiredVel, us_timestamp_t executionTime);
//
//   class BrakeController : MotorController
//      BrakeController(PinName pwmPin, us_timestamp_t startTime, float KP, float KI, float KD);
//
//   *NOTES*
//   -Interface between motors on the AGC and PIDController class.
//   -Subclasses: SteeringController, SpeedController, BrakeController.
//   -Subclasses have a PIDController and appropriate measurement class.
//
// ####################################################################################

#ifndef LOW_LEVEL_NUCLEO_MOTORCONTROLLER_HPP
#define LOW_LEVEL_NUCLEO_MOTORCONTROLLER_HPP

#include <mbed.h>
#include "pidcontroller.hpp"
#include "potentiometer.hpp"
#include "tachometer.hpp"

namespace low_level {
    namespace nucleo {

        /* -------------------------------------------------------------------------------------------------------- */

        /* Abstract class to facilitate motor control */
        class MotorController {
            protected:
                PwmOut* pwmPin;
                PIDController* controller;
        
            public:
                /**Used by controllers for common parameters.
                 * @param PinName Desired pin to be used for PWM.
                 * @param us_timestamp_t Time in us of startup.
                 * @param float Proportional constant used for PID control.
                 * @param float Integral constant used for PID control.
                 * @param float Derivative constant used for PID control. */
                MotorController(PinName pwmPin, us_timestamp_t startTime, float KP, float KI, float KD);
        };

        /* -------------------------------------------------------------------------------------------------------- */

        /* Controls AGC steering wheel */
        class SteeringController : public MotorController {
            private:
                DigitalOut* inhibitPin;
                
            public:
                /**Constructs an instance of SteeringController class
                 * @param PinName Desired pin to be used for PWM.
                 * @param PinName Desired pin to be used for enabling drive.
                 * @param float Proportional constant used for PID control.
                 * @param float Integral constant used for PID control.
                 * @param float Derivative constant used for PID control. */
                SteeringController(ros::NodeHandle &nh,PinName pwmPin, PinName inhibitPin, PinName potPin, us_timestamp_t startTime, float KP, float KI, float KD);

                /**Deallocates potentiometer and PIDController*/
                ~SteeringController();

                /**Sets the pin to be used to enable/inhibit the motor.
                 * @param PinName Desired pin to be used for enabling drive. */
                void SetInhibitPin(PinName inhibitPin);

                /**Attempts to drive motor to desired angle. Uses
                 * PIDController and potentiometer to do so.
                 * @param float Desired angle.
                 * @param us_timestamp_t Time of execution in us. */
                void DriveMotor(float desiredAngle, us_timestamp_t executionTime);
        };

        /* -------------------------------------------------------------------------------------------------------- */

        /* Controls AGC wheels */
        class SpeedController : public MotorController {
            private:
            public:
                /**Constructs an instance of WheelController class
                 * @param PinName Desired pin to be used for PWM. */
                SpeedController(PinName pwmPin,  PinName tachPinA, PinName tachPinB, us_timestamp_t startTime, float KP, float KI, float KD);
                
                /**Deallocates tachometer and PIDController*/
                ~SpeedController();

                /**Attempts to drive motor to desired velocity. Uses
                 * PIDController and tachometer to do so.
                 * @param float Desired velocity.
                 * @param us_timestamp_t Time of execution in us. */
                void DriveMotor(float desiredVel, us_timestamp_t executionTime);
        };

        /* -------------------------------------------------------------------------------------------------------- */

        /* Controls AGC braking motor */

        class BrakeController : public MotorController {
            private:

            public:
                /**Constructs an instance of BrakeController class.
                 * @param PinName Desired pin to be used for PWM.
                 * @param us_timestamp_t Starting time in us of controller.
                 * @param float KP, KI, KD PID gain coefficients. */ 
                BrakeController(PinName pwmPin, us_timestamp_t startTime, float KP, float KI, float KD);
                ~BrakeController();

                void DriveMotor(float desiredBrake, us_timestamp_t executionTime);
        };
    }
}

#endif //LOW_LEVEL_NUCLEO_MOTORCONTROLLER_HPP