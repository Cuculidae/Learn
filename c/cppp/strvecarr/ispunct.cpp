/**
 * ispunct.cpp
 * ispunct function is <cctype>.
 * Compilation: g++ -o ispunct ispunct.cpp -std=c++11
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
    string s("Hello Word!!!");
    // punct_cnt has the same type that s.size() returns 
    decltype(s.size()) punct_cnt = 0;
    // count the number of punctuation numbers in s
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
          << " punctuation characters in " << s << endl;

    return 0;
}
