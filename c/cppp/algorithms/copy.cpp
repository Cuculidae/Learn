/**
 * copy.cpp
 * Compilation: g++ -o copy copy.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::copy;

/*
 * The value returned by copy is the (incremented) value of its destination
 * iterator. That is, ret will point just past the last element copied into a2.
 */

int main(void)
{
    int ia1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia2[sizeof(ia1)/sizeof(*ia1)];
    copy(begin(ia1), end(ia1), begin(ia2));

    for (const int i : ia2)
        cout << i << " ";
    cout << endl;

    return 0;
}
