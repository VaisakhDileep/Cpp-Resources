/*
Created by  : Vaisakh Dileep
Date        : 13, October, 2021
Description : This program helps to understand how to represent seconds in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

void display_chrono_seconds(chrono::seconds s)
{
    cout<<s.count()<<"\n";
}

int main()
{
    chrono::seconds s1; // Uninitialized "chrono::seconds" variable.

    // chrono::seconds s2 = 2; // This is not supported since we can't assign an "int" value to "chrono::second", but we can use c++ list-like initialization to achieve the same.

    chrono::seconds s3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::seconds s4 = s3; // We can also initialize it with another "chrono::seconds" object.

    // s4 = 100; // We can't assign an "int" value to a "chrono::second" object, assignment will only work if they are both "chrono::second" objects.

    s4 = 100s; // We can use 's' literal suffix to assign a "chrono::second" object with a literal(only works for c++ versions after c++14).

    cout<<"s1: "<<s1.count()<<"\n"; // In order to display the "chrono::second" object, use ".count()" member method.
    cout<<"s3: "<<s3.count()<<"\n";
    cout<<"s4: "<<s4.count()<<"\n\n";

/*
    cout<<"display_chrono_seconds(4): "; // This won't work since we can't assign "int" to a "chrono::second" object.
    display_chrono_seconds(4);
*/

    cout<<"display_chrono_seconds(4s): ";
    display_chrono_seconds(4s);

    cout<<"display_chrono_seconds(s3): ";
    display_chrono_seconds(s3);

    cout<<"display_chrono_seconds(chrono::seconds {77}): ";
    display_chrono_seconds(chrono::seconds {77});
    cout<<"\n";

    chrono::seconds t1 {100s}, t2 {55s}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::second" object and an int object together.
    result = t1 - 50; // We can't subtract a "chrono::second" object and an int object together.
*/

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * t2; // We can't multiply two "chrono::second" objects together.
    result = t1 / t2; // We can't divide two "chrono::second" objects together.
*/

// All 6 logical operators are supported for "chrono::second" objects.

    cout<<"min value that chrono::second can hold: "<<chrono::seconds::min().count()<<"\n";
    cout<<"max value that chrono::second can hold: "<<chrono::seconds::max().count()<<"\n";

    return 0;
}