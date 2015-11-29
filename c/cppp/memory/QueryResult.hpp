#ifndef QUERYRESULT_HPP
#define QUERYRESULT_HPP
#
#include "TextQuery.hpp"
#include <iostream>

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
    QueryResult(std::string s,
                  std::shared_ptr<std::set<TextQuery::line_no>> p,
                  std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    private:
    std::string sought;                                 // word this query represents
    std::shared_ptr<std::set<TextQuery::line_no>> lines;// lines it's on
    std::shared_ptr<std::vector<std::string>> file;     // input file
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
