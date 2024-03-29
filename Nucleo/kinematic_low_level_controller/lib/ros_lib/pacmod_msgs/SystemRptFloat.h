#ifndef _ROS_pacmod_msgs_SystemRptFloat_h
#define _ROS_pacmod_msgs_SystemRptFloat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SystemRptFloat : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enabled_type;
      _enabled_type enabled;
      typedef bool _override_active_type;
      _override_active_type override_active;
      typedef bool _command_output_fault_type;
      _command_output_fault_type command_output_fault;
      typedef bool _input_output_fault_type;
      _input_output_fault_type input_output_fault;
      typedef bool _output_reported_fault_type;
      _output_reported_fault_type output_reported_fault;
      typedef bool _pacmod_fault_type;
      _pacmod_fault_type pacmod_fault;
      typedef bool _vehicle_fault_type;
      _vehicle_fault_type vehicle_fault;
      typedef double _manual_input_type;
      _manual_input_type manual_input;
      typedef double _command_type;
      _command_type command;
      typedef double _output_type;
      _output_type output;

    SystemRptFloat():
      header(),
      enabled(0),
      override_active(0),
      command_output_fault(0),
      input_output_fault(0),
      output_reported_fault(0),
      pacmod_fault(0),
      vehicle_fault(0),
      manual_input(0),
      command(0),
      output(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      union {
        bool real;
        uint8_t base;
      } u_override_active;
      u_override_active.real = this->override_active;
      *(outbuffer + offset + 0) = (u_override_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_active);
      union {
        bool real;
        uint8_t base;
      } u_command_output_fault;
      u_command_output_fault.real = this->command_output_fault;
      *(outbuffer + offset + 0) = (u_command_output_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_input_output_fault;
      u_input_output_fault.real = this->input_output_fault;
      *(outbuffer + offset + 0) = (u_input_output_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->input_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_output_reported_fault;
      u_output_reported_fault.real = this->output_reported_fault;
      *(outbuffer + offset + 0) = (u_output_reported_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->output_reported_fault);
      union {
        bool real;
        uint8_t base;
      } u_pacmod_fault;
      u_pacmod_fault.real = this->pacmod_fault;
      *(outbuffer + offset + 0) = (u_pacmod_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pacmod_fault);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_fault;
      u_vehicle_fault.real = this->vehicle_fault;
      *(outbuffer + offset + 0) = (u_vehicle_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_fault);
      union {
        double real;
        uint64_t base;
      } u_manual_input;
      u_manual_input.real = this->manual_input;
      *(outbuffer + offset + 0) = (u_manual_input.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_manual_input.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_manual_input.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_manual_input.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_manual_input.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_manual_input.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_manual_input.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_manual_input.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->manual_input);
      union {
        double real;
        uint64_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_command.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_command.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_command.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_command.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->command);
      union {
        double real;
        uint64_t base;
      } u_output;
      u_output.real = this->output;
      *(outbuffer + offset + 0) = (u_output.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_output.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_output.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_output.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_output.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_output.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_output.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_output.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->output);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
      union {
        bool real;
        uint8_t base;
      } u_override_active;
      u_override_active.base = 0;
      u_override_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_active = u_override_active.real;
      offset += sizeof(this->override_active);
      union {
        bool real;
        uint8_t base;
      } u_command_output_fault;
      u_command_output_fault.base = 0;
      u_command_output_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command_output_fault = u_command_output_fault.real;
      offset += sizeof(this->command_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_input_output_fault;
      u_input_output_fault.base = 0;
      u_input_output_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->input_output_fault = u_input_output_fault.real;
      offset += sizeof(this->input_output_fault);
      union {
        bool real;
        uint8_t base;
      } u_output_reported_fault;
      u_output_reported_fault.base = 0;
      u_output_reported_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->output_reported_fault = u_output_reported_fault.real;
      offset += sizeof(this->output_reported_fault);
      union {
        bool real;
        uint8_t base;
      } u_pacmod_fault;
      u_pacmod_fault.base = 0;
      u_pacmod_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pacmod_fault = u_pacmod_fault.real;
      offset += sizeof(this->pacmod_fault);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_fault;
      u_vehicle_fault.base = 0;
      u_vehicle_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle_fault = u_vehicle_fault.real;
      offset += sizeof(this->vehicle_fault);
      union {
        double real;
        uint64_t base;
      } u_manual_input;
      u_manual_input.base = 0;
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_manual_input.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->manual_input = u_manual_input.real;
      offset += sizeof(this->manual_input);
      union {
        double real;
        uint64_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_command.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->command = u_command.real;
      offset += sizeof(this->command);
      union {
        double real;
        uint64_t base;
      } u_output;
      u_output.base = 0;
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_output.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->output = u_output.real;
      offset += sizeof(this->output);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SystemRptFloat"; };
    const char * getMD5(){ return "e3af53d7d085bbad777634bcc2681141"; };

  };

}
#endif