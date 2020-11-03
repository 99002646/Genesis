#ifndef __ACCOUNT_H
#define __ACCOUNT_H
#include<string>
class Account {
	std::string m_accNumber; 
	std::string m_accName;
	double m_balance;

public:
	Account();
	Account(std::string, std::string, double);
	Account(const Account&);
	void credit(double);
	void debit(double);
	std::string getCustomerId();
	std::string getCustomerName();
	double getBalance() const;
	void display();
    std::string getId() ;
    std::string getName() const;
        
};

#endif
