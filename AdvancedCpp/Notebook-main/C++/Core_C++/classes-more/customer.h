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
  Customer(int, std::string,std::string, double);
  Customer(int, std::string,std::string);
  void recharge(double);
  void makeCall(int);
  void display() const;
  double getBalance() const;
};
#endif
