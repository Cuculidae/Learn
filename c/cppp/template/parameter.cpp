/**
 * parameter.cpp
 * something about template parameters.
 * Compilation: g++ -o parameter parameter.cpp Sales_data.o -std=c++11
 * Created: 2015-09-27
 */

#include <iostream>
#include <functional>
#include "Sales_data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::less;

/*
 * Like the names of function parameters, a template paramter name has no
 * intrinsic meaning.
 * Template parameters follow normal scoping rules. Unlike most other contexts,
 * however, a name used as a template parameter may not be reused within the
 * template.
 *
 * A template declaration must include the template parameters. As with function
 * parameters, the names of a template parameter need not be the same across the
 * declarations and the definition of the same template.
 *
 * By default, the language assumes that a name accessed through the scope
 * operator to a template type parameter is not a type. As a result, if we want
 * to use a type member of a template type parameter, we must explicitly tell
 * the compiler that the name is a type by using the keyword typename. When we
 * inform the compiler that a name represents a type, we must use the keyword
 * typename, not class.
 *
 * Earlier versions of the language, allowed default arguments only with class
 * template. In C++11, we can supply default arguments for both function and
 * class templates. As usual, the types of function template parameters are
 * deduced from their corresponding arguments.
 * Whenever we use a class template, we must always follow the template's name
 * with brackets. In particular, if a class template provides default arguments
 * for all of its template parameters, and we want ot use those defaults, we
 * must put an empty bracket pairt following the template's name.
 */

typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    {
        A tmp = a;  // tmp has the type as the template parameter A, not double
      //double B;   // error: redeclares template parameter B
    }
}

// declares but does not define compare and Blob
//template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;
// all three uses of calc refer to the same function template
template <typename T> T calc(const T&, const T&);   // declaration
template <typename U> U calc(const U&, const U&);   // declaration
// definition of the template
template <typename Type>
Type calc(const Type &a, const Type &b) { /* ... */ }

/* expects a container as its argument and uses typename to specify its return
 * type and to generate a value initialized element to return if c is empty.
 */
template <typename T>
typename T::value_type top(const T& c)
{
    if (! c.empty())
        return c.back();
    else
        return typename T::value_type();
}

// compare has a default template argument, less<T>
// and a default function argument, F()
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

template <class T = int> class Numbers {    // by default T is int
public:
    Numbers(T v = 0): val(v) { }
private:
    T val;
};

int main(void)
{
    cout << "compare(1, 2): " << compare(1,2) << endl;
    Sales_data item1(cin), item2(cin);
    cout << "compare(item1,item2): " 
         << compare(item1, item2, compareIsbn) << endl;

    Numbers<> average_precision; // empty <> says we want the default type

    return 0;
}
