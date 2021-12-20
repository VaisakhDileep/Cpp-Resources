/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2021
Description : This program helps to understand mutex::try_lock() in C++.
*/

#include<iostream>

#include<thread>

#include<mutex>

using namespace std;

unsigned long long count {0};

unsigned long long fail_count {0};

mutex m_1 {};

void counter(unsigned long long num)
{
    for(int i {0}; i < num; i++)
    {
        if(m_1.try_lock()) // "mutex::try_lock()" will only try to lock the mutex, if it fails then the thread does not get blocked but it returns "false".
        {
            count++;

            m_1.unlock();
        }
        else
        {
            fail_count++;
        }
    }
}

mutex m_2 {};

void test_function()
{
    m_2.try_lock();

    m_2.try_lock(); // Calling "mutex::try_lock()" on the same thread more than once, might create a dead lock situatoin with undefined behaviour.
}

int main()
{
    thread t1 {counter, 10000};
    thread t2 {counter, 10000};

    t1.join();
    t2.join();

    cout<<"count: "<<count<<"\n\n"; // This is the number of times we were able to successfully lock the thread.

    cout<<"fail count: "<<fail_count<<"\n\n"; // This is the number of times we were not able to lock the thread.

    cout<<"count + fail_count: "<<(count + fail_count)<<"\n"; // This is the number of times we attempted to lock the thread.

    thread t3 {test_function};

    t3.join(); // This might create an undefined behaviour in some systems.

    return 0;
}