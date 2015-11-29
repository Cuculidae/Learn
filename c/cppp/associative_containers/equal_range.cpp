/**
 * equal_range.cpp
 * Compilation: g++ -o equal_range equal_range.cpp -std=c++11
 * Created: 2015-09-20
 */

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;

/*
 *      Operations to Find Elements in an Associative Container:
 * *****************************************************************************
 * lower_bound and upper_bound not valid for the unordered containers.
 * c.find(k)        Returns an iterator to the (first) element with key k, or
 *                  the off-the-end iterator if k is not in the container.
 * c.count(k)       Returns the number of elements with key k. For the
 *                  containers with unique keys, the result is always zero or
 *                  one.
 * c.lower_bound(k) Returns an iterator to the first element with key not less
 *                  than k.
 * c.upper_bound(k) Returns an iterator to the first element with key greater
 *                  than k.  
 * c.equal_range(k) Returns a pair of iterators denoting the elements with key
 *                  k. The first member of that pair holds the same iterator as
 *                  lower_bound wound have returned and second holds the 
 *                  iterator upper_bound would have returned.
 * *****************************************************************************
 *
 * We are guaranteed that iterating across a multimap or multiset returns all
 * the elements with a given key in sequence.
 *
 * Calling lower_bound and upper_bound on the same key yields an iterator range
 * that denotes all the elements with that key.
 *
 * The iterator returned from lower_bound may or may not refer to an element
 * with the given key. If the key is not in the container, then lower_bound
 * refers to the first point at which this key can be inserted while preserving
 * the element order within the container. If lower_bound and upper_bound return
 * the same iterator, then the given key is not in the container.
 */
int main(void)
{
    multimap<string, string> authors = {
        {"Barth John", "Sot-weed Factor"},
        {"Barth John", "Lost in the Funhouse"},
        {"Alain de Botton", "Essays in Love"},
        {"Alain de Botton", "The Romantic Movement"},
        {"Alain de Botton", "Kiss and Tell"},
    };
    string search_item("Alain de Botton");      // author we'll look for
    // pos holds iterators that denote the range of elements for this key
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first) {
        cout << pos.first->second << endl;   // print each title
    }

    return 0;
}
