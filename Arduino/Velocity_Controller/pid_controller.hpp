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
        
        error = setpoint - measured;
        integral += error * timePassed * ki;
        derivative = (error - previousError) / timePassed;

        //Stop integral windup
        if(integral > upperControlLimit) integral = upperControlLimit;
        else if(integral < lowerControlLimit) integral = lowerControlLimit;
        
        float control = (error * kp) + integral + (derivative * kd);

        //Bound control term within correct range
        if(control > upperControlLimit) control = upperControlLimit;
        else if(control < lowerControlLimit) control = lowerControlLimit;

        previousError = error;

        return control;

        //Room for improvement:
        //derivative kick,
        //PID handles frequency
        //Changing frequency on the fly
        //Changing tunings on the fly (works better with preset period)
   }
};

#endif //PID_CONTROLLER_HPP
