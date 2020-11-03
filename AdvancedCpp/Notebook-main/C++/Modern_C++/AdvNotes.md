## Trivial Classes in C++

* has compiler provided special member functions
* contiguous memory area occupied
* 

1. Type of Objects
    * Trivial and Non Trivial Objects
    Trivial Copy constructor is given by the compiler

## Move Schematics(Move Constr)
    * In Scenario the duplicate heap blocks are created
    * best convention is to transfer the heap block
    *   move assignment is done for the Temp objects and Named objects by type casting
    *   perfect forwarding
    *   to call l-value and r-value dedicated

## Lamdas 
    * used to write temporary function
    * Lambdas for effective callback mechanism, without the need for defining named functions inadvance

    int Banking::countAccountsWithMinBal(double minval) {
    int count=0;
    count = std::count_if(accounts.begin(), accounts.end(),
                                        [minval](const Account& ref) {
        return ref.getBalance() > minval;
    });
    return count;
    }

    double Banking::findAccountWithMaBalance() {

    

    auto iter = std::maxval(accounts.begin(), accounts.end(), 
                    [](const Account& r1, const Account& r2) {
                        return r1.getBalance() < r2.getBalance();
    });
    }
