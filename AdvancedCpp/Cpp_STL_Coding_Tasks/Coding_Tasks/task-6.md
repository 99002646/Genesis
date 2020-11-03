# Problem Statement - Banking Account

Extended the Banking problem as follows, with focus on polymorphic features

## Account class specialization
* Specialize account with derived classes SavingsAccount, CreditAccount. In credit class consider balance as outstanding amount.
* Keep common data members in base class
* Keep specialized data members in derived classes
* Implement suitable constructors for Base, Derived classes
* Implement auto generated IDs for account objects
* Add pure virtual functions like credit, debit in Base class
* Override pure virtual functions in derived classes
* Override <\< operator in derived classes for console output

## Banking class
  * Create a collection of Accounts using suitable STL container (polymorphic container 
    which holds both type of objects)
  * Implement following operations on the collection
    * addAccount
    * removeAccount by id
    * display all accounts
    * find account by id
    * find all savings accounts matching with customer name (sub string match)
    * find average balance in all savings accounts
    * find the credit account with maximum balance
    * count all savings accounts with certain range of balance
    * count all credit accounts whose balance is less than certain limit

## Class Diagram
* Draw the class diagram for above problem statement

## Analysis
* Advantages and disadvantages of a) single container holding both type of pointers b) two different containers for each type of account

## Implementation & Test plan
* Implement the classes as per above requirements
* Provide suitable test code to check above functionality


