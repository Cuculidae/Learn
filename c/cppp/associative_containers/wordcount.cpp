/**
 * wordcount.cpp
 * This program reads its input and reports how often each word appears.
 * Compilation: g++ -o wordcount wordcount.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;

int main(void)
{
    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                              "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word) {
        // count only words that are not in exclude
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];     // fetch and increment the counter for word
        }
    }


    // get an iterator positioned on the first element
    auto map_it = word_count.cbegin();
    // compare the current iterator to the off-the-end iterator
    while (map_it != word_count.cend()) {
        // dereference the iterator to print the element key-value pairs
        cout << map_it->first << " occurs "
             << map_it->second << " times" << endl;
        ++map_it;   // increment the iterator to denote the next element
    }
    return 0;
}
