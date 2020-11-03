/*# Banking class
  * Create a collection of Accounts using suitable STL container
  * Implement following operations on the collection
    * addAccount
    * removeAccount by id
    * display all accounts
    * find account by id
    * find all accounts matching with customer name (sub string match)
    * find average balance in all accounts
    * find the account with maximum balance
    * count all accounts with certain range of balance
    * count all accounts whose balance is less than certain limit
*/

#include "account.h"
#include <list>
#include <iterator>
class banking{
    std::list <account> a;
public:
    void addAccount(std::string,std::string,double);
    void removeAccountByid(std::string);
    std::string AccountWithMaxBal();
    void displayAccounts();
    std::string FindAccountById(std::string);
    std::string FindAccountsWithCustomerName(std::string);
    double AvgBalance();
    int CountAccountsWithInRange(double,double);
    int CountAccountsLessThanLimit(double);
};



