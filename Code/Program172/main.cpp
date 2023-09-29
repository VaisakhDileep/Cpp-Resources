/*
Created by  : Vaisakh Dileep
Date        : 11, February, 2023
Description : This program helps to understand how to declare static variables inside template functions in C++.
*/

#include<iostream>

using namespace std;

template<typename T>
void temp_func(T arg) { // Just a random template function that accepts a template argument.
    static int function_call_counter = 0;

    function_call_counter++;

    cout << "temp_func has been called " << function_call_counter << " number of times.\n";
}

int main() {
    temp_func<string>("one");
    temp_func<string>("two");
    temp_func<string>("three");
    cout << "\n";

    temp_func<char*>("one");
    temp_func<char*>("two");
    temp_func<char*>("three"); // Notice how each different template instances have their own copy of the static variable. That's why "function_call_counter" got reset when invoking "temp_func<char*>".
    cout << "\n";

    temp_func<char[]>("one");
    temp_func<char[]>("two");
    temp_func<char[]>("three");
    cout << "\n";

    temp_func<const char*>("one");
    temp_func<const char*>("two");
    temp_func<const char*>("three");
    temp_func<const char*>("four"); // Notice here "string", "char*", "char[]" and "const char*" have different template instances.
    cout << "\n";

    temp_func("one");
    temp_func("two");
    temp_func("three"); // By default if we are not providing any template arguments explicitly to "temp_func", it will automatically deduce the type to "const char*".
    cout << "\n";

    temp_func<int>(1);
    temp_func<int>(2);
    temp_func<int>(3);

    return 0;
}