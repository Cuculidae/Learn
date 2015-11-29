/**
 * istream_iterator.cpp
 * istream_iterator of iostream iterator.
 * Compilation: g++ -o istream_iterator istream_iterator.cpp -std=c++11
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
using std::istream_iterator;
using std::accumulate;
using std::vector;

/*
 * When we create a stream iterator, we must specify the type of objects that
 * the iterator will read or write. An istream_iterator uses >> to read a
 * stream. Therefore, the type that an istream_iterator reads must have an input
 * operator defined.
 *
 * We can default initialize the iterator, which creates an iterator that we can
 * use as the off-the-end value.
 *
 * An iterator bound to a stream is equal to the end iterator once its
 * associated stream hits end-of-file or encounters an IO error.
 *
 * istream_iterator operations: 
 * istream_iterator<T> in(is);  in reads values of type T from input stream is.
 * istream_iterator<T> end;     Off-the-end iterator for an istream_iterator
 *                              that reads values of type T.
 * in1 == in2                   in1 and in2 must read the same type. They are
 * in1 != in2                   equal if they are both the end value or are
 *                              bound to the same input stream.
 * *in                          Returns the value read from the stream.
 * in->mem                      Synonym for (*in).mem.
 * ++in, in++                   Reads the next value from the input stream using
 *                              the >> operator for the element type. As usual,
 *                              the prefix version returns a reference to the
 *                              incremented iterator. The postfix version
 *                              returns the old value.
 *
 * When we bind an istream_iterator to a stream, we are not guaranteed that it
 * will read the stream immediately. The implementation is permitted to delay
 * reading the stream until we use the iterator. We are guaranteed that before
 * we dereference the iterator for the first time, the stream will have been
 * read.
 */

int main(void)
{
    istream_iterator<int> in_iter(cin), eof;    // read ints from cin
    cout << "vector<int> vec(in_iter, eof): ";
    vector<int> vec(in_iter, eof);      // construct vec from an iterator range
    for (const auto i : vec)
        cout << i << " ";
    cout << endl;

    cin.clear();
    cout << "accumulate(in_iter, eof, 0): ";
    cout << accumulate(in_iter, eof, 0) << endl;

    cin.clear();
    istream_iterator<int> in(cin);
    int i;
    cin >> i;
    cout << "cin >> i: " << i << endl;
    cout << "*in: " << *in << endl;
    cin >> i;
    cout << "cin >> i: " << i << endl;
    cout << "*++in: " << *++in << endl;
    cin >> i;
    cout << "cin >> i: " << i << endl;

    return 0;
}
