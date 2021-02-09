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


namespace low_level {
    namespace nucleo {
                void red_led_on();
                void red_led_off();
                
                void yellow_led_on();
                void yellow_led_off();
                
                void green_led_on();
                void green_led_off();

                void all_leds_off();
                void all_leds_on();
                
                void only_red_led_on();
                void only_yellow_led_on();
                void only_green_led_on();

                /** Blink at 10 Hz */
                void green_led_blink_fast();   
                /** Blink at 1 Hz */ 
                void green_led_blink_slow();  

                /** Blink at 10 Hz */
                void yellow_led_blink_fast();  
                /** Blink at 1 Hz */
                void yellow_led_blink_slow();  

                /** Blink at 10 Hz */
                void red_led_blink_fast();      
                /** Blink at 1 Hz */
                void red_led_blink_slow();     
    }
}