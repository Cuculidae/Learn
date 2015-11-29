/**
 * scope.cpp
 * statement scope.
 * Compilation: g++ -o scope scope.cpp
 * Created: 2015-11-01
 */

#include <iostream>

using std::cout;
using std::endl;

int get_num()
{
    static int cnt = 0;
    return ++cnt % 10;
}

int main()
{
    /*
     * We can define variables inside the control structure of the if, switch,
     * while, and for statements. Variables defined in the constrol structure
     * are visible only within that statement and are out of scope after the
     * statement ends.
     */
    while (int i = get_num())   // i is created and initialized on each iteration
        cout << i << endl;
    
    return 0;
}
