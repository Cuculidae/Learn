/**
 * switch.cpp
 * Demonstrate the use of the switch statement.
 * Compilation: g++ -o switch swtich.cpp
 * Created: 2015-09-08
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    /*
     * The control expression of swtich is converted to an integral type.
     * The case keyword and its associated value together are known as the case
     * label. case labels must be integral constant expressions.
     * It is an error for any two case labels to have the same value.
     */
    double d = 3.14;
    switch (d) {
        case 1: cout << 1 << endl; break;
        case 2: cout << 2 << endl; break;
        case 3: cout << 2 << endl; break;
        default: break;
    }

    /*
     * It is illegal to jump from a place where a variable with an initializer
     * is out of scope to a place whre that variable is in scope.
     * If we need to define and initialize a variable for a particular case, we
     * can do so by defining the variable inside a block, thereby ensuring that
     * the variable is out of scope at the point of any subsequent label.
     */

    return 0;
}
