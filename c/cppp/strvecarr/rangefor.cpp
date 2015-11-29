/**
 * rangefor.cpp
 * Syntax of C++11 range for statement.
 * Compilation: g++ -o rangefor rangefor.cpp -std=c++11
 * Created: 2015-09-05
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
    /*
     * range for statement (Since C++11)
     * for (declaration : expression)
     *      statement;
     *   where expression is an object of a type that represents a sequence, and
     *   declaration defines the variable that we'll use to access the
     *   underlying elements in the sequence.
     * Iterates through the elements in a given sequence
     *
     * Note: The body of the range for must not change the size of the sequence
     *       over which it is iterating.
     */
    string str("some string");
    // print the characters in str one character in a line
    for (auto c : str)  // for every char in str
        cout << c << endl;

    return 0;
}
