#include<list>
class Account {
   //virtual - debit, credit
   virtual ~Account() {  }
};
class SavingsAccount:public Account {
   //override virtual
   virtual ~SavingsAccount() {  }
};
class CreditAccount:public Account {
   //override virtual
   virtual ~CreditAccount() {  }
};

/*void transactDemo(Account* ptr) {
    //debit, credit
}
void transactDemo(Account& ref) {
    //debit, credit
}*/

class Banking {
  std::list<Account*> accounts;
  public:
  void addAccount(AccountType type,int id, std::string name, double balance) {
     if(type==Savings)
        ptr = new SavingsAccount(id,name,balance);
     if(type==Credit)
        ptr = new CreditAccount(id,name,balance);
     accounts.push_back(ptr);
  }
  void removeAccount(int id) {
    //TODO
  }
  ~Banking() {
    //auto iter = accounts.begin();
    //for(; iter!=accounts.end();++iter)
    //    delete *iter;
    for(Account* ptr:accounts)      //for(auto ptr:accounts)
       delete ptr;
  }
  void displayAll() {
     auto iter = accounts.begin();
     for(; iter!=accounts.end();++iter)
        (*iter)->display();
  }
};

int main() {
  /*SavingsAccount s1;
  CreditAccount c1;
  transactDemo(&s1);
  transactDemo(&c1);
  transactDemo(s1);
  transactDemo(c1);*/
  return 0;
}
