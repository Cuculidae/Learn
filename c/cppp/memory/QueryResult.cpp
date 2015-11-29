/**
 * QueryResult.cpp
 * The QueryResult class is intended to represent the results of a query. Those
 * results include the set of line numbers associated with the given word and
 * the corresponding lines of text from the input file. These data are stored in
 * objects of type TextQuery. This class has a print function to print the 
 * results in a QueryResult.
 * Compilation: g++ -c QueryResult.cpp
 * Created: 2015-09-22
 */

#include "QueryResult.hpp"

using std::ostream;
using std::endl;

ostream &print(ostream &os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << ((qr.lines->size() > 1) ? " times" : "time") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines) {    // for every element in the set
        os << "\t(line " << num + 1 << ") "
           << (*qr.file)[num] << endl;
    }
    return os;
}
