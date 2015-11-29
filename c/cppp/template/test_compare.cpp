/**
 * test_compare.cpp
 * function template.
 * Compilation: g++ -o test_compare test_compare.cpp -std=c++11
 * Created: 2015-09-26
 */

#include "compare.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::less;

int main(void)
{
    // instantiates int compare(const int&, const int&)
    cout << "compare(1, 2): " << compare(1,2) << endl;  // T is int
    // instantiates int compare(const vector<int>&, const vector<int>&)
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << "compare(vec1, vec2): " << compare(vec1, vec2) << endl; // T is vector<int>

    // int compare(const char (&p1)[3], const char (&p2)[4])
    cout << "compare(\"hi\", \"mom\"): " << compare("hi", "mom") << endl;

    return 0;
}
