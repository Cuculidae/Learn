/**
 * capacity.cpp
 * Compilation: g++ -o capacity capacity.cpp -std=c++11
 * Created: 2015-09-16
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
 * C++11 introduces shrink_to_fit.
 * shrink_to_fit valid only for vector, string, and deque.
 * capacity and reserve valid only for vector and string.
 *
 * c.shrink_to_fit() Request to reduce capacity() to equal size().
 * c.capacity()      Number of elements c can have before reallocation is
 *                   necessary.
 * c.reserve()       Allocate space for at least n elements.
 *
 * reserve does not change the number of elements in the container; it affects
 * only how much memory the vector preallocates. As a result, a call to reserve
 * will never reduce the amount of space that the container uses. Similarly, the
 * resize members (Â9.3.5, p.352) change only the number of elements in the
 * container, not its capacity.
 *
 * Calling shrink_to_fit is only a request; there is no guarantee that the
 * library will return the memory.
 *
 * Each vector implementation can choose its own allocation strategy. However,
 * it must not allocate new memory until it is forced to do so.
 */

int main(void)
{
    vector<int> ivec;
    // size should be zero; capacity is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    // give ivec 24 elements
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);

    // size should be 24;capacity will be >= 24 and is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capactiy: " << ivec.capacity() << endl;

    ivec.reserve(50);   // sets capacity to at least 50;might be more
    // size should be 24;capacity will be >= 50 and is implentation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    // add elements to use up the excess capacity
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    // capacity should be unchanged and size and capacity are now equal
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    ivec.push_back(42); // add one more element
    // size should be 51; capacity will be >= 51 and is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    ivec.shrink_to_fit();   // ask for the memory to be returned
    // size should be unchanged; capacity is implentation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    return 0;
}
