
enum Quadrant {
    Q1=1,
    Q2,
    Q3,
    Q4
};

//TODO: template syntax to make point as generic class
class MyPoint {
  //TODO: data members - x, y
  public:
  //TODO: suitable constructors
  //TODO: operations : distanceFromOrigin, getQuadrant
  //TODO: operations : move etc.
  //TODO: display function
};
int main() {
    MyPoint<int> p1(3,4);
    int d1 = p1.distanceFromOrigin();
    std::cout << d1 << "\n";
    p1.display();
    Quadrant qr = p1.getQuadrant();
    std::cout << qr << "\n";
    p1.move(2,3);      //Point will move from (3,4) to (5,8)

    MyPoint<int> p2;   //Assume (1,1) as default position
    p2.move(3,4);      //Will move from (1,1) to (4,5)
    qr = p2.getQuadrant();
    std::cout << qr << "\n";
    p2.display();

    MyPoint<float> p3(-2.3f, -4.8f);
    qr = p3.getQuadrant();
    std::cout << qr << "\n";

    //TODO: create another Point of double type
    //      and test the avaiable functionality

    return 0;
}
