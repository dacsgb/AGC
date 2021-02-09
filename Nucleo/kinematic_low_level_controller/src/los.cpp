// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Loss-of-Signal (LOS) SOURCE
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
//   -Only one instance of this class should be initialized
//   -Pass the instance by reference to other classes as necessary
//
//TODO Finish implementing state machine when velocity control
//TODO   and/or manual overrides are implemented
//
// ##########################################   



#include "los.hpp"

namespace low_level {
    namespace nucleo {

        // Implementaton of LOS class
        LOS::LOS(ros::NodeHandle &nh, int PERIOD, char* los_pub_topic_name, char* los_sub_topic_name) : nucleo_pub(los_pub_topic_name, &nucleo_state), jetson_sub(los_sub_topic_name, &LOS::jetson_cb, this) {
            nucleo_state.status.data    = status::status_msg::CONNECTING;
            jetson_state.status.data    = status::status_msg::FATAL;
            prev_jstate.status.data     = status::status_msg::FATAL;
            prev_nstate.status.data     = status::status_msg::DISCONNECTED;

            handle_connecting();

            _nh = &nh;
            this->PERIOD = PERIOD;

            //_nh->advertiseService(nucleo_server);
            //_nh->serviceClient(jetson_server);

            _nh->advertise(nucleo_pub);
            _nh->subscribe(jetson_sub);
            los_timeout.attach_us(callback(this, &LOS::timeout_callback), 3*PERIOD);
        }
        int LOS::update() {
            if(!_nh->connected() || sub_timeout == true) { 
                nucleo_state.status.data    = status::status_msg::DISCONNECTED;
                jetson_state.status.data    = status::status_msg::DISCONNECTED; 
                prev_jstate.status.data     = status::status_msg::DISCONNECTED;
            }

            //status::status_srvRequest   jetson_req;
            //status::status_srvResponse  jetson_resp;

            //los_timeout.attach_us(callback(this, &LOS::timeout_callback), 2*PERIOD);

            // Call all services in this block
            //! SERVICE CALLS MUST HAVE A TIMEOUT GUARD
            //jetson_server.call(jetson_req, jetson_resp);
            //
            //los_timeout.detach();

            //jetson_state.status = jetson_resp.status;

            nucleo_pub.publish(&nucleo_state);

            float pi = M_PI;

            switch(nucleo_state.status.data) {
                case status::status_msg::FATAL:
                    if(prev_nstate.status.data != nucleo_state.status.data) handle_nucleo_fatal();
                    return status::status_msg::FATAL;
                case status::status_msg::UNSTABLE:
                    handle_nucleo_unstable();       // Guard intentionally removed
                    return status::status_msg::UNSTABLE;
                case status::status_msg::HEALTHY:
                    if(prev_nstate.status.data != nucleo_state.status.data) set_nucleo_healthy();
                    break;
                case status::status_msg::DISCONNECTED:
                    if(prev_nstate.status.data != nucleo_state.status.data) handle_disconnect();
                    return status::status_msg::DISCONNECTED;
            }

            switch(jetson_state.status.data) {
                case status::status_msg::FATAL:
                    if(prev_jstate.status.data != jetson_state.status.data) handle_jetson_fatal();
                    return status::status_msg::FATAL;
                case status::status_msg::HEALTHY:
                    if(prev_jstate.status.data != jetson_state.status.data) handle_jetson_healthy();
                    break;
                case status::status_msg::UNSTABLE:
                    if(prev_jstate.status.data != jetson_state.status.data) handle_jetson_unstable();
                    return status::status_msg::UNSTABLE;
                default:
                    _nh->logwarn("NUCLEO::LOS - UNKNOWN CONNECTION STATE FROM JETSON");
                    break;
            }

            return jetson_state.status.data;
        }
        void LOS::handle_jetson_healthy() {
            prev_jstate.status.data = jetson_state.status.data;
            if(nucleo_state.status.data == status::status_msg::HEALTHY) all_leds_off();
            green_led_blink_slow();
        }
        void LOS::handle_jetson_unstable() {
            prev_jstate.status.data = jetson_state.status.data;
            (nucleo_state.status.data == status::status_msg::UNSTABLE) ? yellow_led_on() : yellow_led_blink_slow();
        }
        void LOS::handle_jetson_fatal() {       //! STOP EVERYTHING
            prev_jstate.status.data = jetson_state.status.data;
            only_red_led_on();
        }
        void LOS::handle_nucleo_healthy() {
            prev_nstate.status.data = nucleo_state.status.data;
            if(jetson_state.status.data == status::status_msg::HEALTHY) {
                yellow_led_off();
                red_led_off();
                green_led_blink_slow();
            }
        }
        void LOS::handle_nucleo_unstable() {
            prev_nstate.status.data = nucleo_state.status.data;
            if(++unstable_count == 20) nucleo_state.status.data = status::status_msg::HEALTHY;
            if(unstable_count == 1) (jetson_state.status.data == status::status_msg::UNSTABLE) ? yellow_led_on() : yellow_led_blink_fast();
        }
        void LOS::handle_nucleo_fatal() {       //! STOP EVERYTHING
            prev_nstate.status.data = nucleo_state.status.data;
            all_leds_off();
            red_led_on();
            yellow_led_on();
        }
        void LOS::handle_connecting() {
            prev_nstate.status.data = nucleo_state.status.data;
            all_leds_off();
            green_led_blink_fast();
        }
        void LOS::handle_disconnect() {         //! STOP EVERYTHING
            prev_nstate.status.data = nucleo_state.status.data;
            all_leds_off();
            red_led_blink_fast();
        }
        void LOS::set_nucleo_fatal() {
            nucleo_state.status.data = status::status_msg::FATAL;
        }
        void LOS::set_nucleo_healthy() {
            if(unstable_count >= 20) nucleo_state.status.data = status::status_msg::HEALTHY;
        }
        void LOS::set_nucleo_unstable() {
            nucleo_state.status.data = status::status_msg::UNSTABLE;
            unstable_count = 0;
        }

        // Callback for LOS timeout
        void LOS::timeout_callback() {
            sub_timeout = true;
            nucleo_state.status.data    = status::status_msg::DISCONNECTED;
            jetson_state.status.data    = status::status_msg::DISCONNECTED; 
            prev_jstate.status.data     = status::status_msg::DISCONNECTED;
            handle_disconnect();
            _nh->logwarn("TIMEOUT WAITING FOR /master/SystemStatus");
        }
        // Callback for nucleo service server
        //void LOS::nucleo_cb(const status::status_srvRequest &req, status::status_srvResponse &resp){
        //    resp.status = nucleo_state.status;
        //}        
        // Callback for jetson status subsriber
        void LOS::jetson_cb(const status::status_msg &msg) {
            jetson_state = msg;
            sub_timeout = false;
            los_timeout.detach();
            los_timeout.attach_us(callback(this, &LOS::timeout_callback), 3*PERIOD);
        }
    }
}
