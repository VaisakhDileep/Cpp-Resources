/*
Created by  : Vaisakh Dileep
Date		: 31, December, 2020
Description : This program helps to understand constructor initialization list in C++.
*/

#include<iostream>

#include<string>

using namespace std;

// --------------- Player Prototype One ---------------

class PlayerPrototypeOne
{
private:
	string name = " ";
	int health = 0;
	int xp = 0;
public:
	PlayerPrototypeOne();
	PlayerPrototypeOne(string player_name);
	PlayerPrototypeOne(string player_name, int player_health, int player_xp);
};

PlayerPrototypeOne::PlayerPrototypeOne()
{ // Here when the object is created it is already initialized.
	name = "None"; // Here first name is initialized and then assigned, so this constructor doesn't initialize but assign.

	health = 100;

	xp = 9999;
}

PlayerPrototypeOne::PlayerPrototypeOne(string player_name)
{
	name = player_name;

	health = 100;

	xp = 9999;
}

PlayerPrototypeOne::PlayerPrototypeOne(string player_name, int player_health, int player_xp)
{
	name = player_name;

	health = player_health;

	xp = player_xp;
}

// --------------- Player Prototype Two ---------------

class PlayerPrototypeTwo
{
private:
	string name = " ";
	int health = 0;
	int xp = 0;
public:
	PlayerPrototypeTwo();
	PlayerPrototypeTwo(string player_name);
	PlayerPrototypeTwo(string player_name, int player_health, int player_xp);
};

PlayerPrototypeTwo::PlayerPrototypeTwo() // Here the constructor initializes the values rather than assigning them.
	:name {"None"}, health {100}, xp {9999}
{
}

PlayerPrototypeTwo::PlayerPrototypeTwo(string player_name)
	:name {player_name}, health {100}, xp {9999}
{
}

PlayerPrototypeTwo::PlayerPrototypeTwo(string player_name, int player_health, int player_xp)
	:name {player_name}, health {player_health}, xp {player_xp}
{
}

int main()
{
	PlayerPrototypeOne HomerSimpson; // Step through the debugger to understand this program.

	PlayerPrototypeOne MargeBouvier {"Marge Bouvier"};

	PlayerPrototypeOne LisaSimpson {"Lisa Simpson", 50, 500};

	PlayerPrototypeTwo BartSimpson;

	PlayerPrototypeTwo MaggieSimpson {"Maggie Simpson"};

	PlayerPrototypeTwo GrandpaSimpson {"Grandpa Simpson", 50, 500};

	return 0;
}