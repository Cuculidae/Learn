/**
 * rref.cpp
 * C++11 rvalue reference.
 * Compilation: g++ -o rref rref.cpp -std=c++11
 * Created: 2015-11-05
 */

#include <iostream>
#include <utility>  // std::move

using std::cout;
using std::endl;

/*
 * An rvalue reference is a reference that must be bound to an rvalue. We cannot
 * bind an rvalue reference to an lvalue. A variable is an lvalue; we cannot
 * directly bind an rvalue reference to a variable even if that variable was
 * defined as an rvalue reference type.
 *
 * Although we cannot directly bind an rvalue reference to an lvalue, we can
 * explicitly cast an lvalue to its corresponding rvalue reference type. We can
 * also obtain an rvalue reference bound to an lvalue by calling a new library
 * function named move, which is defined in the utility header. It is essential
 * to realize that the call to move promises that we do not intend to use the
 * moved-from object again except to assign to it or to destroy it. After a call
 * to move, we cannot make any assumptions about the value of the moved-from
 * object.
 *
 * Code that uses move should use std::move, not move. Doing so avoids potential
 * name collisions.
 */

int main()
{
    int i = 0;
    int &r1 = i;
    cout << "i = " << i << ", r1 = " << r1 << endl;
  //int &&rr = i;       // error: cannot bind an rvalue reference to an lvalue
    int &&rr1 = 1;
    cout << "rr1 = " << rr1 << endl;
  //int &&rr2 = rr1;    // error: the expression rr1 is an lvalue!
    int &r2 = rr1;
    cout << "r2 = " << r2 << endl;
    r2 = 2;
    cout << "rr1 = " << rr1 << endl;
    cout << "r2 = " << r2 << endl;

    int &&rr3 = std::move(i);   // ok
    cout << "rr3 = " << rr3 << endl;

    return 0;
}
