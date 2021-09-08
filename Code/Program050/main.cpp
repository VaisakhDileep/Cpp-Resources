/*
Created by  : Vaisakh Dileep
Date		: 1, January, 2021
Description : This program helps to set default value to constructor parameters in C++.
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
	Player(string player_name = "None", int player_health = 0, int player_xp = 0); // Constructor with default parameter values.
/*
	Player() // 0-args constructor
	{

	} // This will generate an error because compiler can't choose which constructor to use.
*/
};

Player::Player(string player_name, int player_health, int player_xp)
	:name {player_name}, health {player_health}, xp {player_xp}
{
	cout<<"Three args constructor called.\n";
}

int main()
{
	Player HomerSimpson {};
	cout<<"\n";

	Player MargeBouvier {"Marge Simpson"};
	cout<<"\n";

	Player LisaSimpson {"Lisa Simpson", 100};
	cout<<"\n";

	Player BartSimpson {"Bart Simpson", 100, 99999};
	cout<<"\n";

	return 0;
}