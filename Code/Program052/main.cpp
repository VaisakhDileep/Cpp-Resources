/*
Created by  : Vaisakh Dileep
Date        : 1, January, 2021
Description : This program helps to understand user-defined copy constructors in C++.
*/

#include<iostream>

#include<string>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
public:
    Player(string player_name = "None", int player_health = 0, int player_xp = 0); // Constructor

    Player(const Player &source); // Copy Constructor

    ~Player();
};

Player::Player(string player_name, int player_health, int player_xp)
    :name {player_name}, health {player_health}, xp {player_xp}
{
    cout<<"Three args constructor called for "<<name<<"\n";
}

Player::Player(const Player &source)
    // :name {source.name + " Copy Constructed"}, health {source.health}, xp {source.xp}
    :Player {source.name + " Copy Constructed", source.health, source.xp} // We can delegate constructors too.
{
    cout<<"Copy constructor called for "<<name<<"\n";
}

Player::~Player()
{
    cout<<"Destructor called for "<<name<<"\n";
}

int main()
{
    {
        Player BartSimpson {"Bart Simpson", 100, 99999};

        Player ElBarto {BartSimpson};

        cout<<"\n";
    }

    cout<<"\n";

    return 0;
}