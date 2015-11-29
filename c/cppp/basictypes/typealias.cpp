/**
 * typealias.cpp
 * Demonstrate the use of type alias in C++
 * Compilation: g++ -o typealias typealias.cpp -std=c++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    /*
     * #1 traditional typedef
     */
    typedef double wages;   // wages is a synonym for double
    typedef wages base, *p; // base is a synonym for double, p for double*
    wages hourly, weekly;   // same as double hourly, weekly;
    typedef char *pstring;
    const pstring cstr = 0; // cstr is a constant pointer to char

    /*
     * #2 C++11, alias declaration
     * Syntax:
     *  using identifier = type-id;
     */
    using Str = const char*;// Str is a synonym for char*
    Str s = "Hello, world";
    std::cout << s << std::endl;

    return 0;
}
