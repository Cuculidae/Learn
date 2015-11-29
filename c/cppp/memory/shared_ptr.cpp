/**
 * shared_ptr.cpp
 * C++11 smart pointer shared_ptr.
 * Compilation: g++ -o shared_ptr shared_ptr.cpp -std=c++11
 * Created: 2015-09-21
 */

#include <iostream>
#include <memory>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::list;
using std::string;

/*
 * shared_ptr automatically destroy their objects and free the associated
 * memory when appropriate.
 *
 * Operations Common to shared_ptr and unique_ptr:
 * shared_ptr<T> sp Null smart pointer that can point to objects of type T.
 * unique_ptr<T> up
 * p                Use p as a condition; true if p points to an object.
 * *p               Dereference p to get the object to which p points.
 * p->mem           Synonym for (*p).mem.
 * p.get()          Returns the pointer in p. Use with caution; the object to
 *                  which the returned pointer points will disappear when the
 *                  smart pointer deletes it.
 * swap(p,q)        Swaps the pointers in p and q.
 * p.swap(q)
 *
 * Operations Specific to shared_ptr:
 * make_shared<T>(args) Returns a shared_ptr pointing to a dynamically allocated
 *                      object of type T. Uses args to initialize that object.
 * shared_ptr<T> p(q)   p is a copy of the shared_ptr q; increments the count in
 *                      q. The pointer in q must be convertible to T*.
 * p = q                pand q are shared_ptrs holding pointers that can be
 *                      converted to one another. Decrements p's reference count
 *                      and increments q's count; deletes p's existing memory if
 *                      p's count goes to 0.
 * p.unique()           Returns true if p.use_count() is one; false otherwise.
 * p.use_count()        Returns the number of objects sharing with p; may be a
 *                      slow operation, intended primarily for debugging
 *                      purposes.
 *
 * If we do not pass any arguments to make_shared, then the object is
 * value-initialized.
 *
 * Because memory is not freed until the last shared_ptr goes away, it can be
 * important to be sure that shared_ptrs don't stay around after they are no
 * longer needed.
 *
 * Other Ways to Define and Change shared_ptrs:
 * shared_ptr<T> p(q)    p manages the object to which the built-in pointer q
 *                       points; q must point to memory allocated by new and
 *                       must be convertible to T*.
 * shared_ptr<T> p(u)    p assumes ownership from the unique_ptr u; makes u ull.
 * shared_ptr<T> p(q, d) p assumes ownership for the object to which the
 *                       built-in pointer q points. q must be convertible to T*.
 *                       p will use the callable object d in place of delete to
 *                       free q.
 * shared_ptr<T> p(p2,d) p is a copy of the shared_ptr p2 except that p uses the
 *                       callable object d in place of delete.
 * p.reset()     If p is the only shared_ptr pointing at its object, reset frees
 * p.reset(q)    p's existing object. If the optional built-in pointer q is
 * p.reset(q, d) passed, makes p point to q, otherwise makes p null. If d is
 *               supplied, will call d to free q otherwise uses delete to free q.
 *
 * The smart pointer constructors that take pointers are explicit. By default, a
 * pointer used to initialize a smart pointer must point to dynamic memory
 * because, by default, smart pointers use delete to free the associated object.
 * We can bind smart pointers to pointers to other kinds of resources.
 *
 * A shared_ptr can coordinate destruction only with other shared_ptrs that are
 * copies of itself. It is dangerous to use a built-in pointer to access an
 * object owned by a smart pointer, because we may not know when that object is
 * destroyed.
 * Don't mix ordinary pointers and smart pointers and don't use get to intialize
 * or assign another smart pointer. Use get only to pass access to the pointer
 * to code that you know will not delete the pointer. In particular, never use
 * get to initialize or assign to another smart pointer.
 */

int main(void)
{
    shared_ptr<string> p1;      // shared_ptr that can point at a string
    shared_ptr<list<int>> p2;   // shared_ptr that can point at a list of ints
    // if p1 is not null, check whether it's an empty string
    if (p1 && p1->empty()) {
        *p1 = "hi";
        cout << *p1 << endl;
    }
    // shared_ptr that points to an int with value 42
    shared_ptr<int> p3 = make_shared<int>(42);
    if (p3) {
        cout << "*p3: " << *p3 << endl;
    }
    // p4 points to a string with value 9999999999
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    if (p4) {
        cout << "*p4: " << *p4 << endl;
    }
    // p5 points to an int that is value initialized to 0
    shared_ptr<int> p5 = make_shared<int>();
    if (p5) {
        cout << "*p5: " << *p5 << endl;
    }

    shared_ptr<int> p6(new int(1024));  // ok: uses direct initialization
    if (p6) {
        cout << "*p6: " << *p6 << endl;
        p6.reset(new int(42));          // ok: points to a new object
        cout << "*p6: " << *p6 << endl;
    }

    return 0;
}
