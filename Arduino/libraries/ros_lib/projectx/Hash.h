#ifndef _ROS_projectx_Hash_h
#define _ROS_projectx_Hash_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class Hash : public ros::Msg
  {
    public:
      int64_t id;
      int64_t deger;

    Hash():
      id(0),
      deger(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int64_t real;
        uint64_t base;
      } u_deger;
      u_deger.real = this->deger;
      *(outbuffer + offset + 0) = (u_deger.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deger.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deger.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deger.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_deger.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_deger.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_deger.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_deger.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->deger);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int64_t real;
        uint64_t base;
      } u_deger;
      u_deger.base = 0;
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_deger.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->deger = u_deger.real;
      offset += sizeof(this->deger);
     return offset;
    }

    const char * getType(){ return "projectx/Hash"; };
    const char * getMD5(){ return "c58586854baf73aa03696ec20686d5f2"; };

  };

}
#endif