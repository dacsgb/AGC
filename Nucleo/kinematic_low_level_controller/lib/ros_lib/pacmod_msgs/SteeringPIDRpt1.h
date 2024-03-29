#ifndef _ROS_pacmod_msgs_SteeringPIDRpt1_h
#define _ROS_pacmod_msgs_SteeringPIDRpt1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _dt_type;
      _dt_type dt;
      typedef double _kp_type;
      _kp_type kp;
      typedef double _ki_type;
      _ki_type ki;
      typedef double _kd_type;
      _kd_type kd;

    SteeringPIDRpt1():
      header(),
      dt(0),
      kp(0),
      ki(0),
      kd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dt;
      u_dt.real = this->dt;
      *(outbuffer + offset + 0) = (u_dt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dt.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dt.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dt.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dt.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dt.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dt);
      union {
        double real;
        uint64_t base;
      } u_kp;
      u_kp.real = this->kp;
      *(outbuffer + offset + 0) = (u_kp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_kp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_kp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_kp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_kp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->kp);
      union {
        double real;
        uint64_t base;
      } u_ki;
      u_ki.real = this->ki;
      *(outbuffer + offset + 0) = (u_ki.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ki.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ki.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ki.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ki.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ki.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ki.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ki.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ki);
      union {
        double real;
        uint64_t base;
      } u_kd;
      u_kd.real = this->kd;
      *(outbuffer + offset + 0) = (u_kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kd.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_kd.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_kd.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_kd.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_kd.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->kd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dt;
      u_dt.base = 0;
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dt.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dt = u_dt.real;
      offset += sizeof(this->dt);
      union {
        double real;
        uint64_t base;
      } u_kp;
      u_kp.base = 0;
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_kp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->kp = u_kp.real;
      offset += sizeof(this->kp);
      union {
        double real;
        uint64_t base;
      } u_ki;
      u_ki.base = 0;
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ki = u_ki.real;
      offset += sizeof(this->ki);
      union {
        double real;
        uint64_t base;
      } u_kd;
      u_kd.base = 0;
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->kd = u_kd.real;
      offset += sizeof(this->kd);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt1"; };
    const char * getMD5(){ return "249e50a60130616c86a15f47dc12d9b9"; };

  };

}
#endif