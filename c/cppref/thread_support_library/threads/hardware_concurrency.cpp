/**
 * hardware_concurrency.cpp
 * std::object member function: hardware_concurrency().
 * Compilation: g++ -o hardware_concurrency hardware_concurrency.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <thread>

/*
 * std::thread::hardware_concurrency
 * -----------------------------------------------------------------------------
 *  static unsigned hardware_concurrency();     (since C++11)
 * -----------------------------------------------------------------------------
 *  Returns the number of concurrent threads supported by the implementation.
 *  The value should be considered only a hint.
 * Return value:
 *  number of concurrent threads supported. If the value is not well defined or
 *  not computable, returns 0.
 * Exceptions:
 *  noexcept specification: noexcept
 */


int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
}
