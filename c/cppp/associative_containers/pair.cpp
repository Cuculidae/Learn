/**
 * pair.cpp
 * Compilation: g++ -o pair pair.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <iostream>
#include <utility>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

/*
 * The pair library type is defined in the <utility> header.
 * A pair holds two data members. The data members of the pair have the
 * corresponding types. There is no requirement that the two types be the same.
 *
 * The default pair constructor value initializes the data members.
 *
 * Unlike other library types, the data members of pair are public. These members
 * are named first and second, respectively.
 *
 * Operations on pairs:
 * pair<T1, T2> p;              p is a pair with value initialized members of
 *                              types T1 and T2, respectively.
 * pair<T1, T2> p(v1, v2);      p is a pair with types T1 and T2; the first and
 *                              second members are initialized from v1 and v2,
 *                              respectively.
 * pair<T1, T2> p = {v1, v2};   Equivalent to p(v1, v2).
 * make_pair(v1, v2)            Returns a pair initialized from v1 and v2. The
 *                              type of the pair is inferred from the types of
 *                              v1 and v2.
 * p.first      Returns the (public) data member of p named first.
 * p.second     Returns the (public) data member of p named second.
 * p1 relop p2  Relational operators (<, >, <=, >=). Relational operators are
 *              defined as dictionary ordering: For example, p1 < p2 is true if
 *              p1.first < p2.first or if !(p2.first < p1.first) && p1.second <
 *              p2.second. Uses the elements < operator.
 * p1 == p2     Two pairs are equal if their first and second members are
 * p1 != p2     respectively equal. Uses the elements == operator.
 */

pair<string, int> process(vector<string> &v);

int main(void)
{
    pair<string, string> anon;      // holds two strings
    // C++ list initialization
    pair<string, string> author{"James", "Joyce"};

    cout << author.first << " " << author.second << endl;

    vector<string> sv{"vector of string"};
    pair<string, int> p = process(sv);
    cout << p.first << " " << p.second << endl;

    return 0;
}

/* we can list initialize the return value */
pair<string, int> process(vector<string> &v)
{
    if (!v.empty())
        return {v.back(), v.back().size()}; // list initialize, C++11
    else
        return pair<string, int> ();     // explicitly construct return value
}
