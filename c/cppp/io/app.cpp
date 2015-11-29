/**
 * app.cpp
 * ofstream::app mode
 * Compilation: g++ -o app app.cpp
 * Created: 2015-09-14
 */

#include <fstream>

using std::ofstream;
using std::endl;

/*
 * Open mode is defined as static constexpr bit mask in std::io_base class.
 *
 * app mode may be specified so long as trunc is not. If app is specified, the
 * file is always opened in outputmode, even if out was not explicitly
 * specified.
 */

int main(int argc, char *argv[])
{
    ofstream out(argv[1], ofstream::app);

    out << "This file is open in mode ofstream::app"
        << endl;

    out.close();

    return 0;
}
