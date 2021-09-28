/*
Created by  : Vaisakh Dileep
Date        : 21, January, 2021
Description : This program helps to understand the final specifier in C++.
*/

#include<iostream>

using namespace std;

class Base final
{
};

/*
class Derived: public Base // This will give an error because Base class is final and cannot be derived from.
{
};
*/

class Wallet
{
public:
    double cash {100};

    virtual void take_money() final // This will prevent further overriding
    {
        // ... Some actions done ...
    }
};

class Thief: public Wallet
{
public:
    /*
    virtual void take_money() // This might be dangerous, but prevented because we used "final" specifier.
    {
        // ... Some actions done ...
    }
    */
};

int main()
{
/*
When we use final specifier at the class level, it prevents the class from being derived from.
When we use final specifier at the methods level, it prevents the virtual method from being overriden in the derived class.
*/

    return 0;
}