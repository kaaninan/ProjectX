#ifndef _ROS_projectx_TouchOSC_Common_h
#define _ROS_projectx_TouchOSC_Common_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "projectx/CommonProperties.h"

namespace projectx
{

  class TouchOSC_Common : public ros::Msg
  {
    public:
      std_msgs::Header header;
      projectx::CommonProperties common;

    TouchOSC_Common():
      header(),
      common()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->common.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->common.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "projectx/TouchOSC_Common"; };
    const char * getMD5(){ return "02b274e5694f91306b366760eaca24ef"; };

  };

}
#endif