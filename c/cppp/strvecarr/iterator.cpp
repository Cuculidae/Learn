/**
 * iterator.cpp
 * Introducing iterators.
 * Compilation: g++ -o iterator iterator.cpp -std=c++11
 * Created: 2015-09-08
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
    /*
     * Types that have iterators have members that return iterators.
     * In particular, these types have members named begin and end.
     * begin returns an iterator that denotes the first element;
     * end returns an off-the-end iterator.
     * 
     * Note:
     *  Iterators may be invalidated by operations that change the size
     *  of the container.
     */
    string s("some string");
    if (s.begin() != s.end()) { // make sure s is not empty
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    /*
     * Iterators support only a few standard operations:
     * #1 dereference           *iter, iter->mem
     * #2 increment/decrement   ++iter, --iter
     * #3 equality/inequality   iter1 == iter2, iter1 != iter2
     */
    // process chars in s until we run out of chars or we hit a whitespace
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // capitalize the current character
    cout << s << endl;
    
    /*
     * If the object is const, then begin and end return a const_iterator;
     * If the object is not const, they return iterator;
     * (Since C++11) cbegin and cend always return a const_iterator.
     */
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();   // it1 has type vector<int>::iterator
    auto it2 = cv.begin();  // it2 has type vector<int>::const_iterator
    auto it3 = v.cbegin();  // it3 has type vector<int>::const_iterator; C++11

    return 0;
}
