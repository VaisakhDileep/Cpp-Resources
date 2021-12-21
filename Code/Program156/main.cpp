/*
Created by  : Vaisakh Dileep
Date        : 20, December, 2021
Description : This program helps to understand recursive_mutex in C++.
*/

#include<iostream>

#include<thread>

#include<mutex>

using namespace std;

recursive_mutex m_1 {}; // "recursive_mutex" will allow us to lock the same thread multiple times.

unsigned long long count {};

void recursive_counter(unsigned long long num)
{
    if(num <= 0)
    {
        return ;
    }

     m_1.lock();

    count++;

    recursive_counter(--num);

    m_1.unlock(); // Suppose we have locked the mutex 'n' times then we have to unlock the mutex 'n' times as well, otherwise it will still be in lock state.
}

int main()
{
    thread t1 {recursive_counter, 10000}; // We can't use higher values since we will run out of stack memory.
    thread t2 {recursive_counter, 10000};

    t1.join();
    t2.join();

    cout<<"count: "<<count<<"\n";

    return 0;
}