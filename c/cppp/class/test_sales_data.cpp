/*
 * test_salse_data.cpp
 * test the Sales_data class.
 * Compilation: g++ -o test_sales_data test_sales_data.cpp -std=c++11
 * Created: 2015-09-12
 */

#include "Sales_data.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    /*
     * The correct way to define an object that uses the default constructor for
     * initialization is to leave off the trailing, empty paratheses.
     */

    // Sales_data obj();    // oops! declares a function not an object
    // Sales_data obj;      // ok: obj is an object not a function
    Sales_data a;
    read(cin, a);
    Sales_data b(cin);
    print(cout, a) << endl;
    print(cout, b) << endl;

    return 0;
}
