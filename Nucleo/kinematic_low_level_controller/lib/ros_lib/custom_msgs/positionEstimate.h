#ifndef _ROS_custom_msgs_positionEstimate_h
#define _ROS_custom_msgs_positionEstimate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_msgs
{

  class positionEstimate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _hEll_type;
      _hEll_type hEll;

    positionEstimate():
      header(),
      latitude(0),
      longitude(0),
      hEll(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_hEll;
      u_hEll.real = this->hEll;
      *(outbuffer + offset + 0) = (u_hEll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hEll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hEll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hEll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hEll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hEll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hEll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hEll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hEll);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_hEll;
      u_hEll.base = 0;
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hEll = u_hEll.real;
      offset += sizeof(this->hEll);
     return offset;
    }

    const char * getType(){ return "custom_msgs/positionEstimate"; };
    const char * getMD5(){ return "3684d34dfe30f7d6456bbd35381e6d7a"; };

  };

}
#endif