#include "HasPtr.hpp"

using std::string;


HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);    // copy the underlying string
    delete ps;      // free the old memory
    ps = newp;      // copy data from rhs into this object
    i = rhs.i;
    return *this;
}

/**

// note rhs is passed by value, which means the HasPtr copy constructor
// copies the string in the right-hand operand into rhs
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // swap the contents of the left-hand operand with the local variable rhs
    swap(*this, rhs);   // rhs now points to the memory this object had used
    return *this;       // rhs is destroyed, which deletes the pointer in rhs
}

*/
