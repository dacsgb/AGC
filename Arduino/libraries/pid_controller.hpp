/*
Author:     Max DeSantis
Contact:    max.desantis@okstate.edu
Purpose:    Compute control variable using PID given setpoint and measured value
*/

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

class PIDController {
    private:
    
    float kp, ki, kd;
    float integral = 0.0;
    float derivative;
    float previousError = 0.0;
    float error;

    int upperControlLimit = 255;
    int lowerControlLimit = 0;

    public:

    PIDController(float KP, float KI, float KD) {
        kp = KP;
        ki = KI;
        kd = KD;
    }

    void setControlLimits(int upperLimit, int lowerLimit) {
        upperControlLimit = upperLimit;
        lowerControlLimit = lowerLimit;
    }

    /**Compute and return control value from PID.
     * @param float Desired value to reach; setpoint
     * @param float Measured value; actual
     * @param unsigned long milliseconds passed since last measure
     * @return float Control value
     */
    float computeControl(float setpoint, float measured, unsigned long timePassed) {
        unsigned 
        error = setpoint - measured;
        integral = integral + (error * timePassed);
        derivative = (error - previousError) / timePassed;

        float control = (error * kp) + (integral * ki) + (derivative * kd);
        
        if(control >)

        previousError = error;

        return control;
    }
};





#endif //PID_CONTROLLER_HPP