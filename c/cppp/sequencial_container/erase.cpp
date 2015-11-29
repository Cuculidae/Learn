/**
 * erase.cpp
 * Compilation: g++ -o erase erase.cpp
 * Created: 2015-10-17
 */

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
 *      erase Operations on Sequential Containers
 * *****************************************************************************
 *  These operations change the size of the container and so are not supported
 *  by array. forward_list has a special version of erase;
 *  pop_back not valid for forward_list; pop_front not valid for vector and string
 * c.pop_back()  Removes the last element in c. Undefined if c is empty. Returns void
 * c.pop_front() Removes the first element in c. Undefined if c is empty. Returns void
 * c.erase(p)    Removes the element denoted by the iterator p and returns an
 *               iterator to the element after the one deleted or the
 *               off-end-iterator if p denotes the last element. Undefined if p
 *               is the off-the-end iterator.
 * c.erase(b,e)  Removes the range of elements denoted by the iterators b and e.
 *               Returns an iterator to the element after the last one that was
 *               deleted or an off-the-end iterator if e is itself an
 *               off-the-end iterator.
 * c.clear()     Removes all the elements in c. Returns void.
 * *****************************************************************************
 *
 * Removing elements anywhere but the beginning or end of a deque invalidates
 * all iterators, references, and pointers. Iterators, references, and pointers
 * to elements after the erase point in a vector or string are invalidated.
 */

void print(list<int> lst)
{
    for (auto i : lst)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    print(lst);
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2)            // if the element is odd
            it = lst.erase(it); // erase this element
        else
            ++it;
    }
    print(lst);

    lst.erase(lst.begin(), --lst.end());
    print(lst);

    return 0;
}
