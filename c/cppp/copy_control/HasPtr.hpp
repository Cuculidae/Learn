/* valuelike HasPtr */

#ifndef HASPTR_HPP
#define HASPTR_HPP
#
#include <string>

/*
 * To provide valuelike behavior, each object has to have its own copy of the
 * resource that the class manages
 * 
 * Assignment operators typically combine the actions of the destructor and the
 * copy constructor. Like the destructor, assignment destroys the left-hand
 * operand's resources. Like the copy constructor, assignment copies data from
 * the right-hand operand. It is crucially important that these actions be done
 * in a sequence that is correct even if an object is assigned to itself.
 *
 * Moreover, when possible, we should also write our assignment operators so
 * that they will leave the left-hand operand in a sensible state should an
 * exception occur.
 *
 * In additon to defining the copy-control members, classes that manage
 * resources often also define a function named swap. Defining swap is
 * particularly important for classes that we plan to use with algorithms that
 * reorder elements. If a class defines its own swap, then the algorithm uses
 * that class-specific version. Otherwise, it uses the swap function defined by
 * the library.
 *
 * Classes that define swap often use swap to define their assignment operator.
 * These operators use a technique known as copy and swap. This technique swaps
 * the left-hand operand with a copy of the right-hand operand.
 * Assignment operators that use copy and swap are automatically exception safe
 * and correctly handle self-assignment.
 */

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        // each HasPtr has its own copy of the string to which ps points
        HasPtr(const HasPtr &p):
            ps(new std::string(*p.ps)), i(p.i) { }
        HasPtr& operator=(const HasPtr &rhs);
        ~HasPtr() { delete ps; }

    private:
        std::string *ps;
        int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // swap the pointers, not the string data
    swap(lhs.i, rhs.i);     // swap the int members
}

#endif
