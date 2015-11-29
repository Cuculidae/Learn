/**
 * unlock.cpp
 * std::mutex object member functioin: unlock()
 * Compilation: g++ -o unlock unlock.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <thread>
#include <mutex>

/*
 * std::mutex::unlock
 * -----------------------------------------------------------------------------
 *  void unlock();          (since C++11)
 * -----------------------------------------------------------------------------
 *  Unlocks the mutex.
 *  The mutex must be locked by the current thread of execution, otherwise, the
 *  behavior is undefined. This operation synchronizes-with (as defined in
 *  std::memory_order) any subsequent lock operation that obtains ownership of
 *  the same mutex.
 *  Notes:
 *   unlock() is usually not called directly: std::unique_lock and
 *   std::lock_guard are used to manage exclusive locking.
 */

int main()
{
    std::mutex test;
    if (test.try_lock()) {
        std::cout << "first try_lock successful\n";
    } else {
        std::cout << "first try_lock NOT successful\n";
        return 0;
    }

    test.unlock();
    test.lock();

    if (test.try_lock()) {
        std::cout << "second try_lock successful\n";
    } else {
        std::cout << "second try_lock NOT successful\n";
    }

    test.lock();    // trying to lock an already-locked std::mutex will
                    // block program execution, so we'll hang here
}
