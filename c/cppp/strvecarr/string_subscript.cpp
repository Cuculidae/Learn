/**
 * string_subscript.cpp
 * Created: 2015-09-05
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
     * string subscript operation
     * the subscipt operator [] takes a string::size_type value that denotes the
     * position of the character that we want to access. The operator returns a
     * reference to the character at the given position.
     * The values we use to subscript a string must be >= 0 and < size().
     * The library is not required to check the value of an subscript.
     * The result of using an index outside this range is undefined.
     * By implication, subscripting an empty string is undefined.
     */

    const string hexdigits = "0123456789ABCDEF";    // possible hex digits
    cout << "Enters a series of numbers between 0 and 15"
          << " separated by spaces. Hit ENTER when finished: "
          << endl;
    string::size_type n;    // hold numbers from the input
    string result;          // hold the resulting hexify'd string
    while (cin >> n)
        if (n < hexdigits.size())   // ignore invalid input
            result += hexdigits[n]; // fetch the indicated hex digit
    cout << "Your hex number is: " << result << endl;

    return 0;
}
