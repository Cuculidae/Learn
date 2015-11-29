/**
 * decltype.cpp
 * Introduction to decltype type specifier.
 * Compilation: g++ -o decltype decltype.cpp -std=c++11
 * Created: 2015-09-04
 */

#include <iostream>

int main(void)
{
    /*
     * decltype (type specifer, Since C++11)
     * Deduce the type from an expression. The compiler analyzes the expression
     * to determin its type but does not evaluate the expression.
     */

    /* 
     * decltype returns the type including top-level const and reference
     * It is worth noting that decltype is the only context in which a variable
     * defined
     */
    const int ci = 0, &cj = ci;
    decltype (ci) x = 0;    // x has type const int
    decltype (cj) y = x;    // y has type const int& and is bound to x
  //decltype (cj) z;        // error: z is a reference and must be initialized

    // decltype of an expression can be reference
    int i = 42, *p = &i, &r = i;
    decltype(r+0) b;    // b is an int
  //decltype(*p)  c;    // error: c is int& and must be initialized

    /*
     * if we wrap the variable's name in one or more sets of parentheses, the
     * compiler will evaluate the operand as an expression.
     */
    // decltype of a parenthesized variable is always a reference
  //decltype((i)) d;    // error: d is int& and must be initialized
    decltype(i)   e;    // e is int


    return 0;
}
