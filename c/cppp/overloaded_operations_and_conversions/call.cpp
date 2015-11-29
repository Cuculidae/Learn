/**
 * call.cpp
 * Calling an overloaded operator directly or indirectly.
 * Compilation: g++ -o call call.cpp -std=c++11
 * Created: 2015-09-23
 */

#include "Sales_data.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    //cout << operator+(1,1) << endl;   // error

    Sales_data item1("123-456-789", 1, 2);
    Sales_data item2("123-456-789", 1, 2);

    cout << item1 + item2 << endl;              // indirect call
    cout << operator+(item1, item2) << endl;    // direct call

    item1 += item2;             // expression-base call
    cout << item1 << endl;
    item1.operator+=(item2);    // equivalent call to a member operator function
    cout << item1 << endl;

    return 0;
}
