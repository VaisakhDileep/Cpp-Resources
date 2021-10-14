/*
Created by  : Vaisakh Dileep
Date        : 13, October, 2021
Description : This program helps to understand how to represent milliseconds in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

int main()
{
    chrono::milliseconds milli_s1; // Uninitialized "chrono::milliseconds" variable.

    // chrono::milliseconds milli_s2 = 2; // This is not supported since we can't assign an "int" to "chrono::milliseconds", but we can use c++ list-like initialization to achieve the same.

    chrono::milliseconds milli_s3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::milliseconds milli_s4 = milli_s3; // We can initialize it with another "chrono::milliseconds" object.

    // milli_s4 = 100; // We can't assign an "int" value to a "chrono::milliseconds" object, assignment will only work if they are both "chrono::milliseconds" objects.

    milli_s4 = 100ms; // We can use 'ms' literal suffix to assign a "chrono::milliseconds" object with a literal(only works for c++ versions after c++14).

    cout<<"milli_s1: "<<milli_s1.count()<<"\n"; // In order to display the "chrono::milliseconds" object, use ".count()" member method.
    cout<<"milli_s3: "<<milli_s3.count()<<"\n";
    cout<<"milli_s4: "<<milli_s4.count()<<"\n\n";

/*
Conversion table for second to milliseconds:
    1 second = 1000 millisecond
*/

    chrono::milliseconds test_1 {1s}; // Here we are trying to cast a "chrono::seconds" literal to a "chrono::milliseconds" object. Since this conversion is loss-less(won't loose data), implicit conversion will take place.

    // chrono::seconds test_2 {10ms}; // This will give a compiler error, since converting from a "chrono::milliseconds" literal to a "chrono::seconds" object will result in a loss of data(rounding when dividing), implicit conversion will not take place here, we need to do it manually.

    chrono::seconds test_3 {chrono::duration_cast<chrono::seconds>(111111ms)}; // See here we lost some data.

    cout<<"test_1: "<<test_1.count()<<"\n";
    cout<<"test_3: "<<test_3.count()<<"\n\n";

    chrono::milliseconds t1 {100ms}, t2 {55ms}, result {};

/*
    result = t1 + 50; // We can't add a "chrono::milliseconds" object and an int literal together.
    result = t1 - 50; We can't subtract an "int" literal from a "chrono::milliseconds" object or vice-versa.
*/

    result = t1 + 5s; // This is possible, chrono will implicitly convert "5s" to "chrono::milliseconds".
    result = t1 - 5s; // This is also possible.

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::milliseconds" object with an int value.
    result = t1 / 2.5; // We can only divide a "chrono::milliseconds" object with an int value.
/*

/*
    result = t1 * t2; // We can't multiply two "chrono::milliseconds" objects together.
    result = t1 / t2; // We can't divide two "chrono::milliseconds" objects together.
*/

// All 6 logical operators are supported for "chrono::milliseconds" objects.

    cout<<"min value that chrono::milliseconds can hold: "<<chrono::milliseconds::min().count()<<"\n";
    cout<<"max value that chrono::milliseconds can hold: "<<chrono::milliseconds::max().count()<<"\n";

    return 0;
}