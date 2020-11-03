#ifndef __BANKING_H
#define __BANKING_H
#include"account.h"
#include<list>
using namespace std;
class Banking {
   std::list<Account> accounts;
public:
   void addAccount(std::string,std::string,double);
   void displayAll();
   double findAverageBalance();
   int countAccountsByBalanceRange(double,double);
   void removeAccountById(std::string); //by id
   Account* findAccountById(std::string);
   Account* findAccountWithMinBalance();
 int  countAll(){return accounts.size();}
};



#endif
