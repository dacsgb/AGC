#ifndef _ROS_custom_msgs_velocityEstimate_h
#define _ROS_custom_msgs_velocityEstimate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_msgs
{

  class velocityEstimate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _velE_type;
      _velE_type velE;
      typedef double _velN_type;
      _velN_type velN;
      typedef double _velU_type;
      _velU_type velU;

    velocityEstimate():
      header(),
      velE(0),
      velN(0),
      velU(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_velE;
      u_velE.real = this->velE;
      *(outbuffer + offset + 0) = (u_velE.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velE.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velE.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velE.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velE.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velE.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velE.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velE.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velE);
      union {
        double real;
        uint64_t base;
      } u_velN;
      u_velN.real = this->velN;
      *(outbuffer + offset + 0) = (u_velN.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velN.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velN.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velN.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velN.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velN.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velN.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velN.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velN);
      union {
        double real;
        uint64_t base;
      } u_velU;
      u_velU.real = this->velU;
      *(outbuffer + offset + 0) = (u_velU.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velU.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velU.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velU.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velU.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velU.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velU.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velU.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velU);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_velE;
      u_velE.base = 0;
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velE.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velE = u_velE.real;
      offset += sizeof(this->velE);
      union {
        double real;
        uint64_t base;
      } u_velN;
      u_velN.base = 0;
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velN.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velN = u_velN.real;
      offset += sizeof(this->velN);
      union {
        double real;
        uint64_t base;
      } u_velU;
      u_velU.base = 0;
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velU.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velU = u_velU.real;
      offset += sizeof(this->velU);
     return offset;
    }

    const char * getType(){ return "custom_msgs/velocityEstimate"; };
    const char * getMD5(){ return "61406b2619738bd0fe334780af479020"; };

  };

}
#endif