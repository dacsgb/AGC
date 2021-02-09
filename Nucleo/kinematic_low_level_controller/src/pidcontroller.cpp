/**************************************************************************************
    Author  -   Max DeSantis
    Email   -   max.desantis@okstate.edu
    Alg     -   Proportional, Integral, Derivative (PID) Controller SOURCE
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

#include <mbed.h>
#include "pidcontroller.hpp"

namespace low_level {
    namespace nucleo {

      PIDController::PIDController() {
        KP = 0;
        KI = 0;
        KD = 0;
      }

      PIDController::PIDController(float KP, float KI, float KD) {
        this->KP = KP;
        this->KI = KI;
        this->KD = KD;
      }

      void PIDController::SetConstantTerms(float KP, float KI, float KD) {
        this->KP = KP;
        this->KI = KI;
        this->KD = KD;
      }

      float PIDController::CalculateControl(float actualVal, float desiredVal, us_timestamp_t timePassed) {
        /* Convert time from us to s */
        timePassed = timePassed * 1E-6;

        /* Standard PID control evaluation */
        error = actualVal - desiredVal;
        integral = integral + (error * timePassed);
        derivative = (error - previousError) / timePassed;

        float control = (error * KP) + (integral * KI) + (derivative * KD);

        previousError = error;

        return control;
      }

    }
}