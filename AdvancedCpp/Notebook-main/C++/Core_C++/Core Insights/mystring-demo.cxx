#include<iostream>
#include<cstring>
class MyString {
  char *m_buf;   // char m_buf[20];
  int m_len;
  public:
  MyString(const char* ps) {
    m_len = strlen(ps);
    m_buf = new char[m_len+1];
    strcpy(m_buf, ps);
  }
  MyString():m_buf(nullptr),m_len(0) { }
  ~MyString() {
    if(m_len>0)
      delete[] m_buf;
  }
  int length() const { return m_len; }
  void display() const { std::cout << m_buf << "\n"; }
};
int main() {
  MyString s1("abcdxyz");
  MyString s2("hello c++, how are you");

  MyString s3(s1);
  std::cout << s3.length() << "\n";
  s3.display();
}