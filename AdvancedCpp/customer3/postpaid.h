#ifndef __POSTPAID_H
#define __POSTPAID_H

#include<string>
#include<cstdint>

#include "customer3.h"

class PostpaidCustomer : public CustomerBase {
  void billPay(double);
  int m_billDate;
  public:
  PostpaidCustomer();
  PostpaidCustomer(std::string,std::string,std::string,double);
  PostpaidCustomer(std::string,std::string,std::string);
  void credit(double) override;           //recharge or billPay
  void makeCall(double) override;
  double getBalance() const;
  void display() const  override;

};

#endif
