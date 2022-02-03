/*
Created by  : Vaisakh Dileep
Date        : 2, February, 2022
Description : This program helps to understand std::async() in C++.
*/

#include<iostream>

#include<thread>

#include<future>

using namespace std;

unsigned long long counter(unsigned long long num)
{
    cout<<"thread ID of counter(): "<<this_thread::get_id()<<"\n";

    unsigned long long count {};

    for(unsigned long long i {0}; i < num; i++)
    {
        count++;
    }

    return count;
}

// std::async: It runs a function asynchronously(potentially in a new thread which might be part of the thread pool) and returns a "std::future" object that will hold the result.

/*
There are three launch policies for creating tasks:
1. std::launch::async
2. std::launch::deferred
3. std::launch::async | std::launch::deferred
*/

int main()
{
    unsigned long long result {};

    thread::id counter_thread_id {}; // Inorder to store the thread id we have to use a "thread::id" object.

    cout<<"thread ID of main(): "<<this_thread::get_id()<<"\n";

    future<unsigned long long> future_element_1 {async(launch::async, counter, 1'00'00'000)}; // "std::launch::async" will enable asynchronous evaluation(it will create a new thread parallel to the current thread).

    result = future_element_1.get();

    cout<<"future_element_1: "<<result<<"\n\n";

    cout<<"thread ID of main(): "<<this_thread::get_id()<<"\n";

    future<unsigned long long> future_element_2 {async(launch::deferred, counter, 1'00'00'000)}; // "std::launch::deferred" will enable lazy evaluation(won't create a new thread).

    result = future_element_2.get();

    cout<<"future_element_2: "<<result<<"\n\n";

    cout<<"thread ID of main(): "<<this_thread::get_id()<<"\n";

    future<unsigned long long> future_element_3 {async(launch::deferred | launch::async, counter, 1'00'00'000)}; // If both "std::launch::deferred" and "std::launch::async" are set, it will depend upon the operating system which to use(if new thread can be created, then the os will create a new thread).

    result = future_element_3.get();

    cout<<"future_element_3: "<<result<<"\n";

    return 0;
}