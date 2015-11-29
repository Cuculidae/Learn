/**
 * test_strblob.cpp
 * Compilation: g++ -o test_strblob test_strblob.cpp -std=c++11
 * Created: 2015-09-21
 */
#include "StrBlob.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
    StrBlob b1 = {"a", "an", "the"};
    StrBlob b2 = b1;
    
    cout << "b1: ";
    for (const auto &b : b1) {
        cout << b << ' ';
    }
    cout << endl;
    cout << "b2: ";
    for (const auto &b : b2) {
        cout << b << ' ';
    }
    cout << endl;

    b2.push_back("about");

    cout << "b1: ";
    for (const auto &b : b1) {
        cout << b << ' ';
    }
    cout << endl;
    cout << "b2: ";
    for (const auto &b : b2) {
        cout << b << ' ';
    }
    cout << endl;

    return 0;
}
