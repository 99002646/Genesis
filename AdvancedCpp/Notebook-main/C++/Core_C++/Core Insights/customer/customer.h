#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include<iostream>
#include<string>
class Customer {
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  void init(int, std::string,std::string, double);
  void recharge(double);
  void makeCall(int);
  void display();
  double getBalance();
};
#endif
