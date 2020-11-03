#include<fstream>
#include<iostream>

int main() {
  std::ifstream fin("alpha.txt");
  // std::ifstream fin;
  // fin.open("alpha.txt");
  char buf[64];
  int maxlen=40;
  char ch;
  std::string str;
  //fin >> buf;
  //fin.read(buf, maxlen);
  //std::getline(fin, str);
  //std::cout << buf << "\n";
  
  
  while (1) {
    fin.get(ch);
    if (fin.eof())
      break;
    std::cout.put(ch);
  }
  fin.close();
}
