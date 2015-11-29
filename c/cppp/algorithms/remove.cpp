/**
 * remove.cpp
 * Compilation: g++ -o remove remove.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using std::cout;
using std::endl;
using std::remove;
using std::copy;
using std::ostream_iterator;
using std::list;

int main(void)
{
    list<int> lst{0,5,1,2,5,3,4,5,5,5};
    int val = 5;
    auto it = remove(lst.begin(), lst.end(), val);

    ostream_iterator<int> out_iter(cout, " ");
    copy(lst.cbegin(), lst.cend(), out_iter);
    cout << endl;
    copy(lst.begin(), it, out_iter);

    return 0;
}
