/**
 * alias.cpp
 * C++11 template type alias.
 * Compilation: g++ -o alias alias.cpp -std=c++11
 * Created: 2015-09-26
 */

#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::pair;

/*
 * A template type alias is a synonym for a family of classes.
 */

int main(void)
{
    /* in C++11, we can define a type alias for a class template */
    template<typename T> using twin<T> = parir<T, T>;
    twin<string> authors{"James", "Joyce"}; // author is a pair<string, string>
    cout << authors.first << ' ' << authors.second << endl;

    /* when we define a template type alias, we can fix one or more of the
     * template parameters
     */
    template <typename T> using partNo = pair<T, unsigned>;
    partNo<string> books{"C++ Primer", 10};   // books is a pair<string, unsigned>
    cout << books.first << ' ' << books.second << endl;

    return 0;
}
