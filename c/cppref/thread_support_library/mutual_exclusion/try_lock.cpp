/**
 * try_lock.cpp
 * std::mutex object member function: try_lock()
 * Compilation: g++ -o try_lock try_lock.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

/*
 * std::mutex::try_lock
 * -----------------------------------------------------------------------------
 *  bool try_lock();        (since C++11)
 * -----------------------------------------------------------------------------
 *  Tries to lock the mutex. Returns immdediately. On successful lock
 *  acquisition returns true, otherwise returns false.
 *  This function is allowed to fail spuriously and return false even if the
 *  mutex is not currently locked by any other thread.
 *  If try_lock is called by a thread that already owns the mutex, the behavior
 *  is undefined.
 *  Prior unlock() operation on the same mutex synchronizes-with (as defined in
 *  std::memory_order) this operation if it returns true. Note that prior lock()
 *  does not synchronizes with this operation if it returns false.
 *  Return value:
 *   true if the lock was accuired successfully, otherwise false.
 */


std::chrono::milliseconds interval(100);

std::mutex mutex;
int job_shared = 0; // both threads can modify 'job_shared', mutex will protect this variable

int job_exclusive = 0;  // only one thread can modify 'job_exclusive', no protection needed

// this thread can modify both 'job_shared' and 'job_exclusive'
void job_1()
{
    std::this_thread::sleep_for(interval);  // let 'job_2' take a lock

    while (true) {
        // try to lock mutex to modify 'job_shared'
        if (mutex.try_lock()) {
            std::cout << "job shared (" << job_shared << ")\n";
            mutex.unlock();
            return;
        } else {
            // can't get lock to modify 'job_shared'
            // but there is some other work to do
            ++job_exclusive;
            std::cout << "job exclusive (" << job_exclusive << ")\n";
            std::this_thread::sleep_for(interval);
        }
    }
}

// this thread can modify only 'job shared'
void job_2()
{
    mutex.lock();
    std::this_thread::sleep_for(5 * interval);
    ++job_shared;
    mutex.unlock();
}

int main()
{
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();
}
