/**
 * detach.cpp
 * std::thread object member function: detach().
 * Compilation: g++ -o detach detach.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <chrono>
#include <thread>

/*
 * std::thread::detach
 * -----------------------------------------------------------------------------
 *  void detach();      (since C++11)
 * -----------------------------------------------------------------------------
 * Separates the thread of execution from the thread object, allowing execution
 * to continue independently. Any allocated resources will be freed once the
 * thread exits.
 * After calling detach *this no longer owns any thread.
 * Postconditions:
 *  joinable() returns false.
 * Exceptions:
 *  std::system_error if joinable() == false or an error occurs.
 */

void independentThread()
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}

int main()
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
