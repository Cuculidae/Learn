/**
 * auto.cpp
 * Introduction to auto type specifier.
 * Compilation: g++ -o auto auto.cpp -std=c++11
 * Created: 2015-09-04
 */

#include <iostream>

/*
 * auto (type specifier, Since C++11)
 * Let the compiler deduce the type from the initializer.
 * By implication, variable that uses auto as its type specifer
 * must have an initializer.
 */

int main(void)
{
    auto i = 0, *p = &i;    // ok: i is int and p is int*
  //auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi

    /*
     * auto infers the type conforming to initialization rules.
     */
    const int ci = 0, &cr = ci;
    auto b = ci;    // b is an int (top-level const is ignored)
    auto c = cr;    // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i;    // d is an int* (& of an int object is int*)
    auto e = &ci;   // e is const int* (& of an const object is const int*)

    /* if we want the deduced type to have a top-level const, we must say so
     * explicitly
     */
    const auto f = ci;  // deduced type of ci is int; f has type const int

    /* we can also specify that we want a reference to the deduced type.
     * nomal initialization rule still applies.
     */
    auto &g = ci;           // g is a const int& that is bound to ci
  //auto &h = 42;           // error: we can't bind a plain reference to a literal
    const auto &j = 42;     // ok: we can bind a const reference to a literal

    return 0;
}
