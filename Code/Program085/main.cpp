/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2021
Description : Exception handling.
*/

#include<iostream>

using namespace std;

int main()
{
// Exception handling is used when dealing with extra ordinary situations. It indicates that an extra ordinary situation has been detected or has occurred.

/*
Exceptions are causes due to:
1. Insufficient resources
2. Missing resources
3. Invalid Operations
4. Range violations
5. Underflows and overflows
6. Illegal data
*/

// A program is said to be exception safe, if it handles exceptions.

// Exception: Exception is an object or primitive type that signals that an error has occurred.

/*
Keywords used when handling exceptions:
throw: It throws an exception, it is followed by an argument.

try { Code that may throw an exception } : If the code throws an exception the try block is exited, the throw exception is handled by a catch handler. If no catch handler exists the program terminates.

catch(Exception ex) { Code to handle the exception }: Code that handles the exception. Can have multiple catch handlers. May or may not cause the program to terminate.
*/

    cout<<"1.0 / 0 : "<<(1.0 / 0)<<"\n"; // Dividing a floating point number by '0' need not generate an exception.
    cout<<"-1.0 / 0: "<<(-1.0 / 0)<<"\n";
    cout<<"0.0 / 0 : "<<(0.0 / 0)<<"\n"; // "nan" - Not a number

    int numerator {};
    int denominator {};

    numerator = 10;
    denominator = 0;

    try
    {
        if(denominator == 0)
        {
            throw 0;
        }
    }
    catch(int &ex)
    {
        cerr<<"Sorry, Division by zero is not supported.\n"; // "cerr" represents the standard error stream.
    }

    return 0;
}