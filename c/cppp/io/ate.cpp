/**
 * ate.cpp
 * ofstream::ate mode
 * Compilation: g++ -o ate ate.cpp
 * Created: 2015-09-14
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

/*
 * Open mode is defined as static constexpr bit mask in std::io_base class.
 *
 * Seek to the end immediately after the open.
 * The ate and binary modes may be specified on any file stream object type
 * and in combination with any other file modes.
 */

int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cout << "argv[1] should specify a file\n";
        return 1;
    }
    ofstream out(argv[1], ofstream::ate);

    out << "This file is open in mode ofstream::out | ofstream::ate"
        << endl;

    /* To associate a file stream with a different file, we must fist close the
     * existing file.
     */
    out.close();

    /* We can subsequently associate a file stream with a file by calling open.
     * If a call to open fails, failbit is set.
     */
    ifstream in;
    in.open(argv[1], ofstream::in | ofstream::ate);
    string s;
    while (getline(in, s))
        cout << s << endl;
    in.close();

    ostringstream ostr("1 2");
    ostr << 3;
    cout << "after writing the int '3' to append stream \"1 2\""
        << "< str() = \"" << ostr.str() << "\"\n";

    ostringstream ate("1 2", ostringstream::ate);
    ate << 3;
    cout << "after writing the int '3' to append stream \"1 2\""
        << "< str() = \"" << ate.str() << "\"\n";

    return 0;
}
