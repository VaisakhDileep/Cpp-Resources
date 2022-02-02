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

void recursive_counter(unsigned long long num, int id)
{
    if(num <= 0)
    {
        return ;
    }

    m_1.lock();

    count++;

    // cout<<"{"<<id<<" : "<<count<<"}\n"; // Notice here that first function call(id = '1') is executed, and once it's completed then only the second function(id = '2') starts executing. It doesn't execute concurrently.

    recursive_counter(--num, id);

    m_1.unlock(); // Suppose we have locked the "recursive_mutex" 'n' times then we have to unlock the same "recursive_mutex" 'n' times as well, otherwise it will still be in the lock state.
}

void iterative_counter(unsigned long long num)
{
    for(unsigned long long i {0}; i < num; i++) // We don't necessary have to use recursion in order to use "recursive_mutex".
    {
        m_1.lock();

        count++;
    }

    for(unsigned long long i {0}; i < num; i++) // We have to unlock the "recursive_mutex" the same number of times that we have locked it.
    {
        m_1.unlock();
    }
}

int main()
{
    thread t1 {recursive_counter, 10000, 1}; // We can't use higher values since we will run out of stack memory.
    thread t2 {recursive_counter, 10000, 2};

    t1.join();
    t2.join();

    cout<<"count: "<<count<<"\n\n";

    count = 0;

    thread t3 {iterative_counter, 10000};
    thread t4 {iterative_counter, 10000};

    t3.join();
    t4.join();

    cout<<"count: "<<count<<"\n";

    return 0;
}