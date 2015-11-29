/**
 * timed_mutex.cpp
 * std::timed_mutex object.
 * Compilation: g++ -o timed_mutex timed_mutex.cpp -std=c++11
 * Created: 2015-11-12
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

/*
 * std::timed_mutex                                 Defined in header <mutex>
 * -----------------------------------------------------------------------------
 *  class timed_mutex;          (since C++11)
 * -----------------------------------------------------------------------------
 *  The timed_mutex class is synchronization primitive that can be used to
 *  protect shared data from being simultaneously accessed by multiple threads.
 *  In a manner similar to mutex, timed_mutex offers exclusive, non-recursive
 *  ownership semantics. In additon, timed_mutex provides the ability to attempt
 *  to claim ownership of a timed_mutex with a timeout via the try_lock_for()
 *  and try_lock_until() methods.
 *  The timed_mutex class satisfies all requirements of TimedMutex and
 *  StandardLayoutType.
 *  The timed_mutex object is neither copyable nor movable.
 *
 *  Member functions:
 * -----------------------------------------------------------------------------
 *  lock            tries to lock the mutex, blocks if the mutex is unavailable
 * -----------------------------------------------------------------------------
 *  try_lock        tries to lock the mutex, returns if the mutex is unavailable
 * -----------------------------------------------------------------------------
 *  try_lock_for    tries to lock the mutex, returns if the mutex has been
 *                  unavailable for the specified timeout duration
 * -----------------------------------------------------------------------------
 *  try_lock_until  tries to lock the mutex, returns if the mutex has been
 *                  unavailable until specified time point has been reached
 * -----------------------------------------------------------------------------
 *  unlock          unlocks the mutex
 * -----------------------------------------------------------------------------
 *  native_handle   returns the underlying implementation-defined thread handle
 * -----------------------------------------------------------------------------
 */


std::timed_mutex mtx;

void fireworks()
{
    // waiting to get a lock: each thread prints "-" every 200ms
    while (!mtx.try_lock_for(std::chrono::milliseconds(200))) {
        std::cout << "-";
    }
    // got a lock! - wait for 1s, the this thread prints "*"
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    mtx.unlock();
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(fireworks);
    }

    for (auto &t : threads) {
        t.join();
    }
}
