#ifndef _ROS_autoware_msgs_ControlCommand_h
#define _ROS_autoware_msgs_ControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_msgs
{

  class ControlCommand : public ros::Msg
  {
    public:
      typedef double _linear_velocity_type;
      _linear_velocity_type linear_velocity;
      typedef double _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      typedef double _steering_angle_type;
      _steering_angle_type steering_angle;

    ControlCommand():
      linear_velocity(0),
      linear_acceleration(0),
      steering_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_linear_velocity;
      u_linear_velocity.real = this->linear_velocity;
      *(outbuffer + offset + 0) = (u_linear_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_linear_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_linear_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_linear_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_linear_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->linear_velocity);
      union {
        double real;
        uint64_t base;
      } u_linear_acceleration;
      u_linear_acceleration.real = this->linear_acceleration;
      *(outbuffer + offset + 0) = (u_linear_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_linear_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_linear_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_linear_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_linear_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->linear_acceleration);
      union {
        double real;
        uint64_t base;
      } u_steering_angle;
      u_steering_angle.real = this->steering_angle;
      *(outbuffer + offset + 0) = (u_steering_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_steering_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_steering_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_steering_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_steering_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->steering_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_linear_velocity;
      u_linear_velocity.base = 0;
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->linear_velocity = u_linear_velocity.real;
      offset += sizeof(this->linear_velocity);
      union {
        double real;
        uint64_t base;
      } u_linear_acceleration;
      u_linear_acceleration.base = 0;
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->linear_acceleration = u_linear_acceleration.real;
      offset += sizeof(this->linear_acceleration);
      union {
        double real;
        uint64_t base;
      } u_steering_angle;
      u_steering_angle.base = 0;
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->steering_angle = u_steering_angle.real;
      offset += sizeof(this->steering_angle);
     return offset;
    }

    const char * getType(){ return "autoware_msgs/ControlCommand"; };
    const char * getMD5(){ return "97bdb8c6dda03d6c6f5a1a98c32d26b8"; };

  };

}
#endif