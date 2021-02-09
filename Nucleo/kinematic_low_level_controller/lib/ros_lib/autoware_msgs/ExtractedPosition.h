#ifndef _ROS_autoware_msgs_ExtractedPosition_h
#define _ROS_autoware_msgs_ExtractedPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class ExtractedPosition : public ros::Msg
  {
    public:
      typedef int32_t _signalId_type;
      _signalId_type signalId;
      typedef int32_t _u_type;
      _u_type u;
      typedef int32_t _v_type;
      _v_type v;
      typedef int32_t _radius_type;
      _radius_type radius;
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _z_type;
      _z_type z;
      typedef double _hang_type;
      _hang_type hang;
      typedef int8_t _type_type;
      _type_type type;
      typedef int32_t _linkId_type;
      _linkId_type linkId;
      typedef int32_t _plId_type;
      _plId_type plId;

    ExtractedPosition():
      signalId(0),
      u(0),
      v(0),
      radius(0),
      x(0),
      y(0),
      z(0),
      hang(0),
      type(0),
      linkId(0),
      plId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_signalId;
      u_signalId.real = this->signalId;
      *(outbuffer + offset + 0) = (u_signalId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signalId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signalId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signalId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signalId);
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
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
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_linkId;
      u_linkId.real = this->linkId;
      *(outbuffer + offset + 0) = (u_linkId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linkId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linkId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linkId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linkId);
      union {
        int32_t real;
        uint32_t base;
      } u_plId;
      u_plId.real = this->plId;
      *(outbuffer + offset + 0) = (u_plId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_signalId;
      u_signalId.base = 0;
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signalId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signalId = u_signalId.real;
      offset += sizeof(this->signalId);
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
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
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_linkId;
      u_linkId.base = 0;
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linkId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linkId = u_linkId.real;
      offset += sizeof(this->linkId);
      union {
        int32_t real;
        uint32_t base;
      } u_plId;
      u_plId.base = 0;
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_plId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->plId = u_plId.real;
      offset += sizeof(this->plId);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ExtractedPosition"; };
    const char * getMD5(){ return "0e48067eb51a80d53e09341230ac756f"; };

  };

}
#endif