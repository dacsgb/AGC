#ifndef _ROS_pacmod_msgs_VehicleSpeedRpt_h
#define _ROS_pacmod_msgs_VehicleSpeedRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class VehicleSpeedRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _vehicle_speed_type;
      _vehicle_speed_type vehicle_speed;
      typedef bool _vehicle_speed_valid_type;
      _vehicle_speed_valid_type vehicle_speed_valid;
      uint8_t vehicle_speed_raw[2];

    VehicleSpeedRpt():
      header(),
      vehicle_speed(0),
      vehicle_speed_valid(0),
      vehicle_speed_raw()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_vehicle_speed;
      u_vehicle_speed.real = this->vehicle_speed;
      *(outbuffer + offset + 0) = (u_vehicle_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vehicle_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vehicle_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vehicle_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vehicle_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vehicle_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vehicle_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vehicle_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vehicle_speed);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_speed_valid;
      u_vehicle_speed_valid.real = this->vehicle_speed_valid;
      *(outbuffer + offset + 0) = (u_vehicle_speed_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_speed_valid);
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->vehicle_speed_raw[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_speed_raw[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_vehicle_speed;
      u_vehicle_speed.base = 0;
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vehicle_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vehicle_speed = u_vehicle_speed.real;
      offset += sizeof(this->vehicle_speed);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_speed_valid;
      u_vehicle_speed_valid.base = 0;
      u_vehicle_speed_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle_speed_valid = u_vehicle_speed_valid.real;
      offset += sizeof(this->vehicle_speed_valid);
      for( uint32_t i = 0; i < 2; i++){
      this->vehicle_speed_raw[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vehicle_speed_raw[i]);
      }
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/VehicleSpeedRpt"; };
    const char * getMD5(){ return "33c26f1bbea2c9136f0821ddc90cd049"; };

  };

}
#endif