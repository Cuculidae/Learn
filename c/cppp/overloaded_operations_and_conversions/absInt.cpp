/**
 * absInt.cpp
 * Compilation: g++ -o absInt absInt.cpp 
 * Created: 2015-09-24
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * Classes that overload the call operator allow objects of its type to be used
 * as if they were a function. Because such classes can also store state, they
 * can be more flexible than ordinary functions.
 *
 * The function-call operator must be a member function. A class may define
 * multiple versionis of the call operator, each of which must differ as to the
 * number or types of their parameters.
 */

struct absInt
{
    operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main(void)
{
    int i = -42;
    absInt a;               // object that has a function-call operator
    cout << a(i) << endl;   // pass i to a.operator()

    return 0;
}
