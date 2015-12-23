#ifndef _ROS_touchosc_msgs_XYPad_h
#define _ROS_touchosc_msgs_XYPad_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "touchosc_msgs/CommonProperties.h"

namespace touchosc_msgs
{

  class XYPad : public ros::Msg
  {
    public:
      std_msgs::Header header;
      touchosc_msgs::CommonProperties common;
      float range[2];
      float x;
      float y;
      bool z;

    XYPad():
      header(),
      common(),
      range(),
      x(0),
      y(0),
      z(0)
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
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z);
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
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z = u_z.real;
      offset += sizeof(this->z);
     return offset;
    }

    const char * getType(){ return "touchosc_msgs/XYPad"; };
    const char * getMD5(){ return "ee31b4143f668690ed4f5b021cf85341"; };

  };

}
#endif