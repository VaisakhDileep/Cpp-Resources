/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2021
Description : Create user-defined exception class.
*/

#include<iostream>

using namespace std;

class DivideByZeroException
{
public:
    DivideByZeroException() = default; // Default constructor

    ~DivideByZeroException() = default; // Default destructor
};

class NegativeValueException
{
public:
    NegativeValueException() = default; // Default constructor

    ~NegativeValueException() = default; // Default destructor
};

double kilo_meter_per_liter(int kilo_meter, int liter)
{
    if(liter == 0)
    {
        throw DivideByZeroException {}; // We are throwing an object of type "DivideByZeroException".
    }

    if(kilo_meter < 0 || liter < 0)
    {
        throw NegativeValueException {}; // We are throwing an object of type "NegativeValueException".
    }

    return static_cast<double>(kilo_meter) / liter;
}

int main()
{
    int kilo_meter = {10};
    int liter = {0};

    double km_per_l;

    try
    {
        km_per_l = kilo_meter_per_liter(kilo_meter, liter);

        cout<<"Km/L: "<<km_per_l<<"\n\n";
    }
    catch(DivideByZeroException &ex)
    {
        cout<<"Division by zero is not supported.\n\n";
    }
    catch(NegativeValueException &ex)
    {
        cout<<"Negative parameter is not supported.\n\n";
    }

    kilo_meter = -10;
    liter = 2;

    try
    {
        km_per_l = kilo_meter_per_liter(kilo_meter, liter);

        cout<<"Km/L: "<<km_per_l<<"\n\n";
    }
    catch(DivideByZeroException &ex)
    {
        cout<<"Division by zero is not suppoted.\n\n";
    }
    catch(NegativeValueException &ex)
    {
        cout<<"Negative parameter is not suppoted.\n\n";
    }

    kilo_meter = 10;
    liter = -2;

    try
    {
        km_per_l = kilo_meter_per_liter(kilo_meter, liter);

        cout<<"Km/L: "<<km_per_l<<"\n\n";
    }
    catch(DivideByZeroException &ex)
    {
        cout<<"Division by zero is not supported.\n\n";
    }
    catch(NegativeValueException &ex)
    {
        cout<<"Negative parameter is not supported.\n\n";
    }

    kilo_meter = 10;
    liter = 2;

    try
    {
        km_per_l = kilo_meter_per_liter(kilo_meter, liter);

        cout<<"Km/L: "<<km_per_l<<"\n\n";
    }
    catch(DivideByZeroException &ex)
    {
        cout<<"Division by zero is not supported.\n\n";
    }
    catch(NegativeValueException &ex)
    {
        cout<<"Negative parameter is not supported.\n\n";
    }

    return 0;
}