#include <iostream>
#include "Quote.hpp"
#include "Bulk_quote.hpp"

using std::cout;
using std::endl;
using std::ostream;

/*
 * When we call a virtual function on an expression that has a plain --
 * nonreference and nonpointer -- type, that call is bound at compile time.
 *
 * If a call to a virtual function uses default arguments, the value that is
 * used is the one defined by the static type through which the function is
 * called.
 */

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()   // calls Quote::isbn
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main(void)
{
    Quote q("Quote", 10);
    Bulk_quote bq("Bulk_quote", 10, 5, 0.5);
    print_total(cout, q, 5);
    print_total(cout, bq, 5);

    return 0;
}
