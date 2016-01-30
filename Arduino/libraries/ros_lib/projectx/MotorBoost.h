#ifndef _ROS_SERVICE_MotorBoost_h
#define _ROS_SERVICE_MotorBoost_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

static const char MOTORBOOST[] = "projectx/MotorBoost";

  class MotorBoostRequest : public ros::Msg
  {
    public:
      const char* in_data;

    MotorBoostRequest():
      in_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_in_data = strlen(this->in_data);
      memcpy(outbuffer + offset, &length_in_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->in_data, length_in_data);
      offset += length_in_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_in_data;
      memcpy(&length_in_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_in_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_in_data-1]=0;
      this->in_data = (char *)(inbuffer + offset-1);
      offset += length_in_data;
     return offset;
    }

    const char * getType(){ return MOTORBOOST; };
    const char * getMD5(){ return "aa8dbb3b5f7aa1f6837fee066be612c8"; };

  };

  class MotorBoostResponse : public ros::Msg
  {
    public:
      const char* out_data;

    MotorBoostResponse():
      out_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_out_data = strlen(this->out_data);
      memcpy(outbuffer + offset, &length_out_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->out_data, length_out_data);
      offset += length_out_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_out_data;
      memcpy(&length_out_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_out_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_out_data-1]=0;
      this->out_data = (char *)(inbuffer + offset-1);
      offset += length_out_data;
     return offset;
    }

    const char * getType(){ return MOTORBOOST; };
    const char * getMD5(){ return "616a79ae09e0166195481d0fb8b7b20c"; };

  };

  class MotorBoost {
    public:
    typedef MotorBoostRequest Request;
    typedef MotorBoostResponse Response;
  };

}
#endif
