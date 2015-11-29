/**
 * TextQuery.cpp
 * Hold the input file in a way that makes querying the file easy.
 * Compilation: g++ -c TextQuery.cpp QueryResult.o -std=c++11
 * Created: 2015-09-22
 */

#include "TextQuery.hpp"
#include "QueryResult.hpp"

using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::vector;
using std::string;

// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {     // for each line in the file
        file->push_back(text);      // remember this line of text
        int n = file->size() - 1;   // the current line number
        istringstream line(text);   // separate the line into wordsk
        string word;
        while (line >> word) {      // for each word in that line
            // if word isn't already in wm, subsripting adds a new entry
            auto &lines = wm[word]; // lines ia shared_ptr
            if (!lines)             // that pointer is null the first time we see word
                lines.reset(new set<line_no>);  // allocate a new set
            lines->insert(n);       // insert this line number
        }
    }
}

QueryResult
TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);   // no found
    else
        return QueryResult(sought, loc->second, file);
}
