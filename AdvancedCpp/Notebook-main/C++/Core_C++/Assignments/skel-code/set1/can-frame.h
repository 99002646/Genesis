#ifndef __CANFRAME_H
#define __CANFRAME_H

constexpr int max_dlc = 8;

class CANFrame {
  uint32_t m_id;
  uint8_t m_dlc;
  uint8_t m_data[max_dlc];
  public:
  CANFrame();
  CANFrame(uint8_t,uint8_t,uint8_t*);   //id, dlc and data
  CANFrame(uint8_t,uint8_t);            //id, dlc, data will be random
  CANFrame(std::string);                //65#A1B2C3D4
  int id() const;
  int dlc() const;
  uint8_t* data() const;
  void dispay() const;
};

#endif
