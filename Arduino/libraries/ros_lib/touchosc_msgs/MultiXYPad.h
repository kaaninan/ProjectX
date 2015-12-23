#ifndef _ROS_touchosc_msgs_MultiXYPad_h
#define _ROS_touchosc_msgs_MultiXYPad_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "touchosc_msgs/CommonProperties.h"

namespace touchosc_msgs
{

  class MultiXYPad : public ros::Msg
  {
    public:
      std_msgs::Header header;
      touchosc_msgs::CommonProperties common;
      float range[2];
      float x[5];
      float y[5];
      bool z[5];

    MultiXYPad():
      header(),
      common(),
      range(),
      x(),
      y(),
      z()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->common.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_rangei;
      u_rangei.real = this->range[i];
      *(outbuffer + offset + 0) = (u_rangei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rangei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rangei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rangei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_xi;
      u_xi.real = this->x[i];
      *(outbuffer + offset + 0) = (u_xi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_yi;
      u_yi.real = this->y[i];
      *(outbuffer + offset + 0) = (u_yi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        bool real;
        uint8_t base;
      } u_zi;
      u_zi.real = this->z[i];
      *(outbuffer + offset + 0) = (u_zi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->common.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_rangei;
      u_rangei.base = 0;
      u_rangei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rangei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rangei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rangei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range[i] = u_rangei.real;
      offset += sizeof(this->range[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_xi;
      u_xi.base = 0;
      u_xi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x[i] = u_xi.real;
      offset += sizeof(this->x[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_yi;
      u_yi.base = 0;
      u_yi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y[i] = u_yi.real;
      offset += sizeof(this->y[i]);
      }
      for( uint8_t i = 0; i < 5; i++){
      union {
        bool real;
        uint8_t base;
      } u_zi;
      u_zi.base = 0;
      u_zi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z[i] = u_zi.real;
      offset += sizeof(this->z[i]);
      }
     return offset;
    }

    const char * getType(){ return "touchosc_msgs/MultiXYPad"; };
    const char * getMD5(){ return "9c4c914fe2ffb44766fc5338b5a82aba"; };

  };

}
#endif