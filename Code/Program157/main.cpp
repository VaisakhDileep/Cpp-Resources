/*
Created by  : Vaisakh Dileep
Date        : 22, December, 2021
Description : This program helps to understand lock_guard in C++.
*/

#include<iostream>

#include<thread>

#include<mutex>

using namespace std;

unsigned long long balance {0};

mutex m_1;

void deposit_money(unsigned long long deposit)
{
// "lock_guard<>" is a very light weight wrapper for owning mutex on scoped basis.

    lock_guard<mutex> lock_g {m_1}; // It acquires the "mutex::lock" the moment the object is created, the "mutex::lock" is automatically removed when it goes out of scope.

    for(int i {0}; i < deposit; i++)
    {
        balance++;
    }
// Note: We can't explicitly call unlock on "lock_guard" objects, it will be automatically called when the scope is terminated.

// Note: "lock_guard<>" objects cannot be moved or copied.
}

unsigned long long count {};

recursive_mutex m_2;

void recursive_counter(unsigned long long num)
{
    if(num <= 0)
    {
        return ;
    }

    lock_guard<recursive_mutex> lock_g {m_2};

    count++;

    recursive_counter(--num);
} // Notice here we don't have to manually unlock the "lock_guard" object at the end of each function call.

int main()
{
    thread t1 {deposit_money, 100000000};
    thread t2 {deposit_money, 100000000};

    t1.join();
    t2.join();

    cout<<"balance: "<<balance<<"\n\n";

    thread t3 {recursive_counter, 10000}; // In my os it will fail for large values("lock_guard" fails after a certain number of function calls).
    thread t4 {recursive_counter, 10000}; // In my os it will fail for large values.

    t3.join();
    t4.join();

    cout<<"count: "<<count<<"\n";

    return 0;
}