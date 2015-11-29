/**
 * condition.cpp
 * C++ conditional operator.
 * Compilation: g++ -o condition condition.cpp
 * Created: 2015-11-01
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    /* Like the logical AND and logical OR (&& and ||) operators, the
     * conditional operator guarantees that only one of expr1 or expr2 is
     * evaluated. The result of the conditional operator is an lvalue if both 
     * expressions are lvalues or if they convert to a common lvalue type.
     * Otherwise the result is an rvalue. */
    int i = 0, j = 0;
    cout << "i = " << i << ", j = " << j << endl;
    (true ? i : j) = 1;
    cout << "i = " << i << ", j = " << j << endl;


    /* The conditional operator can be used as the cond or as one or both of the
     * exprs of another conditional expression. The conditional operator is
     * right associative. */
    (cout << 1) ? (cout << 2) :
        (cout << 3) ? (cout << 4) : (cout << 5);

    return 0;
}
