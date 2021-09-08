#ifndef _HERO_H_
#define _HERO_H_

#include<string>

#include "Player.hpp"

using namespace std;

class Hero: public Player
{
public:
// Data Members
	string clan;

// Member Methods
	Hero(); // Constructor

	~Hero(); // Destructor

	void set_hero_name(string hero_name); // Setters
	void set_hero_xp(int hero_xp);
	void set_hero_clan(string hero_clan);

	string get_hero_name(); // Getters
	int get_hero_xp();
	string get_hero_clan();
};

#endif