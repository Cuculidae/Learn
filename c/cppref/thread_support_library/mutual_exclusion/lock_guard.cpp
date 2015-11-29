/**
 * lock_guard.cpp
 * std::lock_guard object.
 * Compilation: g++ -o lock_guard lock_guard.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <thread>
#include <mutex>

/*
 * std::lock_guard                                  Defined in header <mutex>
 * -----------------------------------------------------------------------------
 *  template< class Mutex > class lock_guard;               (since C++11)
 *                                                          (until C++17)
 * -----------------------------------------------------------------------------
 *  template< class... MutexTypes > class lock_guard;       (since C++17)
 * -----------------------------------------------------------------------------
 *  The class lock_guard is a mutex wrapper that provides a convenient
 *  RAII-style mechanism for owning a mutex or several mutexes (since C++17) for
 *  the duration of a scoped block.
 *  When a lock_guard object is created, it attempts to take ownership of the
 *  mutex it is given. When control leaves the scope in which the lock_guard
 *  object was created, the lock_guard is destructed and mutex is released.
 *  If several mutexes are given, deadlock avoidance algorithm is used as if by
 *  std::lock. (since C++17)
 *  The lock_guard class is non-copyable.
 *
 *  Constructor:
 * -----------------------------------------------------------------------------
 *  explicit lock_guard( mutex_type &m);
 *  explicit lock_guard( MutexTypes&... m);
 *  lock_guard( mutex
 * -----------------------------------------------------------------------------
 *  destructor
 * -----------------------------------------------------------------------------
 *  operator=   deleted
 * -----------------------------------------------------------------------------
 */

int g_i = 0;
std::mutex g_i_mutex;   // protects g_i

void safe_increment()
{
    std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    std::cout << std::this_thread::get_id() << ": " << g_i << '\n';
    // g_i_mutex is automatically released when lock goes out of scope
}

int main()
{
    std::cout << __func__ << ": " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << __func__ << ": " << g_i << '\n';
}
