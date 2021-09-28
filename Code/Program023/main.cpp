/*
Created by  : Vaisakh Dileep
Date        : 21, December, 2020
Description : This program helps to understand math functions in C++.
*/
#include<iostream>

#include<cmath> // For more information go to https://en.cppreference.com/w/cpp/header/cmath

using namespace std;

int main()
{
// C++ standard libraries contain a lot of predefined functions and classes, Third-party libraries also contain a lot of functions which we need in specific applications like game development. We can also define our own functions and classes.
// https://en.cppreference.com/w/cpp/header --> This contains all the C++ standard libraries.

    double num {};

    cout<<"Enter any number: ";

    cin>>num;

    cout<<"The Square root of "<<num<<" is: "<<sqrt(num)<<"\n";
    cout<<"The Cubed root of "<<num<<" is: "<<cbrt(num)<<"\n";
    cout<<"The sine of "<<num<<" is: "<<sin(num)<<"\n";
    cout<<"The cosine of "<<num<<" is: "<<cos(num)<<"\n";
    cout<<"The ceil of "<<num<<" is: "<<ceil(num)<<"\n";
    cout<<"The floor of "<<num<<" is: "<<floor(num)<<"\n";
    cout<<"The round of "<<num<<" is: "<<round(num)<<"\n\n";

    cout<<"absolute value of -1: "<<abs(-1.2)<<"\n\n";

    double power {};

    cout<<"Enter a power to raise "<<num<<": ";

    cin>>power;

    cout<<num<<" raised to "<<power<<" is: "<<pow(num, power)<<"\n";

    return 0;
}