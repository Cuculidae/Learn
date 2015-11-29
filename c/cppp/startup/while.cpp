/**
 * while.cpp
 * Demonstrate while loop, sum from 1 to 10 inclusive.
 * Compilation: g++ -o while while.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;

    return 0;
}
