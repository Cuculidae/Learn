/**
 * sleep_for.cpp
 * std::this_thread::sleep_for
 * Compilation: g++ -o sleep_for sleep_for.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <chrono>
#include <thread>

/*
 * std::this_thread::sleep_for      Defined in header <thread>
 * -----------------------------------------------------------------------------
 *  template< class Rep, class Period>
 *  void sleep_for( const std::chrono::duration<Rep, Period>& sleep_duration );
 *                                                          (since C++11)
 * -----------------------------------------------------------------------------
 *  Blocks the execution of the current thread at least the specified
 *  sleep_duration.
 *  A steady clock is used to measure the duration. This function may block for
 *  longer than sleep_duration due to scheduling or resource contention delays.
 * Exceptions:
 *  Any exception thrown by clock, time_point, or duration during the
 *  execution(clocks, time points and durations provided by the standard library
 *  new throw)
 */

int main()
{
    std::cout << "Hello waiter" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Waited " << elapsed.count() << "ms.\n";
}
