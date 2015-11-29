/**
 * tie.cpp
 * tie a stream to an ostream.
 * Compilation: g++ -o tie tie.cpp
 * Created: 2015-09-13
 */

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ostream;

/*
 * When an input stream is tied to an output stream, any attempt to read the
 * input streamwill first flush the buffer associated with the output stream.
 * 
 * The library ties cin to cout, cerr to cout.
 *
 * s.tie()      returns a pointer to the output stream, if any, to which this
 *              object otherwise return nullptr
 * s.tie(ostream *) takes a pointer to an ostream and ties itself to that
 *                  ostream, returns a pointer to old tied ostream
 *
 * Each stream can be tied to at most one streamat a time. However, multiple
 * streams can tie themselves to the same ostream.
 */

int main(void)
{
    ostream *old_tie = cin.tie(&cerr);

    int i;
    while (cin) {
        cout << "before read cin ";
        cin >> i;
        cout << "after read cin\n";
    }

    cin.tie(old_tie);

    return 0;
}
