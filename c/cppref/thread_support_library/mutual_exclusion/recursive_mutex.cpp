/**
 * recursive_mutex.cpp
 * std::recursive_mutex
 * Compilation: g++ -o recursive_mutex recursive_mutex.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <mutex>
#include <thread>

/*
 * std::recursive_mutex                             Defined in header <mutex>
 * -----------------------------------------------------------------------------
 *  class recursive_mutex;      (since C++11)
 * -----------------------------------------------------------------------------
 *  The recursive_mutex class is a synchronization primitive that can be used to
 *  protect shared data from being simultaneously accessed by multiple threads.
 *  recursive_mutex offers exclusive, recursive ownership semantics:
 *  # A calling thread owns a recursive_mutex for a period of time that starts
 *    when it successfully calls neither lock or try_lock. During this period,
 *    the thread may make additional calls to lock or try_lock. The period of
 *    ownership ends when the thread makes a matching number of calls to unlock.
 *  # When a thread owns a recursive_mutex, all other threads will block (for
 *    calls to lock) or receive a false return value (for try_lock) if they
 *    attempt to claim ownership of the recursive_mutex.
 *  # The maximum number of times that a recursive_mutex may be locked is
 *    unspecified, but after that number is reached, alls to lock will throw
 *    std::system_error and calls to try_lock will return false.
 *
 * The behavior of a program is undefined if a recursive_mutex is destroyed
 * while still owned by some thread. The recursive_mutex class satisfies all
 * requirements of Mutex and StandardLayoutType.
 *
 * Member Functions:
 * -----------------------------------------------------------------------------
 * lock     locks the mutex, blocks if the mutex is not available
 * -----------------------------------------------------------------------------
 * try_lock tries to lock the mutex, returns if the mutex is not available
 * -----------------------------------------------------------------------------
 * unlock   unlocks the mutex
 * -----------------------------------------------------------------------------
 * native_handle returns the underlying implementation-defined thread handle
 * -----------------------------------------------------------------------------
 */


std::recursive_mutex rmutex;

void f(std::string s, int n, int i)
{
    if (i == n) return;
    rmutex.lock();      // lock
    std::cout << std::string(i, '\t') << s << " locked\n";
    f(s, n, i+1);       // recursive
    std::cout << std::string(i, '\t') << s << " unlocked\n";
    rmutex.unlock();    // corresponding unlock
}

int main()
{
    std::thread t1(f, "thread 1", 3, 0);
    std::thread t2(f, "thread 2", 3, 0);

    t1.join();
    t2.join();
}
