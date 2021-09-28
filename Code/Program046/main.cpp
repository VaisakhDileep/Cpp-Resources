/*
Created by  : Vaisakh Dileep
Date        : 30, December, 2020
Description : This program helps to understand default constructors in C++.
*/

#include<iostream>

using namespace std;

// --------------- Player Prototype One ---------------

class PlayerPrototypeOne
{
private:
    string name;
    int health;
    int xp;
public:
    void set_name(string player_name)
    {
        name = player_name;
    }

    string get_name()
    {
        return name;
    }
};

// --------------- Player Prototype Two ---------------

class PlayerPrototypeTwo
{
private:
    string name;
    int health;
    int xp;
public:
    PlayerPrototypeTwo(string player_name, int player_health, int player_xp)
    {
        name = player_name;

        health = player_health;

        xp = player_xp;
    }

    void set_name(string player_name)
    {
        name = player_name;
    }

    string get_name()
    {
        return name;
    }
};

int main()
{
// If we do not include any constructors, then C++ will generate a Default Constructor that does nothing. Default constructor is no longer compiler-generated once the user-defined constructor is declared.

    PlayerPrototypeOne Lynn_Langermann; // Here default constructor is called because we haven't defined any other constructor.

    PlayerPrototypeTwo Blake_Langermann {"Blake Langermann", 100, 0}; // Here we will need three arguments to construct an object.

    // PlayerPrototypeTwo Jessica_Gray; // This will generate an error because default constructor isn't there(Three Args Constructor overides it).

    return 0;
}