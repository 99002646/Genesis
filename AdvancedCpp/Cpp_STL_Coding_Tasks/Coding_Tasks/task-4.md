# Problem Statement - Mobile Billing Solution

## Customer class
* Design a Customer class as follows
  * Data members - id, name, phone, balance
  * Suitable constructors
  * Pure virtual functions like credit, makeCall, display etc.
* Derive Customer class as Prepaid, Postpaid customers
  * Add any additional data members applicable
  * Provide derived class constructors with suitable delegation to Base class constructor
  * Impelement auto genrated customer IDs 
  * Override pure virtual functions with suitable business logic
  * Implement any additional functionality in derived classes  
  * Overload <\< operator for console output

## BillingSolution class
  * Create a collection of Customer using suitable STL container(s)
  * Implement following operations on the collection
    * add customer
    * remove Customer by id
    * display all customers
    * find Customer by id
    * find all Customers by  matching name (substring match)
    * find average balance of all Prepaid customers
    * find the Postpaid customer with maximum outstanding limit (balance)
    * find the Prepaid with minimum balance
    * count all Prepaid customers whose balance is above certain limit
    * count all Postpaid customer whose balance is in with certain range

## Class Diagram
* Draw the class diagram for above problem statement

## Implementation & Test plan
* Implement the classes as per above requirements
* Provide suitable test code to check above functionality


