/**
 * io.cpp
 * Created: 2015-09-24
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

/*
 * Generally, output operators should print the contents of the object, with
 * minimal formatting. They should not print a newline.
 *
 * Input and output operatos that conform to the conventions of the iostream
 * library must be ordinary nonmember functions. These operators cannot be
 * members of our own class. If they were, the the left-hand operand would have
 * to be an object of our class type. IO operators usually must be declared as
 * friends.
 *
 * Ordinarily the first parameter of an input operator is an reference to the
 * stream from which it is to read, and the second parameter is a reference to
 * the (nonconst) object into which to read. The operator usually returns a
 * reference to its given stream. The second parameter must be nonconst because
 * the purpose of an input operator is to read data into this object.
 *
 * Input operators must deal with the possibility that the input might fail;
 * output operators generally don't bother. Input operators should decide what,
 * if anything, to do about error recovery.
 */

class X
{
    public:
        X(int v=0): i(v) { }
        operator<<(ostream &os) { os << i << endl; }
    private:
        int i;
};

int main(void)
{
    X x(1);
    x << cout;

    return 0;
}
