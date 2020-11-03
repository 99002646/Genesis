#include "banking.h"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <cstring>
#include<numeric>
//using namespace std;
void banking :: addAccount(std::string name,std::string num,double bal){
    a.push_back(account(name,num,bal));
}
void banking :: removeAccountByid(std::string num){
    std::list <account> :: iterator iter;
    for(iter = a.begin();iter != a.end();++iter){
        if(num == iter->getId()){
            a.erase(iter);
            break;
        }
    }
    
}
//Normal STL operation
std::string banking :: AccountWithMaxBal(){
    std::list <account> :: iterator iter = a.begin();
    double maxbal = iter -> getBalance();
    std::string id = iter->getId();
    for(;iter != a.end();++iter){
        if(maxbal < iter->getBalance()){
            maxbal = iter->getBalance();
            id = iter->getId();
        }
    }
    return id;
}



void banking::displayAccounts(){
    std::cout << "";
}
std::string banking :: FindAccountById(std::string id){
    std::list <account> ::iterator iter=a.begin();
    std::string name = iter->getName();
    for(;iter != a.end();++iter){
        if(id == iter->getId()){
            name = iter->getName();
        }
    }
    return name;
}
std::string banking :: FindAccountsWithCustomerName(std::string name){
    std::list <account> ::iterator iter=a.begin();
    std::string id = iter->getId();
    for(;iter != a.end();++iter){
        if(name == iter->getName()){
            id = iter->getId();
        }
    }
    return id;
}

double banking :: AvgBalance(){
    std::list <account> ::iterator iter=a.begin();
    double sum = 0;
    for(;iter != a.end();++iter){
        sum += iter->getBalance();
    }
    return (sum/a.size());
}

int banking :: CountAccountsWithInRange(double minval,double maxval){
    std::list <account> ::iterator iter=a.begin();
    int cnt=0;
    /*for(iter= a.begin();iter != a.end();++iter){
        if((iter->getBalance() > minval) && (iter->getBalance() < maxval)){
            cnt++;
        }
    }*/
    std::for_each(begin(a),end(a),[&](account& r){
       if((r.getBalance() > minval) && (r.getBalance() < maxval)) cnt++;
    });
    return cnt;
}
int banking :: CountAccountsLessThanLimit(double limit){
    std::list <account> ::iterator iter=a.begin();
    int cnt=0;
    cnt = std::count_if(a.begin(),a.end(),[limit](account& r){
        return (r.getBalance() < limit) ;
    });
   return cnt;
}
/*account&  banking :: AccountWithMaxBal(){
    //std::list <account> :: iterator iter;
    auto iter = std::max_element(a.begin(),a.end(),
        [](account& r1,account& r2){
            return (r1.getBalance() < r2.getBalance());
        });
       // std::cout << (iter -> getName()) << "\n";
      //  std::cout << (iter -> getId()) << "\n";
       // std::cout << (iter -> getBalance()) << "\n";
    return *iter;
}*/

