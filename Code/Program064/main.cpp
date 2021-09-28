/*
Created by  : Vaisakh Dileep
Date        : 8, January, 2021
Description : This program helps to understand pointer to data members in C++.
*/

#include<iostream>

using namespace std;

class Computer
{
public:
    int RAM;
};

int main()
{
/*
Syntax for declaring pointers to data members:
    DataType class_name::*pointer_name;

Syntax for assigning pointers to data members:
    pointer_name = &class_name::data_member_name;

Syntax for declaring and assigning pointers to data members:
    DataType class_name::*pointer_name = &class_name::datamember_name;
*/

    int Computer::*pRAM = &Computer::RAM;

    Computer Acer;

    Acer.RAM = 16;
    cout<<"RAM: "<<Acer.RAM<<"\n";

    Acer.*pRAM = 32; // (.*) --> Pointer to member operator
    cout<<"RAM: "<<Acer.RAM<<"\n\n";

    Computer *Asus = new Computer;

    Asus->RAM = 16;
    cout<<"RAM: "<<Asus->RAM<<"\n";

    Asus->*pRAM = 32; // (->*) --> Pointer to member operator
    cout<<"RAM: "<<Asus->RAM<<"\n\n";

    delete Asus;

    return 0;
}