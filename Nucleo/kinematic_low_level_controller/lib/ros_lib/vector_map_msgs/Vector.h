#ifndef _ROS_vector_map_msgs_Vector_h
#define _ROS_vector_map_msgs_Vector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Vector : public ros::Msg
  {
    public:
      typedef int32_t _vid_type;
      _vid_type vid;
      typedef int32_t _pid_type;
      _pid_type pid;
      typedef double _hang_type;
      _hang_type hang;
      typedef double _vang_type;
      _vang_type vang;

    Vector():
      vid(0),
      pid(0),
      hang(0),
      vang(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_vid;
      u_vid.real = this->vid;
      *(outbuffer + offset + 0) = (u_vid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vid);
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.real = this->pid;
      *(outbuffer + offset + 0) = (u_pid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid);
      union {
        double real;
        uint64_t base;
      } u_hang;
      u_hang.real = this->hang;
      *(outbuffer + offset + 0) = (u_hang.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hang.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hang.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hang.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hang.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hang.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hang.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hang.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hang);
      union {
        double real;
        uint64_t base;
      } u_vang;
      u_vang.real = this->vang;
      *(outbuffer + offset + 0) = (u_vang.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vang.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vang.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vang.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vang.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vang.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vang.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vang.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vang);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_vid;
      u_vid.base = 0;
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vid = u_vid.real;
      offset += sizeof(this->vid);
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.base = 0;
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid = u_pid.real;
      offset += sizeof(this->pid);
      union {
        double real;
        uint64_t base;
      } u_hang;
      u_hang.base = 0;
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hang.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hang = u_hang.real;
      offset += sizeof(this->hang);
      union {
        double real;
        uint64_t base;
      } u_vang;
      u_vang.base = 0;
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vang.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vang = u_vang.real;
      offset += sizeof(this->vang);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Vector"; };
    const char * getMD5(){ return "31b12e48aa00ab978560f41960d4e3c5"; };

  };

}
#endif