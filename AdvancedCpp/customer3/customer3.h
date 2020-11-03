#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include<string>
#include<cstdint>

enum AccountType {
  Prepaid,
  Postpaid
};

class CustomerBase {
    //protected:
  std::string m_custId;
  std::string m_custName;
  std::string m_phone;
  double m_balance;
  AccountType m_type;
  public:
  CustomerBase();
  CustomerBase(std::string,std::string,std::string,double);
  CustomerBase(std::string,std::string,std::string);
  CustomerBase(const CustomerBase&);
  virtual  void credit(double)=0;
  virtual  void makeCall(double)=0;
  void setBalance(double) ;
  double getBalance() const;
  virtual void display() const=0;
};

#endif

