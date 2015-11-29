/**
 * push_front.cpp
 * inserts a new element at the front of the container.
 * Compilation: g++ -o push_front push_front.cpp -std=c++11
 * Created: 2015-09-16
 */

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
 * the list, forward_list, and deque containers support push_front.
 */

int main(void)
{
    list<int> ilist;
    // add elements to the start of ilist
    for (size_t ix = 0; ix != 4; ++ix)
        ilist.push_front(ix);
    for (const auto &i : ilist)
        cout << i << " ";
    cout << endl;

    return 0;
}
