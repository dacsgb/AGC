// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Loss-of-Signal (LOS) INCLUDE
//   Date    -   06-04-2020
//
//   static library with helper functions for user leds
//      
//  *NOTES*
//   -Be sure pin numbers (implemented in leds.cpp) don't conflict
//      with other files in program.
//
// ########################################## 

#include <mbed.h>
#include "leds.h"

namespace low_level {
    namespace nucleo {
        DigitalOut green_led(LED1), yellow_led(PE_1), red_led(LED3);
        Timeout green_timeout, yellow_timeout, red_timeout;

        const float FAST = 0.1f;
        const float SLOW = 1.0f;

        float gspd, yspd, rspd;

        void green_cb()     { green_led  = !green_led;  green_timeout.attach(green_cb, gspd); }
        void yellow_cb()    { yellow_led = !yellow_led; yellow_timeout.attach(yellow_cb, yspd); }
        void red_cb()       { red_led    = !red_led;    red_timeout.attach(red_cb, rspd); }

        void green_led_on()     { green_led = 1; green_timeout.detach(); }
        void green_led_off()    { green_led = 0; green_timeout.detach(); }
        
        void yellow_led_on()    { yellow_led = 1; yellow_timeout.detach(); }
        void yellow_led_off()   { yellow_led = 0; yellow_timeout.detach(); }
        
        void red_led_on()       { red_led = 1; red_timeout.detach(); }
        void red_led_off()      { red_led = 0; red_timeout.detach(); }

        void all_leds_on()       { green_led_on(); yellow_led_on(); red_led_on(); }
        void all_leds_off()      { green_led_off(); yellow_led_off(); red_led_off(); }
        
        void only_green_led_on()    { all_leds_off(); green_led_on();    }
        void only_yellow_led_on()   { all_leds_off(); yellow_led_on();   }
        void only_red_led_on()      { all_leds_off(); red_led_on();      }
    
        void green_led_blink_fast() { gspd = FAST; green_timeout.attach(&green_cb, gspd);   }
        void green_led_blink_slow() { gspd = SLOW; green_timeout.attach(&green_cb, gspd);   }

        void yellow_led_blink_fast() { yspd = FAST; yellow_timeout.attach(&yellow_cb, yspd);    }
        void yellow_led_blink_slow() { yspd = SLOW; yellow_timeout.attach(&yellow_cb, yspd);    }

        void red_led_blink_fast() { rspd = FAST; red_timeout.attach(&red_cb, rspd);     }
        void red_led_blink_slow() { rspd = SLOW; red_timeout.attach(&red_cb, rspd);     }
    }
}