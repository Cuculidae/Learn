/**
 * while.cpp
 * while loop
 * Compilation: g++ -o while while.cpp
 * Created: 2015-09-08
 */

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    /*
     * while (condition)
     *      statement
     * The condition can be an expression or a declaration of a single variable
     * with a brace-or-equals initializer.
     * condition may not be empty.
     * Variables defined in a while condition or while body are created and
     * destroyed on each iteration.
     */

    // while loop with a declaration condition
    char cstr[] = "Hello";
    int k = 0;
    while (char c = cstr[k++])
        cout << c;
    cout << endl;

    return 0;
}
