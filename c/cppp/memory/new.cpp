/**
 * new.cpp
 * Compilation: g++ -o new new.cpp -std=c++11
 * Created: 2015-09-21
 */

#include <iostream>
#include <string>
#include <new>

using std::cout;
using std::endl;
using std::string;
using std::nothrow;

/*
 * Objects allocated on the free store are unnamed, so new offers no way to name
 * the objects that it allocates. Instead, new returns a pointer to the object
 * it allocates.
 *
 * By default, dynamically allocated objects are default initialized.
 *
 * We can initialize a dynamically allocated object using direct
 * initialization.We can use traditional construction (using parentheses), and
 * in C++11 standard, we can also use list initialization (with curly braces).
 * We can also value initialize a dynamically allocated object by following the
 * type name with a pair of empty parentheses.
 *
 * In C++11, when we provide an initializer inside parentheses, we can use auto
 * to deduce the type of the object we want to allocate from that initializer.
 *
 * It is legal to use new to allocate const objects. Like any other const, a
 * dynamically allocated const object must be initialized. A const dynamic
 * object of a class type that defines a default constructor may be initialized
 * implicitly. Objects of other types must be explicitly initialized. Because
 * the allocated object is const, the pointer returned by new is a pointer to
 * const.
 *
 * By default, if new is unable to allocate the requested storage, it throws an
 * exception of type bad_alloc. We can prevent new from throwing an exception by
 * using a different form of new. This form of new is refered to as placement
 * new. If this form of new is unable to allocate the requested storage, it will
 * return a null pointer. Both bad_alloc and nothrow are defined in the new
 * header.
 *
 * Like new, a delete expression performs two actions: It destroys the object to
 * which its given pointer points, and it frees the corresponding memory. The
 * pointer we pass to delete must either point to dynamically allocated memory
 * or a null pointer. Deleting a pointer to memory that was not allocated by
 * new, or deleting the same pointer value more than once, is undefined.
 *
 * Although the value of a const object cannot be modified, the object itself
 * can be destroyed.
 *
 * It is of good practive to assign nullptr to the pointer after we use delete.
 */

int main(void)
{
    int *pi1 = new int;     // default initialized; *pi1 is undefined
    int *pi2 = new int();   // value initialized to 0; *pi2 is 0
    cout << "*pi1: " << *pi1 << endl;
    cout << "*pi2: " << *pi2 << endl;
    auto pi3 = new auto(3); // *pi3 == 3
    cout << "*pi3: " << *pi3 << endl;
    delete pi1;
    pi1 = nullptr;
    delete pi2;
    pi2 = nullptr;
    delete pi3;
    pi3 = nullptr;
    string *ps1 = new string(10, 'c');
    cout << "*ps1: " << *ps1 << endl;
    delete ps1;
    ps1 = nullptr;

    // allocate and initialize a const int
    const int *pci = new const int(1024);
    cout << "*pci: " << *pci << endl;
    // allocate a default-initialized const empty string
    const string *pcs = new const string;
    cout << "*pcs: " << *pcs << endl;
    delete pci;
    pci = nullptr;
    delete pcs;
    pcs = nullptr;

    int *pi4 = new (nothrow) int(4);    // if allocation fails, new returns a null pointer
    cout << "*pi4: " << *pi4 << endl;
    delete pi4;
    pi4 = nullptr;

    return 0;
}
