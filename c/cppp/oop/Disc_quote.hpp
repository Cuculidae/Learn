#ifndef DISC_QUOTE_HPP
#define DISC_QUOTE_HPP
#
#include <utility>
#include "Quote.hpp"

/*
 * A pure virtual function does not have to be defined. We specify that a
 * virtual function is a pure virtual by writing = 0 in place of a function body
 * just before the semicolon that ends the declaration. The = 0 may appear only
 * on the declaration of a virtual function in the class body.
 * It is worth noting that we can provide a definition for a pure virtual.
 * However, the function body must be defined outside the class.
 *
 * A class containing (or inheriting without overriding) a pure virtual function
 * is an abstract base class. We cannot (directly) create objects of a type that
 * is an abstract base class.
 *
 * Under inheritance, the scope of a derived calss is nested inside the scope of
 * its base classes.
 *
 * Name lookup happens at compile time. The static type of an object, reference,
 * or pointer determines which members of that object are visible. Even when the
 * static and dynamic types might differ (as can happen when a reference or
 * pointer to a base class is used), the static type determines what members can
 * be used.
 *
 * Like any other scope, a derived class can reuse a name defined in one of its
 * direct or indirect base classes. A derived-class member with the same name as
 * a member of the base class hides direcct use of the base-class member.
 */

// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
            std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const
        { return {quantity, discount}; }

protected:
    std::size_t quantity = 0;   // purchase size for the discount to apply
    double discount = 0.0;      // fractional discount to apply
};

#endif
