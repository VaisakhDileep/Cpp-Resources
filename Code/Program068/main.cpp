/*
Created by  : Vaisakh Dileep
Date        : 15, January, 2021
Description : This program helps to understand inheritance in C++.
*/

#include<iostream>

#include "Player.hpp"

#include "Hero.hpp"

using namespace std;

int main()
{
// Inheritance provides a method for creating new classes from existing classes. The new class contains the data and behaviour of the existing class. It allows us to reuse existing code.

/*
Single Inheritance: A new class is created from another "single" class.

Multiple Inheritance: A new class is created from "two or more" classes.

Base class(parent class, super class): The class being extended or inherited from.

Derived class(child class, sub class): The class being created from the "Base" class. It will inherit attributes and operations from the "Base" class.

    Base <--- Derived [UML representation]

"Is-A" Relationship: Here we use public inheritance, derived classes are sub-types of their Base classes. We can use a derived class object whenever we need to use a base class object.

We use inheritance for the following purposes:
1. Generalization: Combining similar classes into a single, more general class based on common attributes.
2. Specialization: Creating new classes from existing classes providing more specialized attributes and operations.

To understand generalization and specialization refer the image in "Additional Resources" named "C++GeneralizationVsSpecialization".

Public Inheritance("Is-A") vs Composition("Has-A"):
    Person <--- Employee (Here Employee is a Person)

    Person ---- Account(Here Person has an Account)

From the above two examples we can derive that Employee also has an Account.

Also we have been using composition all along,
Class Person
{
private:
    string name; // Person has a name
    Account account; // Person has an account
};

Aggregation, Association and Composition are also different techniques used for modeling object oriented behaviour(Check them out later).
*/

/*
Syntax for deriving classes from existing classes:
class Base
{
    // Base class members ...
};

class Derived: access-specifier Base // Here "access-specifier" can be public, private, or protected(by default it is private).
{
    // Derived class members ...
};
*/

/*
public(access-specifier) inheritance: It established "Is-A" relationship between Derived and Base classes.

private and protected inheritance: It established "derived class Has-A base class" relationship(different from composition).
*/
    Player Homer {};

    Homer.set_player_name("Homer J Simpson");
    Homer.set_player_xp(100);

    cout<<"Player name: "<<Homer.get_player_name()<<"\n";
    cout<<"Player xp  : "<<Homer.get_player_xp()<<"\n\n";

    Player *Bart {nullptr};

    Bart = new Player;

    Bart->set_player_name("Bart J Simpson");
    Bart->set_player_xp(500);

    cout<<"Player name: "<<Bart->get_player_name()<<"\n";
    cout<<"Player xp  : "<<Bart->get_player_xp()<<"\n\n";

    delete Bart;

    Hero Chief_Clancy_Wiggum {};

    Chief_Clancy_Wiggum.set_hero_name("Clancy Wiggum");
    Chief_Clancy_Wiggum.set_hero_xp(-1);
    Chief_Clancy_Wiggum.set_hero_clan("Springfield Police Department");

    cout<<"Hero name: "<<Chief_Clancy_Wiggum.get_hero_name()<<"\n";
    cout<<"Hero xp  : "<<Chief_Clancy_Wiggum.get_hero_xp()<<"\n";
    cout<<"Hero clan: "<<Chief_Clancy_Wiggum.get_hero_clan()<<"\n\n";

    Hero *Officer_Lou;

    Officer_Lou = new Hero;

    Officer_Lou->set_player_name("Lou"); // See here we can use base class's methods too.
    Officer_Lou->set_player_xp(-2);
    Officer_Lou->set_hero_clan("Springfield Police Department");

    cout<<"Hero name: "<<Officer_Lou->get_player_name()<<"\n";
    cout<<"Hero xp  : "<<Officer_Lou->get_player_xp()<<"\n";
    cout<<"Hero clan: "<<Officer_Lou->get_hero_clan()<<"\n\n";

    delete Officer_Lou;

    return 0;
}