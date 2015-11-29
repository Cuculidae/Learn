/**
 * people.cpp
 * Compilation: g++ -o peopel people.cpp -std=c++11
 * Created: 2015-09-14
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;

/*
 * Types in <sstream> inherits types in <iostream>.
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

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &num);
const string &format(const string &num);

int main(void)
{
    string line, word;          // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input

    // read the input a line at a time until cin hits eof (or another error)
    while (getline(cin, line)) {
        PersonInfo info;        // create an object to hold this record's data
        istringstream record(line);         // bind record to the line we've just read
        record >> info.name;                // read the name
        while (record >> word)              // read the phone numbers
            info.phones.push_back(word);    // and store them
        people.push_back(info);
    }

    for (const auto &entry : people) {      // for each entry in people
        ostringstream formatted, badNums;   // objects created on each loop
        for (const auto &nums : entry.phones) { // for each number
            if (!valid(nums)) {
                badNums << " " << nums; // string in badnums
            } else {
                // writes to formatted string
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())          // there were no bad numbers
            cout << entry.name << " "       // print the name
                << formatted.str() << endl; // and formatted numbers
        else                                    // print the name and bad numbers
            cerr << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}

bool valid(const string &num)
{
    return true;
}

const string &format(const string &num)
{
    return num;
}
