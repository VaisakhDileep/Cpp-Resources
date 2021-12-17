/*
Created by  : Vaisakh Dileep
Date        : 16, December, 2021
Description : This program helps to understand mutex in C++.
*/

#include<iostream>

#include<thread>

#include<mutex>

using namespace std;

unsigned long long balance {0};

void deposit_money_1(unsigned long long deposit) // without "mutex".
{
    for(int i {0}; i < deposit; i++)
    {
        balance++; // This line of code(block of code) is the race condition(critical section). Any thread is free to access this line of code.
    }
}

mutex m {}; // Make sure to make the mutex key global, so that they can be shared across multiple threads.

// mutex are not copyable and not movable.

void deposit_money_2(unsigned long long deposit) // with "mutex".
{
    for(int i {0}; i < deposit; i++)
    {
        m.lock();

        balance++; // This line of code(block of code) is the race condition(critical section). Which ever thread starts the "deposit_money_2" function will be allowed to update "balance" while the other thread will be locked.

        m.unlock();
    }
}

// Note: race condition is a situation where two or more threads/processes happen to change a common data at the same time.

// Note: critical section is the protected section that we have to protect if there is a race condition.

int main()
{
    thread t1 {deposit_money_1, 100000000};

    thread t2 {deposit_money_1, 100000000};

    t1.join();
    t2.join();

    cout<<"balance: "<<balance<<"\n\n"; // We don't get the desired output here, this is because the two threads are working on the critical section at the same time(updates made by one thread may not be reflected on the other thread).

    balance = 0;

    thread t3 {deposit_money_2, 100000000};

    thread t4 {deposit_money_2, 100000000};

    t3.join();
    t4.join();

    cout<<"balance: "<<balance<<"\n";

    return 0;
}