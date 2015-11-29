/**
 * pointer.cpp
 * Demonstrate the syntax of pointer type.
 * Compilation: g++ -o pointer pointer.cpp -std=c++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    // C++11, nullptr literal
    int *p = nullptr;

    /*
     * The type of a pointer must match the type of the object it points to,
     * except the two following exceptions:
     *
     * #1 We can use a pointer to const to point to a nonconst object.
     */
    const double pi = 3.14;
    const double *cptr = &pi;
    std::cout << "*cptr == " << *cptr << std::endl;
    double pii = 3.14159;
    cptr = &pii;
    std::cout << "*cptr == " << *cptr << std::endl;

    return 0;
}
