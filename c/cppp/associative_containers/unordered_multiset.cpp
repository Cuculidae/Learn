/**
 * unordered_multiset.cpp
 * Compilation: g++ -o unordered_multiset unordered_multiset.cpp -std=c++11
 * Created: 2015-09-21
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include "Sales_data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::hash;
using std::unordered_multiset;

/*
 * However,we cannot directly define an unordered container that uses a our own
 * class types for its key type. Unlike the containers, we cannot use the hash
 * template directly. Instead, we must supply our own version of the hash
 * template.
 *
 * If our class has its own == operator we can override just the hash function:
 *  // use FooHash to generate the hash code; Foo must have an == operator
 *  unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);
 */

size_t hasher(const Sales_data &sd);
bool eqOp(const Sales_data &lhs, const Sales_data &rhs);

int main(void)
{
    using SD_multiset = unordered_multiset<Sales_data,
                           decltype(hasher)*, decltype(eqOp)*>;
    // arguments are the bucket size and pointers to the hash function and
    // equality operator
    SD_multiset bookstore(42, hasher, eqOp);
    Sales_data sale;
    while (read(cin, sale)) {
        bookstore.insert(sale);
    }
    for (const auto &sd : bookstore) {
        print(cout, sd) << endl;
    }

    return 0;
}

size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}
