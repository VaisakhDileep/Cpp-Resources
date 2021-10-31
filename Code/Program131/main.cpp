/*
Created by  : Vaisakh Dileep
Date        : 13, October, 2021
Description : This program helps to understand how to represent seconds in C++.
*/

#include<iostream>

#include<chrono>

using namespace std;

/*
Different time container supported in chrono library:
1. hours
2. minutes
3. seconds
4. milliseconds
5. microseconds
6. nanoseconds

As we go from (6 -> 1), implicit casting happens. Implicit casting does'nt work when we move from (1 -> 6), we have to use explicit casting.
*/

// seconds is the base of the chrono library represented as "chrono::duration<int64_t, ratio<1, 1>>".

void display_chrono_seconds(chrono::seconds s)
{
    cout<<s.count()<<"\n";
}

int main()
{
    chrono::seconds s1; // Uninitialized "chrono::seconds" object.

    // chrono::seconds s2 = 2; // This is not supported since we can't assign an "int" value to "chrono::seconds", but we can use c++ list-like initialization to achieve the same.

    chrono::seconds s3 {100}; // We can initialize it with an "int" value only if we use c++ list-like initialization.

    chrono::seconds s4 = s3; // We can also initialize it with another "chrono::seconds" object.

    // s4 = 100; // We can't assign an "int" value to a "chrono::seconds" object, assignment will only work if they are both "chrono::seconds" objects.

    s4 = 100s; // We can use 's' literal suffix to assign a "chrono::seconds" object with a literal(only works for c++ versions after c++14).

    cout<<"s1: "<<s1.count()<<"\n"; // In order to display the "chrono::seconds" object, use ".count()" member method.
    cout<<"s3: "<<s3.count()<<"\n";
    cout<<"s4: "<<s4.count()<<"\n\n";

/*
    cout<<"display_chrono_seconds(4): "; // This won't work since we can't assign "int" to a "chrono::seconds" object.
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
    result = t1 + 50; // We can't add a "chrono::seconds" object and an "int" literal together or vice-versa.
    result = t1 - 50; // We can't subtract an "int" literal from a "chrono::seconds" object or vice-versa.
*/

    result = t1 + t2;
    result = t1 - t2;

    result = t1 * 2;
    result = t1 / 2;

/*
    result = t1 * 2.5; // We can only multiply a "chrono::seconds" object with an "int" value.
    result = t1 / 2.5; // We can only divide a "chrono::seconds" object with an "int" value.
*/

/*
    result = t1 * t2; // We can't multiply two "chrono::seconds" objects together.
    result = t1 / t2; // We can't divide two "chrono::seconds" objects together.
*/

// All 6 logical operators are supported for "chrono::seconds" objects.

    cout<<"min value that chrono::seconds can hold: "<<chrono::seconds::min().count()<<"\n";
    cout<<"max value that chrono::seconds can hold: "<<chrono::seconds::max().count()<<"\n\n";

    chrono::duration<int32_t> seconds_32_bit {}; // If we want to use our own custom underlying "int" data-type, we can do so. This method can be used for other chrono containers as well.

    cout<<"min value that chrono::duration<int32_t> can hold: "<<chrono::duration<int32_t>::min().count()<<"\n"; // If our application is memory sensitive, we can use this method to tone down our memory consumption.
    cout<<"max value that chrono::duration<int32_t> can hold: "<<chrono::duration<int32_t>::max().count()<<"\n\n";

    chrono::duration<double> seconds_double {}; // The default container is a 64-bit int data-type and does not support floating point values, however we can explicitly plug in a double data-type to our time container.

    seconds_double = 1.5s;

    cout<<"seconds_double: "<<seconds_double.count()<<"\n\n";

    seconds_double = 1s + 1ms; // 'ms' stands for millisecond.

    cout<<"1s + 1ns(chrono::duration<int32_t>): "<<seconds_double.count()<<"\n"; // Notice here that the result is in seconds.

    seconds_double = 1s + 1min; // This will also work.

    cout<<"1s + 1min(chrono::duration<int32_t>): "<<seconds_double.count()<<"\n\n";

    chrono::seconds test {};

    // test = 1s + 1ms; // This will give a compiler error since "1ms" has to be converted to seconds and since it's not loss-less, we have to explicitly do so.

    test = 1s + 1min; // 'min' stands for minutes. Since converting "1ms" to seconds is loss-less, it will be implicitly converted to seconds.

    cout<<"1s + 1min(chrono::seconds): "<<test.count()<<"\n\n";

    chrono::duration<double, std::milli> milliseconds_double {}; // Results will be expressed in milliseconds hereafter. We could also use "chrono::duration<double, ratio<1, 1000>> milliseconds_double {}"

    milliseconds_double = 1s + 1ms;

    cout<<"milliseconds_double: "<<milliseconds_double.count()<<"\n";

/*
if 1 time_container = x seconds:
    use std::ratio<x, 1>

else if 1 time_container = 1 / x seconds:
    use std::ratio<1, x>
*/

    chrono::duration<double, ratio<60, 1>> minutes_double {}; // We can manually do the same for others using "std::ratio<>".

    minutes_double = 1s + 1h + 10ms; // All the values will be first converted to seconds and after getting the result, conversion takes place to minutes(no need to do explicit conversion).

    cout<<"minutes_double: "<<minutes_double.count()<<"\n";

    return 0;
}