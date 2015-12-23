#ifndef _ROS_projectx_MultiFader_h
#define _ROS_projectx_MultiFader_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "projectx/CommonProperties.h"

namespace projectx
{

  class MultiFader : public ros::Msg
  {
    public:
      std_msgs::Header header;
      projectx::CommonProperties common;
      uint16_t dimension;
      float range[2];
      uint8_t values_length;
      float st_values;
      float * values;
      bool z;

    MultiFader():
      header(),
      common(),
      dimension(0),
      range(),
      values_length(0), values(NULL),
      z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->common.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->dimension >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dimension >> (8 * 1)) & 0xFF;
      offset += sizeof(this->dimension);
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
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_valuesi;
      u_valuesi.real = this->values[i];
      *(outbuffer + offset + 0) = (u_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values[i]);
      }
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
      this->dimension =  ((uint16_t) (*(inbuffer + offset)));
      this->dimension |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->dimension);
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
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (float*)realloc(this->values, values_lengthT * sizeof(float));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_values;
      u_st_values.base = 0;
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_values = u_st_values.real;
      offset += sizeof(this->st_values);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(float));
      }
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

    const char * getType(){ return "projectx/MultiFader"; };
    const char * getMD5(){ return "809deaed82ef6d600e6957164fb63431"; };

  };

}
#endif