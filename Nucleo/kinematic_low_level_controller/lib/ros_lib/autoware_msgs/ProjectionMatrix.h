#ifndef _ROS_autoware_msgs_ProjectionMatrix_h
#define _ROS_autoware_msgs_ProjectionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class ProjectionMatrix : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      double projection_matrix[16];

    ProjectionMatrix():
      header(),
      projection_matrix()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      union {
        double real;
        uint64_t base;
      } u_projection_matrixi;
      u_projection_matrixi.real = this->projection_matrix[i];
      *(outbuffer + offset + 0) = (u_projection_matrixi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_projection_matrixi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_projection_matrixi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_projection_matrixi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_projection_matrixi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_projection_matrixi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_projection_matrixi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_projection_matrixi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->projection_matrix[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      union {
        double real;
        uint64_t base;
      } u_projection_matrixi;
      u_projection_matrixi.base = 0;
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_projection_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->projection_matrix[i] = u_projection_matrixi.real;
      offset += sizeof(this->projection_matrix[i]);
      }
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ProjectionMatrix"; };
    const char * getMD5(){ return "383fdce8566145c0d8ee5731cf4d6531"; };

  };

}
#endif