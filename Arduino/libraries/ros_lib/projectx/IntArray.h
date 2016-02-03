#ifndef _ROS_projectx_IntArray_h
#define _ROS_projectx_IntArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class IntArray : public ros::Msg
  {
    public:
      uint8_t deger_length;
      int64_t st_deger;
      int64_t * deger;

    IntArray():
      deger_length(0), deger(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = deger_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < deger_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_degeri;
      u_degeri.real = this->deger[i];
      *(outbuffer + offset + 0) = (u_degeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_degeri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_degeri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_degeri.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_degeri.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_degeri.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_degeri.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_degeri.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->deger[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t deger_lengthT = *(inbuffer + offset++);
      if(deger_lengthT > deger_length)
        this->deger = (int64_t*)realloc(this->deger, deger_lengthT * sizeof(int64_t));
      offset += 3;
      deger_length = deger_lengthT;
      for( uint8_t i = 0; i < deger_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_deger;
      u_st_deger.base = 0;
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_deger.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_deger = u_st_deger.real;
      offset += sizeof(this->st_deger);
        memcpy( &(this->deger[i]), &(this->st_deger), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "projectx/IntArray"; };
    const char * getMD5(){ return "b33d02db9df612bb8d91e911852cbddb"; };

  };

}
#endif