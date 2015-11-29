/**
 * try_lock_for.cpp
 * std::timed_mutex object member function try_lock_for
 * Compilation: g++ -o try_lock_for try_lock_for.cpp -std=c++11
 * Created: 2015-11-12
 */

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <vector>

/*
 * std::timed_mutex::try_lock_for
 * -----------------------------------------------------------------------------
 *  template< class Rep, class Period >                            (since C++11)
 *  bool try_lock_for( const std::chrono::duration<Rep, Period>& timeout );
 * -----------------------------------------------------------------------------
 *  Tries to lock the mutex. Blocks until specified timeout has elapsed or the
 *  lock is acquired, whichever comes first. On successful lock acquisition
 *  returns true, otherwise returns false.
 *  If timeout is less or equal timeout.zero(), the function behaves like
 *  try_lock().
 *  A steady clock is used to measure the duration. This function may block for
 *  longer than timeout due to scheduling or resource contention delays.
 *  As with try_lock(), this function is allowed to fail spuriously and return
 *  false even if the mutex was not locked by any other thread at some point
 *  during timeout.
 *  Prior unlock() operation on the same mutex synchronizes-with (as defined in
 *  std::memory_order) this operation if it returns true.
 *  If try_lock_for is called by a thread that already owns the mutex, the
 *  behavior is undefined.
 *
 * Exceptions:
 *  Any exception thrown by clock, time_point, or duration during the execution
 *  (clocks, time points, and durations provided by the standard library never
 *  throw)
 */


std::mutex cout_mutex;  // control access to std::cout
std::timed_mutex mutex;

void job(int id)
{
    using Ms = std::chrono::milliseconds;
    std::ostringstream stream;

    for (int i = 0; i < 3; ++i) {
        if (mutex.try_lock_for(Ms(100))) {
            stream << "success ";
            std::this_thread::sleep_for(Ms(100));
            mutex.unlock();
        } else {
            stream << "failed ";
        }
        std::this_thread::sleep_for(Ms(100));
    }

    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[" << id << "] " << stream.str() << "\n";
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(job, i);
    }

    for (auto &t : threads) {
        t.join();
    }
}
