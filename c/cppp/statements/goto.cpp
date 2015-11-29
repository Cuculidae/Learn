/**
 * goto.cpp
 * C++ goto statement.
 * Compilation: g++ -o goto goto.cpp
 * Created: 2015-11-02
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    /*
     * A goto statement provides an unconditional jump from the goto to a
     * another statement in the same function.
     * Programs should not use gotos. gotos make programs hard to understand and
     * hard to modify.
     *
     * Label identifiers are independent of names used for variables and other
     * identifiers. Hence, a label may have the same identifier as another
     * entity in the program without interfering with the other uses of that
     * identifier. The goto and the labeled statement to which it transfers
     * control must be in the same function.
     *
     * As with a switch statement, a goto cannot transfer control from a point
     * where an initialized variable is out of scope to a point where that
     * variable is in scope. A jump backward over an already executed definition
     * is okay. Jumping back to a piont before a variable is defined destroys
     * the variable and constructs it again.
     */

    // backward jump over an initialized variable definition is okay
    int i = 0;
begin:
    int sz = i++;
    if (sz < 10) {
        cout << sz << ' ';
        goto begin;
    }
    cout << endl;

    return 0;
}
