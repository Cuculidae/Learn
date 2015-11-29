/**
 * push_back.cpp
 * Member function push_back of std::vector.
 * Compilation: g++ -o push_back push_back.cpp -std=c++11
 * Created: 2015-09-07
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
    string word;
    vector<string> text;
    while (cin >> word)
        text.push_back(word);   // append word to text

    for (auto s : text)
        cout << s << endl;

    return 0;
}
