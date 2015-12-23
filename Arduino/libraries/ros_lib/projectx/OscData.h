#ifndef _ROS_projectx_OscData_h
#define _ROS_projectx_OscData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class OscData : public ros::Msg
  {
    public:
      uint8_t name_length;
      int64_t st_name;
      int64_t * name;
      uint8_t value_length;
      int64_t st_value;
      int64_t * value;

    OscData():
      name_length(0), name(NULL),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_namei;
      u_namei.real = this->name[i];
      *(outbuffer + offset + 0) = (u_namei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_namei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_namei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_namei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_namei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_namei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_namei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_namei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->name[i]);
      }
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
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (int64_t*)realloc(this->name, name_lengthT * sizeof(int64_t));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_name;
      u_st_name.base = 0;
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_name.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_name = u_st_name.real;
      offset += sizeof(this->st_name);
        memcpy( &(this->name[i]), &(this->st_name), sizeof(int64_t));
      }
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

    const char * getType(){ return "projectx/OscData"; };
    const char * getMD5(){ return "2e8562cd47ba1887eb1c2b71a82b7377"; };

  };

}
#endif