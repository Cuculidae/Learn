/**
 * test_account.cpp
 * test the Account class.
 * Compilation: g++ -o test_account test_account.cpp Account.cpp -std=c++11
 * Created: 2015-09-12
 */

#include <iostream>
#include "Account.hpp"

int main(void)
{
    double r;
    r = Account::rate();    // access a static member using the scope operator
    std::cout << r << std::endl;

    Account ac1;
    Account *ac2 = &ac1;
    // equivalent ways to call the static member rate function
    r = ac1.rate();         // through an Account object or reference
    std::cout << r << std::endl;
    r = ac2->rate();        // through an pointer to Account object
    std::cout << r << std::endl;

    return 0;
}
