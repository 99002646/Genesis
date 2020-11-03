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
  virtual void makeCall(int nmins) = 0;
  virtual void credit(int amount) = 0;
  virtual int getBalance() const =0 ;
  void display() const {
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
  /*void credit(int amount) {  
    std::cout << "Derived -- credit\n";
    balance += amount;
  }*/
  int getBalance() const{ 
    return balance;
  }
  void display() const {
    //Method-1:- print getId(), getName(), getMobile(), getBalance(), validity
    //Method-2:- Base display(), print validity
  }
};
class PostpaidCustomer : public Customer {
  // TODO: declare suitable additional data members
  double outstanding;
  int billingdate;

public:
  PostpaidCustomer(int id, std::string name, std::string mob, double bal, int x)
      : Customer(id, name, mob), outstanding(bal),billingdate(x) {}
  PostpaidCustomer(int id, std::string name, std::string mob,int x)
                :Customer(id,name, mob),outstanding(500), billingdate(x) { }
  void makeCall(int nmins) { 
    std::cout << "Derived -- makeCall\n";
    outstanding += nmins;   //nmins * callrate
  }
  void credit(int amount) {  
    std::cout << "Derived -- credit\n";
    outstanding -= amount;
  }
  int getBalance() const{ 
    return outstanding;
  }
  void display() const {
    //Method-1:- print getId(), getName(), getMobile(), getBalance(), validity
    //Method-2:- Base display(), print billingdate
  }
};

int main() {
  //Customer c1(1001, "Richard", "9845012345");

  PrepaidCustomer preobj(1001, "Richard", "9845012345", 600, 45);
  preobj.display();

  PrepaidCustomer postobj(1002, "Stevens", "9845012346", 400, 23);
  postobj.display();

  Customer *pc = &preobj;   //&postobj
  Customer &rc = preobj;    //postobj

  pc->makeCall(5);
  rc.makeCall(5);

  Customer *ptr1 = new PrepaidCustomer(1003, "Scott", "98223 12347", 500, 60); 
  Customer *ptr2 = new PostpaidCustomer(1004, "Meyers", "98223 12348", 200, 24); 
  ptr1->makeCall(5);    //should invike from derived class
  ptr2->credit(100);  //should invoke from derived class
  int bal = ptr1->getBalance();    //here balance means outstanding amount
  std::cout << "Balance is :" << bal << "\n";
  ptr2->display();

  //Customer c1(1003, "Meyers","9845012346" ); // uncommenting this line will lead to error
  delete ptr1;
  delete ptr2;
}
