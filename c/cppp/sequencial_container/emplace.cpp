/**
 * emplace.cpp
 * Sequential container emplace operatioins (C++11).
 * Compilation: g++ -o emplace emplace.cpp -std=c++11
 * Created: 2015-09-16
 */

#include <iostream>
#include <deque>
#include "Sales_data.hpp"

using std::cout;
using std::endl;
using std::deque;

/*
 * C++11 introduces three new members -- emplace_front, emplace_back and
 * emplace -- that construct rather than copy elements.
 *
 * When we call an emplace member, we pass arguments to a constructor for the
 * element type. The emplace members use those arguments to construct an element
 * directly in space managed by the container.
 *
 * The emplace functions construct elements in the container. The arguments to
 * these functions must match a constructor for the element type.
 */

int main(void)
{
    deque<Sales_data> c;

    // construct a Sales_data object at the end of c
    // uses the three-argument Sales_data constructor
    c.emplace_back("978-0590353403", 25, 15.99);

    c.emplace_back();   // uses the Sales_data default constructor
    
    c.emplace(c.begin(), "999-9999999999"); // uses Sales_data(string)
    // uses the Sales_data constructor that takes an ISBN, a count, and a price
    c.emplace_front("978-0590353403", 25, 15.99);

    for (const auto &s : c)
        print(cout, s) << endl;

    return 0;
}
