/*
Created by  : Vaisakh Dileep
Date        : 14, December, 2021
Description : This program helps to understand threading in C++.
*/

#include<iostream>

#include<thread> // Only supported for C++11 versions and above.

#include<chrono>

using namespace std;

unsigned long long odd_sum {};

unsigned long long even_sum {};

void sum_first_n_odd(unsigned long long n) // For the time-being I am only going to use functions that return void.
{
    for(unsigned long long i {1}; i <= n; i += 2)
    {
        odd_sum += i;
    }
}

void sum_first_n_even(unsigned long long n)
{
    for(unsigned long long i {0}; i <= n; i += 2)
    {
        even_sum += i;
    }
}

int main()
{
// Everything after this is the "main" thread.
    unsigned long long n {10000000000};

    chrono::high_resolution_clock::time_point start_time {chrono::high_resolution_clock::now()};

    sum_first_n_even(n);
    sum_first_n_odd(n);

    cout<<"even_sum_1: "<<even_sum<<"\n";
    cout<<"odd_sum_1 : "<<odd_sum<<"\n\n";

    chrono::high_resolution_clock::time_point stop_time {chrono::high_resolution_clock::now()};

    chrono::duration<double, ratio<1, 1>> elapsed_time {stop_time - start_time}; // This way we can get the result in 's'.

    cout<<"Elapsed time: "<<elapsed_time.count()<<"s\n\n";
/*
Syntax for creating a thread:
    std::thread thread_object(callable);

"callable" could be:

1. Function pionter.
2. Function object(functor).
3. Lambda expression.
*/

    even_sum = 0;

    odd_sum = 0;

    start_time = chrono::high_resolution_clock::now();

    thread thread_1(sum_first_n_even, n); // Here we used function pointer to create the thread. The first parameter is the function name followed by the list of parameters.

    thread thread_2(sum_first_n_odd, n);

// Note: If we create multiple threads at the same time it doesn't guarantee which one will start first. Here either "thread_1" or "thread_2" will start first.

    thread_1.join(); // This will wait for "thread_1" to finish executing so that it can proceed executing the main thread.
    thread_2.join(); // This will wait for "thread_2" to finish executing so that it can proceed executing the main thread.

    cout<<"even_sum_1: "<<even_sum<<"\n";
    cout<<"odd_sum_1 : "<<odd_sum<<"\n\n";

    stop_time = chrono::high_resolution_clock::now();

    elapsed_time = stop_time - start_time;

    cout<<"Elapsed time: "<<elapsed_time.count()<<"s\n\n"; // In my computer, threading worsens the time, but might improve performance in other systems.

// Inorder to compile a program with threads use the following command: g++ -Wall -std=c++17 -pthread main.cpp -o main

    return 0;
}