#ifndef _ROS_vector_map_msgs_Pole_h
#define _ROS_vector_map_msgs_Pole_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Pole : public ros::Msg
  {
    public:
      typedef int32_t _plid_type;
      _plid_type plid;
      typedef int32_t _vid_type;
      _vid_type vid;
      typedef double _length_type;
      _length_type length;
      typedef double _dim_type;
      _dim_type dim;

    Pole():
      plid(0),
      vid(0),
      length(0),
      dim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_plid;
      u_plid.real = this->plid;
      *(outbuffer + offset + 0) = (u_plid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plid);
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
        double real;
        uint64_t base;
      } u_length;
      u_length.real = this->length;
      *(outbuffer + offset + 0) = (u_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_length.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_length.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_length.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_length.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->length);
      union {
        double real;
        uint64_t base;
      } u_dim;
      u_dim.real = this->dim;
      *(outbuffer + offset + 0) = (u_dim.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dim.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dim.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dim.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dim.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dim.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dim.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dim.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_plid;
      u_plid.base = 0;
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_plid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->plid = u_plid.real;
      offset += sizeof(this->plid);
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
        double real;
        uint64_t base;
      } u_length;
      u_length.base = 0;
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_length.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->length = u_length.real;
      offset += sizeof(this->length);
      union {
        double real;
        uint64_t base;
      } u_dim;
      u_dim.base = 0;
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dim.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dim = u_dim.real;
      offset += sizeof(this->dim);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Pole"; };
    const char * getMD5(){ return "d9d65404b5e1f838856c9aeaa9d94be8"; };

  };

}
#endif