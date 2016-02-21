#ifndef _ROS_projectx_Sensor_h
#define _ROS_projectx_Sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class Sensor : public ros::Msg
  {
    public:
      int64_t dis;
      int64_t ldr;
      int64_t gaz;
      float temp;
      float temp_out;
      float humidity;

    Sensor():
      dis(0),
      ldr(0),
      gaz(0),
      temp(0),
      temp_out(0),
      humidity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_dis;
      u_dis.real = this->dis;
      *(outbuffer + offset + 0) = (u_dis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dis.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dis.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dis.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dis.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dis.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dis);
      union {
        int64_t real;
        uint64_t base;
      } u_ldr;
      u_ldr.real = this->ldr;
      *(outbuffer + offset + 0) = (u_ldr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ldr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ldr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ldr.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ldr.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ldr.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ldr.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ldr.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ldr);
      union {
        int64_t real;
        uint64_t base;
      } u_gaz;
      u_gaz.real = this->gaz;
      *(outbuffer + offset + 0) = (u_gaz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gaz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gaz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gaz.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gaz.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gaz.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gaz.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gaz.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gaz);
      offset += serializeAvrFloat64(outbuffer + offset, this->temp);
      offset += serializeAvrFloat64(outbuffer + offset, this->temp_out);
      offset += serializeAvrFloat64(outbuffer + offset, this->humidity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_dis;
      u_dis.base = 0;
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dis.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dis = u_dis.real;
      offset += sizeof(this->dis);
      union {
        int64_t real;
        uint64_t base;
      } u_ldr;
      u_ldr.base = 0;
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ldr.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ldr = u_ldr.real;
      offset += sizeof(this->ldr);
      union {
        int64_t real;
        uint64_t base;
      } u_gaz;
      u_gaz.base = 0;
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gaz.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gaz = u_gaz.real;
      offset += sizeof(this->gaz);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temp_out));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->humidity));
     return offset;
    }

    const char * getType(){ return "projectx/Sensor"; };
    const char * getMD5(){ return "949ea192333261d5f2a0646fc476a04c"; };

  };

}
#endif