/*
Created by  : Vaisakh Dileep
Date        : 31, October, 2021
Description : This program helps to understand the period data member for the different predefined duration types.
*/

#include<iostream>

#include<chrono>

using namespace std;

chrono::duration<int64_t, ratio<1, 1>> se;
/*
Internally all the chrono containers are represetned as the duration<> class.

nanoseconds: typedef duration<int64_t, nano> nanoseconds
microseconds: typdef duration<int64_t, micro> microseconds
milliseconds: typedef duration<int64_t, milli> milliseconds
second: typedef duration<int64_t, ratio<1, 1>> seconds
minutes: typedef duration<int64_t, ratio<60, 1>> minutes
hours: typedef duration<int64_t, ratio<3600, 1>> hours
*/

/*
Internally duration<> class is represented as:

template<class Rep, class Period = ratio<1>> // "Period" is the relation of the duration object with seconds. It is given through the ratio<> template.
class duration
{
    // code ...
}
*/

int main()
{
    cout<<"nanoseconds:\n";
    cout<<"numerator value of period  : "<<chrono::nanoseconds::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::nanoseconds::period::den<<"\n\n";

    cout<<"microseconds:\n";
    cout<<"numerator value of period  : "<<chrono::microseconds::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::microseconds::period::den<<"\n\n";

    cout<<"milliseconds:\n";
    cout<<"numerator value of period  : "<<chrono::milliseconds::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::milliseconds::period::den<<"\n\n";

    cout<<"seconds:\n";
    cout<<"numerator value of period  : "<<chrono::seconds::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::seconds::period::den<<"\n\n";

    cout<<"minutes:\n";
    cout<<"numerator value of period  : "<<chrono::minutes::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::minutes::period::den<<"\n\n";

    cout<<"hours:\n";
    cout<<"numerator value of period  : "<<chrono::hours::period::num<<"\n";
    cout<<"denominator value of period: "<<chrono::hours::period::den<<"\n\n";

    return 0;
}