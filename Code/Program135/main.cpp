/*
Created by  : Vaisakh Dileep
Date        : 14, October, 2021
Description : This program helps to understand how to represent minutes in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

int main()
{
    chrono::minutes m1; // Uninitialized "chrono::minutes" object.

    // chrono::minutes m2 = 2; // This is not supported since we can't assign an "int" value to "chrono::minutes", but we can use c++ list-like initializer to achieve the same.

    chrono::minutes m3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::minutes m4 = m3; // We can initialize it with another "chrono::minutes" object.

    // m4 = 100; // We can't assign an "int" value to a "chrono::minutes" object, assignment will only work if they are both "chrono::minutes" objects.

    m4 = 100min; // We can use 'min' literal suffix to assign a "chrono::minutes" object with a literal(only works for c++ versions above c++14).

    cout<<"m1: "<<m1.count()<<"\n"; // In order to display the "chrono::minutes" object, use ".count()" member method.
    cout<<"m3: "<<m3.count()<<"\n";
    cout<<"m4: "<<m4.count()<<"\n\n";

/*
Conversion table for minute to seconds:
    1 minute = 60 seconds
*/

    // chrono::minutes test_1 {1s} // This will give a compiler error, since converting from a "chrono::seconds" literal to a "chrono::minutes" object will result in a loss of data(rounding when division), implicit conversion will not take place here, we need to do it manually.

    chrono::minutes test_2 {chrono::duration_cast<chrono::minutes>(65s)}; // See here we lost some data.

    chrono::seconds test_3 {1min}; // Here we are trying to cast a "chrono::minutes" literal to a "chrono::seconds" object. Since this conversion is loss-less(won't loose data), implicit conversion will take place.

    cout<<"test_2: "<<test_2.count()<<"\n";
    cout<<"test_3: "<<test_3.count()<<"\n\n";

    chrono::minutes t1 {100min}, t2 {55min}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::minutes" object and an "int" literal together.
    result = t1 - 50; // We can't subtract an "int" literal from a "chrono::minutes" object or vice-versa.
*/

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::minutes" objects with an "int" value.
    result = t1 / 2.5; // We can only divide a "chrono::minutes" object with an "int" value.
*/

/*
    result = t1 * t2; // We can't multiply two "chrono::minutes" objects together.
    result = t1 / t2; // We can't divide two "chrono::minutes" objects together.
*/

// All 6 logical operators are supported for "chrono::minutes" objects.

    cout<<"min value that chrono::minutes can hold: "<<chrono::minutes::min().count()<<"\n";
    cout<<"max value that chrono::minutes can hold: "<<chrono::minutes::max().count()<<"\n";

    return 0;
}