
#include"banking.h"
#include"account.h"
#include"SavingsAccount.h"
#include"CreditAccount.h"
#include<list>
#include<iostream>
#include<utility>
#include<algorithm>
#include <numeric>

void Banking::addAccount(std::string id,std::string name,double bal) {
   accounts.push_back(SavingsAccount(id,name,bal));
}

void Banking::displayAll() {
   std::list<SavingsAccount>::iterator iter;
   /*
   for(iter=accounts.begin();iter!=accounts.end();++iter)
       iter->display();
       */

     //USING STL ALGORITHMS
     std::for_each(accounts.begin(),accounts.end(),[](SavingsAccount &ref){return ref.display();});
}

double Banking:: findAverageBalance(){
	
	double sum=0;
	int count=0;
  /*std::list<SavingsAccount>::iterator it;
	for(it=accounts.begin();it!=accounts.end();++it){
       		sum+=it->getBalance();
		count++;
  */
    //USING STL ALGORITHMS
    auto tot_sum = std::accumulate(accounts.begin(),accounts.end(),0,[](int sum,SavingsAccount &ref){return ref.getBalance()+sum;});
    count = std::count_if(accounts.begin(),accounts.end(),[](const SavingsAccount& ref){return ref.getBalance();});
    return (double)(tot_sum/count);
}

int Banking::countAccountsByBalanceRange(double min,double max){
	
	int count=0;
  /*std::list<SavingsAccount>::iterator it;
	for(it=accounts.begin();it!=accounts.end();++it){
		if(it->getBalance() > min && it->getBalance() < max)
         		count++;
	}*/
   //USING STL ALGORITHMS
  count = std::count_if(accounts.begin(),accounts.end(),[min,max](const SavingsAccount& ref){return ref.getBalance() > min && ref.getBalance() < max;});

	return count;
}


SavingsAccount* Banking::findAccountById(std::string keyId) {
  /*std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) {
    if(iter->getNumber()==keyId)
        return &(*iter);
	}*/
   //USING STL ALGORITHMS
   auto var =std::find_if(accounts.begin(),accounts.end(),[keyId] (const SavingsAccount& ref){ return (ref.getNumber()==keyId );});
   if(&(*var)!= NULL)
      return &(*var);
   else 
    return NULL;
}

SavingsAccount* Banking::findAccountByName(std::string name) {
 
    //USING STL ALGORITHMS
    auto var =std::find_if(accounts.begin(),accounts.end(),[=] (const SavingsAccount& ref){ return (ref.getName()==name );});
   if(&(*var)!= NULL)
      return &(*var);
   else 
    return NULL;
  
}

void Banking::removeAccountById(std::string keyId) {
  /*std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter)
	{
    	if(iter->getNumber()==keyId)
        	break;
	}
  if(iter!=accounts.end())
    accounts.erase(iter);*/

    //USING STL ALGORITHMS

    auto var = std::find_if(accounts.begin(),accounts.end(),[=]( SavingsAccount& ref){ return (ref.getNumber()==keyId);});
   
    accounts.erase(var);
}


 SavingsAccount& Banking::findAccountWithMaxBalance() {
  /*std::list<SavingsAccount>::iterator iter;
  iter=accounts.begin();
  double maxBal = iter->getBalance();
  std::list<SavingsAccount>::iterator maxIter=iter;
  std::advance(iter,1);
  for(;iter!=accounts.end();++iter) {
    if(iter->getBalance() > maxBal) {
        maxBal = iter->getBalance();
        maxIter = iter;
    }
  }
  return *maxIter;*/

  //USING STL ALGORITHMS
    auto iter = std::max_element(accounts.begin(),accounts.end(),[](SavingsAccount &ref1,SavingsAccount &ref2){return ref1.getBalance() < ref1.getBalance(); });
    return *iter;
}
int Banking::countAccountsByBalanceLess(double bal){
    int count=0;
  /*std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) {
    if(iter->getBalance() < bal) {
        c++;

    }
  }
  return c;*/

  //USING STL ALGORITHMS
  count = std::count_if(accounts.begin(),accounts.end(),[=](const SavingsAccount& ref){return ref.getBalance() <bal;});

 return count;

}



