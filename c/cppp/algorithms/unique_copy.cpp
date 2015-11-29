/**
 * unique_copy.cpp
 * Compilation: g++ -o unique_copy unique_copy.cpp -std=c++11
 * Created: 2015-09-19
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::unique_copy;
using std::back_inserter;
using std::ostream_iterator;

int main(void)
{
    constexpr int sz = 10;
    list<int> lst;
    vector<int> iv;
    for (int i = 0; i < sz; ++i) {
        iv.push_back(i);
        iv.push_back(i);
    }

    unique_copy(iv.cbegin(), iv.cend(), back_inserter(lst));
    ostream_iterator<int> out_iter(cout, " ");
    copy(lst.cbegin(), lst.cend(), out_iter);

    return 0;
}
