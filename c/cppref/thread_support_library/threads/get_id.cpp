/**
 * get_id.cpp
 * std::thread object member function: get_id().
 * Compilation: g++ -o get_id get_id.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <chrono>
#include <thread>

/*
 * std::thread::get_id
 * -----------------------------------------------------------------------------
 *  std::thread::id get_id() const;     (since C++11)
 * -----------------------------------------------------------------------------
 *  Returns a value of std::thread::id identifying the thread associated with
 *  *this.
 * Return value:
 *  A value of type std::thread::id identifying the thread associated with
 *  *this. If there is no thread associated, default constructed std::thread::id
 *  is returned.
 * Exceptions:
 *  noexcept specification: noexcept
 */

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t1(foo);
    std::thread::id t1_id = t1.get_id();

    std::thread t2(foo);
    std::thread::id t2_id = t2.get_id();

    std::cout << "t1's id: " << t1_id << '\n';
    std::cout << "t2's id: " << t2_id << '\n';

    t1.join();
    t2.join();
}
