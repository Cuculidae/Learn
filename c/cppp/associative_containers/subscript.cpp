/**
 * subscript.cpp
 * Compilation: g++ -o subscript subscript.cpp -std=c++11
 * Created: 2015-09-20
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

/*
 * The map and unordered_map containers provide the subscript operator and a
 * corresponding at function.
 *
 * Subscript Operation for map and unordered_map:
 * c[k]     Returns the element with key k; if k is not in c, adds a new,
 *          value-initialized element with key k.
 * c.at(k)  Checked access to the element with key k; throws an out_of_range
 *          exception (§ 5.6, p. 193) if k is not in c.
 *
 * The set types do not support subscripting because there is no "value"
 * associated with a key in a set. 
 * We cannot subscript a multimap or an unordered_multimap because there may be
 * more than one value associated with a given key.
 *
 * Using a key that is not already present adds an element with that key to the
 * map.
 *
 * when we subscript a map, we get a mapped_type object; when we dereference a
 * map iterator, we get a value_type object.
 *
 * Because the subscript operatormight insert an element, wemay use subscript
 * only on a map that is not const.
 */

int main(void)
{
    map<string, size_t> word_count; // empty map
    // insert a value-initialized element with key Anna;then assign 1 to its value
    word_count["Anna"] = 1;
    cout << word_count["Anna"] << endl; // fetch the element indexed by Anna; prints 1
    ++word_count["Anna"];               // fetch the element and add 1 to it
    cout << word_count["Anna"] << endl;  // fetch the element and print it; prints 2

    return 0;
}
