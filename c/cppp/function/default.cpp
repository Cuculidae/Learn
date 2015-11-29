/**
 * default.cpp
 * C++ default arguments.
 * Compilation: g++ -o default default.cpp
 * Created: 2015-11-03
 */

#include <iostream>

using namespace std;

/*
 * Each parameter can have its default specified only once in a given scope. Any
 * subsequent declaration can add a default only for a parameter that has not
 * previously had a default specified.
 *
 * Local variables may not be used as a default argument. Excepting that
 * restriction, a default argument can be any expression that has a type that is
 * convertible to the type of the parameter. Names used as default arguments are
 * resolved in the scope of the function declaration. The value that those names
 * represent is evaluated at the time of the call.
 */

// no default for i
void f(int i, int j = 1) {
    cout << "f(): i = " << i << ", j = " << j << endl;
}

int wd = 10;
void g(int i = wd) {
    cout << "g(): i = " << i << endl;
}

int h() {
    return 42;
}

int main()
{
    f(0);       // calls f(0, 1)

    // redeclaration
    void f(int i = g(), int j = 2);
    f();        // calls f(g(), 2)

    ::wd = 15;  // changes the value of a default argument
    int wd = 5; // hides the outer definition of wd but does not change the default
    g();        // calls g(15)

    return 0;
}
