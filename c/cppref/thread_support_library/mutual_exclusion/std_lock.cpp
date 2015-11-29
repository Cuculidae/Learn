/**
 * std_lock.cpp
 * std::lock
 * Compilation: g++ -o std_lock std_lock.cpp -std=c++11
 * Created: 2015-11-11
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <chrono>

/*
 * std::lock
 * -----------------------------------------------------------------------------
 *  template< class Lockable1, class Lockable2, class... LockableN >
 *  void lock(Lockable1& lock1, Lockable2& lock2, LockableN&... lockn);
 *                                                          (since C++11)
 * -----------------------------------------------------------------------------
 *  Locks the given Lockable objects lock1, lock2, ... lockn using a deadlock
 *  avoidance algorithm to avoid deadlock. The objects are locked by an 
 *  unspecified series of calls to lock, try_lock, unlock. If a call to lock or 
 *  unlock results in an exception. unlock is called for any locked objects 
 *  before rethrowing.
 */

struct Employee {
    Employee(std::string id) : id(id) { }
    std::string id;
    std::vector<std::string> lunch_partners;
    std::mutex m;
    std::string output() const {
        std::string ret = "Employee " + id + " has lunch partners: ";
        for (const auto& partner : lunch_partners)
            ret += partner + " ";
        return ret;
    }
};

void send_mail(Employee &, Employee &)
{
    // simulate a time-consuming messaging operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void assign_lunch_partner(Employee &e1, Employee &e2)
{
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << e1.id << " and " << e2.id << " are waiting for locks\n";
    }

    // use std::lock to acquire two locks without worrying about
    // other calls to assign_lunch_partner deadlocking us
    {
        std::lock(e1.m, e2.m);
        std::lock_guard<std::mutex> lk1(e1.m, std::adopt_lock);
        std::lock_guard<std::mutex> lk2(e2.m, std::adopt_lock);
        std::cout << e1.id << " and " << e2.id << " got locks\n";
        e1.lunch_partners.push_back(e2.id);
        e2.lunch_partners.push_back(e1.id);
    }
    send_mail(e1, e2);
    send_mail(e2, e1);
}

int main()
{
    Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");
    // assign in parallel threads because mailing uses about lunch assignments
    // takes a long time
    std::vector<std::thread> threads;
    threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(bob));
    threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(alice));
    threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));

    for (auto &thread : threads) thread.join();
    std::cout << alice.output() << '\n' << bob.output() << '\n'
              << christina.output() << '\n' << dave.output() << '\n';
}
