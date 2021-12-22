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
}

int main()
{
    thread t1 {deposit_money, 100000000};
    thread t2 {deposit_money, 100000000};

    t1.join();
    t2.join();

    cout<<"balance: "<<balance<<"\n";

    return 0;
}