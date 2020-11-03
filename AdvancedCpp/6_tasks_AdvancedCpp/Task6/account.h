#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include<string>
//using namespace std;
class AccountBase {
protected:
  std::string m_accNumber;
  std::string m_accName;
  double m_balance;
  public:
  AccountBase();
  AccountBase(std::string,std::string,double);
  AccountBase(std::string,std::string);
  AccountBase(const AccountBase&);
  virtual void debit(double)=0;
  virtual void credit(double)=0;
  virtual void display() const = 0;
  double getBalance() const;
  void setbalance(double);
  std::string getName() const;
  std::string getNumber() const;
};
#endif

