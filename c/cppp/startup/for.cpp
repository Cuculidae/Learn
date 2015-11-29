/**
 * for.cpp
 * Demonstrate for loop, sum from 1 to 10 inclusive.
 * Compilation: g++ -o for for.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    int sum = 0;
    for (int val = 0; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;

    return 0;
}
