#include<string>
#include<map>
#include<iostream>
#include<functional>

class Adder {
public:
  int operator()(int a, int b) { return a + b; }
  int operator()(int a, int b,int c) { return a + b + c; }
};
class MyCompare {
    public:
    bool operator() (int key1, int key2) {
        return key1 > key2;
    }
}; 
int main() {
  Adder sum;        //Function object
  int a=10,b=20,c;
  c=sum(a,b);       //sum.operator() (a,b)

  //std::map<int, std::string, MyCompare> cities;
  std::map<int, std::string, std::greater<int>> cities;
  cities.insert(std::make_pair(103,"Bengaluru"));
  cities.insert(std::make_pair(105,"Mumbai"));
  cities.insert(std::make_pair(101,"Pune"));
  cities.insert(std::make_pair(102,"Delhi"));
  cities.insert(std::make_pair(104,"Chennai"));

  for(auto p : cities) 
    std::cout << p.first << "," << p.second << "\n";

  return 0;
}