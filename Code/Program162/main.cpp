/*
Created by  : Vaisakh Dileep
Date        : 2, February, 2022
Description : This program helps to understand std::future and std::promise in C++.
*/

#include<iostream>

#include<thread>

#include<future>

/*
std::promise: It provides a facility to store a value or an exception that is later acquired asynchronously via a std::future object created by the std::promise object.
Note: std::promise object is meant to be used only once.
*/

/*
std::future: It provides a mechanism to access the result of asynchronous operations.

Some of the important points to note about "std::future":
1. An asynchronous operation(created via "std::sync", "std::packaged_task", "std::promise") can provide a "std::future" object to the creator of that asynchronous operation.
2. The creator of the asynchronous operation can then use a variety of methods to query, wait for, or extract a value from the "std::future" object.
3. When the asynchronous operation is ready to send the result to the creator, it can do so by modifying shared state(any variable, object or memory space that exists in a shared scope) that is linked to the creator's "std::future" object.
*/

using namespace std;

void counter(promise<unsigned long long> &promise_element, unsigned long long num)
{
    this_thread::sleep_for(chrono::seconds {3}); // This line of code will emulate doing some work.

    unsigned long long count {};

    for(unsigned long long i {0}; i < num; i++)
    {
        count++;
    }

    promise_element.set_value(count);

    this_thread::sleep_for(chrono::seconds {3}); // This line of code will emulate doing some work.
}

int main()
{
    promise<unsigned long long> promise_element {};

    future<unsigned long long> future_element {promise_element.get_future()};

    thread t1 {counter, std::ref(promise_element), 10'00'00'000};
    cout<<"*****start of t1***** \n";

    cout<<"future_element.get(): "<<future_element.get()<<"\n"; // Notice here that we get the result even before 't1' finishes executing.

    t1.join();

    cout<<"*****end of t1*****\n";

    return 0;
}