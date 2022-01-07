/*
Created by  : Vaisakh Dileep
Date        : 31, December, 2021
Description : This program helps to understand unique_lock in C++.
*/

#include<iostream>

#include<thread>

#include<mutex>

using namespace std;

unsigned long long balance {0};

mutex m_1;

void deposit_money_1(unsigned long long deposit)
{
    unique_lock<mutex> unique_l_1 {m_1}; // Here it will take the ownership as well as lock the mutex.

    unique_lock<mutex> unique_l_2 {move(unique_l_1)}; // We can move a "unique_lock<>" object, but can't copy it.

    for(int i {0}; i < deposit; i++)
    {
        balance++;
    }
}

void deposit_money_2(unsigned long long deposit)
{
    unique_lock<mutex> unique_l_1 {m_1, defer_lock}; // This locking strategy will do not acquire ownership of the mutex(does not lock it).

    unique_lock<mutex> unique_l_2 {move(unique_l_1)}; // We can move a "unique_lock<>" object.

    // unique_l_1.lock(); // This is no longer valid, since we moved it.

    unique_l_2.lock(); // We have to lock it later.

    for(int i {0}; i < deposit; i++)
    {
        balance++;
    }
}

void deposit_money_3(unsigned long long deposit)
{
    m_1.lock(); // Notice here we have locked the mutex before making the "unique_lock<>" object own the mutex.

    unique_lock<mutex> unique_l_1 {m_1, adopt_lock}; // This locking strategy will own the the mutex(the calling thread should already have ownership of the mutex).

    unique_lock<mutex> unique_l_2 {move(unique_l_1)}; // We can move a "unique_lock<>" object.

    for(int i {0}; i < deposit; i++)
    {
        balance++;
    }
}

void deposit_money_4(unsigned long long deposit, int id)
{
    unique_lock<mutex> unique_l {m_1, try_to_lock}; // This locking strategy will try to acquire ownership of the mutex without blocking it.

    if(unique_l.owns_lock()) // ".owns_lock()" returns whether the object owns a lock. It is true if the managed mutex object was locked(or adopted) by the "unique_lock<>" object.
    {
        cout<<id<<" successfully got the lock.\n";

        for(int i {0}; i < deposit; i++)
        {
            balance++;
        }
    }
    else
    {
        cout<<id<<" did not get the link.\n";
    }
}

int main()
{
// "unique_lock<>" is a mutex ownership wrapper.

/*
The features of "unique_lock<>" are:
1. "unique_lock<>" can have different locking strategies.
2. We can use time-constrained locking attempts("try_lock_for", "try_lock_until").
3. "unique_lock<>" supports recursive locking.
4. "unique_lock<>" allows transfer of lock ownership(move) but does not supporting copy operation.
5. "unique_lock<>" supports condition variables.
*/

    thread t1 {deposit_money_1, 100000000};
    thread t2 {deposit_money_1, 100000000};

    t1.join();
    t2.join();

    cout<<"balance: "<<balance<<"\n\n";

    balance = 0;

    thread t3 {deposit_money_2, 100000000};
    thread t4 {deposit_money_2, 100000000};

    t3.join();
    t4.join();

    cout<<"balance: "<<balance<<"\n\n";

    balance = 0;

    thread t5 {deposit_money_3, 100000000};
    thread t6 {deposit_money_3, 100000000};

    t5.join();
    t6.join();

    cout<<"balance: "<<balance<<"\n\n";

    balance = 0;

    thread t7 {deposit_money_4, 100000000, 1};
    thread t8 {deposit_money_4, 100000000, 2};

    t7.join();
    t8.join();

    cout<<"\nbalance: "<<balance<<"\n";

    return 0;
}