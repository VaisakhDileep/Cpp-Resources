/*
Created by  : Vaisakh Dileep
Date        : 23, December, 2020
Description : This program helps to understand pass by reference in user-defined functions in C++.
*/

#include<iostream>

using namespace std;

void swap(int &a, int&b);

int main()
{
// References(&) are also known as aliases.
    int x {10}, y {20};

    cout<<"x: "<<x<<"  y: "<<y<<"\n";

    swap(x, y);

    cout<<"x: "<<x<<"  y: "<<y<<"\n";

// When dealing with very large vectors there is a copying overhead when passing by value so pass by reference helps in this case as it saves time.

    return 0;
}

void swap(int &a, int &b)
{
    int temp {a};

    a = b;
    b = temp;
}