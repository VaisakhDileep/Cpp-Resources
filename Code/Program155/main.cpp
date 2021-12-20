/*
Created by  : Vaisakh Dileep
Date        : 20, December, 2021
Description : This program helps to understand timed_mutex in C++.
*/

#include<iostream>

#include<mutex>

#include<thread>

#include<chrono>

using namespace std;

timed_mutex m_1 {}; // "timed_mutex" is similar to "mutex" but it has two specialized functions "try_lock_for()" and "try_lock_until()".

void increment_1(unsigned long long &num)
{
    if(m_1.try_lock_for(chrono::seconds {5})) // This function will lock the mutex if it is availabe and returns "true", else it will wait for '5' seconds. If the time runs out then it will return "false".
    {
        num++;

        this_thread::sleep_for(chrono::seconds {3}); // This line of code will emulate doing some work.

        m_1.unlock();
    }
}

timed_mutex m_2 {};

void increment_2(unsigned long long &num)
{
    if(m_2.try_lock_until(chrono::system_clock().now() + chrono::seconds {5})) // This is similar to the above function but it will wait until the time in the clock is reached.
    {
        num++;

        this_thread::sleep_for(chrono::seconds {3}); // This line of code will emulate doing some work.

        m_2.unlock();
    }
}

int main()
{
    unsigned long long count {};

    thread t1 {increment_1, std::ref(count)};
    thread t2 {increment_1, std::ref(count)};

    t1.join();
    t2.join();

    cout<<"count: "<<count<<"\n\n"; // We are getting the desired result.

    thread t3 {increment_2, std::ref(count)};
    thread t4 {increment_2, std::ref(count)};

    t3.join();
    t4.join();

    cout<<"count: "<<count<<"\n"; // We are getting the desired result.

    return 0;
}