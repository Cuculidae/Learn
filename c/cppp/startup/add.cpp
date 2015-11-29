/**
 * add.cpp
 * Demonstrate I/O, reads two number and outputs the sum.
 * Compilation: g++ -o add add.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
        << " is " << v1 + v2 << std::endl;

    return 0;
}
