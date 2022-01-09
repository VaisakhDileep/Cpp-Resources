/*
Created by  : Vaisakh Dileep
Date        : 8, January, 2021
Description : This program helps to understand conditional variables in C++.
*/

#include<iostream>

#include<condition_variable>

#include<thread>

using namespace std;

/*
conditional variable: It is a synchronization primitive that can be used to block a thread, or multiple thread at the same time, until another thread both modifies a shared variable(the condition) and notifies the conditional_variable.
It is like communication between different threads.

Conditional variables have two purposes:
1. Notify other threads.
2. Wait for some condition to be satisfied.
*/

condition_variable cv {};

mutex m {};

long long balance {-1}; // '-1' means that the account is not created(the account is new).

void deposit_money_1(long long money)
{
    unique_lock<mutex> unique_l {m};

    if(balance == -1)
    {
        balance = 0;
    }

    balance += money;

    cout<<"current balance(deposit_money_1): "<<balance<<"\n\n";

    cv.notify_one(); // This will notify only one active thread.

    this_thread::sleep_for(chrono::seconds {2}); // This line of code will emulate doing some work.

// Note: Even though we used "notify_one()", the mutex will only be available after the unique_lock object is destroyed.
}

void deposit_money_2(long long money)
{
    unique_lock<mutex> unique_l {m};

    if(balance == -1)
    {
        balance = 0;
    }

    balance += money;

    cout<<"current balance(deposit_money_2): "<<balance<<"\n\n";

    cv.notify_all(); // This will notify all the active threads.

    this_thread::sleep_for(chrono::seconds {2}); // This line of code will emulate doing some work.

// Note: Even though we used "notify_all()", the mutex will only be available after the unique_lock object is destroyed.
}

void withdraw_money(long long money)
{
    unique_lock<mutex> unique_l {m};

    cv.wait(unique_l, [] {return (balance == -1) ? false : true;}); // Using "wait()", it will unlock the mutex and wait until it gets notified.

    if(balance >= money)
    {
        balance -= money;

        cout<<"amount deducted successfully .....\n";
    }
    else
    {
        cout<<"amount cannot be deducted successfully .....\n";
    }

    cout<<"current balance(withdraw_money): "<<balance<<"\n\n";
}

void withdraw_money_with_delay_1(long long money)
{
    unique_lock<mutex> unique_l {m};

    cv.wait_for(unique_l, chrono::seconds {1}); // This will unlock the mutex and wait for '1' second until it tries to re-acquire the mutex.

    if(balance >= money)
    {
        balance -= money;

        cout<<"amount deducted successfully .....\n";
    }
    else
    {
        cout<<"amount cannot be deducted successfully .....\n";
    }

    cout<<"current balance(withdraw_money_with_delay_1): "<<balance<<"\n\n";
}

void withdraw_money_with_delay_2(long long money)
{
    unique_lock<mutex> unique_l {m};

    cv.wait_until(unique_l, chrono::system_clock().now() + chrono::seconds {1}); // This will unlock the mutex and wait until the time is reached to re-acquire the mutex.

    if(balance >= money)
    {
        balance -= money;

        cout<<"amount deducted successfully .....\n";
    }
    else
    {
        cout<<"amount cannot be deducted successfully .....\n";
    }

    cout<<"current balance(withdraw_money_with_delay_2): "<<balance<<"\n\n";
}

int main()
{
    thread t1 {withdraw_money, 500};
    thread t2 {deposit_money_1, 700};

    t1.join();
    t2.join();

    balance = -1;

    cout<<"----------------------------------------\n\n";

    thread t3 {withdraw_money, 500};
    thread t4 {deposit_money_1, 200};

    t3.join();
    t4.join();

/*
    balance = -1;

    cout<<"----------------------------------------\n\n";

    thread t5 {withdraw_money, 100};
    thread t6 {withdraw_money, 200};
    thread t7 {deposit_money_1, 500};

    t5.join();
    t6.join();
    t7.join();
*/ // This won't work since "deposit_money_1" will only notify one of the active thread, the other will keep waiting.

    balance = -1;

    cout<<"----------------------------------------\n\n";

    thread t8 {withdraw_money, 100};
    thread t9 {withdraw_money, 200};
    thread t10 {deposit_money_2, 500};

    t8.join();
    t9.join();
    t10.join();

    balance = -1;

    cout<<"----------------------------------------\n\n";

    thread t11 {withdraw_money_with_delay_1, 100};
    thread t12 {deposit_money_2, 500};

    t11.join();
    t12.join();

    balance = -1;

    cout<<"----------------------------------------\n\n";

    thread t13 {withdraw_money_with_delay_2, 100};
    thread t14 {deposit_money_2, 500};

    t13.join();
    t14.join();

    return 0;
}