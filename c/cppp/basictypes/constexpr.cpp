/**
 * constexpr.cpp
 * C++11 constexpr syntax.
 * Compilation: g++ -o constexpr constexpr.cpp -std=c++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    /*
     * constexpr    (Since C++11)
     * specifies that the value of a variable or function can appear in constant
     * expressions.
     * A constexpr variable is implicitly const and must be initialized by
     * constant expressions.
     * A constexpr function is implicitly inline.
     */
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    std::cout << "mf == " << mf << ", limit == " << limit << std::endl;

    /*
     * We can initialize a constexpr pointer from the nullptr or the literal 0.
     * We can also point (or bind to) an object that remains at fixed address.
     * When we define a pointer in a constexpr declaration, the constexpr
     * specifier applies to the pointer, not the type to which the pointer
     * points.
     */
    constexpr int *q = nullptr; // q is a const pointer to int

    return 0;
}
