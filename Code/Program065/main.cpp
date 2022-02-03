/*
Created by  : Vaisakh Dileep
Date        : 8, January, 2021
Description : This program helps to understand pointer to member methods in C++.
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

    // int (Computer::*pRAM)(int) = Computer::RAM; // We can also use "Computer::RAM" instead of "&Computer::RAM".

    // int (Computer::*pRAM)(int) = RAM; // We can also use "RAM" instead of "&Computer::RAM".
};

class Car
{
public:
    string car_name;

    int top_speed;

    void print_car_name()
    {
        cout<<"car name: "<<car_name<<"\n";
    }

    void print_car_top_speed()
    {
        cout<<"top speed: "<<top_speed<<"\n";
    }

    void print_all_details()
    {
        void (Car::*display_car_name)() {print_car_name};

        void (Car::*display_top_speed)() {print_car_top_speed};

        (this->*display_car_name)(); // When dealing with function pointers to member methods, we have to invoke(call) it using it's object pointer("this"). (->*) --> Pointer to member operation.

        (this->*display_top_speed)();
    }
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

    cout<<"RAM: "<<(Acer.*Acer.pRAM)(16)<<"\n\n"; // (.*) --> Pointer to member operation.

    Car BMW {};

    BMW.car_name = "BMW M8";

    BMW.top_speed = 250;

    BMW.print_all_details();

    return 0;
}