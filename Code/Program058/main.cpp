/*
Created by  : Vaisakh Dileep
Date        : 2, January, 2021
Description : This program helps to understand "this" pointer in C++.
*/

#include<iostream>

#include<string>

using namespace std;

class Name
{
private:
    string name;
public:
    void set_default_name(); // Setters
    void set_name(string name);

    void compare_name(const Name &name_object);
};

void Name::set_default_name()
{
    // name = "None";

    this->name = "None";
}

void Name::set_name(string name)
{
    this->name = name; // Here we can't use "name = name;" because there is a naming conflict(don't know which name to assign).
}

void Name::compare_name(const Name &name_object) // Here "&name_object" is an l-value reference.
{
    if(this == &name_object) // Here '&' is the "address of" operator.
    {
        cout<<"They are the same objects.\n";
    }
    else
    {
        cout<<"They are different objects.\n";
    }
}

int main()
{
// "this" is a reserved keyword. It contains the address of the current object. It can only be used inside the class scope.

    Name Homer;

    Homer.set_default_name();
    Homer.set_name("Homer J Simpson");
    Homer.compare_name(Homer);

    return 0;
}