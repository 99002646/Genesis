#include<utility>
class Point {
  int m_x;
  int m_y;
  public:
  Point(int x,int y):m_x(x),m_y(y) { }
  void printxy() {  }
};
template<typename T>
class my_smart_ptr {
  T *m_ptr;  //=nullptr;
  public:
  my_smart_ptr():m_ptr(nullptr) {  }
  my_smart_ptr(T *ptr):m_ptr(ptr) {  }
  ~my_smart_ptr() {
    if(m_ptr!=nullptr)
      delete m_ptr;
  }
  my_smart_ptr(const my_smart_ptr&)=delete;
  my_smart_ptr& operator=(const my_smart_ptr&)=delete;
  my_smart_ptr(my_smart_ptr&& rr) {
    m_ptr=rr.m_ptr;
    rr.m_ptr=nullptr;
  }
  my_smart_ptr& operator=(my_smart_ptr&& rr) {
    //TODO:self check
    m_ptr=rr.m_ptr;
    rr.m_ptr=nullptr;
    return *this;
  }
  T* operator->() { return m_ptr; }
  T& operator*() { return *m_ptr; }
  //release
  //reset
  T* get() { return m_ptr; }  
};
int main() {
   my_smart_ptr<Point> up1(new Point(2,3));
   
   my_smart_ptr<Point> up2(std::move(up1));
   //up2 = std::move(up1);
   up2->printxy();
   Point p1 = *up2;   //Point& ref = *up2;
   
}
   
