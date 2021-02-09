#ifndef _ROS_tablet_socket_msgs_Waypoint_h
#define _ROS_tablet_socket_msgs_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tablet_socket_msgs
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef double _lat_type;
      _lat_type lat;
      typedef double _lon_type;
      _lon_type lon;

    Waypoint():
      lat(0),
      lon(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.real = this->lat;
      *(outbuffer + offset + 0) = (u_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.real = this->lon;
      *(outbuffer + offset + 0) = (u_lon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lon);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.base = 0;
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lat = u_lat.real;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.base = 0;
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lon = u_lon.real;
      offset += sizeof(this->lon);
     return offset;
    }

    const char * getType(){ return "tablet_socket_msgs/Waypoint"; };
    const char * getMD5(){ return "deb12644498d4b5511a84dbd9af1e283"; };

  };

}
#endif