/**
 * seek.cpp
 * Random access to a stream.
 * Compilation: g++ -o seek seek.cpp -std=c++11
 * Created: 2015-10-15
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::string;
using std::fstream;

/*
 * Although these seek and tell functions are defined for all the stream types,
 * whether they do anything useful depends on the device to which the stream is
 * bound. On most systems, the streams bound to cin, cout, cerr, and clong do
 * not support random access.
 *
 *              Seek and Tell Functions
 * *****************************************************************************
 * tellg()          Return the current position of the marker in an input stream
 * tellp()          (tellg) or an output stream(tellp).
 * seekg(pos)       Reposition the marker in an input or output stream to the
 * seekp(pos)       given absolute address in the stream. pos is usually a value
 *                  returned by a previous call to the corresponding tellg or
 *                  tellp function.
 * seekp(off, from) Reposition the marker for an input or output stream integral
 * seekg(off, from) number off characters ahead or behind from. from can be one of
 *                      # beg, seek relative to the beginning of the stream
 *                      # cur, seek relative to the current position of the stream
 *                      # end, seek relative to the end of the stream
 * *****************************************************************************
 * The g versions indicate that we are "getting" (reading) data, and the p
 * functions indicate that we are "putting" (writing) data.
 */

int main()
{
    // open for input and output and preposition file pointers to end-of-file
    fstream inOut("copyOut", 
                    fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }
    // inOut is opened in ate mode, so it starts out positioned at the end
    auto end_mark = inOut.tellg();  // remember original end-of-file position
    inOut.seekg(0, fstream::beg);   // reposition to the start of the file
    size_t cnt = 0;                 // accumulator for the byte count
    string line;                    // hold each line of input
    // while we haven't hit an error and are still reading the original data
    while (inOut && inOut.tellg() != end_mark
            && getline(inOut, line)) {  // and can get another line of input
        cnt += line.size() + 1;         // add 1 to account for the newline
        auto mark = inOut.tellg();      // remember the read position
        inOut.seekp(0, fstream::end);   // set the write marker to the end
        inOut << cnt;                   // write the accumulated length
        // print a separator if this is not the last line
        if (mark != end_mark)   inOut << " ";
        inOut.seekg(mark);              // restore the read position
    }
    inOut.seekp(0, fstream::end);       // seek to the end
    inOut << '\n';                      // write a newline at end-of-file

    return 0;
}
