/*
Created by  : Vaisakh Dileep
Date        : 8, September, 2021
Description : This program helps to understand make files in C++.
*/

#include<iostream>

#include "Ford.hpp"

using namespace std;

int main()
{
    Ford mustang {};

    mustang.set_model_name("4th generation mustang 4.6L 4v DOHC modular V8");

    mustang.set_year_of_release(1996);

    cout<<mustang.model_name<<"\n";
    cout<<mustang.year_of_release<<"\n";

    return 0;
}