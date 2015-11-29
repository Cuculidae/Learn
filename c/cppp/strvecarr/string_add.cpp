/**
 * string_add.cpp
 * Concatenation of strings.
 * Compilation: g++ -o string_add string_add.cpp
 * Created: 2015-09-04
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string s1 = "hello", s2 = "world";
    // adds two string
    cout << s1+s2 << endl;

    // the string library let us convert both character literals
    // and character string literals to strings.
    // When we mix strings and string or character literals, at least one
    // operand to each + operator must be of string type.
    string s3 = s1 + ", " + s2 + '\n';
    cout << s3;

    return 0;
}
