#define MAX_SIZE 10
#include<iostream>
template <typename T> class MyStack {
  T arr[MAX_SIZE]; // T *arr;
  int maxlen;
  int top;

public:
  MyStack(int len) : maxlen(len), top(-1) {
    // arr = new T[maxlen];
  }
  /*~MyStack() {
    delete[] arr;
  }*/
  void push(T val) {
    arr[++top] = val; // TODO: overflow
  }
  T pop() {
    return arr[top--]; // TODO: underflow
  }
  //isEmpty
  //isFull
};

int main() {
  MyStack<int> s1(10);
  s1.push(10);
  s1.push(20);
  s1.push(30);
  std::cout << s1.pop();
  MyStack<double> s2(8);
  s2.push(1.1);
  s2.push(2.2);
  std::cout << s2.pop() << "\n";
}
