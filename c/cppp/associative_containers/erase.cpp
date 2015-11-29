/**
 * erase.cpp
 * Associative container erase operation.
 * Compilation: g++ -o erase erase.cpp -std=c++11
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
 * Removing Elements from an Associative Container:
 * c.erase(k)       Removes every element with key k from c. Returns size_type
 *                  indicating the number of elements removed.
 * c.erase(p)       Removes the element denoted by the iterator p from c. p must
 *                  refer to an actual element in c; it must not be equal to
 *                  c.end(). Returns an iterator to the element after p or
 *                  c.end() if p denotes the last element in c.
 * c.erase(b, e)    Removes the elements in the range denoted by the iterator
 *                  pair b, e. Returns e.
 */
int main(void)
{
    map<string, size_t> word_count;         // empty from string to size_t
    string word;
    while (cin >> word) {
        // inserts an element with key equal to word and value 1;
        // if word is already in word_count, insert does nothing
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {          // word was already in word_count
            ++ret.first->second;    // increment the counter
        }
    }
    cin.clear();
    cout << "input a word to be removed: ";
    cin >> word;
    // erase on a key returns the number of elements removed
    if (word_count.erase(word))
        cout << "ok: " << word << " removed\n";
    else
        cout << "oops: " << word << " not found\n";
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
    multimap<string, string>::size_type cnt = authors.erase("Barth, John");
    cout << cnt << endl;

    return 0;
}
