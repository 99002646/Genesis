template <typename T> class Sample {
  T m_x;
  T m_y;

public:
  Sample(T x, T y);
  T getx() const;
  T gety() const;
  T getsum() const;
  void display() const;
};

template<typename T>
Sample<T>::Sample(T x, T y):m_x(x),m_y(y) { }

template<typename T>
T Sample<T>::getx() const {
  return m_x; 
}

template<typename T>
T Sample<T>::gety() const {
  return m_y; 
}

template<typename T>
T Sample<T>::getsum() const {
  return m_x + m_y; 
}

template<typename T>
void Sample<T>::display() const {
  // print m_x, m_y
}

int main() {
  Sample<int> s1(10, 20);
  Sample<float> s2(2.3f, 4.5f);
  Sample<double> s3(2.3, 5.6);
  Sample<int> s4(11, 12);
}
