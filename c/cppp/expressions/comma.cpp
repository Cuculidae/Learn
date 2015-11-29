/**
 * comma.cpp
 * C++ comma operator.
 * Compilation: g++ -o comma comma.cpp
 * Created: 2015-11-01
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    /* Like the logical AND and logical OR and the conditional operator, the
     * comma operator guarantees the order in which its operands are evaluated.
     * The result of a comma expression is the value of its right-hand
     * expression. The result is an lvalue if the right-hand operand is an
     * lvalue. */
    int i = 0, j = 0;
    cout << "i = " << i << ", j = " << j << endl;
    (i, j) = 1;
    cout << "i = " << i << ", j = " << j << endl;

    return 0;
}
