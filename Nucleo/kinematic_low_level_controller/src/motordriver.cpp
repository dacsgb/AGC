// ##########################################
// 
//   Author  -   Max DeSantis
//   Email   -   max.desantis@okstate.edu
//   Alg     -   Motor Driver SOURCE
//   Date    -   06-13-2020
//
//  *NOTES*
//   -Designed to store pin information and output PWM signals to relevant motors.
//
// ##########################################

#include <mbed.h>
#include "motordriver.hpp"

namespace low_level {
    namespace nucleo {
        void MotorDriver::SetPwmPin(PinName pwmPin) {this->pwmPin = pwmPin;}

        void SteeringDriver::Drive (float desiredAngle) {
            //TODO: Gather measurement and time.
            // Calculate PID control.
            // Disable inhibit pin.
            // Send drive signal to motor.
        }
        
        void WheelDriver::Drive (float desiredVel) {
            //Must account for braking, therefore should be separate from steering driver.
            //TODO: Gather measurement and time.
            // Calculate PID Control.
            // Send drive signal to motor.
            // Account for "brake" signal. If desiredVel = 0 then drivePwm = 0 and brakePwm = something?
        
        }
    }
}