// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Autoware Interface SOURCE
//   Date    -   07-28-2020
//      
//  *NOTES*
//
// ##########################################


#include "autoware_interface.hpp"
#include "vehicle_parameters.h"

namespace low_level {
    namespace nucleo {
        AutowareInterface::AutowareInterface(ros::NodeHandle &nh, char* cmd_topic_name) : cmd_sub(cmd_topic_name, &AutowareInterface::cmd_cb, this) {
            _nh = &nh;
            this->cmd_topic_name = cmd_topic_name;
        }
        void AutowareInterface::cmd_cb(const autoware_msgs::VehicleCmd &msg) {
            vehicle_cmd = msg;
        }

        float AutowareInterface::getLinearCmd() {
            return vehicle_cmd.twist_cmd.twist.linear.x;
        }
        float AutowareInterface::getAngularCmd() {
            return vehicle_cmd.twist_cmd.twist.angular.z;
        }
        float AutowareInterface::getSteeringAngle() {
            float v = vehicle_cmd.twist_cmd.twist.linear.x;
            float theta_dot = vehicle_cmd.twist_cmd.twist.angular.z;
            return atan((theta_dot*L)/v) / LAMBDA;
        }
    }
}