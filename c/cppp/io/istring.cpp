/**
 * istring.cpp
 * istringstream in <sstream> read from a string.
 * Compilation: g++ -o istring istring.cpp
 * Created: 2015-09-14
 */

#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

/*
 * The istringstream type inherits std::istream.
 *
 * The istringstream type reads a string.
 *
 * sstream strm;    strm is an unbound sstream. sstream is one of the types
 *                  defined in the <sstream> header.
 * sstream strm(s); strm is an sstream that holds a copy of string s. This
 *                  constructor is explicit.
 * strm.str();      returns a copy of the string that strm holds.
 * strm.str(s);     Copy the string s into strm. returns void.
 *
 * When the string has been completely read, eof is signaled and the next
 * operation would fail.
 */

int main(void)
{
    istringstream strm;         // an unbound istringstream
    string s;

    do {
        cout << "input a line of text:\n";
        getline(cin, s);
    
        strm.str(s);            // copies s into strm
        while (strm >> s)
            cout << s << endl;
        strm.clear();           // iostate should be clear, otherwise next input would fail
        cout << strm.str();     // outputs the string strm holds
        cout << '\n' << endl;
    } while (cin);

    return 0;
}
