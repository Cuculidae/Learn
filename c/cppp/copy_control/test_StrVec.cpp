/**
 * test_StrVec.cpp
 * test the StrVec class.
 * Compilation: g++ -o test_StrVec test_StrVec.cpp StrVec.o -std=c++11
 * Created: 2015-11-07
 */

#include <iostream>
#include "StrVec.hpp"

using namespace std;

int main()
{
    StrVec sv = {"Hello", "World", "!"};
    for (const auto &s : sv)
        cout << s << ' ';
    cout << endl;

    sv.reserve(5);
    cout << "reverve(5) capacity: " << sv.capacity()
         << " , size: " << sv.size() << endl;

    sv.resize(3);
    cout << "resize(3) capacity: " << sv.capacity()
         << " , size: " << sv.size() << endl;
    sv.resize(4);
    cout << "resize(4) capacity: " << sv.capacity()
         << " , size: " << sv.size() << endl;

    sv.push_back("from");
    sv.push_back("cai");
    for (const auto &s : sv)
        cout << s << ' ';
    cout << endl;

    return 0;
}
