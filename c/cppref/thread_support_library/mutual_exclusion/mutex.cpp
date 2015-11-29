/**
 * mutex.cpp
 * C++11 std::mutex object.
 * Compilation: g++ -o mutex mutex.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

/*
 * std::mutex                                   Defined in header <mutex> 
 * -----------------------------------------------------------------------------
 *  class mutex;            (since C++11)
 * -----------------------------------------------------------------------------
 *  The mutex class is a synchronization primitive that can be used to protect
 *  shared data from being simultaneously accessed by multiple threads.
 *  mutex offers exclusive, non-recursive ownership semantics:
 *   # A calling thread owns a mutex from the time that it successfully calls
 *     either lock or try_lock until is calls unlock.
 *   # When a thread owns a mutex, all other threads will block (for calls to
 *     lock) or receive a false return value (for try_lock) if they attempt to
 *     claim ownership of the mutex.
 *   # A calling thread must not own the mutex prior to calling lock or try_lock.
 *  
 *  The behavior of a program is undefined if a mutex is destroyed while still
 *  owned by some thread. The mutex class satisfies all requirements of Mutex
 *  and StandardLayoutType.
 *  std::mutex is neither copyable or movable.
 *
 *  Notes:
 *   std::mutex is usually not accessed directly: std::unique_lock and
 *   std::lock_guard are used to manage locking in exception-safe manner.
 */


std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";

    g_pages_mutex.lock();   // or, to be exception-safe, use std::lock_guard
    g_pages[url] = result;
    g_pages_mutex.unlock();
}

int main()
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();

    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }

}
