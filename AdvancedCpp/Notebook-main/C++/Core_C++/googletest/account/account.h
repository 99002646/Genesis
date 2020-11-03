#include<string>
class Account {
  int customerId; // ideally to be of string type
  std::string customerName;
  double balance;

public:
  Account();
  Account(int, std::string, double);
  Account(const Account &);
  void credit(double);
  void debit(double);
  int getCustomerId();
  std::string getCustomerName();
  double getBalance() const;
  void display();
};
