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

#include "potentiometer.hpp"

//const float M_PI = 3.14159265358979323846;

namespace low_level {
    namespace nucleo {
        Pot::Pot(ros::NodeHandle &nh, PinName pin) : _pot(pin) { 
            _nh = &nh;
        }
        Pot::Pot(ros::NodeHandle& nh, PinName pin, float center_pot_pos, float max_pot_pos) : _pot(pin) { 
            _nh = &nh;
             calibrate(center_pot_pos, max_pot_pos);
        }
        void Pot::calibrate(float center_pot_pos, float max_pot_pos) {
            float diff = abs(center_pot_pos - max_pot_pos);
            float left_pot_bound = center_pot_pos - diff;
            float right_pot_bound = center_pot_pos + diff;

            if(left_pot_bound < 0)  { _nh->logfatal("POTENTIOMETER LOW BOUNDARY SET BELOW 0");  } //! LOG FATAL W/ SERVER & EXIT 
            if(right_pot_bound > 1) { _nh->logfatal("POTENTIOMETER HIGH BOUNDARY SET ABOVE 1"); } //! LOG FATAL W/ SERVER & EXIT  

            _left_pot_bound = left_pot_bound;
            _right_pot_bound = right_pot_bound;
            _mid = (_left_pot_bound + _right_pot_bound) / 2;
        }
        void Pot::beginAverage(float period) {
            _period = period;
            _sum = 0;
            _counts = 0;
            _read_avg = true;
            _avg_timeout.attach(callback(this, &Pot::timeout_callback), _period);
        }
        void Pot::endAverage() {
            _avg_timeout.detach();
        }
        float Pot::readADC() {
            if(_read_avg) {
                _read_avg = false;
                return _sum/(float)_counts;
            } else return _pot.read();
        }
        float Pot::readVolts() {
            if(_read_avg) {
                _read_avg = false;
                return 3.3*_sum/(float)_counts;
            } else return 3.3*_pot.read();
        }
        float Pot::readmVolts() {
            if(_read_avg) {
                _read_avg = false;
                return 3300*_sum/(float)_counts;
            } else return 3300*_sum/(float)_counts;
        } 
        float Pot::readDegrees() {
            if(_read_avg) {
                _read_avg = false;
                return ADCtoDeg*(_sum/(float)_counts);
            } else return ADCtoDeg*_pot.read();
        }
        float Pot::readRadians() {
            return M_PI/180*readDegrees();
        }
        void Pot::timeout_callback() {
            _sum += _pot.read();
            ++_counts;
            _avg_timeout.attach(callback(this, &Pot::timeout_callback), _period);
        }

        float Pot:: readAverageDegrees() {
            float returnVal;
            endAverage();
            returnVal = readDegrees();
            beginAverage(_period);
            return returnVal;
        }
        float Pot::readAverageRadians() {
            float returnVal;
            endAverage();
            returnVal = (M_PI / 180) * readDegrees();
            beginAverage(_period);
            return returnVal;
        }
    }
}