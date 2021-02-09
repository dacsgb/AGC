#ifndef _ROS_vector_map_msgs_CrossWalk_h
#define _ROS_vector_map_msgs_CrossWalk_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class CrossWalk : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _aid_type;
      _aid_type aid;
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _bdid_type;
      _bdid_type bdid;
      typedef int32_t _linkid_type;
      _linkid_type linkid;
      enum { CLOSURE_LINE = 0 };
      enum { STRIPE_PATTERN = 1 };
      enum { BICYCLE_LANE = 2 };

    CrossWalk():
      id(0),
      aid(0),
      type(0),
      bdid(0),
      linkid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.real = this->aid;
      *(outbuffer + offset + 0) = (u_aid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aid);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_bdid;
      u_bdid.real = this->bdid;
      *(outbuffer + offset + 0) = (u_bdid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bdid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bdid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bdid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bdid);
      union {
        int32_t real;
        uint32_t base;
      } u_linkid;
      u_linkid.real = this->linkid;
      *(outbuffer + offset + 0) = (u_linkid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linkid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linkid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linkid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linkid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_aid;
      u_aid.base = 0;
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aid = u_aid.real;
      offset += sizeof(this->aid);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_bdid;
      u_bdid.base = 0;
      u_bdid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bdid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bdid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bdid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bdid = u_bdid.real;
      offset += sizeof(this->bdid);
      union {
        int32_t real;
        uint32_t base;
      } u_linkid;
      u_linkid.base = 0;
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linkid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linkid = u_linkid.real;
      offset += sizeof(this->linkid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/CrossWalk"; };
    const char * getMD5(){ return "626e8d6afb39af06dfd0654aa131f1cb"; };

  };

}
#endif