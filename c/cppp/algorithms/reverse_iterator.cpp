/**
 * reverse_iterator.cpp
 * reverse iterators.
 * Compilation: g++ -o reverse_iterator reverse_iterator.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::find;

/*
 * A reverse iterator inverts the meaning of increment (and decrement).
 * Incrementing (++it) a reverse iterator moves the iterator to the previous
 * element; derementing (--it) moves the iterator to the next element.
 *
 * Versions that begins with c is introduced in C++11.
 *
 * The containers, aside from forward_list, all have reverse iterators. We
 * obtain a reverse iterator by calling the rbegin, rend, crbegin, and crend
 * members. These members return reverse iterators to the last element in the
 * container and one past (i.e., one before) the beginning of the container.
 *
 * Technically speaking, the relationship between normal and reverse iterators
 * accommodates the properties of a left-inclusive range.
 *
 * The fact that reverse iterators are intended to represent ranges and that
 * these ranges are asymmetric has an important consequence: When we initialize
 * or assign a reverse iterator from a plain iterator, the resulting iterator
 * does not refer to the same element as the original.
 */

int main(void)
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    // reverse iterator of vector from back to from
    for (auto r_iter = vec.crbegin();   // binds r_iter to the last element
               r_iter != vec.crend();   // crend refers 1 before the last element
               ++r_iter)                // 
        cout << *r_iter << ' ';        // prints 9,8,7,...0
    cout << endl;

    // sort in reverse; puts the smallest element at the end of vec
    sort(vec.rbegin(), vec.rend());
    for (const auto i : vec)
        cout << i << " ";
    cout << endl;

    string line("FIRST,MIDDLE,LAST");
    // find the first element in a comma-separated list
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;
    // find the last element in a comma-separated list
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    // WRONG: will generate the word in reverse order
    cout << string(line.crbegin(), rcomma) << endl;
    // ok: get a forward iterator and read to the end of line
    cout << string(rcomma.base(), line.cend()) << endl;

    return 0;
}
