#include "billing.h"
#include "customer.h"
#include "prepaid.h"
#include "postpaid.h"
#include<numeric>
#include<algorithm>
#include <list>
#include <iterator>

void MobileBilling::addCustomer(int id,std::string name,std::string phn,double bal)
{
    cust.push_back(PrepaidCustomer(id,name,phn,bal));
}

void MobileBilling::removeCustomer(int id)
{
   // std::list<PrepaidCustomer> :: iterator iter;


    auto iter = std::find_if(cust.begin(),cust.end(),[=]( PrepaidCustomer& l1){ return (l1.getCustomerId()==id);});
   
    cust.erase(iter);   
}



PrepaidCustomer* MobileBilling:: findCustomerById(int id)
{
    // std::list<PrepaidCustomer> :: iterator iter;

  auto iter = std::find_if(cust.begin(), cust.end(), [id] ( PrepaidCustomer& s) { return s.getCustomerId() == id; } );
  if(&(*iter)!=NULL)
  {
  return &(*iter);
  }
  return NULL;
  
}
PrepaidCustomer* MobileBilling:: findCustomerByPhone(std::string phn)
{
   // std::list<PrepaidCustomer> :: iterator iter;
    auto iter = std::find_if(cust.begin(), cust.end(), [phn] ( PrepaidCustomer& s) { return !(s.getPhone().compare(phn)); } );
  if(&(*iter)!=NULL)
  {
  return &(*iter);
  }
  return NULL;

}
double MobileBilling:: findAverageBalance()
{
    double sum=0,res=0;
    std:: list <PrepaidCustomer> :: iterator iter;
    res=accumulate(cust.begin(),cust.end(),0,[](int i ,PrepaidCustomer& x){return x.getBalance()+i;});
    //(int i, const Object& o){ return o.getValue1() + i; });

    return res/cust.size();

}
double MobileBilling:: findMaxBalance()
{
    //std:: list<PrepaidCustomer> :: iterator iter = cust.begin();
   // auto maxBal  = iter->getBalance();
   // auto maxiter = iter;
   

    auto var =std::max_element(cust.begin(),cust.end(),[=] (PrepaidCustomer& r1, PrepaidCustomer& r2) 
{ return ( r1.getBalance() < r2.getBalance());});
 return (var->getBalance());
 
}



int MobileBilling:: countByMinBalance(double minval)
{
     int count=0;
 auto var =std::count_if(cust.begin(),cust.end(),[=] (PrepaidCustomer& r1)
{ return ((r1.getBalance()>=minval)  );}
);
 
return var;

}

int MobileBilling:: countAll()
{
   return cust.size();
}

