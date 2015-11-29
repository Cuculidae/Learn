/**
 * bookstore.cpp
 * Compilation: g++ -o bookstore bookstore.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <iterator>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

int main(void)
{
    istream_iterator<Sales_item> item_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");

    Sales_item sum;
    if (item_iter != eof) {
        // store the first transaction in sum and read the next record
        Sales_item sum = *item_iter++;
        while (item_iter != eof) {
            // if the current transaction (which is stored in item_iter) has the
            // same ISBN
            if (item_iter->isbn() == sum.isbn()) {
                sum += *item_iter++;    // add it to sum and read the next transaction
            }
            else {
                out_iter = sum;     // write the current sum
                sum = *item_iter++; // read the next transaction
            }
        }
        out_iter = sum; // remember to print the last records
    }
    else {
        cerr << "No data?!!!" << endl;
    }

    return 0;
}
