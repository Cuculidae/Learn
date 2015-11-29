/**
 * allocator.cpp
 * The library allocator class.
 * Compilation: g++ -o allocator allocator.cpp -std=c++11
 * Created: 2015-09-22
 */

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::allocator;
using std::string;

/*
 * It provides a type-aware allocation of raw, unconstructed, memory.
 *
 * We must construct objects in order to use memory returned by allocate. Using
 * unconstructed memory in other ways is undefined.
 *
 * In C++11, the construct member takes a pointer and zero or more additional
 * arguments; it constructs an element at the given location.
 *
 * Standard allocator Class and Customized Algorithms:
 * allocator<T> a      Defines an allocator object named a that can allocate
 *                     memory for objects of type T.
 * a.allocate(n)       Allocates raw, unconstructed memory to hold n objects of
 *                     type T.
 * a.deallocate(p,n)   Deallocates memory that held n objects of type T starting
 *                     at the address in the T* pointer p; p must be a pointer
 *                     previously returned by allocate, and n must be the size
 *                     requested when p was created. The user must run destroy
 *                     on any objects that were constructed in this memory
 *                     before calling deallocate.
 * a.construct(p,args) pmust be a pointer to type T that points to raw memory;
 *                     args are passed to a constructor for type T, which is
 *                     used to construct an object in the memory pointed to by p.
 * a.destroy(p)        Runs the destructor on the object pointed to by the T*
 *                     pointer p.
 *
 * allocator Algorithms:
 * uninitialized_copy(b, e, b2) 
 *      Copies elements from the input range denoted by iterators b and e into
 *      unconstructed, raw memory denoted by the iterator b2. The memory denoted
 *      by b2 must be large enough to hold a copy of the elements in the input
 *      range.
 * uninitialized_copy_n(b,n,b2)
 *      Copies n elements starting from the one denoted by the iterator b into
 *      rawmemory starting at b2.
 * uninitialized_fill(b, e, t)
 *      Constructs objects in the range of raw memory denoted by iterators b and
 *      e as a copy of t.
 * uninitialized_fill_n(b,n,t)
 *      Constructs an unsigned number n objects starting at b. b must denote
 *      unconstructed, raw memory large enough to hold the given number of objects.
 */

int main(void)
{
    const int n = 6;
    allocator<string> alloc;            // objects that can allocate strings
    auto const p = alloc.allocate(n);   // allocate n unconstructed string

    auto q = p; // q will point to one past the the last constructed element
    alloc.construct(q++);   // *q is the empty string
    alloc.construct(q++, 10, 'c');  // *q is cccccccccc
    alloc.construct(q++, "hi");     // *q is hi
    q = uninitialized_copy(p, q, q);
    for (auto it = p; it != q; ++it)
        cout << *it << ' ';
    cout << endl;

    while (q != p)
        alloc.destroy(--q);     // free the strings we actually allocated
    alloc.deallocate(p, n);

    return 0;
}
