#include "Hero.hpp"

#include<string>

using namespace std;

Hero::Hero()
	: clan {"Earth Buddies"}
{
}

Hero::~Hero()
{
}

void Hero::set_hero_name(string hero_name)
{
	player_name = hero_name;
}

void Hero::set_hero_xp(int hero_xp)
{
	player_xp = hero_xp;
}

void Hero::set_hero_clan(string hero_clan)
{
	clan = hero_clan;
}

string Hero::get_hero_name()
{
	return player_name;
}

int Hero::get_hero_xp()
{
	return player_xp;
}

string Hero::get_hero_clan()
{
	return clan;
}