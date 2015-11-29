/**
 * remove_if.cpp
 * Compilation: g++ -o remove_if remove_if.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using std::cout;
using std::endl;
using std::remove_if;
using std::copy;
using std::ostream_iterator;
using std::list;

int main(void)
{
    list<int> lst{0,1,2,3,4,5,6,7,8,9};

    // remove the odd elements from v1
    auto it = remove_if(lst.begin(), lst.end(),
            [] (int i) { return i % 2; });

    ostream_iterator<int> out_iter(cout, " ");
    copy(lst.cbegin(), lst.cend(), out_iter);
    cout << endl;
    copy(lst.begin(), it, out_iter);

    return 0;
}
