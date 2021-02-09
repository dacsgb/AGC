// ##########################################
// 
//   Author  -   Max DeSantis
//   Email   -   max.desantis@okstate.edu
//   Alg     -   Motor Driver INCLUDE
//   Date    -   06-13-2020
//
//  *NOTES*
//   -Interface between motors on the AGC and PIDController class.
//   -Two subclasses: SteeringDriver and WheelDriver. No unified "motordriver"
//      because they have different responsibilties.
//   -Subclasses have a PIDController and appropriate measurement class.
//
// ##########################################

#ifndef LOW_LEVEL_NUCLEO_MOTORDRIVER_HPP
#define LOW_LEVEL_NUCLEO_MOTORDRIVER_HPP

#include <mbed.h>
#include "pidcontroller.hpp"

namespace low_level {
    namespace nucleo {
        class MotorDriver {
            private:
                PwmOut pwmPin;
                PIDController controller;
        
            public:
                /** Sets the pin to be used to send PWM signal to motor.
                 * 
                 * @param PinName Desired pin to be used for PWM.
                 */
                void SetPwmPin(PinName pin);

                virtual void Drive(float control);

        };

        class SteeringDriver : public MotorDriver {
            private:
                DigitalOut inhibitPin;
                //! Include potentiometer class to measure.
            public:
                /** Constructs an instance of SteeringDriver class
                * 
                * @param PinName Desired pin to be used for PWM.
                * @param PinName Desired pin to be used for enabling drive.
                */
                SteeringDriver(PinName pwmPin, PinName inhibitPin);

                /** Sets the pin to be used to enable/inhibit the motor.
                * 
                * @param PinName Desired pin to be used for enabling drive.
                */
                void SetInhibitPin(PinName inhibitPin);

                /** Attempts to drive motor to desired angle. Uses
                *  PIDController and potentiometer to do so.
                * @param float Desired angle.
                */
                void Drive(float desiredAngle) override;
        };

        class WheelDriver : public MotorDriver {
            private:
                PwmOut brakePin;
                //! Include so far unmade tachometer class for measurements
            public:
                /** Constructs an instance of WheelDriver class
                * 
                * @param PinName Desired pin to be used for PWM.
                */
                WheelDriver(PinName pin);

                /** Sets the pin to be used to activate the braking motor.
                * 
                * @param PinName Desired pin to be used for braking.
                */
                void SetBrakePin(PinName brakePin);

                /** Attempts to drive motor to desired velocity. Uses
                *  PIDController and tachometer to do so.
                * @param float Desired velocity.
                */
                void Drive(float desiredVel) override;
        };
    }
}

#endif //LOW_LEVEL_NUCLEO_MOTORDRIVER_HPP