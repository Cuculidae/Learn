/**
 * elimDups.cpp
 * Compilation: g++ -o elimDups elimDups.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::vector;
using std::string;
using std::istringstream;

void elimDups(vector<string> &words);

/*
 * A call to sort arranges the elements in the input range into sorted order
 * using the element type's < operator.
 *
 * The unique algorithm rearranges the input range to eliminate adjacent
 * duplicated entries, and returns an iterator that denotes the end of the range
 * of the unique values.
 */

int main(void)
{
    string text = "the quick red fox jumps over the slow red turtle";
    istringstream is(text);
    vector<string> words;
    string s;

    while (is >> s)
        words.push_back(s);

    elimDups(words);

    for (const auto &s : words)
        cout << s << " ";
    cout << endl;

    return 0;
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // eliminate duplicates and return an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}
