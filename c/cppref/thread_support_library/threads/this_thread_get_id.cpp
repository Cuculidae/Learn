/**
 * this_thread_get_id.cpp
 * std::this_thread::get_id
 * Compilation: g++ -o this_thread_get_id this_thread_get_id.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

/*
 * std::this_thread::get_id             Defined in header <thread>
 * -----------------------------------------------------------------------------
 *  std::thread::id get_id();       (since C++11)
 * -----------------------------------------------------------------------------
 * Returns the id of the current thread.
 * Return value:
 *  id of the current thread.
 */

std::mutex g_display_mutex;

void foo()
{
    g_display_mutex.lock();
    std::cout << "thread " << std::this_thread::get_id() << " sleeping...\n";
    g_display_mutex.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}
