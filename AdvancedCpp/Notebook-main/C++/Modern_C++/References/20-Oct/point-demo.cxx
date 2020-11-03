class Point {
  int m_x;
  int m_y;
  public:
  //TODO
};
int main() {
  Point p1(2,3);
  Point p2(p1);
  Point p3;
  p3=p1;
  
  Point p4(std::move(p2));  //p2 --> (0,0)
  Point p5;
  p5=std::move(p4);         //p4 --> (0,0)
 
  return 0; 
}
  
