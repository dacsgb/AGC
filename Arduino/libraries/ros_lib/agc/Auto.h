#ifndef _ROS_agc_Auto_h
#define _ROS_agc_Auto_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace agc
{

  class Auto : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _autonomous_type;
      _autonomous_type autonomous;

    Auto():
      header(),
      autonomous(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_autonomous;
      u_autonomous.real = this->autonomous;
      *(outbuffer + offset + 0) = (u_autonomous.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_autonomous;
      u_autonomous.base = 0;
      u_autonomous.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autonomous = u_autonomous.real;
      offset += sizeof(this->autonomous);
     return offset;
    }

    const char * getType(){ return "agc/Auto"; };
    const char * getMD5(){ return "8712f85b0dc1b79095d4399e062bd29a"; };

  };

}
#endif
