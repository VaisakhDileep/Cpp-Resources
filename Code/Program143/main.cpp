/*
Created by  : Vaisakh Dileep
Date        : 15, November, 2021
Description : Ctime library.
*/

#include<iostream>

#include<ctime>

using namespace std;

void test_function() // for benchmarking
{
    int counter {};

    for(int i {0}; i < 10'00'00'000; i++)
    {
        counter = rand(); // For each iteration it will assign a random number to "counter".
    }
}

void display_time_structure(const tm &time_struct)
{
    cout<<"sec                 : "<<time_struct.tm_sec<<"\n";
    cout<<"min                 : "<<time_struct.tm_min<<"\n";
    cout<<"hour                : "<<time_struct.tm_hour<<"\n";
    cout<<"month day           : "<<time_struct.tm_mday<<"\n";
    cout<<"month               : "<<time_struct.tm_mon<<"\n";
    cout<<"year                : "<<time_struct.tm_year<<"\n";
    cout<<"week day            : "<<time_struct.tm_wday<<"\n";
    cout<<"year day            : "<<time_struct.tm_yday<<"\n";
    cout<<"daylight saving time: "<<time_struct.tm_isdst<<"\n\n";
}

int main()
{
    time_t current_time_1 {}; // "time_t" is generally implemented as an integral value representing the number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC(epoch).

    time(&current_time_1); // Inorder to get the current time.

    cout<<"current time 1: "<<ctime(&current_time_1)<<"\n"; // Inorder to display the current time.

    cout<<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<<"\n\n"; // Number of clock ticks per second.

/*
Internally "tm" looks like:
struct tm
{
    int tm_sec;   // seconds, range: [0, 59]
    int tm_min;   // minutes, range: [0, 59]
    int tm_hour;  // hours, range: [0, 23]
    int tm_mday;  // day of the month, range: [1, 31]
    int tm_mon;   // month, range: [0, 11]
    int tm_year;  // The number of years since 1900
    int tm_wday;  // day of the week, range: [0, 6]
    int tm_yday;  // day of the year, range: [0, 365]
    int tm_isdst; // daylight saving time.
};
*/

    tm *time_structure_GMT {gmtime(&current_time_1)};

    cout<<"GMT time structure: \n";
    display_time_structure(*time_structure_GMT);

    tm *time_structure_local_time {localtime(&current_time_1)};

    cout<<"local time structure: \n";
    display_time_structure(*time_structure_local_time);

    time_t current_time_GMT {mktime(time_structure_GMT)}; // We can convert a time structure to a time object.

    cout<<"current time GMT: "<<ctime(&current_time_GMT)<<"\n"; // Notice that it's still displayed in local time.

    time_t start_time {time(NULL)}; // "time(NULL)" will return the time since epoch. Passing "start_time" as an argument to "time()" will also do the same.

    time(&start_time);

    test_function();

    time_t end_time {time(NULL)};

    time(&end_time);

    double elapsed_time {end_time - start_time};

    cout<<"elapsed time: "<<elapsed_time<<"s\n"; // We get the result as integral values.

    clock_t clock_start {}, clock_end {};

    clock_start = clock(); // "clock()" will return the number of clock ticks elapsed since the program was launched.

    test_function();

    clock_end = clock();

    elapsed_time = double(clock_end - clock_start) / CLOCKS_PER_SEC;

    cout<<"elapsed time[using clock ticks]: "<<elapsed_time<<"s\n\n";

    // We can format the way we display time by using "strftime". For more information(the different format) refer: https://www.cplusplus.com/reference/ctime/strftime/

    char buffer[100];

    strftime(buffer, 100, "Time: %H(24 hour format)", time_structure_local_time); // time should be passed in "tm"(time structure) format.

    cout<<"buffer: "<<buffer<<"\n";

    return 0;
}