// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Loss-of-Signal (LOS) INCLUDE
//   Date    -   06-04-2020
//
//   class LOS
//      LOS(ros::NodeHandle &nh, unsigned int PERIOD, char* los_srv_server_name, char* los_srv_client_name)
//      int update()
//      void get_nucleo_state()
//      void set_nucleo_healthy()
//      void set_nucleo_unstable()
//      void set_nucleo_stable()
//      
//  *NOTES*
//   -Contains logic for detecting/handling LOS events and bad state
//
//TODO Finish implementing state machine when velocity control
//TODO   and/or manual overrides are implemented
//
// ##########################################  

#ifndef LOW_LEVEL_NUCLEO_LOS_HPP
#define LOW_LEVEL_NUCLEO_LOS_HPP

#include <mbed.h>
#include <ros.h>
#include <std_msgs/String.h>

#include <status/status_msg.h>
#include <status/status_srv.h>

#include "leds.h"
namespace low_level {
    namespace nucleo {
        /** Class to handle loss-of-signal events with ROS
         * 
         * @note Only construct 1 instance of this class.
         * @todo Finish implementing state machine when velocity control and/or manual overrides are implemented
         */ 
        class LOS {
            private:
                // ROS message objects
                std_msgs::String str_msg;

                //TODO ServiceServers are too slow with the current release of rosserial_python. Maybe retry when rosserial_server (cpp version of rosserial_python) is released as non-experimental 
                
                // ROS objects
                //ros::ServiceServer<status::status_srvRequest, status::status_srvResponse, LOS> nucleo_server;
                //ros::ServiceClient<status::status_srvRequest, status::status_srvResponse> jetson_server;
                ros::NodeHandle *_nh;   
                ros::Publisher nucleo_pub;
                ros::Subscriber<status::status_msg, LOS> jetson_sub;

                status::status_msg jetson_state;                        // Jetson state
                status::status_msg nucleo_state;
                status::status_msg prev_jstate, prev_nstate;
                Timeout los_timeout;                                    // Timeout instance to trigger LOS states
                unsigned int PERIOD;                                    // Microseconds   
                unsigned short unstable_count = 20;
                bool sub_timeout = false;

                // Helper functions to handle system states
                //! NOT FULLY IMPLEMENTED
                void handle_jetson_healthy();
                void handle_jetson_unstable();
                void handle_jetson_fatal();

                void handle_nucleo_healthy();
                void handle_nucleo_unstable();
                void handle_nucleo_fatal();

                void handle_connecting();
                void handle_disconnect();

                // Callback functions
                void timeout_callback();
                //void nucleo_cb(const status::status_srvRequest &req, status::status_srvResponse &resp);
                void jetson_cb(const status::status_msg &msg);

            public:
                /** Construct an instance of the LOS class
                 * 
                 * @param nh ROS Node Handle
                 * @param PERIOD Period (uS) of incoming messages. LOS timeout is 3x this value.
                 * @param los_pub_topic_name Name of the ROS topic to which state data is published
                 * @param los_sub_topic_name Name of the ROS topic with state data from Jetson
                  */
                LOS(ros::NodeHandle &nh, int PERIOD, char* los_pub_topic_name, char* los_sub_topic_name);
            
                /** Publish state data and parse Jetson state
                 *
                 * @return State of system
                 * @note System state is handled in this function
                 */
                int update();

                /** Get nucleo state
                 * 
                 * @return Current nucleo_state
                 * @note This should be known
                 */
                void get_nucleo_state();

                /** Set nucleo_state to healthy. Will be published to Jetson when LOS::update() is called   */
                void set_nucleo_healthy();

                /** Set nucleo_state to unstable. Will be published to Jetson when LOS::update() is called 
                 * 
                 * @note State will reset to healthy for 20 calls to LOS::update().
                 */
                void set_nucleo_unstable();

                /** Set nucleo_state to fatal. Will be published to Jetson when LOS::update() is called     */
                void set_nucleo_fatal();
        };
    }
}

#endif // LOW_LEVEL_NUCLEO_LOS_HPP