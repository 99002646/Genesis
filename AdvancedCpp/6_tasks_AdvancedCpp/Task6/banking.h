#include<list>
#include<iostream>
#include"account.h"
#include"SavingsAccount.h"
#include"CreditAccount.h"
class Banking {
   std::list<SavingsAccount> accounts;
   public:
   void addAccount(std::string,std::string,double);
   void removeAccountById(std::string); //by id
   void displayAll();
   int  countAll(){return accounts.size();};
   SavingsAccount* findAccountById(std::string);
   SavingsAccount* findAccountByName(std::string);
   double findAverageBalance();
   SavingsAccount& findAccountWithMaxBalance();
   int countAccountsByBalanceRange(double,double);
   int countAccountsByBalanceLess(double);
};





