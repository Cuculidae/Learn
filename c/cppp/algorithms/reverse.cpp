/**
 * reverse.cpp
 * Compilation: g++ -o reverse reverse.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using std::cout;
using std::endl;
using std::reverse;
using std::list;
using std::ostream_iterator;

int main(void)
{
    list<int> lst{1,2,3,4,5,6,7,8,9};
    reverse(lst.begin(), lst.end());
    ostream_iterator<int> out_iter(cout, " ");
    copy(lst.cbegin(), lst.cend(), out_iter);

    return 0;
}
