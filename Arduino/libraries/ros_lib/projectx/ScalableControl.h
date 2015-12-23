#ifndef _ROS_projectx_ScalableControl_h
#define _ROS_projectx_ScalableControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "projectx/CommonProperties.h"

namespace projectx
{

  class ScalableControl : public ros::Msg
  {
    public:
      std_msgs::Header header;
      projectx::CommonProperties common;
      float range[2];
      float value;
      bool z;

    ScalableControl():
      header(),
      common(),
      range(),
      value(0),
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
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
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
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
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

    const char * getType(){ return "projectx/ScalableControl"; };
    const char * getMD5(){ return "4b6ef3bf63f615ec962c83cced2ac5dc"; };

  };

}
#endif