#ifndef _ROS_projectx_MotorOutSingleArray_h
#define _ROS_projectx_MotorOutSingleArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class MotorOutSingleArray : public ros::Msg
  {
    public:
      int64_t id[21];
      int64_t pos[21];

    MotorOutSingleArray():
      id(),
      pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 21; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_idi;
      u_idi.real = this->id[i];
      *(outbuffer + offset + 0) = (u_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_idi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_idi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_idi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_idi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id[i]);
      }
      for( uint8_t i = 0; i < 21; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 21; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_idi;
      u_idi.base = 0;
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_idi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id[i] = u_idi.real;
      offset += sizeof(this->id[i]);
      }
      for( uint8_t i = 0; i < 21; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_posi;
      u_posi.base = 0;
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos[i] = u_posi.real;
      offset += sizeof(this->pos[i]);
      }
     return offset;
    }

    const char * getType(){ return "projectx/MotorOutSingleArray"; };
    const char * getMD5(){ return "de04d0ab49b6de06afa1f92fbae073c5"; };

  };

}
#endif