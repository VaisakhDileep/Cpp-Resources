/*
Created by  : Vaisakh Dileep
Date        : 14, October, 2021
Description : This program helps to understand how to represent microseconds in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

int main()
{
    chrono::microseconds micro_s1; // Uninitialized "chrono::microseconds" object.

    // chrono::microseconds micro_s2 = 2; // This is not supported since we can't assign an "int" value to "chrono::microseconds", but we can use c++ list-like initializer to achieve the same.

    chrono::microseconds micro_s3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::microseconds micro_s4 = micro_s3; // We can initialize it with another "chrono::microseconds" objects.

    // micro_s4 = 100; // We can't assign an "int" value to a "chrono::microseconds" object, assignment will only work if they are both "chrono::microseconds" objects.

    micro_s4 = 100us; // We can use 'us' literal suffix to assign a "chrono::microseconds" object with a literal(only works for c++ versions above c++14).

    cout<<"micro_s1: "<<micro_s1.count()<<"\n"; // In order to display the "chrono::microseconds" object, use ".count()" member method.
    cout<<"micro_s3: "<<micro_s3.count()<<"\n";
    cout<<"micro_s4: "<<micro_s4.count()<<"\n\n";

/*
Conversion table for second to microseconds:
    1 second = 1000000 microseconds
*/

    chrono::microseconds test_1 {1s}; // Here we are trying to cast a "chrono::seconds" literal to a "chrono::microseconds" object. Since this conversion is loss-less(won't loose data), implicit conversion will take place.

    // chrono::seconds test_2 {10us} // This will give a compiler error, since converting from a "chrono::microseconds" literal to a "chrono::seconds" object will result in a loss of data(rounding when dividing), implicit conversion will not take place here, we need to do it manually.

    chrono::seconds test_3 {chrono::duration_cast<chrono::seconds>(1111111111us)}; // See here we lost some data.

    cout<<"test_1: "<<test_1.count()<<"\n";
    cout<<"test_3: "<<test_3.count()<<"\n\n";

    chrono::microseconds t1 {100us}, t2 {55us}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::microseconds" object and an "int" literal together.
    result = t1 - 50; // We can't subtract an "int" literal from a "chrono::microseconds" object or vice-versa.
*/

    result = t1 + 5s; // This is possible, chrono will implicitly convert "5s" to "chrono::microseconds".
    result = t1 - 5s; // This is also possible.

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::microseconds" object with an "int" value.
    result = t1 / 2.5; // We can only divide a "chrono::microseconds" object with an "int" value.
*/

/*
    result = t1 * t2; // We can't multiply two "chrono::microseconds" objects together.
    result = t1 / t2; // We can't divide two "chrono::microseconds" objects together.
*/

// All 6 logical operators are supported for "chrono::microseconds" objects.

    cout<<"min value that chrono::microseconds can hold: "<<chrono::microseconds::min().count()<<"\n";
    cout<<"max value that chrono::microseconds can hold: "<<chrono::microseconds::max().count()<<"\n";

    return 0;
}