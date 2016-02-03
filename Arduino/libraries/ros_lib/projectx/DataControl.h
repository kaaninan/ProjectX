#ifndef _ROS_projectx_DataControl_h
#define _ROS_projectx_DataControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class DataControl : public ros::Msg
  {
    public:
      const char* data;
      uint8_t value_length;
      int64_t st_value;
      int64_t * value;

    DataControl():
      data(""),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      memcpy(outbuffer + offset, &length_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_valuei;
      u_valuei.real = this->value[i];
      *(outbuffer + offset + 0) = (u_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_valuei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_valuei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_valuei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_valuei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_data;
      memcpy(&length_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (int64_t*)realloc(this->value, value_lengthT * sizeof(int64_t));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_value;
      u_st_value.base = 0;
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_value = u_st_value.real;
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "projectx/DataControl"; };
    const char * getMD5(){ return "9ac12026f5dc300a479ba9f011cab4bf"; };

  };

}
#endif