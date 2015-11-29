/**
 * join.cpp
 * std::thread object member function: join().
 * Compilation: g++ -o join join.cpp -std=c++11
 * Creatd: 2015-11-10
 */

#include <iostream>
#include <chrono>
#include <thread>

/*
 * std::thread::join
 * -----------------------------------------------------------------------------
 *  void join();        (since C++11)
 * -----------------------------------------------------------------------------
 *  Blocks thre current thread until the thread identified by *this finishes its
 *  execution.
 * Postconditions:
 *  joinable is false.
 * Exceptions:
 *  std::system_error if an error occurs.
 * Error Conditions:
 * # resource_deadlock_would_occur if this->get_id() == std::this_thread::get_id()
 *   (deadlock detected)
 * # no_such_process if the thread is not valid
 * # invalid_argument if joinable is false
 */

void foo()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);

    std::cout << "starting second helper...\n";
    std::thread helper2(bar);

    std::cout << "waiting for helpers to finish..." << std::endl;
    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}
