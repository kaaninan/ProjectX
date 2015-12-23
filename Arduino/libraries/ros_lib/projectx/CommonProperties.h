#ifndef _ROS_projectx_CommonProperties_h
#define _ROS_projectx_CommonProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class CommonProperties : public ros::Msg
  {
    public:
      const char* tabpage;
      const char* name;
      int16_t x;
      int16_t y;
      uint16_t width;
      uint16_t height;
      const char* visible;
      const char* color;

    CommonProperties():
      tabpage(""),
      name(""),
      x(0),
      y(0),
      width(0),
      height(0),
      visible(""),
      color("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_tabpage = strlen(this->tabpage);
      memcpy(outbuffer + offset, &length_tabpage, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tabpage, length_tabpage);
      offset += length_tabpage;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int16_t real;
        uint16_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int16_t real;
        uint16_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->y);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->height);
      uint32_t length_visible = strlen(this->visible);
      memcpy(outbuffer + offset, &length_visible, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->visible, length_visible);
      offset += length_visible;
      uint32_t length_color = strlen(this->color);
      memcpy(outbuffer + offset, &length_color, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->color, length_color);
      offset += length_color;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_tabpage;
      memcpy(&length_tabpage, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tabpage; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tabpage-1]=0;
      this->tabpage = (char *)(inbuffer + offset-1);
      offset += length_tabpage;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int16_t real;
        uint16_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int16_t real;
        uint16_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y = u_y.real;
      offset += sizeof(this->y);
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
      this->height =  ((uint16_t) (*(inbuffer + offset)));
      this->height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->height);
      uint32_t length_visible;
      memcpy(&length_visible, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_visible; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_visible-1]=0;
      this->visible = (char *)(inbuffer + offset-1);
      offset += length_visible;
      uint32_t length_color;
      memcpy(&length_color, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color-1]=0;
      this->color = (char *)(inbuffer + offset-1);
      offset += length_color;
     return offset;
    }

    const char * getType(){ return "projectx/CommonProperties"; };
    const char * getMD5(){ return "2c6057f4de35b509307640ef1d0f3aac"; };

  };

}
#endif