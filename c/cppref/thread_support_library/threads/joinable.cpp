/**
 * joinable.cpp
 * std::thread object member function: joinable().
 * Compilation: g++ -o joinable joinable.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <chrono>
#include <thread>

/*
 * std::thread::joinable
 * -----------------------------------------------------------------------------
 *  bool joinable() const;      (since C++11)
 * -----------------------------------------------------------------------------
 *  Checks if the thread object identifies an active thread of execution.
 *  Specifically, returns true if get_id() != std::thread::id(). So a default
 *  constructed thread is not joinable.
 *  A thread that has finish executing code, but has not yet been joined is
 *  still considered an active thread of execution and is therefore joinable.
 * Return Value:
 *  true if the thread object identifies an active thread of execution, false
 *  otherwise.
 * Exceptions:
 *  noexcept specification: noexcept
 */

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t;
    std::cout << "before starting, joinable: " << t.joinable() << '\n';

    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() << '\n';

    t.join();
    std::cout << "after joining, joinable: " << t.joinable() << '\n';
}
