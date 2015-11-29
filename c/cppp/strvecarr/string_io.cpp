/**
 * string_io.cpp
 * Demonstrate string I/O operations.
 * Compilation: g++ -o string_io string_io.cpp
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
     * The string input operator reads and discards any leading whitespaces(e.g.
     * spaces, newlines, tabs). It then reads characters until the next
     * whitespace character is encounter.
     */

    string s;

    cout << "cin >>s; getline(cin, s)" << endl;
    cin >> s;
    cout << s << endl;
    getline(cin, s);
    cout << s << endl;

    // reads whitespace-separated string from cin into s
    while (cin >> s)
        cout << s << endl;

    return 0;
}
