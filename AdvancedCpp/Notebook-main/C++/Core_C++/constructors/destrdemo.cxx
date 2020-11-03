#include <iostream>
class Box {
private:
  int length;
  int breadth;
  int height;

public:
  Box(int x, int y, int z):length(x),breadth(y),height(z) { }
  Box():length(0),breadth(0),height(0) { }
  ~Box() {
    std::cout << "Box class destructor" << "\n";
  }
  int Box::getVolume() const { return length * breadth * height; }
  void Box::display() const {
    //print length, breadth, height
  }
};
int main() {
  Box b1(10, 12, 5);
  std::cout << b1.getVolume() << "\n";

  Box *pb = new Box(1, 8, 6);

  Box b2;
  Box b3(b1);
  delete pb;
  return 0;
}
