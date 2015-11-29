/**
 * replace.cpp
 * Compilation: g++ -o replace replace.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::replace;

int main(void)
{
    list<int> ilst(10);
    // replace any element with the value 0 with 42
    replace(ilst.begin(), ilst.end(), 0, 42);

    for (const int i : ilst)
        cout << i << " ";
    cout << endl;

    return 0;
}
