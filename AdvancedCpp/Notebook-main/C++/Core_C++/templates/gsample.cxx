template <typename T> 
class Sample {
  T m_x;
  T m_y;

public:
  Sample(T x, T y) : m_x(x), m_y(y) {}
  void setxy(T x, T y) {
    m_x = x;
    m_y = y;
  }
  T getx() { return m_x; }
  T gety() { return m_y; }
  T getsum() { return m_x + m_y; }
};

int main() {
  Sample<int> s1(10, 20);
  Sample<float> s2(2.3f, 4.5f);
  Sample<double> s3(2.3, 5.6);
  Sample<int> s4(11, 12);
}
