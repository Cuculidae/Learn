/**
 * runQueries.cpp
 * Search a given file for words that might occur in it.
 * Compilation: g++ -o runQueries runQueries.cpp -std=c++11
 * Created: 2015-09-22
 */

#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile);

int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cout << "Usage: runQueries INFILE" << endl;
        return 1;
    }
    ifstream infile(argv[1]);

    runQueries(infile);
    infile.close();

    return 0;
}

void runQueries(ifstream &infile)
{
    // infile is an ifsttream that is the filewe want to query
    TextQuery tq(infile);   // store the file and build the query map
    // iterate with the user;prompt for a word to find and print the results
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit eof on the input or if a 'q' is entered 
        if (!(cin >> s) || s == "q")    break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}
