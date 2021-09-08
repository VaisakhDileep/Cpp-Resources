#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<string>

using namespace std;

class Player
{
public:
// Data Members
	string player_name;
	int player_xp {};

// Member Methods
	Player(); // Constructor

	~Player(); // Destructor

	void set_player_name(string player_name); // Setters
	void set_player_xp(int player_xp);

	string get_player_name(); // Getters
	int get_player_xp();
};

#endif