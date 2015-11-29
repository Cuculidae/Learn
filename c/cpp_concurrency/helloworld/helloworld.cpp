/**
 * helloworld.cpp
 * Hello World program in concurrency.
 * Compilation: g++ -o helloworld helloworld.cpp -std=c++11
 * Created: 2015-11-08
 */

#include <iostream>
#include <thread>

/*
 * Every thread has to have an initial function, which is where the new thread
 * of execution begins. For the initial thread in an application, this is
 * main(), but for every other thread it's specified in the constructor of a
 * std::thread object.
 *
 * After the new thread has been launched, the initial thread continues
 * execution. If it didn't wait for the new thread to finish, it would merrily
 * continue to the end of main() and thus end the program -- possibly before the
 * new thread has had a chance to run. This is why the call to join() is there
 * -- this causes the calling thread (in main()) to wait for the thread
 *  associated with the std::thread object.
 */

void hello()
{
    std::cout << "Hello Concurrent World\n" << std::endl;
}

int main()
{
    std::thread t(hello);
    t.join();

    return 0;
}
