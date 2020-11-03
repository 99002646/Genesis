#include<fstream>
int main() {
  std::ofstream fout("sample.txt");
  // std::ofstream fout;
  // fout.open("sample.txt");
  fout << "Hello C++\n";
  fout.write("Abcdxyz", 7);
  for (int i = 0; i < 6; i++)
    fout.put(65 + i);
  fout.close();
  return 0;
}
