/**
 * swap.cpp
 * std::thread object swap operatioins.
 * Compilation: g++ -o swap swap.cpp -std=c++11
 * Created: 2015-11-10
 */

#include <iostream>
#include <thread>
#include <chrono>

/*
 * std::thread::swap
 * -----------------------------------------------------------------------------
 *  void swap(thread& other);       (since C++11)
 * -----------------------------------------------------------------------------
 *  Exchanges the underlying handles of two thread objects.
 * Exceptions:
 *  noexcept
 *
 * std::swap    (std::thread)
 * -----------------------------------------------------------------------------
 *  void swap( thread &lhs, thread &rhs);       (since C++11)
 * -----------------------------------------------------------------------------
 *  Overloads the std::swap algorithm for std::thread. Exchanges the state of
 *  lhs with that of rhs. Effectively calls lhs.swap(rhs).
 * Exceptions:
 *  noexcept
 */

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t1(foo);
    std::thread t2(bar);

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;
    
    std::swap(t1, t2);

    std::cout << "after std::swap(t1, t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.swap(t2);
    std::cout << "after t1.swap(t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
}
