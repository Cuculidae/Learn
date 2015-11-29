/**
 * list_initialize.cpp  (since C++11)
 * Compilation: g++ -o list_initialize.cpp -std=c++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    long double ld = 3.1415926536;

    int a{ld}, b = {ld}; // error: narrowing conversion
    int c(ld), d = ld;   // ok: but value will be truncated

    return 0;
}
