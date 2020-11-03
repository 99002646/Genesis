#include <iostream>
class Shape {
public:
  virtual double area()=0;
  virtual double circumference()=0;
  void print() {  
    //some code
  }
};
class Polygon : public Shape {
  public:

};
const double pi = 22.0 / 7.0;
class Circle : public Shape {
  double radius;
public:
  
  Circle(int r) : radius(r) {}
  double area() {
    std::cout << "Circle::area\n";
    return pi * radius * radius;
  }
  double circumference() {
    std::cout << "Circle::circumference\n";
    return 2 * pi * radius;
  }
};

int main() {
  //Shape s1;
  Circle c1(7);
  Shape *ps = &c1; // new Circle(7);
  Shape &ref = c1;
  ps->area();
  ps->circumference();
  ref.area();
  ref.circumference();
  // delete ps;
  // Shape *p1=new Shape();
  Shape *p1 = new Circle(7);
  p1->area();
  p1->circumference();

  Shape *ptr;
  //Shape obj;   
  Circle obj(7);
  ptr = &obj;
  ptr->area();
  obj.area();
  return 0;
}
/* In case of virtual functions, binding takes place
   based on actual objects pointed/binded
   but on static type of pointer/reference
*/
