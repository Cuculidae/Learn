/**
 * queue.cpp
 * Sequential container adaptor: queue
 * Compilation: g++ -o queue queue.cpp
 * Created: 2015-10-17
 */

#include <iostream>
#include <queue>
#include <list>

using std::cout;
using std::endl;
using std::queue;
using std::list;

/*
 * In addition to the sequential containers, the library defines three
 * sequential container adaptors: stack, queue, and priority_queue.
 *      Operations and Types Common to the Container Adaptors
 * *****************************************************************************
 * size_type        Type large enough to hold the size of the largest object of
 *                  this type.
 * value_type       Element type.
 * reference        value_type&
 * const_reference  const value_type&
 * container_type   Type of the underlying container on which the adaptor is
 *                  implemented.
 * A a;             Create a new empty adaptor named a.
 * A a(c);          Create a new adaptor named a with a copy of the container c.
 * relational operators Each adaptor supports all the relational operators: ==,
 *                      !=, <, <=, >, >=. These operators return the result of
 *                      comparing the underlying containers.
 * a.empty()        false if a has many elements, true otherwise.   
 * a.size()         Number of elements in a.
 * swap(a, b)       Swaps the contents of a and b; a and b must have the same
 * a.swap(b)        type, including the type of the container on which they are
 *                  implemented.
 * *****************************************************************************
 *
 * Each adaptor defines two constructors: the default constructor that creates
 * an empty object, and a constructor that takes a container and intializes the
 * adaptor by copying the given container.
 * By default both stack and queue are implemented in terms of deque, and a
 * priority_queue is implemented on a vector. We can override the default
 * container type by naming a sequenctial container as a second type argument
 * when we create the adaptor.
 * There are constraints on which container can be used for a given adaptor. All
 * of the adaptors require the ability to add and remove elements. As a result,
 * they cannot be built on array. Similarly, we cannot use forward_list, because
 * all of the adaptors require operations that add, remove, or access the last
 * element in the container.
 *
 *  Defined in header <queue>
 * -----------------------------------------------------------------------------
 *  template<
 *      class T,
 *      class Container = std::deque<T>
 *  > class stack;
 * -----------------------------------------------------------------------------
 * A queue requires that the underlying container supports:
 *  # push_back
 *  # back
 *  # pop_front
 *  # front
 *
 *      Queue Operations
 * *****************************************************************************
 *      By default queue uses dequeue; queue can use a list as well.
 * q.pop()          Removes, but does not return, the front element.
 * q.front()        Returns, but does not remove, the front element.
 * q.back()         Returns, but does not remove, the back element.
 * q.push(item)     Create an element with value item or constructed from args
 * q.emplace(args)  at the end of the queue.
 * *****************************************************************************
 */

int main()
{
    queue<int, list<int> > q;    // empty queue
    // fill up the queue
    for (size_t ix = 0; ix != 10; ++ix)
        q.push(ix);     // q holds 0...9 inclusive
    while (!q.empty()) {        // while there are still values in q
        int value = q.front();
        cout << value << ' ';
        q.pop();
    }
    cout << endl;

    return 0;
}