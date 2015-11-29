/**
 * count.cpp
 * Compilation: g++ -o count count.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <forward_list>

using std::cout;
using std::endl;
using std::count;
using std::forward_list;

int main(void)
{
    forward_list<int> lst{1, 2, 3, 4, 5, 5};

    int val = 5;
    cout << count(lst.cbegin(), lst.cend(), 5) << endl;

    return 0;
}
