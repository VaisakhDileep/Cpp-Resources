/*
Created by  : Vaisakh Dileep
Date		: 31, December, 2020
Description : This program helps to understand delegating constructors in C++.
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
	PlayerPrototypeOne();
	PlayerPrototypeOne(string player_name);
	PlayerPrototypeOne(string player_name, int player_health, int player_xp);
};

PlayerPrototypeOne::PlayerPrototypeOne()
	:name {"None"}, health {0}, xp {0}
{
	cout<<"No args constructor called.\n";
}

PlayerPrototypeOne::PlayerPrototypeOne(string player_name)
	:name {player_name}, health {0}, xp {0}
{
	cout<<"One arg constructor called.\n";
}

PlayerPrototypeOne::PlayerPrototypeOne(string player_name, int player_health, int player_xp)
	:name {player_name}, health {player_health}, xp {player_xp}
{
	cout<<"Three args constructor called.\n";
}

// --------------- Player Prototype Two ---------------

class PlayerPrototypeTwo
{
private:
	string name;
	int health;
	int xp;
public:
	PlayerPrototypeTwo();
	PlayerPrototypeTwo(string player_name);
	PlayerPrototypeTwo(string player_name, int player_health, int player_xp);
};

PlayerPrototypeTwo::PlayerPrototypeTwo()
	:PlayerPrototypeTwo {"None", 0, 0} // We can delegate constructor only for constructor list initialization.
{
	cout<<"No args constructor called.\n";
}

PlayerPrototypeTwo::PlayerPrototypeTwo(string player_name)
	:PlayerPrototypeTwo {player_name, 0, 0}
{
	cout<<"One arg constructor called.\n";
}

PlayerPrototypeTwo::PlayerPrototypeTwo(string player_name, int player_health, int player_xp)
	:name {player_name}, health {player_health}, xp {player_xp}
{
	cout<<"Three args constructor called.\n";
}

int main()
{
	PlayerPrototypeOne HomerSimpson;
	cout<<"\n";

	PlayerPrototypeOne MargeBouvier {"Marge Bouvier"};
	cout<<"\n";

	PlayerPrototypeOne LisaSimpson {"Lisa Simpson", 100, 99999};
	cout<<"\n";

	PlayerPrototypeTwo BartSimpson;
	cout<<"\n";

	PlayerPrototypeTwo MaggieSimpson {"Maggie Simpson"};
	cout<<"\n";

	PlayerPrototypeTwo GrandpaSimpson {"Grandpa Simpson", 100, 99999};
	cout<<"\n";

	return 0;
}