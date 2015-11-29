/**
 * test_DebugDelete.cpp
 * test the DebugDelete class template.
 * Compilation: g++ -o test_DebugDelete test_DebugDelete.cpp -std=c++11
 * Created: 2015-09-27
 */

#include <iostream>
#include <memory>
#include <string>
#include "DebugDelete.hpp"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;

int main(void)
{
    double *p = new double;
    DebugDelete d;      // an object that can act like a delete expression
    d(p);   // calls DeleteDebug::oerator()(double *) const, which deletes p
    int* p2 = new int;
    // calls operator()(int *) on a temporary DebugDelete object
    DebugDelete()(p2);

    // destroying the object to which p points
    // instantiates DebugDelete::operator()<int>(int *)
    unique_ptr<int, DebugDelete> ip(new int, DebugDelete());
    // destroying the object to which sp points
    // instantiates DebugDelete::operator()<string>(string *)
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

    return 0;
}
