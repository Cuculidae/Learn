/**
 * ostring.cpp
 * ostringstream in <sstream> read from a string.
 * Compilation: g++ -o ostring ostring.cpp
 * Created: 2015-09-14
 */

#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

/*
 * The ostringstream type inherits std::ostream.
 *
 * The ostringstream type writes a string.
 *
 * sstream strm;    strm is an unbound sstream. sstream is one of the types
 *                  defined in the <sstream> header.
 * sstream strm(s); strm is an sstream that holds a copy of string s. This
 *                  constructor is explicit.
 * strm.str();      returns a copy of the string that strm holds.
 * strm.str(s);     Copy the string s into strm. returns void.
 *
 */

int main(void)
{
    ostringstream strm;         // an unbound ostringstream
    string s, rsp;

    do {
        cout << "getline(cin, s): ";
        getline(cin, s);
    
        cout << "execute strm.str(s)? (yes/no): ";
        getline(cin, rsp);                  // read interactive respose
        if (rsp[0] != 'n') {
            strm.str(s);                    // copies s into strm
            cout << " after strm.str(s):\n";
        }
        cout << " cout << strm.str(): ";
        cout << strm.str() << '\n';     // outputs the string strm holds

        cout << "getline(cin, s): ";
        getline(cin, s);
        strm << s;                          // writes string
        cout << " after strm << s:\n";
        cout << " cout << strm.str(): ";
        cout << strm.str() << '\n';         // outputs the string strm holds

        cout << "Continue test? (yes/no): ";
        getline(cin, rsp);                  // read interactive respose
        cout << endl;
    } while (rsp[0] != 'n');

    return 0;
}
