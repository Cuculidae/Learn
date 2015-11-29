/**
 * toupper.cpp
 * toupper function in <cctype>.
 * Compilation: g++ -o toupper toupper.cpp -std=c++11
 * Created: 2015-09-05
 */

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string s("Hello World!!!");
    // convert s to uppercase
    for (auto &c : s)   // note c is a reference
        c = toupper(c);
    cout << s << endl;

    return 0;
}
