/**
 * for.cpp
 * for statement.
 * Compilation: g++ -o for for.cpp
 * Created: 2015-09-08
 */

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    /*
     * for (init-statement condition; expression)
     *      statement
     * Names declared by the init-statement (if init-statement is a declaration)
     * and names declared by condition (if condition is a declaration) are in
     * the same scope (which is also the scope of statement).
     * While in C++, the scope of the init-statement and the scope of statement
     * are one and the same, in C the scope of statement is nested within the
     * scope of init-statement:
     * for (int i = 0; ; ) {
     *     long i = 1;   // valid C, invalid C++
     *     // ...
     * }
     */
    
    // condition may be declaration
    char cstr[] = "Hello";
    for (int i = 0; char c = cstr[i]; ++i)
        cout << c << " ";
    cout << endl;

    // init-statement can be an expression
    int n = 0;
    for (cout << "Loop start\n";
          cout << "Loop test\n";
          cout << "Iteration " << ++n << '\n')
        if (n > 1)  break;
    
    return 0;
}
