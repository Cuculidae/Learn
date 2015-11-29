/**
 * accumulate.cpp
 * Defined in <numeric>
 * Compilation: g++ -o accumulate accumulate.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <numeric>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::accumulate;

/*
 * The type of the third argument to accumulate determines which addition
 * operator is used and is the type that accumulate returns.
 */

int main(void)
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;

    vector<string> svec = {"C++", " ", "Primer", " ", "Fifth ed"};
    cout << accumulate(svec.cbegin(), svec.cend(), string("")) << endl;

    return 0;
}
