/**
 * priority_queue.cpp
 * Sequential container adaptor: priority_queue
 * Compilation: g++ -o priority_queue priority_queue.cpp
 * Created: 2015-10-17
 */

#include <iostream>
#include <queue>
#include <functional>

using std::cout;
using std::endl;
using std::priority_queue;
using std::greater;

/*
 * In addition to the sequential containers, the library defines three
 * sequential container adaptors: stack, queue, and priority_queue.
 *      Operations and Types Common to the Container Adaptors
 * *****************************************************************************
 * size_type        Type large enough to hold the size of the largest object of
 *                  this type.
 * value_type       Element type.
 * container_type   Type of the underlying container on which the adaptor is
 *                  implemented.
 * reference        value_type&
 * const_reference  const value_type&
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
 *      priority_queue Operations
 * *****************************************************************************
 *      By default priority_queue uses vector; queue can use a deque as well.
 * q.pop()          Removes, but does not return, the highest-priority element.
 * q.top()          Returns, but does not remove, the highest-priority elemeent.
 * q.push(item)     Create an element with value item or constructed from args
 * q.emplace(args)  in its appropriate position in the priority_queue.
 * *****************************************************************************
 *
 *  Defined in header <queue>
 * -----------------------------------------------------------------------------
 *  template<
 *      class T,
 *      class Container = std::vector<T>,
 *      class Compare = std::less<typename Container::value_type>
 *  > class priority;
 *  ----------------------------------------------------------------------------
 * A priority_queue lets us establish a priority among the elements held in the
 * queue. Newly added elements are placed ahead of all the elements with a low
 * priority. By default, the library uses the < operator on the element type to
 * determine relative priorities.
 *
 * A priority_queue requires that the underlying container supports:
 *  # push_back
 *  # pop_back
 *  # front
 *  # random access the elements
 */

int main()
{
    priority_queue<int> maxpq;  // empty priorty queue
    // fill up the priority queue
    for (size_t ix = 0; ix != 10; ++ix)
        maxpq.push(ix);     // maxpq holds 0...9 inclusive
    while (!maxpq.empty()) {        // while there are still values in maxpq
        int value = maxpq.top();
        cout << value << ' ';
        maxpq.pop();
    }
    cout << endl;

    priority_queue<int, std::vector<int>, greater<int> > minpq; // empty priorty queue
    // fill up the priority queue
    for (size_t ix = 0; ix != 10; ++ix)
        minpq.push(ix);     // minpq holds 0...9 inclusive
    while (!minpq.empty()) {        // while there are still values in minpq
        int value = minpq.top();
        cout << value << ' ';
        minpq.pop();
    }
    cout << endl;

    return 0;
}
