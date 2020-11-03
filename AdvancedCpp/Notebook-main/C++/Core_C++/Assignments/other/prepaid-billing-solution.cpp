class Customer {
  private:
  // TODO: declare suitable data members: cust id, name,phone number
  public:
  // TODO: add suitable constructors
  // TODO: add other functions
};
class PrepaidCustomer {
  // TODO: declare suitable additional data members ,e.g. balance, validity etc.
  public:
  // TODO: add suitable constructors for derived class
  // TODO: override necessary functions
  // TODO: add other functions
};  
int main() {

  PrepaidCustomer pobj(1001, "Richard", "9845012345"); 
  pobj->display();
  Customer *ptr = new PrepaidCustomer(1001, "Scott", "98223 12345", 500);
  ptr->makeCall(5);    //should invike from derived class
  ptr->billPay(100);  //should invoke from derived class
  int bal = ptr->getBalance();    //here balance means outstanding amount
  std::cout << "Balance is :" << bal << "\n";
  ptr->display();

  //Customer c1(1003, "Meyers","9845012346",200 ); 
  //uncommenting this line should be an error 
  //TODO: release the memory for object pointed by ptr
}
