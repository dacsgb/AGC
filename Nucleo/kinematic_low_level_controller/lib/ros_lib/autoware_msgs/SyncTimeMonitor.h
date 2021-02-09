#ifndef _ROS_autoware_msgs_SyncTimeMonitor_h
#define _ROS_autoware_msgs_SyncTimeMonitor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_msgs
{

  class SyncTimeMonitor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _image_raw_type;
      _image_raw_type image_raw;
      typedef double _points_raw_type;
      _points_raw_type points_raw;
      typedef double _points_image_type;
      _points_image_type points_image;
      typedef double _vscan_points_type;
      _vscan_points_type vscan_points;
      typedef double _vscan_image_type;
      _vscan_image_type vscan_image;
      typedef double _image_obj_type;
      _image_obj_type image_obj;
      typedef double _image_obj_ranged_type;
      _image_obj_ranged_type image_obj_ranged;
      typedef double _image_obj_tracked_type;
      _image_obj_tracked_type image_obj_tracked;
      typedef double _current_pose_type;
      _current_pose_type current_pose;
      typedef double _obj_label_type;
      _obj_label_type obj_label;
      typedef double _cluster_centroids_type;
      _cluster_centroids_type cluster_centroids;
      typedef double _obj_pose_type;
      _obj_pose_type obj_pose;
      typedef double _execution_time_type;
      _execution_time_type execution_time;
      typedef double _cycle_time_type;
      _cycle_time_type cycle_time;
      typedef double _time_diff_type;
      _time_diff_type time_diff;

    SyncTimeMonitor():
      header(),
      image_raw(0),
      points_raw(0),
      points_image(0),
      vscan_points(0),
      vscan_image(0),
      image_obj(0),
      image_obj_ranged(0),
      image_obj_tracked(0),
      current_pose(0),
      obj_label(0),
      cluster_centroids(0),
      obj_pose(0),
      execution_time(0),
      cycle_time(0),
      time_diff(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_image_raw;
      u_image_raw.real = this->image_raw;
      *(outbuffer + offset + 0) = (u_image_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_raw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_raw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_raw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_raw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_raw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_raw);
      union {
        double real;
        uint64_t base;
      } u_points_raw;
      u_points_raw.real = this->points_raw;
      *(outbuffer + offset + 0) = (u_points_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_points_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_points_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_points_raw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_points_raw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_points_raw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_points_raw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_points_raw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->points_raw);
      union {
        double real;
        uint64_t base;
      } u_points_image;
      u_points_image.real = this->points_image;
      *(outbuffer + offset + 0) = (u_points_image.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_points_image.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_points_image.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_points_image.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_points_image.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_points_image.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_points_image.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_points_image.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->points_image);
      union {
        double real;
        uint64_t base;
      } u_vscan_points;
      u_vscan_points.real = this->vscan_points;
      *(outbuffer + offset + 0) = (u_vscan_points.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vscan_points.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vscan_points.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vscan_points.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vscan_points.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vscan_points.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vscan_points.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vscan_points.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vscan_points);
      union {
        double real;
        uint64_t base;
      } u_vscan_image;
      u_vscan_image.real = this->vscan_image;
      *(outbuffer + offset + 0) = (u_vscan_image.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vscan_image.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vscan_image.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vscan_image.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vscan_image.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vscan_image.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vscan_image.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vscan_image.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vscan_image);
      union {
        double real;
        uint64_t base;
      } u_image_obj;
      u_image_obj.real = this->image_obj;
      *(outbuffer + offset + 0) = (u_image_obj.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_obj.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_obj.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_obj.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_obj.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_obj.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_obj.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_obj.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_obj);
      union {
        double real;
        uint64_t base;
      } u_image_obj_ranged;
      u_image_obj_ranged.real = this->image_obj_ranged;
      *(outbuffer + offset + 0) = (u_image_obj_ranged.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_obj_ranged.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_obj_ranged.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_obj_ranged.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_obj_ranged.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_obj_ranged.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_obj_ranged.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_obj_ranged.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_obj_ranged);
      union {
        double real;
        uint64_t base;
      } u_image_obj_tracked;
      u_image_obj_tracked.real = this->image_obj_tracked;
      *(outbuffer + offset + 0) = (u_image_obj_tracked.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_obj_tracked.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_obj_tracked.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_obj_tracked.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_obj_tracked.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_obj_tracked.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_obj_tracked.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_obj_tracked.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_obj_tracked);
      union {
        double real;
        uint64_t base;
      } u_current_pose;
      u_current_pose.real = this->current_pose;
      *(outbuffer + offset + 0) = (u_current_pose.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_pose.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_pose.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_pose.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current_pose.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current_pose.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current_pose.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current_pose.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current_pose);
      union {
        double real;
        uint64_t base;
      } u_obj_label;
      u_obj_label.real = this->obj_label;
      *(outbuffer + offset + 0) = (u_obj_label.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_label.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_label.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_label.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_obj_label.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_obj_label.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_obj_label.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_obj_label.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->obj_label);
      union {
        double real;
        uint64_t base;
      } u_cluster_centroids;
      u_cluster_centroids.real = this->cluster_centroids;
      *(outbuffer + offset + 0) = (u_cluster_centroids.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cluster_centroids.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cluster_centroids.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cluster_centroids.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cluster_centroids.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cluster_centroids.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cluster_centroids.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cluster_centroids.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cluster_centroids);
      union {
        double real;
        uint64_t base;
      } u_obj_pose;
      u_obj_pose.real = this->obj_pose;
      *(outbuffer + offset + 0) = (u_obj_pose.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_pose.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_pose.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_pose.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_obj_pose.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_obj_pose.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_obj_pose.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_obj_pose.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->obj_pose);
      union {
        double real;
        uint64_t base;
      } u_execution_time;
      u_execution_time.real = this->execution_time;
      *(outbuffer + offset + 0) = (u_execution_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_execution_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_execution_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_execution_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_execution_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_execution_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_execution_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_execution_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->execution_time);
      union {
        double real;
        uint64_t base;
      } u_cycle_time;
      u_cycle_time.real = this->cycle_time;
      *(outbuffer + offset + 0) = (u_cycle_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cycle_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cycle_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cycle_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cycle_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cycle_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cycle_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cycle_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cycle_time);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_image_raw;
      u_image_raw.base = 0;
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_raw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_raw = u_image_raw.real;
      offset += sizeof(this->image_raw);
      union {
        double real;
        uint64_t base;
      } u_points_raw;
      u_points_raw.base = 0;
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_points_raw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->points_raw = u_points_raw.real;
      offset += sizeof(this->points_raw);
      union {
        double real;
        uint64_t base;
      } u_points_image;
      u_points_image.base = 0;
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_points_image.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->points_image = u_points_image.real;
      offset += sizeof(this->points_image);
      union {
        double real;
        uint64_t base;
      } u_vscan_points;
      u_vscan_points.base = 0;
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vscan_points.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vscan_points = u_vscan_points.real;
      offset += sizeof(this->vscan_points);
      union {
        double real;
        uint64_t base;
      } u_vscan_image;
      u_vscan_image.base = 0;
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vscan_image.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vscan_image = u_vscan_image.real;
      offset += sizeof(this->vscan_image);
      union {
        double real;
        uint64_t base;
      } u_image_obj;
      u_image_obj.base = 0;
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_obj.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_obj = u_image_obj.real;
      offset += sizeof(this->image_obj);
      union {
        double real;
        uint64_t base;
      } u_image_obj_ranged;
      u_image_obj_ranged.base = 0;
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_obj_ranged.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_obj_ranged = u_image_obj_ranged.real;
      offset += sizeof(this->image_obj_ranged);
      union {
        double real;
        uint64_t base;
      } u_image_obj_tracked;
      u_image_obj_tracked.base = 0;
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_obj_tracked.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_obj_tracked = u_image_obj_tracked.real;
      offset += sizeof(this->image_obj_tracked);
      union {
        double real;
        uint64_t base;
      } u_current_pose;
      u_current_pose.base = 0;
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current_pose.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current_pose = u_current_pose.real;
      offset += sizeof(this->current_pose);
      union {
        double real;
        uint64_t base;
      } u_obj_label;
      u_obj_label.base = 0;
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_obj_label.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->obj_label = u_obj_label.real;
      offset += sizeof(this->obj_label);
      union {
        double real;
        uint64_t base;
      } u_cluster_centroids;
      u_cluster_centroids.base = 0;
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cluster_centroids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cluster_centroids = u_cluster_centroids.real;
      offset += sizeof(this->cluster_centroids);
      union {
        double real;
        uint64_t base;
      } u_obj_pose;
      u_obj_pose.base = 0;
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_obj_pose.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->obj_pose = u_obj_pose.real;
      offset += sizeof(this->obj_pose);
      union {
        double real;
        uint64_t base;
      } u_execution_time;
      u_execution_time.base = 0;
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_execution_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->execution_time = u_execution_time.real;
      offset += sizeof(this->execution_time);
      union {
        double real;
        uint64_t base;
      } u_cycle_time;
      u_cycle_time.base = 0;
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cycle_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cycle_time = u_cycle_time.real;
      offset += sizeof(this->cycle_time);
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
     return offset;
    }

    const char * getType(){ return "autoware_msgs/SyncTimeMonitor"; };
    const char * getMD5(){ return "8c6a4dd195d4ccc31d38fad617327689"; };

  };

}
#endif