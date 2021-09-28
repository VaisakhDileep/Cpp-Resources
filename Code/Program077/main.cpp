/*
Created by  : Vaisakh Dileep
Date        : 20, January, 2021
Description : This program helps to understand the override specifier in C++.
*/

#include<iostream>

using namespace std;

class Base
{
public:
    virtual void say_hello() const
    {
        cout<<"Hello - You are inside the Base class.\n";
    }
};

class Derived_1: public Base
{
public:
    virtual void say_hello() // The signatures don't match(we have a "const" specifier in Base's class method), so we can't use the override specifier here.
    {
        cout<<"Hello - You are inside the Derived 1 class.\n";
    }
};

class Derived_2: public Base
{
public:
    virtual void say_hello() const override // If the signatures don't match then we will get a compiler error because the override specifier will check for it.
    {
        cout<<"Hello - You are inside the Derived 2 class.\n";
    }
};

int main()
{
/*
In order to override Base class virtual functions, the function signatures and return type should match exactly. If they are different then we are redefining and not overriding. Redefinition is statically bound.

C++11 provides an override specifier to have the compiler ensure overriding.
*/
    Base *base_pointer_1 = new Base(); // static binding will take place
    base_pointer_1->say_hello();

    Derived_1 *derived_1_pointer_1 = new Derived_1(); // static binding will take place
    derived_1_pointer_1->say_hello();

    Base *base_pointer_2 = new Derived_1(); // Here we don't get the desired output because the methods are redefined and not overriden(functions signatures does not watch).
    base_pointer_2->say_hello();

    Base *base_pointer_3 = new Derived_2(); // This will work
    base_pointer_3->say_hello();

    return 0;
}