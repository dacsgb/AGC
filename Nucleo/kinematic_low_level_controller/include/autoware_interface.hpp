// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Autoware Interface INCLUDE
//   Date    -   07-28-2020
//      
//  *NOTES*
//
// ##########################################

#ifndef AUTOWARE_INTERFACE
#define AUTOWARE_INTERFACE

#include <string>

#include <mbed.h>
#include <ros.h>

#include <autoware_msgs/VehicleCmd.h>

namespace low_level {
    namespace nucleo {
        class AutowareInterface {
            private:
                ros::NodeHandle *_nh;
                ros::Subscriber<autoware_msgs::VehicleCmd, AutowareInterface> cmd_sub;

                autoware_msgs::VehicleCmd vehicle_cmd;

                std::string cmd_topic_name;

                void cmd_cb(const autoware_msgs::VehicleCmd &msg);

            public:
                AutowareInterface(ros::NodeHandle &nh, char* cmd_topic_name);

                float getLinearCmd();
                float getAngularCmd();
                float getSteeringAngle();
        };    
    }
}


#endif // VEHICLE_PARAMETERS_H