#include<list>
#include<iostream>
#include"point.h"
class STLPoint {
   std::list<Point> points;
   public:

   void addPoint(int,int);
   void displayAll();
   int  countAll(Quadrant);
   int countAllPoints(){return points.size();}
   int  displayPointOnCircle(int);
   int  displayPointinCircle(int);
};
