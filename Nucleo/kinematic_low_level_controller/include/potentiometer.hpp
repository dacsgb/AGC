// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Loss-of-Signal (LOS) INCLUDE
//   Date    -   06-04-2020
//
//   class Pot
//      Pot(PinName pin, float leftPos, float rightPos);
//
//      void calibrate(float leftPos, float rightPos);
//      void beginAverage(float frequency);
//      void endAverage();
//
//      unsigned int readADC();
//      float readVolts();
//      float readmVolts();
//      float readDegrees();
//      float readRadians();
//      void readAverageRadians(float& returnVal);
//      
//  *NOTES*
//
// ##########################################  

#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <mbed.h>
#include <ros.h>

namespace low_level {
    namespace nucleo {
        /** @class Calculator to extrapolate angular position from potentiometer
         * 
         */ 
        class Pot {
            private:
                AnalogIn _pot;
                Timeout _avg_timeout;
                ros::NodeHandle* _nh;

                void timeout_callback();

                float _left_pot_bound, _right_pot_bound, _mid;
                float _period, _sum = 0;
                unsigned int _counts = 0;
                bool _read_avg = false;

                const int ADCtoDeg = 1;  //TODO Figure this out

            public:
                /** Constructor without calibration
                 * 
                 *  @param pin Analog input pin of potentiometer
                 *  @note Must be subsequently calibrated to read degrees or radians
                 */ 
                
                Pot(ros::NodeHandle &nh, PinName pin);

                /** Constructor with calibration
                 * 
                 * @param pin Analog input pin of potentiometer
                 * @param center_pot_pos Raw potentiometer value corresponding to zero rotation
                 * @param max_pot_pos Raw potentiometer value corresponding to position with maximal deviation from zero rotation
                 * @note To find center_pot_pos, record Pot::readADC() at position corresponding to zero rotation 
                 * @note To find max_pot_pos, record Pot::readADC() at posiiton corresponding to maximal absolute value of rotation
                 */ 
                Pot(ros::NodeHandle &nh, PinName pin, float center_pot_pos, float max_pot_pos);
                

                /** Calibrate the calculator
                 * 
                 * @param pin Analog input pin of potentiometer
                 * @param center_pot_pos Raw potentiometer value corresponding to zero rotation
                 * @param max_pot_pos Raw potentiometer value corresponding to position with maximal deviation from zero rotation
                 * @note To find center_pot_pos, record Pot::readADC() at position corresponding to zero rotation 
                 * @note To find max_pot_pos, record Pot::readADC() at posiiton corresponding to maximal absolute value of rotation
                 */ 
                void calibrate(float center_pot_pos, float max_pot_pos);


                void beginAverage(float period);
                void endAverage();

                float readADC();
                float readVolts();
                float readmVolts();
                float readDegrees();
                float readRadians();
                float readAverageDegrees();
                float readAverageRadians();
        };
    }
}

#endif // POTENTIOMETER_H