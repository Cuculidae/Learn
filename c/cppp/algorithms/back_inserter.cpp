/**
 * back_inserter.cpp
 * Compilation: g++ -o back_inserter back_inserter.cpp
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::back_inserter;
using std::fill_n;

int main(void)
{
    vector<int> vec;    // empty vector
    // ok: back_inserter creates an insert iterator that adds elements to vec
    fill_n(back_inserter(vec), 10, 0);  // appends elements to vec

    for (const int i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}
