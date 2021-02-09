/**************************************************************************************
    Author  -   Max DeSantis
    Email   -   max.desantis@okstate.edu
    Alg     -   Proportional, Integral, Derivative (PID) Controller INCLUDE
    Date    -   08-27-2020

    class PIDController
        PIDController();
        PIDController(us_timestamp_t startTime, float KP, float KI, float KD);
        SetConstantTerms(float KP, float KI, float KD);
        SetStartTime(us_timestamp_t startTime);
        CalculateControl(float actualVal, float desiredVal, us_timestamp_t executionTime);

    *NOTES*
    -Implements PID controller on provided input with provided coefficients.
    -Performs no control itself; output must be utilized by other class.

**************************************************************************************/

#ifndef LOW_LEVEL_NUCLEO_PIDCONTROLLER_HPP
#define LOW_LEVEL_NUCLEO_PIDCONTROLLER_HPP

#include <mbed.h>

namespace low_level {
    namespace nucleo {
        /* Class to implement a PID control loop */
        class PIDController {
            private:
                /* Control values */
                float KP, KI, KD;
                float integral = 0.0;
                float derivative;
                float previousError = 0.0;
                float error;

            public:

                /**Construct an instance of the PIDController class
                 * Initializes KP, KI, and KD as 0. */
                PIDController();

                /**Construct an instance of the PIDController class
                 * @param float PID coefficient KP
                 * @param float PID coefficient KI
                 * @param float PID coefficient KD */
                PIDController(float KP, float KI, float KD);

                /**Store control coefficients 
                 * @param float PID coefficient KP
                 * @param float PID coefficient KI
                 * @param float PID coefficient KD */
                void SetConstantTerms(float KP, float KI, float KD);

                /**Performs PID loop calculation and returns control variable
                 * @param float Actual value being controlled (actual speed, actual angle).
                 * @param float Desired value to be reached (ideal speed, ideal angle).
                 * @param us_timestamp_t Time passed since last execution in us. */
                float CalculateControl(float actualVal, float desiredVal, us_timestamp_t timePassed);
        };
    }
}
#endif //LOW_LEVEL_NUCLEO_CONTROLLER_HPP