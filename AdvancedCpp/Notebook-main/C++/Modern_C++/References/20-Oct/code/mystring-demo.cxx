/**
 * Non Trivial class - MyString example
 * Rule of three/zero
 * Scope of overloading more operators
 */
#include <cstring>
#include <iostream>
class MyString {
  char *m_buf;
  int m_len;

public:
  MyString() : m_buf(nullptr), m_len(0) {}
  MyString(const char *pbuf) {
    m_len = strlen(pbuf);
    m_buf = new char[m_len + 1];
    strcpy(m_buf, pbuf);
  }
  MyString(const MyString& ref) : m_len(ref.m_len) {
    m_buf = new char[m_len + 1];
    strcpy(m_buf, ref.m_buf);
  }
  MyString(MyString&& rr) {
    m_len=rr.m_len;
    m_buf=rr.m_buf;
    rr.m_len=0;
    rr.m_buf=nullptr;
  }
  ~MyString() {
    if (m_len > 0) // m_buf != nullptr
      delete[] m_buf;
  }
  MyString &operator=(const MyString& ref) {
    if(this == &ref) return *this;        //self assignment
    if(m_buf!=nullptr) delete[] m_buf;    //??
    m_len = ref.m_len;
    m_buf = new char[m_len + 1];
    strcpy(m_buf, ref.m_buf);
    return *this;
  }
  MyString& MyString::operator=(MyString&& rr) {
    assert(this != rr);
    if(m_buf!=nullptr) delete[] m_buf;
    m_len=rr.m_len;
    m_buf=rr.m_buf;
    rr.m_len=0;
    rr.m_buf=nullptr;
    return *this;
  }
  int length() const { return m_len; }
  void display() const { std::cout << m_buf << "\n"; }
};
int main() {
  MyString s1("abcdxyz");    //param
  s1.display();
  std::cout << "length: " << s1.length() << "\n";

  MyString s2(std::move(s1));
  s2.display();
  
  MyString s3;
  s3 = std::move(s2);
  
  MyString s4("hello");
  s4 = std::move(s3);
  
  return 0;
}

/** TODO : Overload other operators in MyString class
    MyString s1("abcd");
    s3 = s1 + s2;
    s4 = s1 + "xyz";
    s3 == s2;
    s1+="1234";
    s2 = "hello";
    s1 < s2
    s1 > s1
    std::cout << s1;
    std::cin >> s2;
*/
