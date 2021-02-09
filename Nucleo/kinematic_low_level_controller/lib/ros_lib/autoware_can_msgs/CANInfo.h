#ifndef _ROS_autoware_can_msgs_CANInfo_h
#define _ROS_autoware_can_msgs_CANInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_can_msgs
{

  class CANInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _tm_type;
      _tm_type tm;
      typedef int32_t _devmode_type;
      _devmode_type devmode;
      typedef int32_t _drvcontmode_type;
      _drvcontmode_type drvcontmode;
      typedef int32_t _drvoverridemode_type;
      _drvoverridemode_type drvoverridemode;
      typedef int32_t _drvservo_type;
      _drvservo_type drvservo;
      typedef int32_t _drivepedal_type;
      _drivepedal_type drivepedal;
      typedef int32_t _targetpedalstr_type;
      _targetpedalstr_type targetpedalstr;
      typedef int32_t _inputpedalstr_type;
      _inputpedalstr_type inputpedalstr;
      typedef double _targetveloc_type;
      _targetveloc_type targetveloc;
      typedef double _speed_type;
      _speed_type speed;
      typedef int32_t _driveshift_type;
      _driveshift_type driveshift;
      typedef int32_t _targetshift_type;
      _targetshift_type targetshift;
      typedef int32_t _inputshift_type;
      _inputshift_type inputshift;
      typedef int32_t _strmode_type;
      _strmode_type strmode;
      typedef int32_t _strcontmode_type;
      _strcontmode_type strcontmode;
      typedef int32_t _stroverridemode_type;
      _stroverridemode_type stroverridemode;
      typedef int32_t _strservo_type;
      _strservo_type strservo;
      typedef int32_t _targettorque_type;
      _targettorque_type targettorque;
      typedef int32_t _torque_type;
      _torque_type torque;
      typedef double _angle_type;
      _angle_type angle;
      typedef double _targetangle_type;
      _targetangle_type targetangle;
      typedef int32_t _bbrakepress_type;
      _bbrakepress_type bbrakepress;
      typedef int32_t _brakepedal_type;
      _brakepedal_type brakepedal;
      typedef int32_t _brtargetpedalstr_type;
      _brtargetpedalstr_type brtargetpedalstr;
      typedef int32_t _brinputpedalstr_type;
      _brinputpedalstr_type brinputpedalstr;
      typedef double _battery_type;
      _battery_type battery;
      typedef int32_t _voltage_type;
      _voltage_type voltage;
      typedef double _anp_type;
      _anp_type anp;
      typedef int32_t _battmaxtemparature_type;
      _battmaxtemparature_type battmaxtemparature;
      typedef int32_t _battmintemparature_type;
      _battmintemparature_type battmintemparature;
      typedef double _maxchgcurrent_type;
      _maxchgcurrent_type maxchgcurrent;
      typedef double _maxdischgcurrent_type;
      _maxdischgcurrent_type maxdischgcurrent;
      typedef double _sideacc_type;
      _sideacc_type sideacc;
      typedef double _accellfromp_type;
      _accellfromp_type accellfromp;
      typedef double _anglefromp_type;
      _anglefromp_type anglefromp;
      typedef double _brakepedalfromp_type;
      _brakepedalfromp_type brakepedalfromp;
      typedef double _speedfr_type;
      _speedfr_type speedfr;
      typedef double _speedfl_type;
      _speedfl_type speedfl;
      typedef double _speedrr_type;
      _speedrr_type speedrr;
      typedef double _speedrl_type;
      _speedrl_type speedrl;
      typedef double _velocfromp2_type;
      _velocfromp2_type velocfromp2;
      typedef int32_t _drvmode_type;
      _drvmode_type drvmode;
      typedef int32_t _devpedalstrfromp_type;
      _devpedalstrfromp_type devpedalstrfromp;
      typedef int32_t _rpm_type;
      _rpm_type rpm;
      typedef double _velocflfromp_type;
      _velocflfromp_type velocflfromp;
      typedef int32_t _ev_mode_type;
      _ev_mode_type ev_mode;
      typedef int32_t _temp_type;
      _temp_type temp;
      typedef int32_t _shiftfrmprius_type;
      _shiftfrmprius_type shiftfrmprius;
      typedef int32_t _light_type;
      _light_type light;
      typedef int32_t _gaslevel_type;
      _gaslevel_type gaslevel;
      typedef int32_t _door_type;
      _door_type door;
      typedef int32_t _cluise_type;
      _cluise_type cluise;

    CANInfo():
      header(),
      tm(""),
      devmode(0),
      drvcontmode(0),
      drvoverridemode(0),
      drvservo(0),
      drivepedal(0),
      targetpedalstr(0),
      inputpedalstr(0),
      targetveloc(0),
      speed(0),
      driveshift(0),
      targetshift(0),
      inputshift(0),
      strmode(0),
      strcontmode(0),
      stroverridemode(0),
      strservo(0),
      targettorque(0),
      torque(0),
      angle(0),
      targetangle(0),
      bbrakepress(0),
      brakepedal(0),
      brtargetpedalstr(0),
      brinputpedalstr(0),
      battery(0),
      voltage(0),
      anp(0),
      battmaxtemparature(0),
      battmintemparature(0),
      maxchgcurrent(0),
      maxdischgcurrent(0),
      sideacc(0),
      accellfromp(0),
      anglefromp(0),
      brakepedalfromp(0),
      speedfr(0),
      speedfl(0),
      speedrr(0),
      speedrl(0),
      velocfromp2(0),
      drvmode(0),
      devpedalstrfromp(0),
      rpm(0),
      velocflfromp(0),
      ev_mode(0),
      temp(0),
      shiftfrmprius(0),
      light(0),
      gaslevel(0),
      door(0),
      cluise(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_tm = strlen(this->tm);
      varToArr(outbuffer + offset, length_tm);
      offset += 4;
      memcpy(outbuffer + offset, this->tm, length_tm);
      offset += length_tm;
      union {
        int32_t real;
        uint32_t base;
      } u_devmode;
      u_devmode.real = this->devmode;
      *(outbuffer + offset + 0) = (u_devmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_devmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_devmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_devmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->devmode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvcontmode;
      u_drvcontmode.real = this->drvcontmode;
      *(outbuffer + offset + 0) = (u_drvcontmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drvcontmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drvcontmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drvcontmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drvcontmode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvoverridemode;
      u_drvoverridemode.real = this->drvoverridemode;
      *(outbuffer + offset + 0) = (u_drvoverridemode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drvoverridemode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drvoverridemode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drvoverridemode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drvoverridemode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvservo;
      u_drvservo.real = this->drvservo;
      *(outbuffer + offset + 0) = (u_drvservo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drvservo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drvservo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drvservo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drvservo);
      union {
        int32_t real;
        uint32_t base;
      } u_drivepedal;
      u_drivepedal.real = this->drivepedal;
      *(outbuffer + offset + 0) = (u_drivepedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drivepedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drivepedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drivepedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drivepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_targetpedalstr;
      u_targetpedalstr.real = this->targetpedalstr;
      *(outbuffer + offset + 0) = (u_targetpedalstr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targetpedalstr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targetpedalstr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targetpedalstr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targetpedalstr);
      union {
        int32_t real;
        uint32_t base;
      } u_inputpedalstr;
      u_inputpedalstr.real = this->inputpedalstr;
      *(outbuffer + offset + 0) = (u_inputpedalstr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inputpedalstr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inputpedalstr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inputpedalstr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inputpedalstr);
      union {
        double real;
        uint64_t base;
      } u_targetveloc;
      u_targetveloc.real = this->targetveloc;
      *(outbuffer + offset + 0) = (u_targetveloc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targetveloc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targetveloc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targetveloc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_targetveloc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_targetveloc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_targetveloc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_targetveloc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->targetveloc);
      union {
        double real;
        uint64_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        int32_t real;
        uint32_t base;
      } u_driveshift;
      u_driveshift.real = this->driveshift;
      *(outbuffer + offset + 0) = (u_driveshift.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driveshift.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_driveshift.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_driveshift.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->driveshift);
      union {
        int32_t real;
        uint32_t base;
      } u_targetshift;
      u_targetshift.real = this->targetshift;
      *(outbuffer + offset + 0) = (u_targetshift.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targetshift.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targetshift.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targetshift.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targetshift);
      union {
        int32_t real;
        uint32_t base;
      } u_inputshift;
      u_inputshift.real = this->inputshift;
      *(outbuffer + offset + 0) = (u_inputshift.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inputshift.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inputshift.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inputshift.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inputshift);
      union {
        int32_t real;
        uint32_t base;
      } u_strmode;
      u_strmode.real = this->strmode;
      *(outbuffer + offset + 0) = (u_strmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strmode);
      union {
        int32_t real;
        uint32_t base;
      } u_strcontmode;
      u_strcontmode.real = this->strcontmode;
      *(outbuffer + offset + 0) = (u_strcontmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strcontmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strcontmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strcontmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strcontmode);
      union {
        int32_t real;
        uint32_t base;
      } u_stroverridemode;
      u_stroverridemode.real = this->stroverridemode;
      *(outbuffer + offset + 0) = (u_stroverridemode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stroverridemode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stroverridemode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stroverridemode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stroverridemode);
      union {
        int32_t real;
        uint32_t base;
      } u_strservo;
      u_strservo.real = this->strservo;
      *(outbuffer + offset + 0) = (u_strservo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strservo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strservo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strservo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strservo);
      union {
        int32_t real;
        uint32_t base;
      } u_targettorque;
      u_targettorque.real = this->targettorque;
      *(outbuffer + offset + 0) = (u_targettorque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targettorque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targettorque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targettorque.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targettorque);
      union {
        int32_t real;
        uint32_t base;
      } u_torque;
      u_torque.real = this->torque;
      *(outbuffer + offset + 0) = (u_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torque.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->torque);
      union {
        double real;
        uint64_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        double real;
        uint64_t base;
      } u_targetangle;
      u_targetangle.real = this->targetangle;
      *(outbuffer + offset + 0) = (u_targetangle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targetangle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targetangle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targetangle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_targetangle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_targetangle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_targetangle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_targetangle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->targetangle);
      union {
        int32_t real;
        uint32_t base;
      } u_bbrakepress;
      u_bbrakepress.real = this->bbrakepress;
      *(outbuffer + offset + 0) = (u_bbrakepress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bbrakepress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bbrakepress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bbrakepress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bbrakepress);
      union {
        int32_t real;
        uint32_t base;
      } u_brakepedal;
      u_brakepedal.real = this->brakepedal;
      *(outbuffer + offset + 0) = (u_brakepedal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brakepedal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brakepedal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brakepedal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brakepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_brtargetpedalstr;
      u_brtargetpedalstr.real = this->brtargetpedalstr;
      *(outbuffer + offset + 0) = (u_brtargetpedalstr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brtargetpedalstr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brtargetpedalstr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brtargetpedalstr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brtargetpedalstr);
      union {
        int32_t real;
        uint32_t base;
      } u_brinputpedalstr;
      u_brinputpedalstr.real = this->brinputpedalstr;
      *(outbuffer + offset + 0) = (u_brinputpedalstr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brinputpedalstr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brinputpedalstr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brinputpedalstr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brinputpedalstr);
      union {
        double real;
        uint64_t base;
      } u_battery;
      u_battery.real = this->battery;
      *(outbuffer + offset + 0) = (u_battery.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_battery.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_battery.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_battery.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_battery.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->battery);
      union {
        int32_t real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        double real;
        uint64_t base;
      } u_anp;
      u_anp.real = this->anp;
      *(outbuffer + offset + 0) = (u_anp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_anp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_anp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_anp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_anp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->anp);
      union {
        int32_t real;
        uint32_t base;
      } u_battmaxtemparature;
      u_battmaxtemparature.real = this->battmaxtemparature;
      *(outbuffer + offset + 0) = (u_battmaxtemparature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battmaxtemparature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battmaxtemparature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battmaxtemparature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battmaxtemparature);
      union {
        int32_t real;
        uint32_t base;
      } u_battmintemparature;
      u_battmintemparature.real = this->battmintemparature;
      *(outbuffer + offset + 0) = (u_battmintemparature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battmintemparature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battmintemparature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battmintemparature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battmintemparature);
      union {
        double real;
        uint64_t base;
      } u_maxchgcurrent;
      u_maxchgcurrent.real = this->maxchgcurrent;
      *(outbuffer + offset + 0) = (u_maxchgcurrent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxchgcurrent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxchgcurrent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxchgcurrent.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_maxchgcurrent.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_maxchgcurrent.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_maxchgcurrent.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_maxchgcurrent.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->maxchgcurrent);
      union {
        double real;
        uint64_t base;
      } u_maxdischgcurrent;
      u_maxdischgcurrent.real = this->maxdischgcurrent;
      *(outbuffer + offset + 0) = (u_maxdischgcurrent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxdischgcurrent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxdischgcurrent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxdischgcurrent.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_maxdischgcurrent.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_maxdischgcurrent.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_maxdischgcurrent.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_maxdischgcurrent.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->maxdischgcurrent);
      union {
        double real;
        uint64_t base;
      } u_sideacc;
      u_sideacc.real = this->sideacc;
      *(outbuffer + offset + 0) = (u_sideacc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sideacc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sideacc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sideacc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sideacc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sideacc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sideacc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sideacc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sideacc);
      union {
        double real;
        uint64_t base;
      } u_accellfromp;
      u_accellfromp.real = this->accellfromp;
      *(outbuffer + offset + 0) = (u_accellfromp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accellfromp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accellfromp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accellfromp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_accellfromp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_accellfromp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_accellfromp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_accellfromp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->accellfromp);
      union {
        double real;
        uint64_t base;
      } u_anglefromp;
      u_anglefromp.real = this->anglefromp;
      *(outbuffer + offset + 0) = (u_anglefromp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglefromp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglefromp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglefromp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_anglefromp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_anglefromp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_anglefromp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_anglefromp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->anglefromp);
      union {
        double real;
        uint64_t base;
      } u_brakepedalfromp;
      u_brakepedalfromp.real = this->brakepedalfromp;
      *(outbuffer + offset + 0) = (u_brakepedalfromp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brakepedalfromp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brakepedalfromp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brakepedalfromp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_brakepedalfromp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_brakepedalfromp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_brakepedalfromp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_brakepedalfromp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->brakepedalfromp);
      union {
        double real;
        uint64_t base;
      } u_speedfr;
      u_speedfr.real = this->speedfr;
      *(outbuffer + offset + 0) = (u_speedfr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speedfr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speedfr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speedfr.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speedfr.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speedfr.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speedfr.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speedfr.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speedfr);
      union {
        double real;
        uint64_t base;
      } u_speedfl;
      u_speedfl.real = this->speedfl;
      *(outbuffer + offset + 0) = (u_speedfl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speedfl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speedfl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speedfl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speedfl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speedfl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speedfl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speedfl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speedfl);
      union {
        double real;
        uint64_t base;
      } u_speedrr;
      u_speedrr.real = this->speedrr;
      *(outbuffer + offset + 0) = (u_speedrr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speedrr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speedrr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speedrr.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speedrr.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speedrr.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speedrr.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speedrr.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speedrr);
      union {
        double real;
        uint64_t base;
      } u_speedrl;
      u_speedrl.real = this->speedrl;
      *(outbuffer + offset + 0) = (u_speedrl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speedrl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speedrl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speedrl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speedrl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speedrl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speedrl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speedrl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speedrl);
      union {
        double real;
        uint64_t base;
      } u_velocfromp2;
      u_velocfromp2.real = this->velocfromp2;
      *(outbuffer + offset + 0) = (u_velocfromp2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocfromp2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocfromp2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocfromp2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocfromp2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocfromp2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocfromp2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocfromp2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocfromp2);
      union {
        int32_t real;
        uint32_t base;
      } u_drvmode;
      u_drvmode.real = this->drvmode;
      *(outbuffer + offset + 0) = (u_drvmode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drvmode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drvmode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drvmode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drvmode);
      union {
        int32_t real;
        uint32_t base;
      } u_devpedalstrfromp;
      u_devpedalstrfromp.real = this->devpedalstrfromp;
      *(outbuffer + offset + 0) = (u_devpedalstrfromp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_devpedalstrfromp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_devpedalstrfromp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_devpedalstrfromp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->devpedalstrfromp);
      union {
        int32_t real;
        uint32_t base;
      } u_rpm;
      u_rpm.real = this->rpm;
      *(outbuffer + offset + 0) = (u_rpm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rpm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rpm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rpm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpm);
      union {
        double real;
        uint64_t base;
      } u_velocflfromp;
      u_velocflfromp.real = this->velocflfromp;
      *(outbuffer + offset + 0) = (u_velocflfromp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocflfromp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocflfromp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocflfromp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocflfromp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocflfromp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocflfromp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocflfromp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocflfromp);
      union {
        int32_t real;
        uint32_t base;
      } u_ev_mode;
      u_ev_mode.real = this->ev_mode;
      *(outbuffer + offset + 0) = (u_ev_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ev_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ev_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ev_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ev_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_temp;
      u_temp.real = this->temp;
      *(outbuffer + offset + 0) = (u_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp);
      union {
        int32_t real;
        uint32_t base;
      } u_shiftfrmprius;
      u_shiftfrmprius.real = this->shiftfrmprius;
      *(outbuffer + offset + 0) = (u_shiftfrmprius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_shiftfrmprius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_shiftfrmprius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_shiftfrmprius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shiftfrmprius);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.real = this->light;
      *(outbuffer + offset + 0) = (u_light.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_light.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_light.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_light.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->light);
      union {
        int32_t real;
        uint32_t base;
      } u_gaslevel;
      u_gaslevel.real = this->gaslevel;
      *(outbuffer + offset + 0) = (u_gaslevel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gaslevel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gaslevel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gaslevel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaslevel);
      union {
        int32_t real;
        uint32_t base;
      } u_door;
      u_door.real = this->door;
      *(outbuffer + offset + 0) = (u_door.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_door.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_door.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_door.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->door);
      union {
        int32_t real;
        uint32_t base;
      } u_cluise;
      u_cluise.real = this->cluise;
      *(outbuffer + offset + 0) = (u_cluise.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cluise.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cluise.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cluise.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluise);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_tm;
      arrToVar(length_tm, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tm; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tm-1]=0;
      this->tm = (char *)(inbuffer + offset-1);
      offset += length_tm;
      union {
        int32_t real;
        uint32_t base;
      } u_devmode;
      u_devmode.base = 0;
      u_devmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_devmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_devmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_devmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->devmode = u_devmode.real;
      offset += sizeof(this->devmode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvcontmode;
      u_drvcontmode.base = 0;
      u_drvcontmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drvcontmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drvcontmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drvcontmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drvcontmode = u_drvcontmode.real;
      offset += sizeof(this->drvcontmode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvoverridemode;
      u_drvoverridemode.base = 0;
      u_drvoverridemode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drvoverridemode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drvoverridemode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drvoverridemode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drvoverridemode = u_drvoverridemode.real;
      offset += sizeof(this->drvoverridemode);
      union {
        int32_t real;
        uint32_t base;
      } u_drvservo;
      u_drvservo.base = 0;
      u_drvservo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drvservo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drvservo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drvservo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drvservo = u_drvservo.real;
      offset += sizeof(this->drvservo);
      union {
        int32_t real;
        uint32_t base;
      } u_drivepedal;
      u_drivepedal.base = 0;
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drivepedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drivepedal = u_drivepedal.real;
      offset += sizeof(this->drivepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_targetpedalstr;
      u_targetpedalstr.base = 0;
      u_targetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->targetpedalstr = u_targetpedalstr.real;
      offset += sizeof(this->targetpedalstr);
      union {
        int32_t real;
        uint32_t base;
      } u_inputpedalstr;
      u_inputpedalstr.base = 0;
      u_inputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inputpedalstr = u_inputpedalstr.real;
      offset += sizeof(this->inputpedalstr);
      union {
        double real;
        uint64_t base;
      } u_targetveloc;
      u_targetveloc.base = 0;
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_targetveloc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->targetveloc = u_targetveloc.real;
      offset += sizeof(this->targetveloc);
      union {
        double real;
        uint64_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        int32_t real;
        uint32_t base;
      } u_driveshift;
      u_driveshift.base = 0;
      u_driveshift.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_driveshift.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_driveshift.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_driveshift.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->driveshift = u_driveshift.real;
      offset += sizeof(this->driveshift);
      union {
        int32_t real;
        uint32_t base;
      } u_targetshift;
      u_targetshift.base = 0;
      u_targetshift.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targetshift.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targetshift.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targetshift.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->targetshift = u_targetshift.real;
      offset += sizeof(this->targetshift);
      union {
        int32_t real;
        uint32_t base;
      } u_inputshift;
      u_inputshift.base = 0;
      u_inputshift.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inputshift.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inputshift.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inputshift.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inputshift = u_inputshift.real;
      offset += sizeof(this->inputshift);
      union {
        int32_t real;
        uint32_t base;
      } u_strmode;
      u_strmode.base = 0;
      u_strmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strmode = u_strmode.real;
      offset += sizeof(this->strmode);
      union {
        int32_t real;
        uint32_t base;
      } u_strcontmode;
      u_strcontmode.base = 0;
      u_strcontmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strcontmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strcontmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strcontmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strcontmode = u_strcontmode.real;
      offset += sizeof(this->strcontmode);
      union {
        int32_t real;
        uint32_t base;
      } u_stroverridemode;
      u_stroverridemode.base = 0;
      u_stroverridemode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stroverridemode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stroverridemode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stroverridemode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stroverridemode = u_stroverridemode.real;
      offset += sizeof(this->stroverridemode);
      union {
        int32_t real;
        uint32_t base;
      } u_strservo;
      u_strservo.base = 0;
      u_strservo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strservo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strservo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strservo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strservo = u_strservo.real;
      offset += sizeof(this->strservo);
      union {
        int32_t real;
        uint32_t base;
      } u_targettorque;
      u_targettorque.base = 0;
      u_targettorque.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targettorque.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targettorque.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targettorque.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->targettorque = u_targettorque.real;
      offset += sizeof(this->targettorque);
      union {
        int32_t real;
        uint32_t base;
      } u_torque;
      u_torque.base = 0;
      u_torque.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_torque.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_torque.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_torque.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->torque = u_torque.real;
      offset += sizeof(this->torque);
      union {
        double real;
        uint64_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        double real;
        uint64_t base;
      } u_targetangle;
      u_targetangle.base = 0;
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_targetangle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->targetangle = u_targetangle.real;
      offset += sizeof(this->targetangle);
      union {
        int32_t real;
        uint32_t base;
      } u_bbrakepress;
      u_bbrakepress.base = 0;
      u_bbrakepress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bbrakepress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bbrakepress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bbrakepress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bbrakepress = u_bbrakepress.real;
      offset += sizeof(this->bbrakepress);
      union {
        int32_t real;
        uint32_t base;
      } u_brakepedal;
      u_brakepedal.base = 0;
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brakepedal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brakepedal = u_brakepedal.real;
      offset += sizeof(this->brakepedal);
      union {
        int32_t real;
        uint32_t base;
      } u_brtargetpedalstr;
      u_brtargetpedalstr.base = 0;
      u_brtargetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brtargetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brtargetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brtargetpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brtargetpedalstr = u_brtargetpedalstr.real;
      offset += sizeof(this->brtargetpedalstr);
      union {
        int32_t real;
        uint32_t base;
      } u_brinputpedalstr;
      u_brinputpedalstr.base = 0;
      u_brinputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brinputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brinputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brinputpedalstr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brinputpedalstr = u_brinputpedalstr.real;
      offset += sizeof(this->brinputpedalstr);
      union {
        double real;
        uint64_t base;
      } u_battery;
      u_battery.base = 0;
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->battery = u_battery.real;
      offset += sizeof(this->battery);
      union {
        int32_t real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        double real;
        uint64_t base;
      } u_anp;
      u_anp.base = 0;
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_anp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->anp = u_anp.real;
      offset += sizeof(this->anp);
      union {
        int32_t real;
        uint32_t base;
      } u_battmaxtemparature;
      u_battmaxtemparature.base = 0;
      u_battmaxtemparature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battmaxtemparature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battmaxtemparature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battmaxtemparature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battmaxtemparature = u_battmaxtemparature.real;
      offset += sizeof(this->battmaxtemparature);
      union {
        int32_t real;
        uint32_t base;
      } u_battmintemparature;
      u_battmintemparature.base = 0;
      u_battmintemparature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battmintemparature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battmintemparature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battmintemparature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battmintemparature = u_battmintemparature.real;
      offset += sizeof(this->battmintemparature);
      union {
        double real;
        uint64_t base;
      } u_maxchgcurrent;
      u_maxchgcurrent.base = 0;
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_maxchgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->maxchgcurrent = u_maxchgcurrent.real;
      offset += sizeof(this->maxchgcurrent);
      union {
        double real;
        uint64_t base;
      } u_maxdischgcurrent;
      u_maxdischgcurrent.base = 0;
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_maxdischgcurrent.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->maxdischgcurrent = u_maxdischgcurrent.real;
      offset += sizeof(this->maxdischgcurrent);
      union {
        double real;
        uint64_t base;
      } u_sideacc;
      u_sideacc.base = 0;
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sideacc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sideacc = u_sideacc.real;
      offset += sizeof(this->sideacc);
      union {
        double real;
        uint64_t base;
      } u_accellfromp;
      u_accellfromp.base = 0;
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_accellfromp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->accellfromp = u_accellfromp.real;
      offset += sizeof(this->accellfromp);
      union {
        double real;
        uint64_t base;
      } u_anglefromp;
      u_anglefromp.base = 0;
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_anglefromp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->anglefromp = u_anglefromp.real;
      offset += sizeof(this->anglefromp);
      union {
        double real;
        uint64_t base;
      } u_brakepedalfromp;
      u_brakepedalfromp.base = 0;
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_brakepedalfromp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->brakepedalfromp = u_brakepedalfromp.real;
      offset += sizeof(this->brakepedalfromp);
      union {
        double real;
        uint64_t base;
      } u_speedfr;
      u_speedfr.base = 0;
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speedfr.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speedfr = u_speedfr.real;
      offset += sizeof(this->speedfr);
      union {
        double real;
        uint64_t base;
      } u_speedfl;
      u_speedfl.base = 0;
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speedfl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speedfl = u_speedfl.real;
      offset += sizeof(this->speedfl);
      union {
        double real;
        uint64_t base;
      } u_speedrr;
      u_speedrr.base = 0;
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speedrr.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speedrr = u_speedrr.real;
      offset += sizeof(this->speedrr);
      union {
        double real;
        uint64_t base;
      } u_speedrl;
      u_speedrl.base = 0;
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speedrl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speedrl = u_speedrl.real;
      offset += sizeof(this->speedrl);
      union {
        double real;
        uint64_t base;
      } u_velocfromp2;
      u_velocfromp2.base = 0;
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocfromp2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocfromp2 = u_velocfromp2.real;
      offset += sizeof(this->velocfromp2);
      union {
        int32_t real;
        uint32_t base;
      } u_drvmode;
      u_drvmode.base = 0;
      u_drvmode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drvmode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drvmode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drvmode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drvmode = u_drvmode.real;
      offset += sizeof(this->drvmode);
      union {
        int32_t real;
        uint32_t base;
      } u_devpedalstrfromp;
      u_devpedalstrfromp.base = 0;
      u_devpedalstrfromp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_devpedalstrfromp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_devpedalstrfromp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_devpedalstrfromp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->devpedalstrfromp = u_devpedalstrfromp.real;
      offset += sizeof(this->devpedalstrfromp);
      union {
        int32_t real;
        uint32_t base;
      } u_rpm;
      u_rpm.base = 0;
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rpm = u_rpm.real;
      offset += sizeof(this->rpm);
      union {
        double real;
        uint64_t base;
      } u_velocflfromp;
      u_velocflfromp.base = 0;
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocflfromp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocflfromp = u_velocflfromp.real;
      offset += sizeof(this->velocflfromp);
      union {
        int32_t real;
        uint32_t base;
      } u_ev_mode;
      u_ev_mode.base = 0;
      u_ev_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ev_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ev_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ev_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ev_mode = u_ev_mode.real;
      offset += sizeof(this->ev_mode);
      union {
        int32_t real;
        uint32_t base;
      } u_temp;
      u_temp.base = 0;
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp = u_temp.real;
      offset += sizeof(this->temp);
      union {
        int32_t real;
        uint32_t base;
      } u_shiftfrmprius;
      u_shiftfrmprius.base = 0;
      u_shiftfrmprius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_shiftfrmprius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_shiftfrmprius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_shiftfrmprius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->shiftfrmprius = u_shiftfrmprius.real;
      offset += sizeof(this->shiftfrmprius);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.base = 0;
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->light = u_light.real;
      offset += sizeof(this->light);
      union {
        int32_t real;
        uint32_t base;
      } u_gaslevel;
      u_gaslevel.base = 0;
      u_gaslevel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gaslevel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gaslevel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gaslevel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gaslevel = u_gaslevel.real;
      offset += sizeof(this->gaslevel);
      union {
        int32_t real;
        uint32_t base;
      } u_door;
      u_door.base = 0;
      u_door.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_door.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_door.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_door.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->door = u_door.real;
      offset += sizeof(this->door);
      union {
        int32_t real;
        uint32_t base;
      } u_cluise;
      u_cluise.base = 0;
      u_cluise.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cluise.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cluise.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cluise.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cluise = u_cluise.real;
      offset += sizeof(this->cluise);
     return offset;
    }

    const char * getType(){ return "autoware_can_msgs/CANInfo"; };
    const char * getMD5(){ return "605f4356821f92a8fec1a756259316df"; };

  };

}
#endif