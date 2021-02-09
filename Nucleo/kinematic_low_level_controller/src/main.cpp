
// ##########################################
// 
//   Author  -   Collin Thornton, Max DeSantis, Fernando Cavazos
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Low Level Controller for Autonomous Golf Cart SOURCE
//   Date    -   06-04-2020
//
//      
//  *NOTES*
//   -User leds indicate connection/state status
//   
//    COLOR CODE            DEVICE  STATUS
//    -fast green         -         CONNECTING
//    -slow green         -         HEALTHY
//    -fast yellow        - nucleo  UNSTABLE (likely time overflow)
//    -slow yellow        - jetson  UNSTABLE
//    -solid yellow       - both    UNSTABLE
//    -fast red           -         DISCONNECTION
//    -solid red          - jetson  FATAL
//    -solid red & yellow - nucleo  FATAL
//
//!  -ALL SERVICE CALLS MUST HAVE A TIMEOUT GUARD
//!  -SERVICE SERVERS ARE TOO SLOW WITH ROSSERIAL_PYTHON. 
//!     TRY IMPLEMENTING WHEN NON-EXPERIMENTAL VERSION OF ROSSERIAL_SERVER IS RELEASED
// eg:
//            Timeout timeout;
//            timeout.attach_us(CALLBACK_FUNCTION, TIMEOUT_IN_MICROSECONDS);
//            server.call(srv_req, srv_resp);
//            timeout.detach();
//
//            void CALLBACK_FUNCTION() {
//              set flag to handle service disconnect here
//              be careful not to use blocking functions in callback
//            }
//
// ##########################################  

#include <mbed.h>
#include <ros.h>
#include <std_msgs/String.h>

#include "los.hpp"
#include "velocitycontroller.hpp"
using namespace low_level::nucleo;

const int PERIOD = 1E5;


int main() {
  ros::NodeHandle nh;
  std_msgs::UInt16 loop_time;

  // Loop time publisher (ms)
  ros::Publisher loop_time_pub("/low_level/nucleo/loop_time", &loop_time);

  green_led_blink_fast();

  nh.getHardware()->setBaud(900000);
  nh.initNode();
  nh.advertise(loop_time_pub);

  while(!nh.connected()) { nh.spinOnce();  wait_ms(1); }


  LOS los = LOS(nh, PERIOD, "/low_level/nucleo/los/status", "/master/SystemStatus");
  VelocityController controller = VelocityController(nh, controller.defaultParams, "/low_level/nucleo/actual", "/low_level/nucleo/cmd"); //Is it legal to reference controller.params like this?
  Timer time, los_timer;
  
  time.start();
  los_timer.start();

  //! Set timeout for watchdog event
  //Watchdog::get_instance().start(PERIOD/1000*3);

  while(1) {
    //! Uncomment this to hard reset if watchdog timeout event occurs
    //Watchdog::get_instance().kick();


    // Get Jetson status and publish nucleo status
    los.update();

    // Wait for period to complete
    // Log warning and set LOS to unstable if loop time has overflowed   

    int time_left = PERIOD - time.read_us();

    if(time_left > 0) {
      los.set_nucleo_healthy();
      wait_us(time_left);
    }
    else {
      nh.logwarn("LOW-LEVEL TIME OVERFLOW");
      los.set_nucleo_unstable();
    }
    loop_time.data = time.read_ms();
    loop_time_pub.publish(&loop_time);

    time.reset();
    nh.spinOnce();
  }
}