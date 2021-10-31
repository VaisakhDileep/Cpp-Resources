/*
Created by  : Vaisakh Dileep
Date        : 14, October, 2021
Description : This program helps to understand how to represent hours in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

int main()
{
    chrono::hours h1; // Uninitialized "chrono::hours" variable.

    // chrono::hours h2 = 2; // This is not supported since we can't assign an "int" value to "chrono::hours", but we can use c++ list-like initializer to achieve the same.

    chrono::hours h3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::hours h4 = h3; // We can initialize it with another "chrono::hours" object.

    // h4 = 100; // We can't assign an "int" value to a "chrono::hours" object, assignment will only work if they are both "chrono::hours" objects.

    h4 = 100h; // We can use 'h' literal suffix to assign a "chrono::hours" object with a literal(only works for c++ versions above c++14).

    cout<<"h1: "<<h1.count()<<"\n"; // In order to display the "chrono::hours" object, use ".count()" member method.
    cout<<"h3: "<<h3.count()<<"\n";
    cout<<"h4: "<<h4.count()<<"\n";

/*
Conversion table for hours to seconds:
    1 hour = 3600 seconds
*/

    // chrono::hours test_1 {1s}; // This will give a compiler error, since converting from a "chrono::seconds" literal to a "chrono::hours" object will result in a loss of data(rounding when division), implicit conversion will not take place here, we need to do it manually.

    chrono::hours test_2 {chrono::duration_cast<chrono::hours>(3601s)}; // See here we lost some data.

    chrono::seconds test_3 {1h}; // Here we are trying to cast a "chrono::hours" literal to a "chrono::seconds" object. Since this converion is loss-less(won't loose data), implicit conversion will take place.

    cout<<"test_2: "<<test_2.count()<<"\n";
    cout<<"test_3: "<<test_3.count()<<"\n\n";

    chrono::hours t1 {100h}, t2 {55h}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::hours" object and an "int" literal together or vice-versa.
    result = t1 - 50; // We can't subtract an "int" literal from a "chrono::hours" object or vice-versa.
*/

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::hours" object with an "int" value.
    result = t1 / 2.5; // We can only divide a "chrono::hours" object with an "int" value.
*/

/*
    result = t1 * t2; // We can't multiply two "chrono::hours" objects together.
    result = t1 / t2; // We can't divide two "chrono::hours" objects together.
*/

// All 6 logical operators are supported for "chrono::hours" objects.

    cout<<"min value that chrono::hours can hold: "<<chrono::hours::min().count()<<"\n";
    cout<<"max value that chrono::hours can hold: "<<chrono::hours::max().count()<<"\n";

    return 0;
}