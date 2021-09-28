/*
Created by  : Vaisakh Dileep
Date        : 22, December, 2020
Description : This program helps to understand how to define functions in C++.
*/

#include<iostream>

using namespace std;

void say_world()
{
    cout<<"World\n";

    cout<<"Bye from say_world()\n";
}

void say_hello()
{
    cout<<"Hello ";

    say_world();

    cout<<"Bye from say_hello()\n";
}

double calc_area(double radius)
{
    const double pi {3.14159};

    return (pi * radius * radius);
}

void area_circle()
{
    double radius {};

    cout<<"Enter the radius of the circle: ";

    cin>>radius;

    cout<<"The area of the circle with radius "<<radius<<" is "<<calc_area(radius)<<"\n";
}

int main()
{
/*
Functions contains the following components:
1. Name: Same rules as naming a variable.
2. Parameter list: The variables passed to the function, their type must be specified.
3. Return type: The type of data that is returned by the function.
4. Body: The statements that are executed by the function, enclosed by { }.

Example of a function with no parameters:

int function_name()
{
    statement(s);

    return 0;
}

Example of a function that takes in 1 parameter:

int function_name(int a)
{
    statement(s);

    return 0;
}

Example of a function that returns void(nothing):

void function_name()
{
    statement(s);

    return; // Optional
}

Example of a function that takes in multiple parameters:

void function_name(int a, std::string b)
{
    statement(s);

    return; // Optional
}
*/

    say_hello(); // Always declare the functions before we use them(declaration should always be above the function call).

    area_circle(); // Note: We can't define a function inside another function.

    cout<<"Bye from main function.\n";

    return 0;
}