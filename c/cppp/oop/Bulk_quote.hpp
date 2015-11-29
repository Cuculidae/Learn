#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP
#
#include "Disc_quote.hpp"

/*
 * A derived class must specify from which class(es) it inherits. It does so in
 * its class derivation list, which is a colon followed by a comma-separated
 * list of names of previously defined classes. Each base class name may be
 * preceded by an optional access specifier, which is one of public, protected,
 * or private.
 *
 * Derived classes frequently, but not always, override the virtual functions
 * that they inherit. If a derived class does not override a virtual from its
 * base, then, like any other member, the derived class inherits the version
 * defined in its base class.
 *
 * C++11 lets a derived class explicitly note that it intends a member function
 * to override a virtual that it inherits. It does so by specifying override
 * after the parameter list, or after the const or reference qualifier(s) if the
 * member is a const or reference function.
 * The compiler will reject a program if a function marked override does not
 * override an existing virtual function.
 * In C++11, we can also designate a function as final. Any attempt to override
 * a function that has been defined as final will be flagged as error.
 * final and override specifiers appear after the paramter list (including any
 * const or reference qualifiers) and after a trailing return.
 *
 * A derived object contains multiple parts: a subobject containing the
 * (nonstatic) members defined in the derived class itself, plus subobjects
 * corresponding to each base class from which the derived class inherits. The
 * standard does not specify how derived objects are laid out in memory.
 *
 * As with a data member, unless we say otherwise, the base part of a derived
 * object is default initialized. The base class is initialized first, and then
 * the members of the derived class are initialized in the order in which they
 * are declared in the class.
 * 
 * A class must be defined, not just declared, before we can use it as a base
 * class.
 *
 * In C++11, we can prevent a class from being used as a base by following the
 * class name with final.
 *
 * The automatic derived-to-base conversion applies only for conversions to a
 * reference or pointer type. When we initialize or assign an object of a base
 * type from an object of a derived type, only the base-class part of the
 * derived object is copied, moved, or assigned. The derived part of the object
 * is ignored.
 *
 * We must define every virtual function, regardless of whether it is used,
 * because the compiler has no way to determine whether a virtual function is
 * used.
 *
 * If a call to a virtual function uses default arguments, the value that is
 * used is the one defined by the static type through which the function is
 * called.
 */

class Bulk_quote : public Disc_quote {   // Bulk_quote inherits from Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    // override the base version in order to implement the bulk purchase
    // discount policy
    double net_price(std::size_t) const override;
};

inline
Bulk_quote::Bulk_quote(const std::string& book, double price,
        std::size_t qty, double disc):
    Disc_quote(book, price, qty, disc) { }

#endif
