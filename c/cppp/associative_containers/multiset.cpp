/**
 * multiset.cpp
 * Associative container multiset.
 * Compilation: g++ -o multiset map.cpp -std=c++11
 * Created: 2015-09-19
 */

#include <iostream>
#include <set>      // define set and multiset
#include <string>
#include <vector>
#include "Sales_data.hpp"

using std::cout;
using std::endl;
using std::set;
using std::multiset;
using std::string;
using std::vector;

/*
 * Associative containers (both ordered and unordered) support the general
 * container operations covered in § 9.2 (p. 328) and listed in Table 9.2 (p.
 * 330). The associative containers do not support the sequential-container
 * position-specific operations, such as push_front or back. Because the
 * elements are stored based on their keys, these operations would be
 * meaningless for the associative containers. Moreover, the associative
 * containers do not support the constructors or insert operations that take an
 * element value and a count.
 *
 * The associative container iterators are bidirectional.
 *
 * For the ordered containers--map, multimap, set, andmultiset--the key type
 * must define a way to compare the elements. By default, the library uses the <
 * operator for the key type to compare the keys.
 *
 * The type of the operation that a container uses to organize its elements is
 * part of the type of that container. To specify our own operation, we must
 * supply the type of that operationwhenwe define the type of an associative
 * container. The operation type is specified following the element type inside
 * the angle brackets that we use to say which type of container we are
 * defining.
 *
 * Associative Container Additional Type Aliases:
 * key_type     Type of the key for this container type
 * mapped_type  Type associated with each key; map types only
 * value_type   For sets, same as the key_type
 *              For maps, pair<const key_type, mapped_type>
 *
 * In general, we do not use the generic algorithms (Chapter 10) with the
 * associative containers. The fact that the keys are constmeans that we cannot
 * pass associative container iterators to algorithms that write to or reorder
 * container elements. Associative containers can be used with the algorithms
 * that read elements. However, many of these algorithms search the sequence. In
 * practice, if we do so at all, we use an associative container with the
 * algorithms either as the source sequence or as a destination.
 * 
 * When we use an iterator to traverse a map, multimap, set, or multiset, the
 * iterators yield elements in ascending key order.
 *
 * There can be several elements with the same key in the multimap and multiset
 * containers.
 *
 */

int main(void)
{
    // define a vector with 20 elements, holding two copies of each number 0 to 9
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.insert(ivec.end(), 2, i);  // duplicate copies of each number
    }
    // iset holds unique elements from ivec; miset holds all 20 elements
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;    // prints 20
    cout << iset.size() << endl;    // prints 10
    cout << miset.size() << endl;   // prints 20

    // bookstore can have several transactions with the same ISBN
    // elements in bookstore will be in ISBN order
    multiset<Sales_data, decltype(compareIsbn)*>
        bookstore(compareIsbn);

    return 0;
}
