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

#include "tachometer.hpp"

const float TACH_CONVERSION = 1.0; //! (UNKNOWN VALUE?) Units: meters per encoder tick.

namespace low_level {
    namespace nucleo {

        Tachometer::Tachometer(PinName pinA, PinName pinB) : encPinA(pinA), encPinB(pinB){
            
            /* Attach interrupt functions */
            encPinA.rise(callback(this, &Tachometer::riseA));
            encPinB.rise(callback(this, &Tachometer::riseB));
            /* NOTE: More accuracy can be gained by attaching interrupts to the fallings edges. */

        }

        float Tachometer::readVelocity(us_timestamp_t timePassed) {

            /* Converts ticks into meters and microseconds into seconds */
            float velocity = (count * TACH_CONVERSION) / (timePassed * 1E-6);
            count = 0;
            return velocity;
        }

        void Tachometer::riseA() {
            
            /* If B is already high, cart is moving backwards. */
            if(encPinB.read()) {
                --count;
            }
            else {
                ++count;
            }
            return;
        }

        void Tachometer::riseB() {

            /* If A is already high, cart is moving forwards. */
            if(encPinA.read()) {
                ++count;
            }
            else {
                --count;
            }
            return;
        }
    }
}