#ifndef _ROS_custom_msgs_gnssSample_h
#define _ROS_custom_msgs_gnssSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace custom_msgs
{

  class gnssSample : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _itow_type;
      _itow_type itow;
      typedef double _fix_type;
      _fix_type fix;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _hEll_type;
      _hEll_type hEll;
      typedef double _hMsl_type;
      _hMsl_type hMsl;
      typedef geometry_msgs::Vector3 _vel_type;
      _vel_type vel;
      typedef double _hAcc_type;
      _hAcc_type hAcc;
      typedef double _vAcc_type;
      _vAcc_type vAcc;
      typedef double _sAcc_type;
      _sAcc_type sAcc;
      typedef double _pDop_type;
      _pDop_type pDop;
      typedef double _hDop_type;
      _hDop_type hDop;
      typedef double _vDop_type;
      _vDop_type vDop;
      typedef double _numSat_type;
      _numSat_type numSat;
      typedef double _heading_type;
      _heading_type heading;
      typedef double _headingAcc_type;
      _headingAcc_type headingAcc;

    gnssSample():
      header(),
      itow(0),
      fix(0),
      latitude(0),
      longitude(0),
      hEll(0),
      hMsl(0),
      vel(),
      hAcc(0),
      vAcc(0),
      sAcc(0),
      pDop(0),
      hDop(0),
      vDop(0),
      numSat(0),
      heading(0),
      headingAcc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_itow;
      u_itow.real = this->itow;
      *(outbuffer + offset + 0) = (u_itow.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_itow.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_itow.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_itow.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_itow.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_itow.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_itow.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_itow.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->itow);
      union {
        double real;
        uint64_t base;
      } u_fix;
      u_fix.real = this->fix;
      *(outbuffer + offset + 0) = (u_fix.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fix.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fix.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fix.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fix.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fix.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fix.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fix.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fix);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_hEll;
      u_hEll.real = this->hEll;
      *(outbuffer + offset + 0) = (u_hEll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hEll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hEll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hEll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hEll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hEll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hEll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hEll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hEll);
      union {
        double real;
        uint64_t base;
      } u_hMsl;
      u_hMsl.real = this->hMsl;
      *(outbuffer + offset + 0) = (u_hMsl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hMsl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hMsl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hMsl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hMsl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hMsl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hMsl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hMsl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hMsl);
      offset += this->vel.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_hAcc;
      u_hAcc.real = this->hAcc;
      *(outbuffer + offset + 0) = (u_hAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hAcc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hAcc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hAcc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hAcc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hAcc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hAcc);
      union {
        double real;
        uint64_t base;
      } u_vAcc;
      u_vAcc.real = this->vAcc;
      *(outbuffer + offset + 0) = (u_vAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vAcc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vAcc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vAcc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vAcc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vAcc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vAcc);
      union {
        double real;
        uint64_t base;
      } u_sAcc;
      u_sAcc.real = this->sAcc;
      *(outbuffer + offset + 0) = (u_sAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sAcc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sAcc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sAcc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sAcc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sAcc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sAcc);
      union {
        double real;
        uint64_t base;
      } u_pDop;
      u_pDop.real = this->pDop;
      *(outbuffer + offset + 0) = (u_pDop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pDop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pDop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pDop.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pDop.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pDop.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pDop.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pDop.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pDop);
      union {
        double real;
        uint64_t base;
      } u_hDop;
      u_hDop.real = this->hDop;
      *(outbuffer + offset + 0) = (u_hDop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hDop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hDop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hDop.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hDop.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hDop.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hDop.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hDop.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hDop);
      union {
        double real;
        uint64_t base;
      } u_vDop;
      u_vDop.real = this->vDop;
      *(outbuffer + offset + 0) = (u_vDop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vDop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vDop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vDop.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vDop.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vDop.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vDop.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vDop.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vDop);
      union {
        double real;
        uint64_t base;
      } u_numSat;
      u_numSat.real = this->numSat;
      *(outbuffer + offset + 0) = (u_numSat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numSat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numSat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numSat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_numSat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_numSat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_numSat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_numSat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->numSat);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_headingAcc;
      u_headingAcc.real = this->headingAcc;
      *(outbuffer + offset + 0) = (u_headingAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_headingAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_headingAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_headingAcc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_headingAcc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_headingAcc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_headingAcc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_headingAcc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->headingAcc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_itow;
      u_itow.base = 0;
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_itow.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->itow = u_itow.real;
      offset += sizeof(this->itow);
      union {
        double real;
        uint64_t base;
      } u_fix;
      u_fix.base = 0;
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fix.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fix = u_fix.real;
      offset += sizeof(this->fix);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_hEll;
      u_hEll.base = 0;
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hEll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hEll = u_hEll.real;
      offset += sizeof(this->hEll);
      union {
        double real;
        uint64_t base;
      } u_hMsl;
      u_hMsl.base = 0;
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hMsl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hMsl = u_hMsl.real;
      offset += sizeof(this->hMsl);
      offset += this->vel.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_hAcc;
      u_hAcc.base = 0;
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hAcc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hAcc = u_hAcc.real;
      offset += sizeof(this->hAcc);
      union {
        double real;
        uint64_t base;
      } u_vAcc;
      u_vAcc.base = 0;
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vAcc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vAcc = u_vAcc.real;
      offset += sizeof(this->vAcc);
      union {
        double real;
        uint64_t base;
      } u_sAcc;
      u_sAcc.base = 0;
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sAcc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sAcc = u_sAcc.real;
      offset += sizeof(this->sAcc);
      union {
        double real;
        uint64_t base;
      } u_pDop;
      u_pDop.base = 0;
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pDop.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pDop = u_pDop.real;
      offset += sizeof(this->pDop);
      union {
        double real;
        uint64_t base;
      } u_hDop;
      u_hDop.base = 0;
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hDop.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hDop = u_hDop.real;
      offset += sizeof(this->hDop);
      union {
        double real;
        uint64_t base;
      } u_vDop;
      u_vDop.base = 0;
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vDop.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vDop = u_vDop.real;
      offset += sizeof(this->vDop);
      union {
        double real;
        uint64_t base;
      } u_numSat;
      u_numSat.base = 0;
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_numSat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->numSat = u_numSat.real;
      offset += sizeof(this->numSat);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_headingAcc;
      u_headingAcc.base = 0;
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_headingAcc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->headingAcc = u_headingAcc.real;
      offset += sizeof(this->headingAcc);
     return offset;
    }

    const char * getType(){ return "custom_msgs/gnssSample"; };
    const char * getMD5(){ return "d0573311aa10335e691a2e99fd2b6d50"; };

  };

}
#endif