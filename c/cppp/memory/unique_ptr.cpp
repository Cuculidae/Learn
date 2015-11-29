/**
 * unique_ptr.cpp
 * C++11 smart pointer unique_ptr.
 * Compilation: g++ -o unique_ptr unique_ptr.cpp -std=c++11
 * Created: 2015-09-22
 */

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

/*
 * A unique_ptr "owns" the object to which it points. Unlike shared_ptr, only
 * one unique_ptr at a time can point to a given object. The object to which a
 * unique_ptr points is destroyed when the unique_ptr is destroyed.
 *
 * Because a unique_ptr owns the object to which it points, unique_ptr does not
 * support ordinary copy or assignment.
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
 * unique_ptr Operations:
 * unique_ptr<T> u1     Null unique_ptrs that can point to objects of type T. u1
 * unique_ptr<T,D> u2   will use delete to free its pointer; u2 will use a
 * unique_ptr<T,D> u(d) callable object of type D to free its pointer.
 * u = nullptr          Deletes the object to which u points; makes u null.
 * u.release()          Relinquishes control of the pointer u had held; returns
 *                      the pointer u had held and makes u null.
 * u.reset()            Deletes the object to which u points;
 * u.reset(q)           If the built-in pointer q is supplied, makes u point to
 * u.reset(nullptr)     that object. Otherwise makes u null.
 *
 * Although we can't copy or assign a unique_ptr,we can transfer ownership from
 * one (nonconst) unique_ptr to another by calling release or reset
 *
 * There is one exception to the rule that we cannot copy a unique_ptr: We can
 * copy or assign a unique_ptr that is about to be destroyed. The most common
 * example iswhenwe return a unique_ptr from a function:
 *  unique_ptr<int> clone(int p) {
 *      // ok: explicitly create a unique_ptr<int> from int*
 *      return unique_ptr<int>(new int(p));
 *  }
 */

int main(void)
{
    unique_ptr<string> p1(new string("Stegosaurus"));
    if (p1) {
        cout << "*p1: " << *p1 << endl;
    }
  //unique_ptr<string> p2(p1);  // error: no copy for unique_ptr
    
    // transfers ownership from p1 to p2
    unique_ptr<string> p2(p1.release());    // release makes p1 null
    if (p2) {
        cout << "*p2: " << *p2 << endl;
    }
    unique_ptr<string> p3(new string("Trex"));
    // transfers ownership from p3 to p2
    p2.reset(p3.release());                 // reset deletes the memory to which p2 had pointed
    if (p2) {
        cout << "*p2: " << *p2 << endl;
    }

    return 0;
}
