/*
Created by  : Vaisakh Dileep
Date        : 30, December, 2020
Description : This program helps to understand constructors and destructors in C++.
*/

#include<iostream>

#include<string>

class Player
{
private:
    std::string name; // Here we used "std::" because there is no namespace declared before the class declaration, we declared it after the class declaration.
    int health;
    int xp;
public:
    void set_name(std::string player_name)
    {
        name = player_name;
    }

// Constructor
    Player()
    {
        std::cout<<"No Args constructor called for: "<<name<<"\n";
    }

    Player(std::string player_name)
    {
        name = player_name;

        std::cout<<"Single Arg constructor called for: "<<name<<"\n";
    }

    Player(std::string player_name, int player_health, int player_xp)
    {
        name = player_name;

        health = player_health;

        xp = player_xp;

        std::cout<<"Three Args constructor called for: "<<name<<"\n";
    }

// Destructor
    ~Player()
    {
        std::cout<<"Destructor called for: "<<name<<"\n";
    }
};

using namespace std;

int main()
{
// Constructors: They are special member methods, they are invoked during the object creation, they are used to initialize the object, they have the same name as the class, they do not have any return type specified, they can be overloaded.

// Destructors: They are special member methods, they have the same name as the class preceeded with a tilde(~), they are invoked automatically when an object is destroyed, they have no return type and no parameters. Only one destructor is allowed per class, so no overloading. It is used to release memory and other resources.

    {
        Player Jessica;

        Player Lynn {"Lynn"};

        Player Blake {"Blake", 100, 0};

        cout<<"\n";

        Jessica.set_name("Jessica");
    } // Destructors are called here --> Destructors are called in reverse order as that of constructors.

    cout<<"\n";

    Player *Walrider = new Player;

    Player *Loutermilch = new Player {"Loutermilch"}; // This is how we initialize dynamically created elements.

    Player *Martha = new Player {"Martha", 100, 0};

    cout<<"\n";

    Walrider->set_name("Walrider");

    delete Walrider;

    delete Loutermilch;

    delete Martha; // Destructors are called here.

    return 0;
}