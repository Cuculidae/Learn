/**
 * PrintString.cpp
 * Fuction-Object classes with state.
 * Compilation: g++ -o PrintString PrintString.cpp -std=c++11
 * Created: 2015-09-24
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::for_each;

/*
 * Like any other class, a function-object class can have additional members
 * aside from operator(). Function-object classes often contain data members
 * that are used to customize the operations in the call operator.
 */

class PrintString
{
    public:
        PrintString(ostream &o = cout, char c = ' ') :
            os(o), sep(c) { }
        void operator()(const string &s) const { os << s << sep; }
        
    private:
        ostream &os;    // stream on which to write
        char sep;       // character to print after each output
};

int main(void)
{
    string s = "hello, world";
    PrintString printer;    // uses the defaults; prints to cout
    printer(s);             // prints s followed by a space on cout;
    PrintString errors(cerr, '\n');
    errors(s);              // prints s followed by a newline on cerr

    vector<string> vs{"a", "an", "the"};
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

    return 0;
}
