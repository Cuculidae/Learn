#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP
#
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;
class TextQuery
{
    public:
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<std::vector<std::string>> file; // input file
        // map of each word to the set of lines in which that word appears
        std::map<std::string,
                  std::shared_ptr<std::set<line_no>>> wm;
};

#endif
