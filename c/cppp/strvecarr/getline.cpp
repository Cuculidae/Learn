/**
 * getline.cpp
 * Compilation: g++ -o getline getline.cpp
 * Created: 2015-09-04
 */
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void)
{
    /*
     * getline defined in header <string>
     * getline takes an input stream and a string, returns the istream.
     * Reads up to the first newline and stores what it read.
     * The newline that causes getline to return is discarded; the newline is
     * not stored in the string.
     */

    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line)) 
        cout << line << endl;

    return 0;
}
