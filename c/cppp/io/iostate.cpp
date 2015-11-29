/**
 * iostate.cpp
 * iostream condition state.
 * Compilation: g++ -o iostate iostate.cpp
 * Created: 2015-09-13
 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::istream;
using std::string;

/*
 * No copy or assign for IO object.
 *
 * The types ifstream and istringstream inherit from istream.
 * The types ofstream and ostringstream inherit from ostream.
 *
 * The IO library defines a machine-dependent integral type named iostate that
 * it uses to convey information about the state of a stream. This type is used
 * as a collection of bits. The IO classes define four constexpr values of type
 * iostate that represent particular bit patterns.
 *******************************************************************************
 * strm::iostate    strm is one of the IO types. iostate is a machine-dependent*
 *                  integral type that represents the condition state of a     *
 *                  stream.                                                    *
 * strm::badbit     strm::iostate value used to indicate that a stream is      *
 *                  corrupted.                                                 *
 * strm::failbit    strm::iostate value used to indicate that an IO operation  *
 *                  failed.                                                    *
 * strm::eofbit     strm::iostate value used to indicate that a stream hit     *
 *                  end-of-file.                                               *
 * strm::goodbit    strm::iostate value used to indicate that a stream is not  *
 *                  in an error state. This value is guaranteed to be zero.    *
 * s.eof()          true if eofbit in the stream s is set.                     *
 * s.fail()         true if failbit or badbit in the stream s is set.          *
 * s.bad()          true if badbit in the stream s is set.                     *
 * s.good()         true if the stream s is in a valid state.                  *
 * s.clear()        Reset all condition values in the stream s to valid state. *
 *                  Returns void.                                              *
 * s.clear(flags)   Reset the condition of s to flags. Type of flags is        *
 *                  strm::iostate. Returns void.                               *
 * s.setstate(flags) Adds specified condition(s) to s. Type of flags is        *
 *                  strm::iostate.                                             *
 * s.rdstate()      Returns current condition of s as a strm::iostate value.   *
 *******************************************************************************
 *
 * Reaching end-of-file sets both eofbit and failbit.
 * The goodbit is guaranteed to have the value 0.
 *
 */

// print the iostate of an istream
void print(istream &is);

int main(void)
{
    cout << "initializing..."<< endl;   // just start
    print(cin);
    cout << endl;

    int i;                              // variable to hold an int read
    string rsp;                         // hold user response
    do {
        cout << "\ntesting iostate\n";
        cout << "cin >> i: ";
        cin >> i;
        print(cin);                     // print io state
        cout << '\n';
        if (!cin) {                     // clear invalid input
            if (!cin.eof()) {
                cin.clear();             // clear condition state
                string garbage;
                getline(cin, garbage);
            }
            cin.clear();                // clear condition state
            cout << "cin iostate cleared\n"; 
        }
        cout << "Continue test (yes/no)? ";
        cout << flush; 
        cin >> rsp;
    } while (rsp[0] != 'n');            // keep testing

    return 0;
}

void print(istream &is)
{
    istream::iostate state = is.rdstate();      // read the iostate

    cout << "Is badbit set?  "                     // test the badbit
        << ((istream::badbit & state) ? "YES" : "NO")
        << endl;
    cout << "Is failbit set?  "                    // test the failbit
        << ((istream::failbit & state) ? "YES" : "NO")
        << endl;
    cout << "Is eofbit set?  "                     // test the eofbit
        << ((istream::eofbit & state) ? "YES" : "NO")
        << endl;
    /* strm::goodbit is guaranteed to be 0 */
    cout << "Is goodbit set?  "                    // test the goodbit
        << ((istream::goodbit & state) ? "YES" : "NO")
        << endl;

    cout << "bad() returns  "                       // test bad() function
         << is.bad() << endl;
    cout << "fail() returns  "                      // test fail() function
         << is.fail() << endl;
    cout << "eof() returns  "                       // test eof() function
         << is.eof() << endl;
    cout << "good() returns  "                      // test good() function
         << is.good(); 

}
