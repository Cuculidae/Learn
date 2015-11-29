/**
 * ostream_iterator.cpp
 * ostream_iterator of iostream iterator.
 * Compilation: g++ -o ostream_iterator ostream_iterator.cpp -std=c++11
 * Created: 2015-09-19
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::vector;

/*
 * An ostream_iterator can be defined for any type that has an output operator
 * (the << operator). When we create an ostream_iterator, we may (optionally)
 * provide a second argument that specifies a character string to print
 * following each element. That string must be a C-style character string (i.e.,
 * a string literal or a pointer to a null-terminated array). We must bind an
 * ostream_iterator to a specific stream. There is no empty or off-the-end
 * ostream_iterator.
 *
 * ostream_iterator iterator Operations:
 * ostream_iterator<T> out(os); out writes values of type T to output stream os.
 * ostream_iterator<T> out(os, d);  out writes values of type T followed by d to
 *                                  output stream os. d points to a
 *                                  null-terminated character array.
 * out = val    Writes val to the ostream to which out is bound using the <<
 *              operator. val must have a type that is compatible with the type
 *              that out can write.
 * *out, ++out, These operations exist but do nothing to out. Each operator
 * out++        returns out.
 */

int main(void)
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec)
        *out_iter++ = e;    // the assignment writes this element to cout
    cout << endl;

    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    return 0;
}
