/*
Created by  : Vaisakh Dileep
Date        : 3, January, 2021
Description : Structure.
*/

#include<iostream>

#include<string>

using namespace std;

struct EmptyStruct
{
};

struct Player
{
private:
    static int player_count; // static data member

    int copy_flag = 0; // If the value is '1' then it is copy constructed.
    string name = " "; // This is supported for C++ structures.
    int health = 0;
    int xp = 0;
public:
    Player(string player_name = "None", int player_health = 0, int player_xp = 0); // Constructor with default value

    Player(const Player &source);

    ~Player();

    string get_name();
    int get_health();
    int get_xp();

    void set_name(string player_name);
    void set_health(int player_health);
    void set_xp(int player_xp);

    static int get_player_count(); // static member function
};

int Player::player_count = 0; // Don't forget to initialize static data members.

Player::Player(string player_name, int player_health, int player_xp)
    :name {player_name}, health {player_health}, xp {player_xp}
{
    cout<<"Constructor called for "<<name<<"\n";

    ++player_count;
}

Player::Player(const Player &source)
    :Player {source.name, source.health, source.xp} // Delegating constructor
{
    copy_flag = 1;

    cout<<"Constructor called for "<<name<<" -- COPY\n";
}

Player::~Player()
{
    if (copy_flag == 1)
    {
        cout<<"Destructor called for "<<name<<" -- COPY \n";
    }
    else
    {
        cout<<"Destructor called for "<<name<<"\n";
    }

    --player_count;
}

string Player::get_name()
{
    return name;
}

int Player::get_health()
{
    return health;
}

int Player::get_xp()
{
    return xp;
}

void Player::set_name(string player_name)
{
    name = player_name;
}

void Player::set_health(int player_int)
{
    health = player_int;
}

void Player::set_xp(int player_xp)
{
    xp = player_xp;
}

int Player::get_player_count() // static member function
{
    return player_count;
}

void display_player(Player player);

void display_active_player_objects();

int main()
{
// Arrays are used to store set of data of similar data types at contiguous memory locations. Unlike arrays, Structures in C++ are user-defined data types which are used to store group of items of non-similar data types.

/*
Syntax for structures:
struct StructureName{
    member 1;
    member 2;
    member 3;
        .
        .
        .
        .
    member n;
}; // Don't forget to use the ';' at the end of the structure declaration.
*/

/*
Difference between C strucutres and C++ structures:
1. C cannot have member functions inside structures but C++ can have member functions inside strucutres.
2. We can directly initialize structure data members in C++ but not possible in C.
3. In C we need to use "struct" keyword to declare a struct variable, whereas it is not necessary in C++.
4. C structures cannot have static members but it is allowed in C++.
5. Structures in C cannot have constructors inside structure but structures in C++ supports constructor creation.
6. The sizeof operator will give '0' for an empty structure in C whereas it is '1' for an empty structure in C++.
7. C structures do not allow the concept of Data hiding but is permitted in C++.
8. C structures do not have access modifiers as these modifiers are not supported by the language. C++ structures can have this concept as it is inbuilt in the language.
*/

/*
In C++, a struct and a class are almost identical, the only difference is that struct members are public by default and class members are private by default.

struct Test // Here Test is equivalent to a class.
{
private:
    //......
};
*/

    EmptyStruct empty;

    display_active_player_objects();

    Player Homer {"Homer J Simpson", 100, 1};

    display_active_player_objects();

    display_player(Homer);

    Homer.set_name("Max Power");
    Homer.set_health(87);
    Homer.set_xp(34);

    display_player(Homer);

    {
        Player ElHomer {Homer};

        display_active_player_objects();
    }

    display_active_player_objects();

    cout<<"Size of an empty structure: "<<sizeof empty<<"\n\n";

/*
As we have seen both structures and classes are similar, but there are some guidelines which programmers should follow:
Use struct for:
    1. Passive objects with public access.
    2. Don't declare methods in struct.
Use class for:
    1. Active objects with private access.
    2. Implement getters/setters as needed.
    3. Implement member methods as necessary.
*/

    return 0;
}

void display_player(Player player)
{
    cout<<"\n--------------------------\n";
    cout<<"Name  :"<<player.get_name()<<"\n";
    cout<<"Health: "<<player.get_health()<<"\n";
    cout<<"XP    : "<<player.get_xp()<<"\n";
    cout<<"--------------------------\n\n";
}

void display_active_player_objects()
{
    cout<<"\n********** Number of active player objects: "<<Player::get_player_count()<<" **********\n\n";
}