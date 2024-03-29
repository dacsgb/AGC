#ifndef _ROS_SERVICE_GetGridMap_h
#define _ROS_SERVICE_GetGridMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grid_map_msgs/GridMap.h"

namespace grid_map_msgs
{

static const char GETGRIDMAP[] = "grid_map_msgs/GetGridMap";

  class GetGridMapRequest : public ros::Msg
  {
    public:
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef double _position_x_type;
      _position_x_type position_x;
      typedef double _position_y_type;
      _position_y_type position_y;
      typedef double _length_x_type;
      _length_x_type length_x;
      typedef double _length_y_type;
      _length_y_type length_y;
      uint32_t layers_length;
      typedef char* _layers_type;
      _layers_type st_layers;
      _layers_type * layers;

    GetGridMapRequest():
      frame_id(""),
      position_x(0),
      position_y(0),
      length_x(0),
      length_y(0),
      layers_length(0), layers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      union {
        double real;
        uint64_t base;
      } u_position_x;
      u_position_x.real = this->position_x;
      *(outbuffer + offset + 0) = (u_position_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position_x);
      union {
        double real;
        uint64_t base;
      } u_position_y;
      u_position_y.real = this->position_y;
      *(outbuffer + offset + 0) = (u_position_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position_y);
      union {
        double real;
        uint64_t base;
      } u_length_x;
      u_length_x.real = this->length_x;
      *(outbuffer + offset + 0) = (u_length_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_length_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_length_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_length_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_length_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->length_x);
      union {
        double real;
        uint64_t base;
      } u_length_y;
      u_length_y.real = this->length_y;
      *(outbuffer + offset + 0) = (u_length_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_length_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_length_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_length_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_length_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->length_y);
      *(outbuffer + offset + 0) = (this->layers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layers_length);
      for( uint32_t i = 0; i < layers_length; i++){
      uint32_t length_layersi = strlen(this->layers[i]);
      varToArr(outbuffer + offset, length_layersi);
      offset += 4;
      memcpy(outbuffer + offset, this->layers[i], length_layersi);
      offset += length_layersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      union {
        double real;
        uint64_t base;
      } u_position_x;
      u_position_x.base = 0;
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position_x = u_position_x.real;
      offset += sizeof(this->position_x);
      union {
        double real;
        uint64_t base;
      } u_position_y;
      u_position_y.base = 0;
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position_y = u_position_y.real;
      offset += sizeof(this->position_y);
      union {
        double real;
        uint64_t base;
      } u_length_x;
      u_length_x.base = 0;
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_length_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->length_x = u_length_x.real;
      offset += sizeof(this->length_x);
      union {
        double real;
        uint64_t base;
      } u_length_y;
      u_length_y.base = 0;
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_length_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->length_y = u_length_y.real;
      offset += sizeof(this->length_y);
      uint32_t layers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      layers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      layers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      layers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->layers_length);
      if(layers_lengthT > layers_length)
        this->layers = (char**)realloc(this->layers, layers_lengthT * sizeof(char*));
      layers_length = layers_lengthT;
      for( uint32_t i = 0; i < layers_length; i++){
      uint32_t length_st_layers;
      arrToVar(length_st_layers, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_layers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_layers-1]=0;
      this->st_layers = (char *)(inbuffer + offset-1);
      offset += length_st_layers;
        memcpy( &(this->layers[i]), &(this->st_layers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETGRIDMAP; };
    const char * getMD5(){ return "b6b21ecd617fdfa7f32e8c349cec3c2e"; };

  };

  class GetGridMapResponse : public ros::Msg
  {
    public:
      typedef grid_map_msgs::GridMap _map_type;
      _map_type map;

    GetGridMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETGRIDMAP; };
    const char * getMD5(){ return "4f8e24cfd42bc1470fe765b7516ff7e5"; };

  };

  class GetGridMap {
    public:
    typedef GetGridMapRequest Request;
    typedef GetGridMapResponse Response;
  };

}
#endif
