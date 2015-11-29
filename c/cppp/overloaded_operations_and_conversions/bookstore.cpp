#include "Sales_data.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main(void)
{
    Sales_data total;           // variable hold the running sum
    if (cin >> total) {         // read the first transaction
        Sales_data trans;       // variable to hold data for the next transaction
        while (cin >> trans) {
            if (total.isbn() == trans.isbn())   // check the isbn
                total += trans;                 // update the running total
            else {
                cout << total << endl;          // print the result
                total = trans;                  // process the next book
            }
        }
        cout << total << endl;          // print the last transaction
    }
    else {                              // there is no input
        cerr << "No data?!" << endl;    // notify the user
    }

    return 0;
}
