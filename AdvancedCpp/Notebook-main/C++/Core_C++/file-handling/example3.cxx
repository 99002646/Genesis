#include<fstream>
#include<iostream>
int main() {
  int maxlen=20;
  char buf[maxlen];
  std::ifstream fin("alpha.txt"); // binary mode?
  fin.read(buf, 6);               // print buf
  fin.seekg(10, std::ios::beg);
  fin.read(buf, 5);
  std::cout.write(buf, 5);
  fin.seekg(-8, std::ios::cur);
  fin.read(buf, 5);
  std::cout.write(buf, 5);
  std::cout << fin.tellg() << "\n";
  fin.seekg(-6, std::ios::end);
  std::cout << fin.tellg() << "\n";
  fin.close();
  return 0;
}
