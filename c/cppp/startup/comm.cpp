/**
 * comm.cpp
 * How multiline comment is processed.
 * Compilation: g++ -o comm comm.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    // test multiline comment
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << /* "*/" /* "/*" */ << std::endl;

    return 0;
}
