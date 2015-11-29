/**
 * buffer.cpp
 * Managing the output buffer.
 * Compilation: g++ -o buffer buffer.cpp
 * Created: 2015-09-13
 */

#include <iostream>

using std::cout;
using std::cin;
using std::ends;
using std::endl;
using std::flush;
using std::unitbuf;
using std::nounitbuf;

/*
 * There are several conditions that cause the buffer to be flushed:
 * # The program completes normally.
 * # The buffer can become full.
 * # Flush the buffer explicitly using a manipulator such as endl.
 * # Use the unitbuf manipulator to set the stream's internal state to
 *   empty the buffer after each output operation.
 * # The output stream stream is flushed whenever the stream to which it is tied
 *   is read or written. The library ties cin to cout, cerr to cout.
 *
 * Output buffers are not flushed if the programterminates abnormally.
 *
 * std::endl    add a newline and flush the buffer
 * std::ends    add a null character and flush the buffer
 * std::flush   flush but adds no characters
 *
 * std::unitbuf   tells the stream to do a flush after every subsequent write.
 * std::nounitbuf restores the stream to use normal, system-managed buffer
 *                flushing
 *
 */

int main(void)
{
    cout << "hi!" << endl;      // writes hi and a newline, then flushes the buffer
    cout << "hi!" << flush;     // writes hi, then flushes the buffer; adds no data
    cout << "hi!" << ends;      // writes hi and a null, the flushes the buffer

    cout << unitbuf;            // all writes will be flushed immediately
    // any output if flushed immediately, no buffering
    cout << nounitbuf;          // returns to normal buffering

    return 0;
}
