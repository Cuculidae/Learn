/**
 * bookstore.cpp
 * bookstore program fstream version.
 * Compilation: g++ -o bookstore bookstore.cpp Sales_data.o -std=c++11
 * Created: 2015-09-13
 */

#include "Sales_data.hpp"
#include <fstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);       // open the file of transactions
    ofstream out(argv[2]);      // open the output file

    Sales_data total;           // variable hold the running sum
    if (read(in, total)) {     // read the first transaction
        Sales_data trans;       // variable to hold data for the next transaction
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn())   // check the isbn
                total.combine(trans);           // update the running total
            else {
                print(out, total) << endl;     // print the result
                total = trans;                  // process the next book
            }
        }
        print(out, total) << endl;     // print the last transaction
    }
    else {                              // there is no input
        cerr << "No data?!" << endl;    // notify the user
    }

    in.close();
    out.close();

    return 0;
}
