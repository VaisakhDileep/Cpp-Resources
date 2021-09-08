/*
Created by  : Vaisakh Dileep
Date		: 30, December, 2020
Description : This program helps to understand constructor overloading in C++.
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
// Overloaded Constructors
	Player();
	Player(string player_name);
	Player(string player_name, int player_health, int player_xp);
};

Player::Player()
{
	name = "None";

	health = 0;

	xp = 0;
}

Player::Player(string player_name)
{
	name = player_name;

	health = 0;

	xp = 0;
}

Player::Player(string player_name, int player_health, int player_xp)
{
	name = player_name;

	health = player_health;

	xp = player_xp;
}

int main()
{
// Classes can have as many constructors as necessary, but each constructor must have a unique signature.

	Player defaultPlayer; // 0-args constructor is called here.

	Player hero {"Lynn Langermann"}; // one-arg constructor is called here.

	Player villain {"Loutermilch", 100, 10}; // three-args constructor is called here.

	return 0;
}