/*
Created by  : Vaisakh Dileep
Date        : 15, January, 2022
Description : This program helps to understand std::lock() in C++.
*/

#include<iostream>

#include<mutex>

#include<thread>

using namespace std;

// "std::lock()" is used to lock multiple mutexes at the same time without creating a deadlock.

mutex m_1 {};
mutex m_2 {};
mutex m_3 {};
mutex m_4 {};
mutex m_5 {};

void print_A_1()
{
    while(true)
    {
        m_1.lock();
        m_2.lock();
        m_3.lock();
        m_4.lock();
        m_5.lock();

        cout<<"A\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

void print_B_1()
{
    while(true)
    {
        m_5.lock();
        m_4.lock();
        m_3.lock();
        m_2.lock();
        m_1.lock();

        cout<<"B\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

// Note: For "print_A_1()" and "print_B_1()", it will result in a deadlock.

void print_A_2()
{
    while(true)
    {
        m_1.lock();
        m_2.lock();
        m_3.lock();
        m_4.lock();
        m_5.lock();

        cout<<"A\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

void print_B_2()
{
    while(true)
    {
        m_1.lock();
        m_2.lock();
        m_3.lock();
        m_4.lock();
        m_5.lock();

        cout<<"B\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

// Note: For "print_A_2()" and "print_B_2()", it will not create a deadlock because all the mutex are locked in the same order(whichever locks 'm1' successfully will only be able to lock the other mutexes).

void print_A_3()
{
    while(true)
    {
        lock(m_1, m_2, m_3, m_4, m_5); // Suppose if "lock()" fails to get the lock for 'm_5', then it will release all the already locked mutexes and wait until 'm_5' becomes available(it will now put 'm_5' at the top-most priority).

        cout<<"A\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

void print_B_3()
{
    while(true)
    {
        lock(m_5, m_4, m_3, m_2, m_1);

        cout<<"B\n";

        m_1.unlock();
        m_2.unlock();
        m_3.unlock();
        m_4.unlock();
        m_5.unlock();
    }
}

int main()
{
/*
    thread t1 {print_A_1};
    thread t2 {print_B_1};

    t1.join();
    t2.join();
*/

/*
    thread t3 {print_A_2};
    thread t4 {print_B_2};

    t3.join();
    t4.join();
*/

    thread t5 {print_A_3};
    thread t6 {print_B_3};

    t5.join();
    t6.join();

    return 0;
}