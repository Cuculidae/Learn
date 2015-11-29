/**
 * transform.cpp
 * Compilation: g++ -o transform transform.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::transform;

/*
 * The transform function takes three iterators and a callable. The first two
 * iterators denote an input sequence and the third is a destination. The
 * algorithm calls the given callable on each element in the input sequence and
 * writes the result to the destination. When the input iterator and the
 * destination iterator are the same, transform replaces each element in the
 * input range with the result of calling the callable on that element.
 */

int main(void)
{
    vector<int> vi;
    for (int i = -10; i < 0; ++i)
        vi.push_back(i);
    for (const auto i : vi)
        cout << i << " ";
    cout << endl;

    transform(vi.begin(), vi.end(), vi.begin(),
            [](int i) -> int
            { if (i < 0) return -i; else return i; });

    for (const auto i : vi)
        cout << i << " ";
    cout << endl;

    return 0;
}
