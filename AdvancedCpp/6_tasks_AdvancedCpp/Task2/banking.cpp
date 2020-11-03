#include "account.h"
#include "banking.h"
#include<list>
#include<iostream>
#include<algorithm>

double sum=0;
void Banking::addAccount(std::string id,std::string name,double bal) {
   accounts.push_back(Account(id,name,bal));

}
void Banking::displayAll() {

 auto var =std::for_each(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return  r1.display();}
);
}
double Banking::findAverageBalance()
{
auto var =std::for_each(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return ((sum+=r1.getBalance()) );}
);
return sum/3;
}

int Banking::countAccountsByBalanceRange(double min,double max) 
{  
 auto var =std::count_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return ((r1.getBalance()>=min) && (r1.getBalance()<=max) );}
);
return var;
}

Account* Banking::findAccountById(std::string keyId) 
{
    auto var =std::find_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return (r1.getId()==keyId );}
);
if(&(*var)!= NULL)
  return &(*var);
else 
return NULL;
}

void Banking::removeAccountById(std::string keyId) 
{
   auto pos=std::find_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return  (r1.getId() == keyId) ;}
);
    cout<<pos->getId();
    if(&(*pos)!=NULL)
    accounts.erase(pos);
}

Account* Banking::findAccountWithMinBalance() {
   auto var =std::min_element(accounts.begin(),accounts.end(),[=] (Account&  r1, Account& r2) 
{ return ( r1.getBalance() < r2.getBalance());}
);
if(&(*var)!= NULL)
  return &(*var);
else 
return NULL;
}
  
  
  

        

