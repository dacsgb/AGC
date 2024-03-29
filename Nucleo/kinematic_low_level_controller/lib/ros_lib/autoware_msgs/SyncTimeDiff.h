#ifndef _ROS_autoware_msgs_SyncTimeDiff_h
#define _ROS_autoware_msgs_SyncTimeDiff_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"

namespace autoware_msgs
{

  class SyncTimeDiff : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _time_diff_type;
      _time_diff_type time_diff;
      typedef ros::Time _camera_type;
      _camera_type camera;
      typedef ros::Time _lidar_type;
      _lidar_type lidar;

    SyncTimeDiff():
      header(),
      time_diff(0),
      camera(),
      lidar()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_time_diff;
      u_time_diff.real = this->time_diff;
      *(outbuffer + offset + 0) = (u_time_diff.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_diff.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_diff.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_diff.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_diff.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_diff.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_diff.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_diff.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_diff);
      *(outbuffer + offset + 0) = (this->camera.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera.sec);
      *(outbuffer + offset + 0) = (this->camera.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera.nsec);
      *(outbuffer + offset + 0) = (this->lidar.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lidar.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lidar.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lidar.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lidar.sec);
      *(outbuffer + offset + 0) = (this->lidar.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lidar.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lidar.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lidar.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lidar.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_time_diff;
      u_time_diff.base = 0;
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_diff.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_diff = u_time_diff.real;
      offset += sizeof(this->time_diff);
      this->camera.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->camera.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->camera.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->camera.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->camera.sec);
      this->camera.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->camera.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->camera.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->camera.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->camera.nsec);
      this->lidar.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->lidar.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lidar.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lidar.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lidar.sec);
      this->lidar.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->lidar.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lidar.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lidar.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lidar.nsec);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/SyncTimeDiff"; };
    const char * getMD5(){ return "c640f7073f6004ba0221e76e2c83ffa1"; };

  };

}
#endif