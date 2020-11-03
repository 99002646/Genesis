#ifndef __POINT_H
#define __POINT_H

enum Quadrant {
  Q1,
  Q2,
  Q3,
  Q4
};

class Point {
  int m_x;
  int m_y;
  public:
  Point();
  Point(int,int);
  Point(const Point&);
  double distanceFromOrigin()  const;
  Quadrant quadrant() const;
  bool isOrigin() const;
  bool isOnXAxis() const;
  bool isOnYAxis() const;
  void display() const;
  int getx() const{return m_x;}
  int gety() const{return m_y;}
};

#endif
