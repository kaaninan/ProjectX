#ifndef _ROS_SERVICE_SensorTemp_h
#define _ROS_SERVICE_SensorTemp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

static const char SENSORTEMP[] = "projectx/SensorTemp";

  class SensorTempRequest : public ros::Msg
  {
    public:

    SensorTempRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SENSORTEMP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SensorTempResponse : public ros::Msg
  {
    public:
      float temp1;
      float temp2;
      float nem;

    SensorTempResponse():
      temp1(0),
      temp2(0),
      nem(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->temp1);
      offset += serializeAvrFloat64(outbuffer + offset, this->temp2);
      offset += serializeAvrFloat64(outbuffer + offset, this->nem);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temp1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temp2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nem));
     return offset;
    }

    const char * getType(){ return SENSORTEMP; };
    const char * getMD5(){ return "813b115f2598f32dc74cb170a02d630f"; };

  };

  class SensorTemp {
    public:
    typedef SensorTempRequest Request;
    typedef SensorTempResponse Response;
  };

}
#endif
