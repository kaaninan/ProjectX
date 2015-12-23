#ifndef _ROS_touchosc_msgs_Tabpage_h
#define _ROS_touchosc_msgs_Tabpage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace touchosc_msgs
{

  class Tabpage : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* tabpage;

    Tabpage():
      header(),
      tabpage("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_tabpage = strlen(this->tabpage);
      memcpy(outbuffer + offset, &length_tabpage, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tabpage, length_tabpage);
      offset += length_tabpage;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_tabpage;
      memcpy(&length_tabpage, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tabpage; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tabpage-1]=0;
      this->tabpage = (char *)(inbuffer + offset-1);
      offset += length_tabpage;
     return offset;
    }

    const char * getType(){ return "touchosc_msgs/Tabpage"; };
    const char * getMD5(){ return "4213ffb5a43e14111c66fe04a2d8f4ec"; };

  };

}
#endif