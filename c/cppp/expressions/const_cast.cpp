/**
 * const_cast.cpp
 * const_cast cast away cv-qualifier.
 * Compilation: g++ -o const_cast const_cast.cpp
 * Created: 2015-11-01
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * A named cast has the following form:
 *  cast-name<type>(expression);
 * where type is the target type of the conversion, and expression is the value
 * to be cast. If type is a reference, then the result is an lvalue. The
 * cast-name may be one of static_cast, dynamic_cast, const_cast, and
 * reinterpret_cast.
 */

int main()
{
    /* A const_cast changes only a low-level const in its operand. If the object
     * was originally not a const, using a cast to obtain write access is legal.
     * However, using a const_cast in order to write to a const object is
     * undefined. */
    int i = 1;  // i is not declared const
    const int &j = i;
    cout << "j = " << j << endl;
    const_cast<int&>(j) = 2;
    cout << "j = " << j << endl;

    return 0;
}
