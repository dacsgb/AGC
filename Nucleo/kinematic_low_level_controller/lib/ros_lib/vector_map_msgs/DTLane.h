#ifndef _ROS_vector_map_msgs_DTLane_h
#define _ROS_vector_map_msgs_DTLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class DTLane : public ros::Msg
  {
    public:
      typedef int32_t _did_type;
      _did_type did;
      typedef double _dist_type;
      _dist_type dist;
      typedef int32_t _pid_type;
      _pid_type pid;
      typedef double _dir_type;
      _dir_type dir;
      typedef double _apara_type;
      _apara_type apara;
      typedef double _r_type;
      _r_type r;
      typedef double _slope_type;
      _slope_type slope;
      typedef double _cant_type;
      _cant_type cant;
      typedef double _lw_type;
      _lw_type lw;
      typedef double _rw_type;
      _rw_type rw;

    DTLane():
      did(0),
      dist(0),
      pid(0),
      dir(0),
      apara(0),
      r(0),
      slope(0),
      cant(0),
      lw(0),
      rw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.real = this->did;
      *(outbuffer + offset + 0) = (u_did.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_did.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_did.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_did.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->did);
      union {
        double real;
        uint64_t base;
      } u_dist;
      u_dist.real = this->dist;
      *(outbuffer + offset + 0) = (u_dist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dist.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dist.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dist.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dist.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dist.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dist.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dist.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dist);
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
      } u_dir;
      u_dir.real = this->dir;
      *(outbuffer + offset + 0) = (u_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dir.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dir.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dir.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dir.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dir.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dir.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dir.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dir);
      union {
        double real;
        uint64_t base;
      } u_apara;
      u_apara.real = this->apara;
      *(outbuffer + offset + 0) = (u_apara.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_apara.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_apara.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_apara.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_apara.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_apara.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_apara.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_apara.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->apara);
      union {
        double real;
        uint64_t base;
      } u_r;
      u_r.real = this->r;
      *(outbuffer + offset + 0) = (u_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r);
      union {
        double real;
        uint64_t base;
      } u_slope;
      u_slope.real = this->slope;
      *(outbuffer + offset + 0) = (u_slope.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_slope.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_slope.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_slope.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_slope.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_slope.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_slope.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_slope.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->slope);
      union {
        double real;
        uint64_t base;
      } u_cant;
      u_cant.real = this->cant;
      *(outbuffer + offset + 0) = (u_cant.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cant.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cant.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cant.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cant.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cant.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cant.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cant.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cant);
      union {
        double real;
        uint64_t base;
      } u_lw;
      u_lw.real = this->lw;
      *(outbuffer + offset + 0) = (u_lw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lw);
      union {
        double real;
        uint64_t base;
      } u_rw;
      u_rw.real = this->rw;
      *(outbuffer + offset + 0) = (u_rw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.base = 0;
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->did = u_did.real;
      offset += sizeof(this->did);
      union {
        double real;
        uint64_t base;
      } u_dist;
      u_dist.base = 0;
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dist.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dist = u_dist.real;
      offset += sizeof(this->dist);
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
      } u_dir;
      u_dir.base = 0;
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dir.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dir = u_dir.real;
      offset += sizeof(this->dir);
      union {
        double real;
        uint64_t base;
      } u_apara;
      u_apara.base = 0;
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_apara.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->apara = u_apara.real;
      offset += sizeof(this->apara);
      union {
        double real;
        uint64_t base;
      } u_r;
      u_r.base = 0;
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r = u_r.real;
      offset += sizeof(this->r);
      union {
        double real;
        uint64_t base;
      } u_slope;
      u_slope.base = 0;
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_slope.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->slope = u_slope.real;
      offset += sizeof(this->slope);
      union {
        double real;
        uint64_t base;
      } u_cant;
      u_cant.base = 0;
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cant.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cant = u_cant.real;
      offset += sizeof(this->cant);
      union {
        double real;
        uint64_t base;
      } u_lw;
      u_lw.base = 0;
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lw = u_lw.real;
      offset += sizeof(this->lw);
      union {
        double real;
        uint64_t base;
      } u_rw;
      u_rw.base = 0;
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rw = u_rw.real;
      offset += sizeof(this->rw);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/DTLane"; };
    const char * getMD5(){ return "50d83078491bca58f98774489d1f1ac9"; };

  };

}
#endif