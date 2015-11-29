/**
 * insert.cpp
 * Associative containers insert operation.
 * Compilation: g++ -o insert insert.cpp -std=c++11
 * Created: 2015-09-20
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::set;
using std::multiset;
using std::vector;
using std::string;
using std::pair;

/*
 * The insert members add one element or a range of elements. Because map and
 * set (and the corresponding unordered types) contain unique keys, inserting an
 * element that is already present has no effect.
 *
 * Associative Container insert Operations:
 * c.insert(v)      v value_type object; args are used to construct an element.
 * c.emplace(args)  For map and set, the element is inserted (or constructed)
 *                  only if an element with the given key is not already in c.
 *                  Returns a pair containing an iterator referring to the
 *                  element with the given key and a bool indicating whether the
 *                  element was inserted. For multimap and multiset, inserts (or
 *                  constructs) the given element and returns an iterator to the
 *                  new element.
 * c.insert(b, e)   b and e are iterators that denote a range of c::value_type
 * c.insert(il)     values; il is a braced list of such values. Returns void.
 *                  For map and set, inserts the elements with keys that are not
 *                  already in c. For multimap and multiset inserts, each
 *                  element in the range.
 * c.insert(p, v)       Like insert(v) (or emplace(args)), but uses iterator p
 * c.emplace(p, args)   as a hint for where to begin the search for where the
 *                      new element should be stored. Returns an iterator to the
 *                      element with the given key.
 *
 * When we insert into a map, we must remember that the element type is a pair.
 * For the containers that allow multiple keys, the insert operation that takes
 * a single element returns an iterator to the new element.
 */

int main(void)
{
    /* only the first element with a given key is inserted. */
    vector<int> ivec = {2,4,6,8,2,4,6,8};       // ivec has eight elements
    set<int> iset;                              // empty set
    iset.insert(ivec.cbegin(), ivec.cend());    // iset has four elements
    for (const auto i : iset)
        cout << i << " ";
    cout << endl;
    iset.insert({1,3,5,7,1,3,5,7});             // iset now has eight elements
    for (const auto i : iset)
        cout << i << " ";
    cout << endl;

    map<string, size_t> word_count;         // empty from string to size_t
    string word;
    // four ways to add word to word_count
    cin >> word;
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    while (cin >> word) {
        // inserts an element with key equal to word and value 1;
        // if word is already in word_count, insert does nothing
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {          // word was already in word_count
            ++ret.first->second;    // increment the counter
        }
    }
    for (const auto &w : word_count) {
        cout << w.first << " occurs "
             << w.second << " times" << endl;
    }

    multimap<string, string> authors;
    // adds the first element with the key Barth, John
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    // ok: adds the second element with the key Barth, John
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    for (const auto &a : authors) {
        cout << a.first << " "
             << a.second << endl;
    }

    return 0;
}
