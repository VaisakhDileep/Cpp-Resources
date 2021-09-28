/*
Created by  : Vaisakh Dileep
Date        : 8, January, 2021
Description : This program helps to understand pointer to member functions in C++.
*/

#include<iostream>

using namespace std;

class Computer
{
private:
    int RAM(int ram) // To have pointer to data members and member functions you need to make them public.
    {
        return ram;
    }
public:
    int (Computer::*pRAM)(int) = &Computer::RAM; // Notice here we can access the private member function using function pointers.
};

int main()
{

/*
Syntax for declaring pointers to member function:
    ReturnType (class_name::*Ptr_name)(argument_type) = &class_name::function_name;

Syntax for function call:
    (object.*object.ptr_name)(arguments);
*/
    Computer Acer;

    cout<<"RAM: "<<(Acer.*Acer.pRAM)(16)<<"\n";

    return 0;
}