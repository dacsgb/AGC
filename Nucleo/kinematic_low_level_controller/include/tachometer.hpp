/************************************************************************************** 

    Author  -   Max DeSantis
    Email   -   max.desantis@okstate.edu
    Alg     -   Tachometer SOURCE
    Date    -   08-27-2020

    class tachometer
        Tachometer(PinName pinA, PinName pinB)
        float readVelocity(us_timestamp_t timePassed)
      
    *NOTES*
    -Provides velocity readings to motordriver class.
    -Reads from wires provided by golfcart tachometer.

**************************************************************************************/

#ifndef LOW_LEVEL_NUCLEO_TACHOMETER_HPP
#define LOW_LEVEL_NUCLEO_TACHOMETER_HPP

#include <mbed.h>

namespace low_level {
    namespace nucleo {
        class Tachometer {
            private:

                /* General tracking vars */
                int count = 0;
                us_timestamp_t prevTime;

                /* Interrupt pins used by the encoder */
                InterruptIn encPinA;
                InterruptIn encPinB;

                /* Interrupt callback functions */
                void riseA();
                void riseB();

            public:

                /**Initialize encoder with its interrupt pins.
                 * @param PinName encoder pin A
                 * @param PinName encoder pin B */
                Tachometer(PinName pinA, PinName pinB);

                /**Return speed of cart in m/s */
                float readVelocity(us_timestamp_t timePassed);
        };

    }
}

#endif //LOW_LEVEL_NUCLEO_TACHOMETER_HPP