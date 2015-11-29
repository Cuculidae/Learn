/**
 * string_init.cpp
 * Demonstrate initialization of std::string.
 * Compilation: g++ -o string_init string_init.cpp
 * Created: 2015-09-03
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string s1;  // default initialization, s1 is the empty string
    cout << "s1 = " << s1 << endl;

    string s2 = "hiya"; // s2 is a copy of the string literal 
                           // up to but not including the null character
    cout << "s2 = " << s2 << endl;

    string s3 = s2;     // s3 is a copy of s2
    cout << "s3 = " << s3 << endl;

    string s4("hiya");  // direct initialization
    cout << "s4 = " << s4 << endl;

    string s5(s4);      // s5 is a copy of s4
    cout << "s5 = " << s5 << endl;

    string s6(10, 'c'); // s6 is cccccccccc
    cout << "s6 = " << s6 << endl;

    return 0;
}
