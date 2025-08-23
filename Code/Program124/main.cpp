/*
Created by  : Vaisakh Dileep
Date        : 8, September, 2021
Description : Header guard.
*/

#include<iostream>

#include "Car_1.hpp" // "Car_1.hpp" also includes "Horn_1.hpp".

#include "Horn_1.hpp" // Inorder to prevent "Horn_1.hpp" from begin included again, we need to provide a header guard for "Horn_1.hpp".

#include "Car_2.hpp" // "Car_2.hpp" also includes "Horn_2.hpp".

#include "Horn_2.hpp" // Inorder to prevent "Horn_2.hpp" from begin included again, we need to provide a header guard for "Horn_2.hpp".

using namespace std;

int main()
{
    Car_1 A {};

    A.say();

    cout<<"\n";

    A.H.say();
    cout<<"\n";

    Car_2 B {};

    B.say();

    cout<<"\n";

    B.H.say();
    cout<<"\n";

    return 0;
}