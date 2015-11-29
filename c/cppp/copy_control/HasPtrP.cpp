#include "HasPtrP.hpp"

HasPtrP::~HasPtrP()
{
    if (--*use == 0) {  // if the reference count goes to 0
        delete ps;      // delete the string
        delete use;     // and the counter
    }
}

HasPtrP& HasPtrP::operator=(HasPtrP &rhs)
{
    ++rhs.use;  // increment the use count of the right-hand operand
    if (--*use == 0) {  // then decrement this object's counter
        delete ps;      // if no other users
        delete use;     // free this object's allocated members
    }
    ps = rhs.ps;        // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this;       // return this object
}
