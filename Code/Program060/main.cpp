/*
Created by  : Vaisakh Dileep
Date        : 3, January, 2021
Description : This program helps to understand static class members in C++.
*/

#include<iostream>

#include<string>

using namespace std;

class Player
{
private:
    // static int player_count {0}; // C++ doesn't support initializing static data members inside the class.

    static int player_count; // static data member

    string name;
    int health;
    int xp;
public:
    Player(string player_name = "None", int player_health = 0, int player_xp = 0); // Constructor with default values

    Player(const Player &source); // Copy constructor - Shallow copy

    ~Player(); // Destructor

    string get_player_name(); // Getters
    int get_player_health();
    int get_player_xp();

    void set_player_name(string player_name); // Setters
    void set_player_health(int player_health);
    void set_player_xp(int player_xp);

    static int get_player_count(); // static class function
};

int Player::player_count {0}; // We have to initialize the static data member, otherwise it will give an error.

Player::Player(string player_name, int player_health, int player_xp)
    :name {player_name}, health {player_health}, xp {player_xp}
{
    ++player_count;
}

Player::Player(const Player &source)
    :Player {source.name, source.health, source.xp} // Delegating constructor
{
    // Here we haven't used "++player_count" because we deligate to the 3-args constructor, where there is "++player_count".
}

Player::~Player()
{
    --player_count;
}

string Player::get_player_name()
{
    return name;
}

int Player::get_player_health()
{
    return health;
}

int Player::get_player_xp()
{
    return xp;
}

void Player::set_player_name(string player_name)
{
    name = player_name;
}

void Player::set_player_health(int player_health)
{
    health = player_health;
}

void Player::set_player_xp(int player_xp)
{
    xp = player_xp;
}

int Player::get_player_count() // static class function
{
    return player_count;
}

void display_active_player_objects();

int main()
{
/*
Static data members: This data member belongs to the class and not the object. It is used to store class-wide information. It can be accessed using the class name.

Static class functions: This function can only access static data members. They are independent of any objects. The can be called by using the class name.
*/
    display_active_player_objects();

    Player Homer{"Homer J Simpson"};

    display_active_player_objects();

    {
        Player Bart {"Bart Simpson"};

        display_active_player_objects();
    }

    display_active_player_objects();

    Player *Lisa = new Player {"Lisa Simpson"};

    display_active_player_objects();

    delete Lisa; // Destructor will be called for Lisa.

    display_active_player_objects();

    return 0;
}

void display_active_player_objects()
{
    cout<<"Number of active player objects: "<<Player::get_player_count()<<"\n"; // Here notice that we are using the static method without creating an object.
}