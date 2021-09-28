/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2021
Description : This program helps to understand how to handle multiple exceptions in C++.
*/

#include<iostream>

#include<string>

using namespace std;

double kilo_meters_per_liter(int kilo_meters, int liters)
{
    double km_per_l {};

    if(liters == 0)
    {
        throw 0;
    }

    if(liters < 0)
    {
        throw string {"liter cannot be a negative value ...\n"};
    }

    if(kilo_meters < 0)
    {
        throw string {"kilo_meter cannot be a negative value ...\n"};
    }

    km_per_l = static_cast<double>(kilo_meters) / liters;

    if(km_per_l > 1000)
    {
        throw bool {true};
    }

    return km_per_l;
}

void handle_kilo_meters_per_liter(int kilometers, int liters)
{
    double km_per_l {};

    try
    {
        km_per_l = kilo_meters_per_liter(kilometers, liters);

        cout<<"Km/L: "<<km_per_l<<"\n\n";
    }
    catch(int &ex)
    {
        cerr<<"Division by zero not possible ...\n\n";
    }
    catch(string &ex)
    {
        cerr<<ex<<"\n";
    }
    catch(...) // Catch all --> Here notice we don't have control over the exception object.
    {
        cerr<<"Your code generated some exception ...\n\n";
    }
}

int main()
{
    handle_kilo_meters_per_liter(10, 0);
    handle_kilo_meters_per_liter(-10, 1);
    handle_kilo_meters_per_liter(10, -1);
    handle_kilo_meters_per_liter(-10, -1);
    handle_kilo_meters_per_liter(10000, 1);
    handle_kilo_meters_per_liter(20, 2);

    return 0;
}