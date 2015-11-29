/**
 * resize.cpp
 * Sequential constainer resize operation.
 * Compilation: g++ -o resize resize.cpp -std=c++11
 * Created: 2015-10-17
 */

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
 * *****************************************************************************
 *          resize not valid for array
 * c.resize(n)      Resize c so that it has n elements. If n < c.size(), the
 *                  excess elements are discarded. If new elements must be
 *                  added, they are value intialized.
 * c.resize(n,t)    Resize c to have n elements. Any elements added have value t.
 * *****************************************************************************
 * If resize shrinks the container, then iterators, references, and pointers to
 * the deleted elements are invalidated; resize on a vector, string, or deque
 * potentially invalidates all iterators, pointers, and references.
 */

void print(list<int> lst)
{
    for (auto i : lst)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    list<int> lst(10, 42);  // ten ints: each has value 42
    print(lst);
    lst.resize(15);         // add five elements of vlaue 0 to the back of lst
    print(lst);
    lst.resize(25, -1);     // adds ten elements of value -1 to the back of lst
    print(lst);
    lst.resize(5);          // erases 20 elements from the back of lst
    print(lst);

    return 0;
}
