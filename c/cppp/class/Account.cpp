#include "Account.hpp"

/* when we define static members outside the class, we do not repeat the static
 * keyword.
 */
double Account::interestRate = initRate();

constexpr int Account::period;  // initializer provided in the class definition

double Account::initRate()
{
    return 0.001;
}

void Account::rate(double newRate)
{
    interestRate = newRate;
}
