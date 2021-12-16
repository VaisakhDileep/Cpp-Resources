/*
Created by  : Vaisakh Dileep
Date        : 16, December, 2021
Description : This program helps to understand join(), detach() and joinable() in C++.
*/

#include<iostream>

#include<thread>

#include<chrono>

using namespace std;

void function()
{
    cout<<"entering .....\n";

    this_thread::sleep_for(chrono::seconds {3}); // This will pause the thread(t1) for '3' sec.

    cout<<"exiting .....\n\n";
}

int main()
{
    cout<<boolalpha;

    thread t1 {function};

    this_thread::sleep_for(chrono::seconds {1}); // This will pause the main thread for '1' sec.

    cout<<"t1.joinable(): "<<t1.joinable()<<"\n"; // ".joinable()" is an observer function. A thread object is said to be joinable if it identifies an active thread of execution.

/*
A thread is not joinable if:
1. It is default-constructed.
2. If either ".join()" or ".detach()" is called on the thread object.
3. It has been moved elsewhere.
*/

    t1.join(); // When using ".join()", execution of the main thread pauses and waits until the new thread finishes execution.

    cout<<"t1.joinable(): "<<t1.joinable()<<"\n\n"; // Here ".joinable()" returns "false", since we have already performed ".join()" on 't1'.

    // t1.join(); // Calling ".join()" on the same thread more than once might result in the program to terminate.

    if(t1.joinable()) // Sometimes when the program is too lengthy, we might loose track of when ".join()" was called. ".joinable()" will help us to check if it was performed earlier.
    {
        t1.join(); // This will prevent the program from terminating, since "t1.joinable()" will return false.
    }

    thread t2 {function};

    this_thread::sleep_for(chrono::seconds {1}); // This will pause the main thread for '1' sec.

    cout<<"t2.joinable(): "<<t2.joinable()<<"\n";

    t2.detach(); // When using ".detach()", execution of the main function continues along with the current thread('t2').
                 // Here "exiting ....." won't be printed since the main thread has already finished executing resulting in the program termination.

    cout<<"t2.joinable(): "<<t2.joinable()<<"\n\n"; // Here ".joinable()" returns false, since we have already performed ".detach()" on 't2'.

    // thread t3 {function}; // This will make the program to terminate by giving an error. If we don't use ".join()" or ".detach()", then when the destructor of the object is called it will check if ".joinable()" returns "true" or "false". If ".joinable()" returns "true", then the program is terminated.

    return 0;
}