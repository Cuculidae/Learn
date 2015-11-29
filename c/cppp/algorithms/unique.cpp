/**
 * unique.cpp
 * Compilation: g++ -o unique unique.cpp -std=c++11
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
using std::unique;
using std::copy;
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
        lst.push_back(i);
        lst.push_back(i);
    }

    ostream_iterator<int> out_iter(cout, " ");
    auto it1 = unique(iv.begin(), iv.end());
    copy(iv.begin(), it1, out_iter);
    cout << endl;
    auto it2 = unique(lst.begin(), lst.end(), 
            [] (int i, int j) { return !(i-j); });
    copy(lst.begin(), it2, out_iter);

    return 0;
}
