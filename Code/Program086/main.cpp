/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2021
Description : This program helps to understand how to throw an exception from a function in C++.
*/

#include<iostream>

using namespace std;

double average(int sum, int total)
{
    if(total == 0)
    {
        throw 0;
    }

    return static_cast<double>(sum) / total;
}

int main()
{
/*
Consider the function,
double calculate_avg(int sum, int total)
{
    return static_cast<double> (sum) / total;
} // Here notice we are returning a double. Suppose an error occurred(like division by zero) we need to warn the user, but this function only has one return type and that too of type double.

// A possible solution is to return a bool('1' for success and '0' for failure) and creating an average variable outside the function and passing it by reference, but there is a problem if we have more than two exceptions[see the complication increases].
*/
    int sum {10};
    int total {0};

    double avg {};

    try
    {
        avg = average(sum, total);
    }
    catch(int &ex)
    {
        cerr<<"Division by zero is not supported.\n\n";
    }

    avg = average(sum, total); // Notice here since we are not catching the exception, our program will terminate and "Bye Bye." will not be printed.

    cout<<"Bye Bye.\n";

    return 0;
}