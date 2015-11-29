/**
 * partition.cpp
 * Compilation: g++ -o partition partition.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::partition;
using std::istringstream;

bool longer5(const string &s);

/*
 * The library defines an algorithm named partition that takes a predicate and
 * partitions the container so that values for which the predicate is true
 * appear in the first part and those for which the predicate is false appear in
 * the second part. The algorithm returns an iterator just past the last element
 * for which the predicate returned true.
 */

int main(void)
{
    string text("the quick red fox jumps over the slow red turtle");
    istringstream is(text);
    string s;

    vector<string> words;
    while (is >> s)
        words.push_back(s);

    auto it = partition(words.begin(), words.end(), longer5);

    for (auto b = words.cbegin(); b != it; ++b)
        cout << *b << " ";
    cout << endl;

    return 0;
}

bool longer5(const string &s)
{
    return s.size() >= 5;
}
