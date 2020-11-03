#ifndef __ACCOUNT_H
#define __ACCOUNT_H

class Account {
  std::string m_id;
  std::string m_name;
  double m_balance;
  public:
  Account();
  Account(std::string, std::string, double);
  void credit(double);
  void debit(double);
  double getBalance() const;
  void display() const;
  friend std::ostream& operator<<(std::ostream& rout, const Account& ref);
};
#endif
