/*
Created by  : Vaisakh Dileep
Date        : 22, December, 2020
Description : Function Prototyping.
*/

#include<iostream>

using namespace std;

double calc_area(double); // Name of the variable is optional, but you can include them.

void area_circle();

void say_hello(string);

int main()
{

/*
The compiler must know about a function before it is used. There are two ways to achieve it.
1. Define functions before calling them.
2. Use function prototypes. Function prototypes are placed at the beginning of the program.

Example of function prototyping:

int function_name(int); ---------> Prototypes
        ... or ...
int function_name(int a); -------> Prototypes

function_name(b) ----------------> Function call(See here we can call the function before declaring them)

int function_name(int a) --------> Function Declaration
{
    statement(s);

    return 0;
}
*/

    area_circle();

    string my_dog {"Skipper"};

    say_hello(my_dog); // Here data is passed by value(copy of the data is passed).

    say_hello("Skipper"); // This is also possible because the compiler casts C-style strings to C++ string.

    return 0;
}

double calc_area(double radius) // Here "radius" is the formal parameter(formal parameters are the parameters defined in the function header).
{
    const double pi {3.14159};

    return pi * radius * radius; // return statement immediately terminates the function.
}

void area_circle()
{
    double radius {};

    cout<<"Enter the radius of the circle: ";

    cin>>radius;

    cout<<"The area of the circle with radius "<<radius<<" is "<<calc_area(radius)<<"\n"; // Here "radius" is the actual parameter(Actual parameters are the parameters used in the function call, the arguments), they are passed by value.
}

void say_hello(string name)
{
    cout<<"Hello "<<name<<"\n";
}