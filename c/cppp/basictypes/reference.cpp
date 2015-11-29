/**
 * reference.cpp
 * Demonstrates usage syntax of reference.
 * Compilation: g++ -o reference reference.cpp
 * Created: 2015-09-03
 */

#include <iostream>

class X {
    public:
    X() { }
    X(const X&) { std::cout << "X copy constructor" << std::endl; }
};

int main(void)
{
    /*
     * A reference is not an object, it's just an alias to another object.
     * Because reference cannot be rebind to another object, it must be
     * initialized.
     */
    int i = 42;
    int &ri = i;
    std::cout << "i == " << i << ", ri == " << ri << std::endl; 
    ++ri;
    std::cout << "i == " << i << ", ri == " << ri << std::endl; 

    /*
     * The type of the reference must match the type of the initializer,
     * except the following two exceptions.
     *
     * #1 We can initialize a reference to const from any expression that can be
     * converted to the type of the reference. In particular, we can bind a
     * reference to const to a nonconst object, a literal, or a more general
     * expression.
     */
    const int &r1 = i;      // OK: bind a const int& to a plain int
    const int &r2 = 42;     // Ok: bind a const int& to a literal
    const int &r3 = r1 * 2; // Ok: bind a const int& to the value of an expr
    std::cout << "r1 == " << r1 << ", r2 == " << r2
        << ", r3 == " << r3 << std::endl;
    double dval = 3.14;
    const int &cri = dval;  // Ok: bind cri to a temp const int from dval
    std::cout << "cri == " << cri << std::endl;

    const X &x = X();

    return 0;
}
