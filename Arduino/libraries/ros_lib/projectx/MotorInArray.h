#ifndef _ROS_projectx_MotorInArray_h
#define _ROS_projectx_MotorInArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class MotorInArray : public ros::Msg
  {
    public:
      uint8_t id_length;
      int64_t st_id;
      int64_t * id;
      uint8_t temp_length;
      int64_t st_temp;
      int64_t * temp;
      uint8_t voltage_length;
      int64_t st_voltage;
      int64_t * voltage;
      uint8_t pos_length;
      int64_t st_pos;
      int64_t * pos;

    MotorInArray():
      id_length(0), id(NULL),
      temp_length(0), temp(NULL),
      voltage_length(0), voltage(NULL),
      pos_length(0), pos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = id_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < id_length; i++){
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
      *(outbuffer + offset++) = temp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temp_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_tempi;
      u_tempi.real = this->temp[i];
      *(outbuffer + offset + 0) = (u_tempi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tempi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tempi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tempi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tempi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tempi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tempi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tempi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temp[i]);
      }
      *(outbuffer + offset++) = voltage_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < voltage_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_voltagei;
      u_voltagei.real = this->voltage[i];
      *(outbuffer + offset + 0) = (u_voltagei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltagei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltagei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltagei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_voltagei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_voltagei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_voltagei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_voltagei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->voltage[i]);
      }
      *(outbuffer + offset++) = pos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_length; i++){
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
      uint8_t id_lengthT = *(inbuffer + offset++);
      if(id_lengthT > id_length)
        this->id = (int64_t*)realloc(this->id, id_lengthT * sizeof(int64_t));
      offset += 3;
      id_length = id_lengthT;
      for( uint8_t i = 0; i < id_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_id;
      u_st_id.base = 0;
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_id = u_st_id.real;
      offset += sizeof(this->st_id);
        memcpy( &(this->id[i]), &(this->st_id), sizeof(int64_t));
      }
      uint8_t temp_lengthT = *(inbuffer + offset++);
      if(temp_lengthT > temp_length)
        this->temp = (int64_t*)realloc(this->temp, temp_lengthT * sizeof(int64_t));
      offset += 3;
      temp_length = temp_lengthT;
      for( uint8_t i = 0; i < temp_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_temp;
      u_st_temp.base = 0;
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_temp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_temp = u_st_temp.real;
      offset += sizeof(this->st_temp);
        memcpy( &(this->temp[i]), &(this->st_temp), sizeof(int64_t));
      }
      uint8_t voltage_lengthT = *(inbuffer + offset++);
      if(voltage_lengthT > voltage_length)
        this->voltage = (int64_t*)realloc(this->voltage, voltage_lengthT * sizeof(int64_t));
      offset += 3;
      voltage_length = voltage_lengthT;
      for( uint8_t i = 0; i < voltage_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_voltage;
      u_st_voltage.base = 0;
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_voltage = u_st_voltage.real;
      offset += sizeof(this->st_voltage);
        memcpy( &(this->voltage[i]), &(this->st_voltage), sizeof(int64_t));
      }
      uint8_t pos_lengthT = *(inbuffer + offset++);
      if(pos_lengthT > pos_length)
        this->pos = (int64_t*)realloc(this->pos, pos_lengthT * sizeof(int64_t));
      offset += 3;
      pos_length = pos_lengthT;
      for( uint8_t i = 0; i < pos_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_pos;
      u_st_pos.base = 0;
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_pos = u_st_pos.real;
      offset += sizeof(this->st_pos);
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "projectx/MotorInArray"; };
    const char * getMD5(){ return "3e33506fbb9fc6f0584fe4650dda8219"; };

  };

}
#endif