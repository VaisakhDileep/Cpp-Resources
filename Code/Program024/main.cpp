/*
Created by  : Vaisakh Dileep
Date        : 22, December, 2020
Description : This program helps to understand random functions in C++.
*/

#include<iostream>

#include<cstdlib> // For more information go to https://en.cppreference.com/w/cpp/header/cstdlib

#include<ctime> // For more information go to https://en.cppreference.com/w/cpp/header/ctime

using namespace std;

int main()
{
    int random_number {}; // For more accurate random numbers use the random header file.

    size_t count {10};  // Number of random numbers to be generated.

    int min {1};        // Lower bound(inclusive).

    int max {6};        // Upper bound(inclusive).

    cout<<"RAND_MAX on this device: "<<RAND_MAX<<"\n\n";

    srand(time(nullptr)); // We seed the random number generator with time.

    for(size_t i {1}; i <= count; ++i)
    {
        random_number = rand() % max + min; // Throwing a dice.

        cout<<"Face of dice: "<<random_number<<"\n";
    }

    return 0;
}