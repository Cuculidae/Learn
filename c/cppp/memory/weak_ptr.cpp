/**
 * weak_ptr.cpp
 * C++11 smart pointer weak_ptr.
 * Compilation: g++ -o weak_ptr weak_ptr.cpp -std=c++11
 * Created: 2015-09-22
 */

#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;
using std::make_shared;
using std::string;

/*
 * A weak_ptr is a smart pointer that does not control the lifetime of the
 * object to which it points. Instead, a weak_ptr points to an object that is
 * managed by a shared_ptr. Binding a weak_ptr to a shared_ptr does not change
 * the reference count of that shared_ptr. Once the last shared_ptr pointing to
 * the object goes away, the object itself will be deleted. That object will be
 * deleted even if there are weak_ptrs pointing to it.
 *
 * Because the object might no longer exist, we cannot use a weak_ptr to access
 * its object directly. To access that object, we must call lock.
 *
 * weak_ptr<T> w     Null weak_ptr that can point at objects of type T.
 * weak_ptr<T> w(sp) weak_ptr that points to the same object as the shared_ptr
 *                   sp. T must be convertible to the type to which sp points.
 * w = p             p can be a shared_ptr or a weak_ptr. After the assignment w
 *                   shares ownership with p.
 * w.reset()         Makes w null.
 * w.use_count()     The number of shared_ptrs that share ownership with w.
 * w.expired()       Returns true if w.use_count() is zero, false otherwise.
 * w.lock            If expired is true, returns a null shared_ptr; otherwise
 *                   returns a shared_ptr to the object to which w points.
 */

int main(void)
{
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);    // wp weakly shares with p; use count in p is unchanged
    if (shared_ptr<int> np = wp.lock()) {   // true if np is not null
        cout << *np << endl;
    }

    return 0;
}
