#ifndef _ROS_SERVICE_Speech_h
#define _ROS_SERVICE_Speech_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

static const char SPEECH[] = "projectx/Speech";

  class SpeechRequest : public ros::Msg
  {
    public:
      const char* data;

    SpeechRequest():
      data("")
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
     return offset;
    }

    const char * getType(){ return SPEECH; };
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; };

  };

  class SpeechResponse : public ros::Msg
  {
    public:
      const char* dondur;

    SpeechResponse():
      dondur("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_dondur = strlen(this->dondur);
      memcpy(outbuffer + offset, &length_dondur, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dondur, length_dondur);
      offset += length_dondur;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_dondur;
      memcpy(&length_dondur, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dondur; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dondur-1]=0;
      this->dondur = (char *)(inbuffer + offset-1);
      offset += length_dondur;
     return offset;
    }

    const char * getType(){ return SPEECH; };
    const char * getMD5(){ return "a9aa7fd6202b23c0accb5c2e77ed20be"; };

  };

  class Speech {
    public:
    typedef SpeechRequest Request;
    typedef SpeechResponse Response;
  };

}
#endif
