/**
 * bitset.cpp
 * Compilation: g++ -o bitset bitset.cpp -std=c++11
 * Created: 2015-10-10
 */

#include <iostream>
#include <string>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::bitset;

/*
 * The standard library defines the bitset class to make it easier to use bit
 * operations and possible to deal with collections of bits that are larger than
 * the longest integral type. The bitset class is defined in the bitset header.
 *
 * The bitset class is a class template that, like the array class, has a fixed
 * size. When we define a bitset, we say how many bits the bitset will contain:
 * ******************************************************************************
 *      Ways to Initialize a bitset
 * bitset<n> b;     b has n bits; each bit is 0. This constructor is a constexpr.
 * bitset<n> b(u);  b is a copy of the n low-order bits unsigned long long value
 *                  u. If n is greater than the size of an unsigned long long,
 *                  the high-order bits are beyond those in the unsigned long
 *                  long are set to zero. This constructor is a constexpr.
 * bitset<n> b(s, pos, m, zero, one);
 *                  b is a copy of the m characters from the string s starting
 *                  at position pos. s may contain only the characters zero and
 *                  one; if s contains any other character, throws
 *                  invalid-argument. The characters are stored in b as zero and
 *                  one,respectively. pos defaults to 0, m defaults to
 *                  string::npos, zero defaults to '0', and one defaults to '1'.
 * bitset<n> b(cp, pos, m, zero, one);
 *                  Same as the previous contructor, but copies from the
 *                  character array to which cp points. If m is not supplied,
 *                  the cp must point to a C-style string. If m is supplied,
 *                  there must be at least m characters that are zero or one
 *                  starting at cp.
 * The contructors that take a string or characters pointer are explicit. The
 * ability to specify alternate characters for 0 and 1 was adde in C++11.
 * ******************************************************************************
 *
 * The bitset operations define various ways to test or set one or more bits.
 * The bitset class also suppports the bitwise operators. The operators have the
 * same meaning when applied to bitset objects as the built-in operators have
 * when applied to unsigned operands.
 * ******************************************************************************
 * b.any()       Is any bit in b on?
 * b.all()       Are all the bits in b on?
 * b.none()      Are no bits in b on?
 * b.count()     Number of bits in b that are on.
 * b.size()      A constexpr function that returns the number of bits in b.
 * b.test(pos)   Returns true if bit at position pos is on, false otherwise.
 * b.set(pos, v) Sets the bit at position pos to the bool value v. v defaults to
 * b.set()       true. If no arguments, turns on all the bits in b.
 * b.reset(pos)  Turns off the bit at position pos or turns off all the bits in b.
 * b.reset()
 * b.flip(pos)   Changes the state of the bit at position pos or of every bit in b.
 * b.flip()
 * b[pos]        Gives access to the bit in b at position pos; if b is const,
 *               the b[pos] returns a bool value true if the bit is on, false
 *               otherwise.
 * b.to_ulong()  Returns an unsigned long or an unsigned long long with the same
 * b.to_ullong() bits as in b. Throws overflow_error if the bit pattern in b
 *               won't fit in the indicated result type.
 * b.to_string(zero, one)
 *               Returns a string reprenting the bit pattern in b. zero and one
 *               default to '0' and '1' and are used to represent the bits 0 and
 *               1 in b.
 * os << b       Prints the bits in b as the characters 1 or 0 to the stream os.
 * is >> b       Reads characters from is into b. Reading stops when the next
 *               character is not a 1 or 0 or when b.size() bits have been read.
 * Note: The count and size operations return a size_t. 
 *       C++11 introduced the all operation.
 * ******************************************************************************
 *
 * The subscript operator is overloaded on const. The const version returns a
 * bool value true if the bit at the given index is on, false otherwise. The
 * nonconst version returns a special type defined by bitset that let us
 * manipulate the bit value at the given index position.
 *
 * The input operator reads until it has read as many characters as the size of
 * the corresponding bitset, or it encounters a character other than 1 or 0, or
 * it encounters end-of-file or an input error.
 */

int main()
{
    bitset<32> bitvec(1U);  // 32 bitsw; low-order bit is 1, remaining bits are 0
    cout << "bitvec: " << bitvec << endl;
    // bitvec1 is smaller than the initializer; high-order bits from the
    // initializer are discarded
    bitset<13> bitvec1(0xbeef);     // bits are 1111011101111
    cout << "bitvec1: " << bitvec1 << endl;
    // bitvec2 is larger than the initializer; high-order bits in bitvec2 are
    // set to zero
    bitset<20> bitvec2(0xbeef);     // bits are 00001011111011101111
    cout << "bitvec2: " << bitvec2 << endl;

    // characters with the lowest indices in the string correspond to the
    // high-order bits, and vice versa
    bitset<32> bitvec4("1100");     // bits 2 and 3 are 1, all others are 0
    cout << "bitvec4: " << bitvec4 << endl;
    string s1("1111111000000011001101");
    bitset<32> bitvec5(s1, 5, 4);   // four bits starting at s1[5], 1100
    cout << "bitvec5: " << bitvec4 << endl;
    bitset<32> bitvec6(s1, s1.size()-4);   // use last four characters
    cout << "bitvec6: " << bitvec6 << endl;
    string s2("aabb");
    bitset<32> bitvec7(s2, 0, 4, 'a', 'b'); // 0011
    cout << "bitvec7: " << bitvec7 << endl;
    cout << "bitvec7.to_string('a','b'): " << bitvec7.to_string('a', 'b') << endl;


    bool is_set = bitvec.any();         // true, one bit is set
    bool is_not_set = bitvec.none();    // false, one bit is set
    bool all_set = bitvec.all();        // false, only one bit is set
    size_t onBits = bitvec.count();     // returns 1
    size_t sz = bitvec.size();          // returns 32
    bitvec.flip();      // reverses the value of all the bits in bitvec
    bitvec.reset();     // sets all the bits to 0
    bitvec.set();       // sets all the bits to 1
    bitvec.flip(0);     // reverses the value of the first bit
    bitvec.set(bitvec.size()-1);    // turns on the last bit
    bitvec.set(0, 0);   // turns off the first bit
    bitvec.test(0);     // returns false because the first bit if off

    bitvec[0] = 0;          // turn off the bit at position 0
    bitvec[31] = bitvec[0]; // set the last bit to the same value as the first bit
    bitvec[0].flip();       // flip the value of the bit at position 0
    ~bitvec[0];             // equivalent operation; flips the bit at position 0
    bool b = bitvec[0];     // convert the value of bitvec[0] to bool

    bitset<16> bits;
    cout << "read bits: ";
    cin >> bits;        // read up to 16 '1' or '0' from cin
    cout << "bits: " << bits << endl;   // print what we just read
    ~bits[0];
    cout << "bits: " << bits << endl;

    return 0;
}
