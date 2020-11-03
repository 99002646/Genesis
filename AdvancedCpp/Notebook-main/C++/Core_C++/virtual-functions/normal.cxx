#include <iostream>
#include <string>
class Customer {
private:
  int custid;
  std::string custname;
  std::string mobno;
  
public:
  Customer(int id, std::string name, std::string mob)
      : custid(id), custname(name), mobno(mob) {}
  void makeCall(int nmins) { 
    std::cout << "Base -- makeCall\n";
  }
  void credit(int amount) {
    std::cout << "Base -- credit\n";
  }
  int getBalance() const { return 0; } ;
  void display() const {
    std::cout << "Base -- display\n";
    //print id, anme, bal, mobno
  } 
};
class PrepaidCustomer : public Customer {
  // TODO: declare suitable additional data members
  double balance;
  int validity;

public:
  PrepaidCustomer(int id, std::string name, std::string mob, double bal, int x)
      : Customer(id, name, mob), balance(bal),validity(x) {}
  PrepaidCustomer(int id, std::string name, std::string mob,int x)
                :Customer(id,name, mob),balance(500), validity(x) { }
  void makeCall(int nmins) { 
    std::cout << "Derived -- makeCall\n";
    balance -= nmins;   //nmins * callrate
  }
  void credit(int amount) {  
    std::cout << "Derived -- credit\n";
    balance += amount;
  }
  int getBalance() const{ 
    return balance;
  }
  void display() const {
    std::cout << "Derived -- display\n";
    //Method-1:- print getId(), getName(), getMobile(), getBalance(), validity
    //Method-2:- Base display(), print validity
  }
};
int main() {
  PrepaidCustomer pobj(1001, "Richard", "9845012345", 600, 45);
  //pobj.display();

  Customer *pc = &pobj;
  Customer &rc = pobj;

  pc->makeCall(5);
  rc.makeCall(5);

  Customer *ptr = new PrepaidCustomer(1001, "Scott", "98223 12345", 500);
  ptr->makeCall(5);   
  ptr->credit(100);  
  int bal = ptr->getBalance();    
  std::cout << "Balance is :" << bal << "\n";
  ptr->display();

  //Customer c1(1003, "Meyers","9845012346" );
  delete ptr;
}
