#include<cmath>
class Shape {
  public:
  virtual double area() { return 0; }
  virtual double circumference() { return 0; }
};
class Circle : public Shape {
  double radius;

public:
  const static double PI = 22.0/7.0;
  Circle(int r):radius(r) { }
  double area() { return PI * radius * radius; }
  double circumference() { return 2 * PI * radius }
};
class Rectangle : public Shape {
  int  length;
  int  breadth;

public:
  Rectangle(int l,int b):length(l),breadth(b) { }
  double area() { return length * breadth; }
  double circumference() { return 2 * (length + breadth); }
};
class Triangle : public Shape {
  int  a;
  int  b;
  int  c;

public:
  Triangle(int x,int y,int z):a(x),b(y),c(z){}
  double area() {  
    double s = (a+b+c)/2;
    return sqrt ( s * (s-a) * (s-b) * (s-c) );
  } 
  double circumference() { return a + b + c; }
};
void compute(Shape* ptr);
void compute(Shape& ptr);
int main() {
  Circle c1(7);
  Rectangle r1(10,8);
  Triangle t1(3,4,5);
  Shape *ps = &c1; // new Circle(7);
  Shape &ref = c1;
  ps->area();
  ps->circumference();
  ref.area();
  ref.circumference();
  // delete ps;
  Shape *ptr;
  bool cond;
  if(cond)
    ptr = new Circle(7);
  else
    ptr = new Rectangle(10,8);
  //ptr->area()
  //ptr->circumference()
  compute(&c1); //Circle object
  compute(&t1); //Triangle object
  compute(c1); //Circle object
  compute(r1); //Rectangle object
  return 0;
}
void compute(Shape* ptr) {
  //print ptr->area();
  //print ptr->circumference();
}
void compute(Shape& ref) {
  //print ref.area();
  //print ref.circumference();
}
