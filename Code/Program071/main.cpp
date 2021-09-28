/*
Created by  : Vaisakh Dileep
Date        : 17, January, 2021
Description : This program helps to understand how to pass arguments to Base class constructor from derived class in C++.
*/

#include<iostream>

using namespace std;

class Base
{
private:
    int value;
public:
    Base()
        : value {0}
    {
        cout<<"No-args constructor called for Base class.\n";
    }

    Base(int value)
        : value {value}
    {
        cout<<"Overloaded{int} constructor called for Base class.\n";
    }
};

class Derived: public Base
{
private:
    int double_value;
public:
    Derived()
        : Base {}, double_value {}
    {
        cout<<"No-args constructor called for Derived class.\n";
    }

    Derived(int value)
        : Base {value}, double_value {value * 2}
    {
        cout<<"Overloaded{int} constructor called for Derived class.\n";
    }
};

int main()
{

/*
Syntax for passing arguments to base class constructors:
class Base
{
public:
    Base(int);
};

Derived::Derived(int x)
    :Base(x), {optional initializers for Derived}
{
    // Code
}
*/
    Base base_zero {}; // No-args constructor called
    cout<<"\n";
    Base base_ten {10}; // Overloaded{int} constructor called
    cout<<"\n";

    Derived derived_zero {}; // No-args constructor called
    cout<<"\n";
    Derived derived_ten {10}; // Overloaded{int} constructor called
    cout<<"\n";

    return 0;
}