/*
Created by  : Vaisakh Dileep
Date        : 18, May, 2021
Description : Pass variable number of arguments to a function.
*/

#include<iostream>

#include<cstdarg> // This header file is required for passing variable number of arguments.

using namespace std;

void function_with_variable_arguments(int count, ...) // "count" is the number of arguments provided. Eclipse(...) means there is a variable number of arguments.
{
    va_list variable_list {}; // "va_list" is provided by "cstdarg" header file.

    va_start(variable_list, count); // "va_start" initializes "variable_list" to retrieve additional arguments.

    for(int i {0}; i < count; i++)
    {
        cout<<va_arg(variable_list, char*)<<" "; // "va_arg" cannot determine the actual type of the arguments passed to the function, so we have to pass the type.
    }

    va_end(variable_list); // Cleans memory reserved for "variable_list".
}

int main()
{
    function_with_variable_arguments(4, "one", "two", "three", "four");

    return 0;
}