/**
 * count_if.cpp
 * Compilation: g++ -o count_if count_if.cpp -std=c++11
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
using std::count_if;
using std::vector;
using std::string;
using std::istringstream;

void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);

/*
 * A call to sort arranges the elements in the input range into sorted order
 * using the element type's < operator.
 *
 * The version of sort that takes a binary predicate uses the given predicate in
 * place of < to compare elements.
 *
 * A stable sort maintains the original order among equal elements.
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

    elimDups(words);    // put words into alphabetical order and remove duplicates

    for (const auto &s : words)
        cout << s << " ";
    cout << endl;

    // resort by length, maintaining alphabetical order among words of the same
    // length
    stable_sort(words.begin(), words.end(), isShorter);

    for (const auto &s : words)
        cout << s << " ";
    cout << endl;

    // how may words greater than length 6
    cout << count_if(words.begin(), words.end(),
            [](const string &s) { return s.size() > 6; })
         << " word(s) greater than length 6" << endl;

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

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
