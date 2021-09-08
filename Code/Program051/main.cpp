/*
Created by  : Vaisakh Dileep
Date		: 1, January, 2021
Description : This program helps to understand copy constructors in C++.
*/

#include<iostream>

using namespace std;

class Player
{
private:
	string name;
	int health;
	int xp;
public:
	Player(string player_name = "None", int player_health = 0, int player_xp = 0); // Constructor

	~Player(); // Destructor

	string get_player_name();
	int get_player_health();
	int get_player_xp();
};

Player::Player(string player_name, int player_health, int player_xp)
	:name {player_name}, health {player_health}, xp {player_xp}
{
	cout<<"Calling constructor for "<<name<<"\n";
}

Player::~Player()
{
	cout<<"Calling destructor for "<<name<<"\n";
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

void display_player(Player);

Player create_duff_man();

int main()
{
// When objects are copied, C++ will create a new object from the existing object.

/*
Copy of an object is made when:
1. Passing objects by value as parameter.
2. Returning an object from a function by value.
3. Constructing one object based on another object of the same class.
*/

// If you don't provide your own way of copying objects by value then the compiler provides a default way of copying objects(memberwise copy).
	{
		Player Homer {"Homer", 100, 99999};

		display_player(Homer);
	} // Destructor of the object is called.

	cout<<"\n\n";

	{
		Player DuffMan;

		DuffMan = create_duff_man();
	}

	cout<<"\n\n";

	{
		Player Bart {"Bart", 100, 99999};

		Player ElBarto {Bart}; // Here copy of Bart is made.
	}

	cout<<"\n";

	return 0;
}

void display_player(Player player) // "player" is a copy of whatever object is provided.
{
	cout<<"--------------------------------\n";
	cout<<"Name  : "<<player.get_player_name()<<"\n";
	cout<<"Health: "<<player.get_player_health()<<"\n";
	cout<<"XP    : "<<player.get_player_xp()<<"\n";
	cout<<"--------------------------------\n";
} // Destructor of the copied object is called here.

Player create_duff_man()
{
	Player player {"Duff Man", 100, 99999};

	return player;
}