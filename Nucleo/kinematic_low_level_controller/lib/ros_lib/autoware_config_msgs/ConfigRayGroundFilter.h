#ifndef _ROS_autoware_config_msgs_ConfigRayGroundFilter_h
#define _ROS_autoware_config_msgs_ConfigRayGroundFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_config_msgs
{

  class ConfigRayGroundFilter : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _sensor_height_type;
      _sensor_height_type sensor_height;
      typedef double _clipping_height_type;
      _clipping_height_type clipping_height;
      typedef double _min_point_distance_type;
      _min_point_distance_type min_point_distance;
      typedef double _radial_divider_angle_type;
      _radial_divider_angle_type radial_divider_angle;
      typedef double _concentric_divider_distance_type;
      _concentric_divider_distance_type concentric_divider_distance;
      typedef double _local_max_slope_type;
      _local_max_slope_type local_max_slope;
      typedef double _general_max_slope_type;
      _general_max_slope_type general_max_slope;
      typedef double _min_height_threshold_type;
      _min_height_threshold_type min_height_threshold;
      typedef double _reclass_distance_threshold_type;
      _reclass_distance_threshold_type reclass_distance_threshold;

    ConfigRayGroundFilter():
      header(),
      sensor_height(0),
      clipping_height(0),
      min_point_distance(0),
      radial_divider_angle(0),
      concentric_divider_distance(0),
      local_max_slope(0),
      general_max_slope(0),
      min_height_threshold(0),
      reclass_distance_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_sensor_height;
      u_sensor_height.real = this->sensor_height;
      *(outbuffer + offset + 0) = (u_sensor_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sensor_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sensor_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sensor_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sensor_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sensor_height);
      union {
        double real;
        uint64_t base;
      } u_clipping_height;
      u_clipping_height.real = this->clipping_height;
      *(outbuffer + offset + 0) = (u_clipping_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_clipping_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_clipping_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_clipping_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_clipping_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_clipping_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_clipping_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_clipping_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->clipping_height);
      union {
        double real;
        uint64_t base;
      } u_min_point_distance;
      u_min_point_distance.real = this->min_point_distance;
      *(outbuffer + offset + 0) = (u_min_point_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_point_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_point_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_point_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_point_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_point_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_point_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_point_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_point_distance);
      union {
        double real;
        uint64_t base;
      } u_radial_divider_angle;
      u_radial_divider_angle.real = this->radial_divider_angle;
      *(outbuffer + offset + 0) = (u_radial_divider_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radial_divider_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radial_divider_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radial_divider_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_radial_divider_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_radial_divider_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_radial_divider_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_radial_divider_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->radial_divider_angle);
      union {
        double real;
        uint64_t base;
      } u_concentric_divider_distance;
      u_concentric_divider_distance.real = this->concentric_divider_distance;
      *(outbuffer + offset + 0) = (u_concentric_divider_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_concentric_divider_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_concentric_divider_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_concentric_divider_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_concentric_divider_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_concentric_divider_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_concentric_divider_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_concentric_divider_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->concentric_divider_distance);
      union {
        double real;
        uint64_t base;
      } u_local_max_slope;
      u_local_max_slope.real = this->local_max_slope;
      *(outbuffer + offset + 0) = (u_local_max_slope.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_local_max_slope.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_local_max_slope.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_local_max_slope.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_local_max_slope.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_local_max_slope.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_local_max_slope.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_local_max_slope.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->local_max_slope);
      union {
        double real;
        uint64_t base;
      } u_general_max_slope;
      u_general_max_slope.real = this->general_max_slope;
      *(outbuffer + offset + 0) = (u_general_max_slope.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_general_max_slope.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_general_max_slope.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_general_max_slope.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_general_max_slope.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_general_max_slope.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_general_max_slope.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_general_max_slope.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->general_max_slope);
      union {
        double real;
        uint64_t base;
      } u_min_height_threshold;
      u_min_height_threshold.real = this->min_height_threshold;
      *(outbuffer + offset + 0) = (u_min_height_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_height_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_height_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_height_threshold.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_height_threshold.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_height_threshold.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_height_threshold.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_height_threshold.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_height_threshold);
      union {
        double real;
        uint64_t base;
      } u_reclass_distance_threshold;
      u_reclass_distance_threshold.real = this->reclass_distance_threshold;
      *(outbuffer + offset + 0) = (u_reclass_distance_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reclass_distance_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reclass_distance_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reclass_distance_threshold.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_reclass_distance_threshold.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_reclass_distance_threshold.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_reclass_distance_threshold.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_reclass_distance_threshold.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->reclass_distance_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_sensor_height;
      u_sensor_height.base = 0;
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sensor_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sensor_height = u_sensor_height.real;
      offset += sizeof(this->sensor_height);
      union {
        double real;
        uint64_t base;
      } u_clipping_height;
      u_clipping_height.base = 0;
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_clipping_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->clipping_height = u_clipping_height.real;
      offset += sizeof(this->clipping_height);
      union {
        double real;
        uint64_t base;
      } u_min_point_distance;
      u_min_point_distance.base = 0;
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_point_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_point_distance = u_min_point_distance.real;
      offset += sizeof(this->min_point_distance);
      union {
        double real;
        uint64_t base;
      } u_radial_divider_angle;
      u_radial_divider_angle.base = 0;
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_radial_divider_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->radial_divider_angle = u_radial_divider_angle.real;
      offset += sizeof(this->radial_divider_angle);
      union {
        double real;
        uint64_t base;
      } u_concentric_divider_distance;
      u_concentric_divider_distance.base = 0;
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_concentric_divider_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->concentric_divider_distance = u_concentric_divider_distance.real;
      offset += sizeof(this->concentric_divider_distance);
      union {
        double real;
        uint64_t base;
      } u_local_max_slope;
      u_local_max_slope.base = 0;
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_local_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->local_max_slope = u_local_max_slope.real;
      offset += sizeof(this->local_max_slope);
      union {
        double real;
        uint64_t base;
      } u_general_max_slope;
      u_general_max_slope.base = 0;
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_general_max_slope.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->general_max_slope = u_general_max_slope.real;
      offset += sizeof(this->general_max_slope);
      union {
        double real;
        uint64_t base;
      } u_min_height_threshold;
      u_min_height_threshold.base = 0;
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_height_threshold.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_height_threshold = u_min_height_threshold.real;
      offset += sizeof(this->min_height_threshold);
      union {
        double real;
        uint64_t base;
      } u_reclass_distance_threshold;
      u_reclass_distance_threshold.base = 0;
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_reclass_distance_threshold.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->reclass_distance_threshold = u_reclass_distance_threshold.real;
      offset += sizeof(this->reclass_distance_threshold);
     return offset;
    }

    const char * getType(){ return "autoware_config_msgs/ConfigRayGroundFilter"; };
    const char * getMD5(){ return "1b9a20593709b07932fff996671d4ed6"; };

  };

}
#endif