/**
 * equal.cpp
 * Compilation: g++ -o equal equal.cpp
 * Created: 2015-09-17
 */

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

/*
 * euals takes three iterators: The first two (as usual) denote the range of
 * elements in the first sequence; the third denotes the first element in the
 * second sequence.
 *
 * Moreover, the element types also need not be the same so long aswe can use ==
 * to compare the element types.
 *
 * Algorithms that take a single iterator denoting a second sequence assume that
 * the second sequence is at least as large at the first.
 */

int main(void)
{
    vector<int> ivec{1, 2, 3, 4, 5};
    list<int> ilst{1, 2, 3, 4, 5};

    cout << (equal(ivec.cbegin(), ivec.cend(), ilst.cbegin()) ?
            "equal" : "not equal") << endl;

    return 0;
}
