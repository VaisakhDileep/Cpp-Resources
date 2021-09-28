/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2021
Description : This program helps to understand stack unwinding in C++.
*/

#include<iostream>

using namespace std;

void func_b1();
void func_c1();

void func_a1()
{
    cout<<"Starting function A1.\n\n";

    func_b1();

    cout<<"Ending function A1.\n\n";
}

void func_b1()
{
    cout<<"Starting function B1.\n\n";

    func_c1();

    cout<<"Ending function B1.\n\n";
}

void func_c1()
{
    cout<<"Starting function C1.\n\n";

    cout<<"Ending function C1.\n\n";
}

void func_b2();
void func_c2();

void func_a2()
{
    cout<<"Starting function A2.\n\n";

    func_b2();

    cout<<"Ending function A2.\n\n";
}

void func_b2()
{
    cout<<"Starting function B2.\n\n";

    func_c2();

    cout<<"Ending function B2.\n\n";
}

void func_c2()
{
    cout<<"Starting function C2.\n\n";

    throw 100;

    cout<<"Ending function C2.\n\n";
}

int main()
{
// If an exception is thrown but not caught in the current scope, then C++ tries to find a handler for the exception by unwinding the stack.

// Function in which the exception was not caught terminates and is removed from the call stack. If no try block was used or the catch handler doesn't match, then stack unwinding occurs again. If the stack is unwound back to main and no catch handler handles the exception, the program terminates.

    func_a1(); // Here's how stack unwinding works when no exception is thrown.

    cout<<"----------------------------------------\n";

    func_a2(); // Here's what happens when an exception is thrown and is not caught.

    return 0;
}