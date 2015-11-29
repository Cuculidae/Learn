/**
 * name_lookup.cpp
 * name lookup under inheritance.
 * Compilation: g++ -o name_lookup name_lookup.cpp
 * Created: 2015-10-07
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * A derived-class member with the same name as a member of the base class hides
 * direct use of the base-class member.
 *
 * We can use a hidden base-class member by using the scope operator.
 *
 * As we've seen, functions declared in an inner scope do not overload functions
 * declared in an outer scope. As a result, functions defined in a derived class
 * do not overload members defined in its base class(es).
 */

struct Base {
    Base(): mem(0) { }
    int memfcn() { cout << "Base::memfcn()" << endl; }
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i): mem(i) { }  // initializes Derived::mem to i
                                // Base::mem is default initialized
    int get_mem() { return mem; }   // returns Derived::mem
    int get_base_mem() { return Base::mem; }
    int memfcn(int i)   // hids memfcn in the Base
        { cout << "Derived::memfcn(int)" << endl; }
protected:
    int mem;    // hides mem in the Base
};

int main(void)
{
    Base b;
    Derived d(42);

    cout << d.get_mem() << endl;        // prints 42
    cout << d.get_base_mem() << endl;   // prints 0
    
    b.memfcn();         // calls Base::memfcn
    d.memfcn(10);       // calls Derived::memfcn
  //d.memfcn();         // error: memfcn with no arguments is hidden
    d.Base::memfcn();   // ok: call Base::memfcn()

    return 0;
}
