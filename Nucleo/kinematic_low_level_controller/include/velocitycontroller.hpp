/**************************************************************************************

    Author  -   Max DeSantis
    Email   -   max.desantis@okstate.edu
    Alg     -   Velocity Controller INCLUDE
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

#ifndef LOW_LEVEL_NUCLEO_VELOCITYCONTROLLER_HPP
#define LOW_LEVEL_NUCLEO_VELOCITYCONTROLLER_HPP

#include <mbed.h>
#include "tachometer.hpp"
#include "potentiometer.hpp"
#include "pidcontroller.hpp"
#include <ros.h>
#include "geometry_msgs/Twist.h"

namespace low_level {
    namespace nucleo {
        class VelocityController {
            private:

                /* State machine */
                enum State {accelerating, coasting, braking, stopping};
                State currentState = stopping;
                State previousState = stopping;

                /* ROS */
                ros::Publisher                          controller_pub;
                ros::Subscriber<geometry_msgs::Twist, VelocityController>   controller_sub;
                geometry_msgs::Twist                    str_msg;

                /* Measurement gathering */
                Ticker          measurementLoop;
                Ticker          speedLoop;
                Ticker          steeringLoop;
                Ticker          brakeLoop;
                Tachometer      tacho;
                Pot             pot;

                float           desiredSpeed = 0;
                float           desiredAngle = 0;
                float           desiredPotVal;

                float           actualSpeed;
                float           actualAngle;
                float           actualPotVal;
                

                /* PID controllers */
                PIDController   speedController;
                PIDController   steeringController;
                PIDController   brakeController;

                /* Pins */
                DigitalOut      steeringInhibitPin;
                PwmOut          speedPin;
                PwmOut          steeringPin;
                PwmOut          brakePin;


            public:

                /* Manages initial configuration of controllers */

                //!FIXME Need default values for all of these.
                struct Parameters {
                    PinName tachPinA;
                    PinName tachPinB;
                    PinName potPin;
                    PinName speedPin;
                    PinName steeringPin;
                    PinName inhibitPin;
                    PinName brakePin;

                    float speedKP = 0;
                    float speedKI = 0;
                    float speedKD = 0;

                    float steeringKP = 0;
                    float steeringKI = 0;
                    float steeringKD = 0;

                    float brakeKP = 0;
                    float brakeKI = 0;
                    float brakeKD = 0;

                } defaultParams;

                /**Estimates current state when new values are received.
                 * @param const geometry_msgs::Twist& Reference variable to ROS message that holds data. */
                void ROSUpdate(const geometry_msgs::Twist& msg);

                /**Create velocity controller. Manages speed, steering, and braking.
                 * @param NodeHandle &nh Reference to ros handler.
                 * @param struct Parameters Defines various pins and PID coefficients.
                 * @param controller_pub_topic_name Name of the ROS topic to which velocity controller data is published
                 * @param controller_sub_topic_name Name of the ROS topic with new data from Jetson */
                VelocityController(ros::NodeHandle &nh, Parameters params, char* controller_pub_topic_name, char* controller_sub_topic_name);

                /**Gathers actual speed and actual steering angle at set rate. */
                void GatherMeasurements();

                /**Speed callback function to be called at set rate. */
                void SpeedControl();

                /**Steering callback function to be called at set rate. */
                void SteeringControl();

                /**Brake callback function to be called at set rate. */
                void BrakeControl();

                /**Directly maps desired speed to built-in speed controller.
                 * @param float Value between 0-1 that will be directly sent to motor by PWM. */
                void DirectDrive(float speedVal);

                /**Directly maps desired braking percentage to motor output.
                 * @param float Value between 0-1 that will be sent to motor by PWM. */
                void DirectBrake(float brakeVal);
        };
    }
}
#endif //LOW_LEVEL_NUCLEO_VELOCITYCONTROLLER_HPP