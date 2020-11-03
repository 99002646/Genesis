#ifndef __COLOR_H
#define __COLOR_H

typedef enum {
  RED=0xFF0000,
  GREEN=0x00FF00,
  BLUE=0x0000FF,
  WHITE=0xFFFFFF,
  BLACK=0x0
  //TODO: some more colors
}color_t;

class Color {
  int m_r;
  int m_g;
  int m_b;
  public:
  Color();
  Color(int,int,int);       //r,g,b values
  Color(int);               //Hex value as int
  Color(std::string);       //Hex value as string
  Color(color_t);           //enum 
  void invert();
  void display() const;
};

#endif
