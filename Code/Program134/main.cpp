/*
Created by  : Vaisakh Dileep
Date        : 14, October, 2021
Description : This program helps to understand how to represent nanoseconds in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

int main()
{
    chrono::nanoseconds nano_s1; // Uninitialized "chrono::nanoseconds" object.

    // chrono::nanoseconds nano_s2 = 2; // This is not supported since we can't assign an "int" value to "chrono::nanoseconds", but we can use c++ list-like initializer to achieve the same.

    chrono::nanoseconds nano_s3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::nanoseconds nano_s4 = nano_s3; // We can initialize it with another "chrono::nanoseconds" object.

    // nano_s4 = 100; // We can't assign an "int" value to a "chrono::nanoseconds" object, assignment will only work if they are both "chrono::nanoseconds" objects.

    nano_s4 = 100ns; // We can use 'ns' literal suffix to assign a "chrono::nanoseconds" object with a literal(only works for c++ versions above c++14).

    cout<<"nano_s1: "<<nano_s1.count()<<"\n"; // In order to display the "chrono::nanoseconds" object, use ".count()" member method.
    cout<<"nano_s3: "<<nano_s3.count()<<"\n";
    cout<<"nano_s4: "<<nano_s4.count()<<"\n\n";

/*
Conversion table for second to nano seconds:
    1 second = 1000000000 nanoseconds
*/

    chrono::nanoseconds test_1 {1s}; // Here we are trying to cast a "chrono::seconds" literal to a "chrono::nanoseconds" object. Since this conversion is loss-less(won't loose data), implicit conversion will take place.

    // chrono::seconds test_2 {10000000000ns} // This will give a compiler error, since converting from a "chrono::nanoseconds" literal to a "chrono::seconds" object will result in a loss of data(rounding when dividing), implicit conversion will not take place here, we need to do it manually.

    chrono::seconds test_3 {chrono::duration_cast<chrono::seconds>(1000000001ns)}; // See here we lost some data.

    cout<<"test_1: "<<test_1.count()<<"\n";
    cout<<"test_3: "<<test_3.count()<<"\n\n";

    chrono::nanoseconds t1 {100ns}, t2 {55ns}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::nanoseconds" object and an "int" literal together or vice-versa.
    result = t1 - 50; // We can't subtract an "int" literal from a "chrono::nanoseconds" object or vice-versa.
*/

    result = t1 + 5s; // This is possible chrono will implicitly convert "5s" to "chrono::nanoseconds".
    result = t1 - 5s; // This is also possible.

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::nanoseconds" object with an "int" value.
    result = t1 / 2.5; // We can only divide a "chrono::nanoseconds" object with an "int" value.
*/

/*
    result = t1 * t2; // We can't multiply two "chrono::nanoseconds" objects together.
    result = t1 / t2; // We can't divide two "chrono::nanoseconds" objects together.
*/

// All 6 logical operators are supported for "chrono::nanoseconds" objects.

    cout<<"min value that chrono::nanoseconds can hold: "<<chrono::nanoseconds::min().count()<<"\n";
    cout<<"max value that chrono::nanoseconds can hold: "<<chrono::nanoseconds::max().count()<<"\n";

    return 0;
}