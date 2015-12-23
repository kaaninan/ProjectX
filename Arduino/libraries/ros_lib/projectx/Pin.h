#ifndef _ROS_SERVICE_Pin_h
#define _ROS_SERVICE_Pin_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

static const char PIN[] = "projectx/Pin";

  class PinRequest : public ros::Msg
  {
    public:
      const char* name;

    PinRequest():
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return PIN; };
    const char * getMD5(){ return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class PinResponse : public ros::Msg
  {
    public:
      int64_t pin;

    PinResponse():
      pin(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_pin;
      u_pin.real = this->pin;
      *(outbuffer + offset + 0) = (u_pin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pin);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_pin;
      u_pin.base = 0;
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pin = u_pin.real;
      offset += sizeof(this->pin);
     return offset;
    }

    const char * getType(){ return PIN; };
    const char * getMD5(){ return "13ce2e1fd6796d00dec37deecb854c69"; };

  };

  class Pin {
    public:
    typedef PinRequest Request;
    typedef PinResponse Response;
  };

}
#endif
