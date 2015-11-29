#include <iostream>

using std::cout;
using std::endl;

/*
 * Members that are const or references must be initialized.
 * Similarly,members that are of a class type that does not define a default
 * constructor also must be initialized. For
 *
 * Members are initialized in the order in which they appear in the class
 * definition. The order in which initializers appear in the constructor
 * initializer list does not change the order of initialization.
 */

class X
{
    public:
        int i;
        int j;
        // undefined: i is initialized before j
        X(int val): j(val), i(j) { }
};

int main(void)
{
    X x(1);
    cout << "x.i = " << x.i
         << ", x.j = " << x.j << endl;

    return 0;
}
