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
        float error [2] = {0.0,0.0};
        unsigned long time[2] = {0.0,0.0};

        float umax = 1;
        float umin = 0;

    public:

        PIDController(float KP, float KI, float KD) {
            kp = KP;
            ki = KI;
            kd = KD;
        }

        void setControlLimits(int upperLimit, int lowerLimit) {
            umin = upperLimit;
            umax = lowerLimit;
        }

        /**Compute and return control value from PID.
         * @param float Desired value to reach; setpoint
         * @param float Measured value; actual
         * @param unsigned long milliseconds passed since last measure
         * @return float Control value
         */
        float computeControl(float setpoint, float measured, unsigned long t1) {
            
            // Store current error and time into arrays
            error[1] = setpoint - measured;
            time[1] = t1;

            // Calculate derivative and integral
            float derivative = (error[1]-error[0]) / (time[1]-time[0]);
            float dintegral = (error[1]-error[0]) * (time[1]-time[0]);
            integral += dintegral;

            // Calculate control input
            float control = (kp*error[1]) + ki*integral + (kd*derivative);

            // Intrgeal windup correction
            if((control > umax) || (control < umin)){
                control -= ki*integral;
                integral -= dintegral;
            } 
        
            //Bound control term within correct range
            control = max(umin,min(umax,control));

            // Shift values in error and time array
            error[0] = error[1];
            time[0] = time[1];

            return control;

            //Room for improvement:
            //derivative kick,
            //PID handles frequency
            //Changing frequency on the fly
            //Changing tunings on the fly (works better with preset period)
    }
};

#endif //PID_CONTROLLER_HPP
