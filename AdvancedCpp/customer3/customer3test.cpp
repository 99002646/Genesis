#include <iostream>
#include "customer3.h"
#include "prepaid.h"
#include "postpaid.h"

using namespace std;

    TEST(PrepaidCustomer,DefaultConstructor) {
    PrepaidCustomer p1("123","1213","PM",1235);
    p1.credit(10);
    p1.display();


    /*PostpaidCustomer p2("123","1222","sai",5289);
     p2.credit(10);
    p2.display();
    return 0;*/
}
