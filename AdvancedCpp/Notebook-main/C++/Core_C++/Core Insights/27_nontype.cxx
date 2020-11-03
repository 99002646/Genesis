#include<iostream>
template <typename T, size_t maxsize> 
class MyStack {
  T arr[maxsize];
  int top;

public:
  MyStack() : top(-1) {}
  void push(T val) {
    arr[++top] = val;  // TODO: overflow
  }
  T pop() {
    return arr[top--]; // TODO: underflow
  }
};

int main() {
  MyStack<int, 10> s1;
  MyStack<float, 8> s2;
  MyStack<double, 12> s3;
  MyStack<int, 8> s4;
  return 0;
}

/**
#include<iostream>
template <typename T> class MyStack {
  T *arr
  int maxlen;
  int top;

public:
  MyStack(int len) :maxlen(len),top(-1) {
    arr = new T[maxlen];
  }
  ~MyStack() {
    delete[] arr;
  }
  void push(T val) {
    arr[++top] = val; // TODO: overflow
  }
  T pop() {
    return arr[top--]; // TODO: underflow
  }
};

int main() {
  MyStack<int> s1(10);
  MyStack<float> s2(8);
  MyStack<double> s3(15);
  MyStack<int> s4(12);
  MyStack<double> s5(12);
  return 0;
}
