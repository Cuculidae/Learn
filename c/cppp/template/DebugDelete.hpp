#ifndef DELETEDEBUG_HPP
#define DELETEDEBUG_HPP
#
#include <iostream>

/*
 * A class -- either an ordinary class or a class template -- may have a member
 * function that is itself a template. Such members are referred to as member
 * templates. Member templates may not be virtual.
 */

// function object class that calls delete on a given pointer
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) { }
    // as with any function template, the type of T is deduced by the compiler
    template <typename T> void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

#endif
