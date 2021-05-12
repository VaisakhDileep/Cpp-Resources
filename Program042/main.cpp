/*
Created by  : Vaisakh Dileep
Date		: 27, December, 2020
Description : This program helps to understand classes and objects in C++.
*/

#include<iostream>

#include<string>

#include<vector>

using namespace std;

class Player // Always give global scope for classes so that everyone can use them.
{
public: // We are making it public so that we can access them in the main function.

// Attributes:
	string name; // Strings are automatically initialized, so don't need to initialize them manually.
	int health {100}; // We can initialize like this post c++ 11.
	int xp {0};

// Methods:
	void talk(string text_to_say)
	{
		cout<<name<<" says "<<"\""<<text_to_say<<"\"\n"; // We can use \" in order to print ".
	}

	bool is_dead();

}; // Don't forget to add ';' at the end of the class definition.

int main()
{

/*
classes: It is a blueprint from which objects are created. It is a user-defined data-type. It contains attributes(data) and methods(functions).
		egs --> std::string, std::vector.

objects: It represents a specific instance of a class.
		egs --> std::vector<int> scores, std::string name.
*/

/*
Syntax for declaring a class:

class Class_Name
{
	// declaration(s);
};
*/

/*
Syntax for declaring objects:

Class_Name object_name1; // For static memory allocation
Class_Name object_name2;

Class_Name *object_name3 = new Class_Name(); // For Dynamic memory allocation.

delete object_name;

Class_Name object_array[] {object_name1, object_name2}; // We can have array of object.

std::vector<Class_Name> object_vector {object_name1}; // We can have vector of objects.

object_vector.push_back(object_name2);
*/
	Player hero;

	hero.name = "Langermann";
	hero.health = 99;
	hero.xp = 990;

	hero.talk("I will dominate !");

	cout<<"Name  : "<<hero.name<<"\n"; // We can use '.' operator to access members in objects.
	cout<<"Health: "<<hero.health<<"\n";
	cout<<"XP    : "<<hero.xp<<"\n\n";

	Player *enemy {nullptr};

	enemy = new Player;

/*
	(*enemy).name = "Val"; // We use () because '.' operator has higher precedence over '*'.
	(*enemy).health = 999999;
	(*enemy).xp = 0;

	cout<<"Name  : "<<(*enemy).name<<"\n";
	cout<<"Health: "<<(*enemy).health<<"\n";
	cout<<"XP    : "<<(*enemy).xp<<"\n\n";
*/
// The above piece of code can be replace by using the '->' operator.

	enemy->name = "Val";
	enemy->health = 999999;
	enemy->xp = 0;

	enemy->talk("I will destroy you !");

	cout<<"Name  : "<<enemy->name<<"\n";
	cout<<"Health: "<<enemy->health<<"\n";
	cout<<"XP    : "<<enemy->xp<<"\n\n";

	Player player_array[] {hero, *enemy};

	vector<Player> player_vector {hero};

	player_vector.push_back(*enemy);

	delete enemy;

	return 0;
}