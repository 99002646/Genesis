class Customer {
  private:
  // TODO: declare suitable data members: cust id, name,phone number balance
  public:
  // TODO: add suitable constructors
  // TODO: add other functions
};
class PostpaidCustomer {
  // TODO: declare suitable additional data members, e.g. balance, billing date etc.
  public:
  // TODO: add suitable constructors for derived class
  // TODO: override necessary functions
  // TODO: add other functions
};  
int main() {

  PostpaidCustomer pobj(1001, "Richard", "9845012345"); 
  pobj->display();
  Customer *ptr = new PostpaidCustomer(1001, "Scott", "98223 12345", 500);
  ptr->recharge(100);  //should invoke from derived class
  ptr->makeCall(5);    //should invike from derived class
  int bal = ptr->getBalance();
  std::cout << "Balance is :" << bal << "\n"
  ptr->display();

  //Customer c1(1003, "Meyers","9845012346",200 ); 
  //uncommenting this line should be an error 
  //TODO: release the memory for object pointed by ptr
}
