/*
Created by  : Vaisakh Dileep
Date        : 2, November, 2021
Description : This program helps to understand the different clocks available in C++.
*/

#include<iostream>

#include<ctime>

#include<chrono>

using namespace std;

void test_function() // for benchmarking
{
    int counter {};

    for(int i {0}; i < 100'0000; i++)
    {
        counter = rand(); // For each iteration it will assign a random number to "counter".
    }
}

int main()
{
// Every "chrono::time_point" object is associated with a clock. "chrono::time_point" objects associated with different clocks do not convert to one another.

/*
The two main clocks in std::chrono library are:
std::chrono::system_clock: system_clock represents the system-wide real time wall clock. It may not be monotic(on most systems, the system time can be adjusted to any moment). It is the only C++ clock that has the ability to map it's time point to C-style time.
std::chrono::steady_clock: steady_clock is a monotonical clock. The time points of this clock cannot decrease as in the case of physical time. It is not related to wall clock time(it could be the time since last reboot). Used for measuring intervals.
*/

// epoch of "std::chrono::system_clock" is unspecific, but most implementations use Unix time(time since 00:00:00 coordinated universe time(UTC), Thursday, 1 January 1970, not counting leap seconds).

// std::chrono::system_clock:
    chrono::system_clock::rep num_ticks_system_clock {}; // "chrono::system_clock::rep" is the signed arithmetic type representing the number of ticks in the clock's duration.

    chrono::system_clock::period system_clock_period {}; // "chrono::system_clock::period" is a "std::ratio" type representing the tick period of the clock in seconds.

    cout<<"system clock period: "<<system_clock_period.num<<"/"<<system_clock_period.den<<"\n\n"; // The tick period.

    cout<<"chrono::system_clock::is_steady: "<<chrono::system_clock::is_steady<<"\n\n"; // It will return false since it does not increase monotonically(any adjustment in the external clock will change it's value).

    chrono::system_clock::duration duration_system_clock {}; // duration class associated with "chrono::system_clock".

    chrono::time_point<chrono::system_clock, chrono::nanoseconds> current_time_point_system_clock {chrono::system_clock::now()}; // "chrono::system_clock::now()" returns the time point corresponding to the current point in time.

    // chrono::system_clock::time_point current_time_point_system_clock {chrono::system_clock::now()}; // We could replace the above statement with this too.

    time_t current_time_system_clock {chrono::system_clock::to_time_t(current_time_point_system_clock)};

    cout<<"current time: "<<ctime(&current_time_system_clock); // This will display the current time.

    chrono::time_point<chrono::system_clock, chrono::nanoseconds> epoch_time_point {0ns};

    time_t epoch_time {chrono::system_clock::to_time_t(epoch_time_point)};

    cout<<"epoch_time: "<<ctime(&epoch_time)<<"\n"; // This will display the epoch time.

// std::chrono::steady_clock:
    chrono::steady_clock::rep num_ticks_steady_clock {}; // "chrono::steady_clock::rep" is the arithmetic type representing the number of ticks in the clock's duration.

    chrono::steady_clock::period steady_clock_period {}; // "chrono::steady_clock::period" is a "std::ratio" type representing the tick period of the clock in seconds.

    cout<<"steady clock period: "<<steady_clock_period.num<<"/"<<steady_clock_period.den<<"\n\n"; // The tick period.

    cout<<"chrono::steady_clock::is_steady: "<<chrono::steady_clock::is_steady<<"\n\n"; // It will return true since it increases monotonically(any adjustment in the external clock won't affect it in anyway).

    chrono::steady_clock::duration duration_steady_clock {}; // duration class associated with "chrono::steady_clock".

    chrono::time_point<chrono::steady_clock, chrono::nanoseconds> current_time_point_steady_clock {chrono::steady_clock::now()}; // Since steady clock is like a stop watch, there is no way of getting the start time(like in the case of epoch).

    // chrono::steady_clock::time_point current_time_point_steady_clock {chrono::steady_clock::now()}; // We could replace the above statement with this too.

    cout<<"current_time_point_steady_clock: "<<current_time_point_steady_clock.time_since_epoch().count()<<"\n\n";

// Benchmarking using std::chrono::system_clock:
    chrono::system_clock::time_point system_clock_start {chrono::system_clock::now()}; // We can also use the "auto" keyword.

    test_function();

    chrono::system_clock::time_point system_clock_stop {chrono::system_clock::now()};

    chrono::system_clock::duration execution_time_system_clock {system_clock_stop - system_clock_start};

    cout<<"execution time[using system clock]: "<<execution_time_system_clock.count()<<"ns \n";

    chrono::duration<double> execution_time_system_clock_in_s {system_clock_stop - system_clock_start}; // "chrono::duration<double>" corresponds to "chrono::seconds" with "double" container.

    cout<<"execution time[using system clock]: "<<execution_time_system_clock_in_s.count()<<"s \n\n";

// Benchmarking using std::chrono::steady_clock:
    chrono::steady_clock::time_point steady_clock_start {chrono::steady_clock::now()}; // We can also use the "auto" keyword.

    test_function();

    chrono::steady_clock::time_point steady_clock_stop {chrono::steady_clock::now()};

    chrono::steady_clock::duration execution_time_steady_clock {steady_clock_stop - steady_clock_start};

    cout<<"execution time[using steady clock]: "<<execution_time_steady_clock.count()<<"ns \n";

    chrono::duration<double> execution_time_steady_clock_in_s {steady_clock_stop - steady_clock_start};

    cout<<"execution_time[using steady clock]: "<<execution_time_steady_clock_in_s.count()<<"s\n";

// std::chrono::high_resolution_clock:
    // In my system, "std::chrono::high_resolution_clock" is a typedef for "std::chrono::system_clock". It might vary is other systems. Generally it is the clock with the shortest tick period.

    return 0;
}