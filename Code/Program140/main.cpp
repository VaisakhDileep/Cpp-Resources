/*
Created by  : Vaisakh Dileep
Date        : 31, October, 2021
Description : This program helps to understand time_point in C++.
*/

#include<iostream>

#include<ctime>

#include<chrono>

using namespace std;

/*
Internally time_point<> class is represented as:

template<typename Clock, typename Duration>
class time_point
{
    // code ...
};
*/

int main()
{
// using "chrono::system_clock" as clock:
    chrono::time_point<chrono::system_clock, chrono::seconds> time_point_1; // Uninitialized "chrono::time_point" variable.

    // chrono::time_point<chrono::system_clock, chrono::seconds> time_point_2 = 100; // This is not supported since we can't assign an "int" value to a "chrono::time_point" object.

    // chrono::time_point<chrono::system_clock, chrono::seconds> time_point_3 {100}; // Even if we use c++ list-like initialization, it is not possible to assign an "int" value to a "chrono::time_point" object.

    chrono::time_point<chrono::system_clock, chrono::seconds> time_point_4 {100s};

    chrono::time_point<chrono::system_clock, chrono::seconds> epoch_time_point_system_clock {0s}; // The start of "chrono::system_clock".

    // Note: "chrono::duration" can be any time duration, but "chrono::time_point" are durations from a specific start point to a specific end point.

    cout<<"time_point_4.time_since_epoch().count(): "<<time_point_4.time_since_epoch().count()<<"\n\n";

    time_t epoch_time_system_clock {chrono::system_clock::to_time_t(epoch_time_point_system_clock)};

    cout<<"point_4_start_point(epoch): "<<ctime(&epoch_time_system_clock);

    time_t point_4_end_point {chrono::system_clock::to_time_t(time_point_4)};

    cout<<"point_4_end_point         : "<<ctime(&point_4_end_point)<<"\n";

// using "chrono::steady_clock" as clock:
    chrono::time_point<chrono::steady_clock, chrono::seconds> time_point_5 {100s};

    chrono::time_point<chrono::steady_clock, chrono::seconds> epoch_time_point_steady_clock {0s};

    cout<<"time_point_5.time_since_epoch().count(): "<<time_point_5.time_since_epoch().count()<<"\n\n";

    chrono::time_point<chrono::system_clock, chrono::seconds> t1 {100s}, t2 {10s};

    chrono::seconds result_1 {};

    result_1 = t1 - t2; // When subtracting two "chrono::time_point" objects, we get a "chrono::duration" object.

    // result_1 = t1 + t2; // This will give an error, since it doesn't make sense to add two time points.

    chrono::time_point<chrono::system_clock, chrono::seconds> t3 {100s}, result_2 {};

    chrono::seconds s1 {50s};

    result_2 = t3 + s1; // We can add a "chrono::duration" object to a "chrono::time_point" object. The result will be a "chrono::time_point" object as well.

    result_2 = t3 - s1; // We can subtract a "chrono::duration" object from a "chrono::time_point" objects. The result will be a "chrono::time_point" object as well.

    chrono::time_point<chrono::system_clock, chrono::seconds> time_point_sec {100s};

    chrono::time_point<chrono::system_clock, chrono::milliseconds> time_point_milli {time_point_sec}; // Since the conversion from "std::seconds" to "std::milliseconds" is loss-less, conversion is done implicitly.

    // chrono::time_point<chrono::system_clock, chrono::minutes> time_point_min {time_point_sec}; // Since the conversion from "std::seconds" to "std::minutes" will result in a loss of data(due to truncation), we need to do the conversion explicitly.

    chrono::time_point<chrono::system_clock, chrono::minutes> time_point_min {chrono::time_point_cast<chrono::minutes>(time_point_sec)};

    cout<<"time_point_sec  : "<<time_point_sec.time_since_epoch().count()<<"\n";
    cout<<"time_point_milli: "<<time_point_milli.time_since_epoch().count()<<"\n";
    cout<<"time_point_min  : "<<time_point_min.time_since_epoch().count()<<"\n";

// Every "chrono::time_point" object is associated with a clock, "chrono::time_point" with different clocks cannot be assigned with each other.

    chrono::time_point<chrono::system_clock, chrono::seconds> time_point_system_clock {10s};

    // chrono::time_point<chrono::steady_clock, chrono::seconds> time_point_steady_clock {time_point_system_clock}; // This will give an error, since the clocks don't match.

    return 0;
}