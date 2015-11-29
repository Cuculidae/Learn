/**
 * replace_copy.cpp
 * Compilation: g++ -o replace_copy replace_copy.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::replace_copy;

int main(void)
{
    list<int> ilst(10);
    vector<int> ivec(10);

    replace_copy(ilst.begin(), ilst.end(), ivec.begin(), 0, 42);

    for (const int i : ilst)
        cout << i << " ";
    cout << endl;

    for (const int i : ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
