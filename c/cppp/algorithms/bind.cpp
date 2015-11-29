/**
 * bind.cpp
 * C++11 bind function.
 * Compilation: g++ -o bind bind.cpp -std=c++11
 * Created: 2015-09-18
 */

#include <functional>   // defines bind, ref, cref and std::placeholders
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::bind;
using std::ref;
using std::sort;
using std::for_each;
using std::vector;
using std::ostream;
using namespace std::placeholders;

/*
 * The general form of a call to bind is:
 *  auto newCallable = bind(callable, arg_list);
 * where newCallable is itself a callable object and arg_list is a
 * comma-separated list of arguments that correspond to the parameters of the
 * given callable.The arguments in arg_list may include names of the form _n,
 * where n is an integer. These arguments are placeholders representing the
 * parameters of newCallableThey stand in place of the arguments that will be
 * passed to newCallable.
 *
 * The _n names are defined in a namespace named placeholders. That namespace is
 * itself defined inside the std namespace. The placeholders namespace is
 * defined in the functional header.
 *
 * By default, the arguments to bind that are not placeholders are copied into
 * the callable object that bind returns.
 *
 * The ref function returns an object that contains the given reference and that
 * is itself copyable. There is also a cref function that generates a class that
 * holds a reference to const. Like bind, the ref and cref functions are defined
 * in the functional header.
 */

bool less(int i, int j)
{
    return i - j;
}

void print(ostream &os, int i, char c)
{
    os << i << c;
}

int main(void)
{
    vector<int> iv{0, 1, 2, 4, 5, 6, 7, 8, 9};
    sort(iv.begin(), iv.end(), bind(less, _2, _1));
    for_each(iv.begin(), iv.end(), bind(print, ref(cout), _1, ' '));
    cout << endl;

    return 0;
}
