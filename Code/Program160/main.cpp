/*
Created by  : Vaisakh Dileep
Date        : 9, January, 2022
Description : This program helps to understand deadlock in C++.
*/

#include<iostream>

#include<mutex>

#include<thread>

#include<chrono>

using namespace std;

mutex m1 {};
mutex m2 {};

void function_1()
{
    m1.lock(); // "function_1" will acquire the lock for 'm1' and waits for '1' second, meanwhile "function_2" will acquire lock for 'm2'. This will create a deadlock, since now "function_1" will need 'm2'.

    this_thread::sleep_for(chrono::seconds {1});

    m2.lock();

    cout<<"successfully entered function_1 .....";

    m1.unlock();
    m2.unlock();
}

void function_2()
{
    m2.lock(); // "function_2" will acquire the lock for 'm2' and waits for '1' second, meanwhile "function_1" will acquire lock for 'm1'. This will create a deadlock, since now "function_2" will need 'm1'.

    this_thread::sleep_for(chrono::seconds {1});

    m1.lock();

    cout<<"successfully entered function_2 .....";

    m1.unlock();
    m2.unlock();
}

int main()
{
    thread t1 {function_1};
    thread t2 {function_2};

    t1.join();
    t2.join();

    return 0;
}