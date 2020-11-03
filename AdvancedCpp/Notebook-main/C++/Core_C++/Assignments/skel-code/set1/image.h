#ifndef __IMAGE_H
#define __IMAGE_H

class Image {
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  public:
  Image();
  Image(int,int,int,int);
  Image(const Image&);
  void move(int,int);
  void scale(int);
  void resize(int,int);
  void dispay() const;
};

#endif
