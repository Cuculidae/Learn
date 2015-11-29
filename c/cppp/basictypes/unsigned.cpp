/**
 * unsigned.cpp
 * Demonstrate the pit-fall of unsigned types.
 * Compilation: g++ -o unsigned unsigned.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    unsigned u1 = 10, u2 = 42;
    std::cout << "u1 == " << u1 << ", u2 == " << u2 << std::endl;
    std::cout << "u2 - u1 == " << u2 - u1 << std::endl;
    std::cout << "u1 - u2 == " << u1 - u2 << std::endl;

    int i1 = 10, i2 = 42;
    std::cout << "i1 == " << i1 << ", i2 == " << i2 << std::endl;
    std::cout << "i2 - i2 == " << i2 - i1 << std::endl;
    std::cout << "i1 - i2 == " << i1 - i2 << std::endl;
    std::cout << "i1 - u1 == " << i1 - u1 << std::endl;
    std::cout << "u1 - i1 == " << u1 - i1 << std::endl;

    return 0;
}
