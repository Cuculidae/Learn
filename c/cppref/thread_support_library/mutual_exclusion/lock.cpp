/**
 * lock.cpp
 * std::mutex object member function: lock()
 * Compilation: g++ -o lock lock.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

/*
 * std::mutex::lock
 * -----------------------------------------------------------------------------
 *  void lock();        (since C++11)
 * -----------------------------------------------------------------------------
 *  Locks the mutex. If another thread has already locked the mutex, a call to
 *  lock will block execution until the lock is acquired.
 *  If lock is called by a thread that already owns the mutex, the behavior is
 *  undefined: the program may deadlock, or, if the implementation can detect
 *  the deadlock, a resource_deadlock_would_occur error condition may be thrown.
 *  Prior unlock() operation on the same mutex synchronizes-with (as defined in
 *  std::memory_order) this operation.
 *  Exceptions:
 *   Throws std::system_error when errors occur, including errors from the
 *   underlying operating system that would prevent lock from meeting its
 *   specifications. The mutex is not locked in the case of any exception being
 *   thrown.
 *  Notes:
 *   lock() is usually not called directly: std::unique_lock and std::lock_guard
 *   are used to manage exclusive locking.
 */

int g_num = 0;  // protected by g_num_mutex
std::mutex g_num_mutex;

void slow_increment(int id)
{
    for (int i = 0; i < 3; ++i) {
        g_num_mutex.lock();
        ++g_num;
        std::cout << id << " => " << g_num << '\n';
        g_num_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread t1(slow_increment, 0);
    std::thread t2(slow_increment, 1);
    t1.join();
    t2.join();
}
