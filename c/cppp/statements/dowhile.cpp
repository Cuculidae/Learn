/**
 * dowhile.cpp
 * do while statement.
 * Compilation: g++ -o dowhile dowhile.cpp
 * Created: 2015-09-08
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
     * A do while ends with a semicolon after the parenthesized condition.
     * Variables used in condition must be defined outside the body of the do
     * while statement.
     * The do while loop does not allow variable definition in the condition.
     */
    // repeatedly ask the user for a pair of numbers to sum
    string rsp;     // used in the condition; can't be defined inside the do
    do {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
              << " = " << val1 + val2 << "\n\n"
              << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');

    return 0;
}
