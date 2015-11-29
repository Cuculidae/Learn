#ifndef QUOTE_HPP
#define QUOTE_HPP
#
#include <string>

/*
 * Base class ordinarily should define a virtual destructor.
 *
 * A base class specifies that a member function should be dynamically bound by
 * preceding its declaration with the keyword virtual. Any nonstatic member
 * function, other than a constructor, may be virtual. The virtual keyword
 * appears only on the declaration inside the class and may not be used on a
 * function definition that appears outside the class body. A function that is
 * declared as virtual in the base class is implicitly virtual in the derived
 * classes as well.
 * When we call a virtual function through a pointer or reference, the call will
 * be dynamically bound.
 *
 * Member functions that are not declared as virtual are resolved at compile
 * time.
 */

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    virtual ~Quote() = default; // dynamic binding for the destructor
    std::string isbn() const { return bookNo; }
    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const
        { return n * price; }

private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};

#endif
