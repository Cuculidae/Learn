/**
 * argument_deduction.cpp
 * function template argument deduction.
 * Compilation: g++ -o argument_deduction argument_deduction.cpp
 * Created: 2015-09-28
 */

#include <iostream>
#include <vector>
#include <string>
#include "compare.hpp"
#include "Blob.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

/*
 * As usual, top level consts in either the parameter or the argument are
 * ignored. The only other conversions performed in a call to a function
 * template are:
 *  # const conversions: A function parameter that is a reference (or pointer)
 *    to a const can be passed a reference (or pointer) to a nonconst object.
 *  # Array or function to pointer conversions: If the function parameter is not
 *    a reference type, then the normal pointer conversion will applied to
 *    arguments of array or function type.
 * Other conversions, such as arithmetic conversions, derived-to-base, and
 * user-defined conversions are not performed.
 *
 * Normal conversions are applied to arguments whose types is not a template
 * parameter.
 * Normal conversions also apply for arguments whose template type paramter is
 * explicitly specified.
 *
 * Explicit template arguments are specified inside angle brackets after the
 * function name and  before the argument list.
 * Explicit template arguments are matched to corresponding template paramters
 * from lest to right; An explicit template argument may be omitted only for the
 * trailling (right-most) parameters, and then only if these can be deduced from
 * the function parameters.
 */

// T1 cannot be deduced: it doesn't appear in the function parameter list
template<typename T1, typename T2, typename T3>
T1 sum(T2 a, T3 b)
{
    return a + b;
}

// a trailing return lets us declare the return type after the parameter list is
// seen
template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;    // return a reference to an element from the range
}

int main(void)
{
    int i = 1;
    long lng = 1024;
    // T1 is explicitly specified; T2 and T3 are inferred from the argument
    // types
    auto val = sum<long long>(i, lng);  // long long sum(int, long)
    cout << "val = " << val << endl;
  //compare(lng, 1024);         // error: template parameters don't match
    cout << "compare<long>(lng, 1024): "
        << compare<long>(lng, 1024) << endl;    // ok: compare(long, long)

    vector<int> vi = {1,2,3,4,5};
    Blob<string> ca = {"hi", "bye"};
    auto &j = fcn(vi.begin(), vi.end());    // fcn should return int&
    auto &s = fcn(ca.begin(), ca.end());    // fcn should return string&

    return 0;
}
