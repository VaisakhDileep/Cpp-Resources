/*
Created by  : Vaisakh Dileep
Date		: 11, February, 2021
Description : This program helps to understand std::map in STL associative containers in C++.
*/

#include<iostream>

#include<string>

#include<set> // For std::set

#include<map> // For std::map and std::multimap

#include<unordered_map> // For std::unordered_map and std::unordered_multimap

using namespace std;

void display(map<string, set<string>> &m)
{
	cout<<"[ ";

	for(const auto &elem : m)
	{
		cout<<"\""<<elem.first<<"\""<<":[ ";

		for(const auto &sub_elem : elem.second)
		{
			cout<<"\""<<sub_elem<<"\""<<" ";
		}

		cout<<"]   ";
	}

	cout<<"]";
}

template<typename T1, typename T2>
void display(const map<T1, T2> &m)
{
	cout<<"[ ";

	for(const auto &elem : m)
	{
		cout<<"\""<<elem.first<<"\""<<":"<<elem.second<<" ";
	}

	cout<<"]";
}

template<typename T1, typename T2>
void display(const multimap<T1, T2> &mm)
{
	cout<<"[ ";

	for(const auto &elem : mm)
	{
		cout<<"\""<<elem.first<<"\""<<":"<<elem.second<<" ";
	}

	cout<<"]";
}

template<typename T1, typename T2>
void display(const unordered_map<T1, T2> &um)
{
	cout<<"[ ";

	for(const auto &elem : um)
	{
		cout<<"\""<<elem.first<<"\""<<":"<<elem.second<<" ";
	}

	cout<<"]";
}

template<typename T1, typename T2>
void display(const unordered_multimap<T1, T2> &umm)
{
	cout<<"[ ";

	for(const auto &elem : umm)
	{
		cout<<"\""<<elem.first<<"\""<<":"<<elem.second<<" ";
	}

	cout<<"]";
}

int main()
{
/*
std::map are similar to a dictionary. Elements are stored as Key, Value pairs(std::pair is used). Elements are ordered by the key. No duplicate elements are allowed(keys are unique).
std::map allows direct element access using keys. All iterators are available and invalidate when corresponding element is deleted.

The different vairants of std::map are:
1. std::map
2. std::unordered_map
3. std::multimap
4. std::unordered_multimap
*/
	map<string, int> SimpsonFamily{{"Homer J Simpson", 39}, {"Marge Bouvier", 36}, {"Bart Simpson", 10}, {"Lisa Simpson", 8}, {"Maggie Simpson", 1}};

	SimpsonFamily.insert(pair<string, int> {"Abraham Simpson", 83});
	SimpsonFamily.insert(make_pair("Abraham Simpson", 84)); // Since "Abraham Simpson" already exists as a key in std::map, this will be ignored.

	SimpsonFamily["Mona Simpson"] = 66; // We can also create a key-value pair using [].

	cout<<"Simpson Family: ";
	display<string, int>(SimpsonFamily); // Notice here that the Simpson characters are arraged based on their key(name).
	cout<<"\n\n";

	cout<<"Size     [Simpson Family]: "<<SimpsonFamily.size()<<"\n";
	cout<<"Max Size [Simpson Family]: "<<SimpsonFamily.max_size()<<"\n\n";
// Note : std::map has no concept of back and front.

	cout<<"Simpson family after updating \"Abraham Simpson\" and \"Bart Simpson\": \n";

	SimpsonFamily["Abraham Simpson"] = 84;
	SimpsonFamily.at("Bart Simpson") = 11; // This will throw an exception if the key is not present in the map, so don't use them for initialization. It is a best practice to use them for updating values.

	cout<<"Simpson Family: ";
	display<string, int>(SimpsonFamily);
	cout<<"\n\n";

	cout<<"Removing \"Mona Simpson\" from the Simpson family: \n";

	map<string, int>::iterator simpson_family_it = SimpsonFamily.find("Mona Simpson"); // We could also use "auto simpson_family_it = SimpsonFamily.find("Mona Simpson");". Always prefer .find() over std::find() as it more optimized to work with std::map.

	if(simpson_family_it != SimpsonFamily.end())
	{
		cout<<simpson_family_it->first<<" removed successfully.\n";

		SimpsonFamily.erase(simpson_family_it);
		// SimpsonFamily.erase(simpson_family_it->first); // This is also possible, we can pass the key to .erase().
	}
	else
	{
		cout<<"Sorry, couldn't find the element in the map ...\n";
	}

	cout<<"Simpson Family: ";
	display<string, int>(SimpsonFamily);
	cout<<"\n\n";

	if(SimpsonFamily.count("Ned Flanders")) // .count() return '1' or '0'('1' if the key is present else '0').
	{
		cout<<"Ned Flanders is a member of The Simpsons family ...\n";
	}
	else
	{
		cout<<"Ned Flanders is not a member of The Simpsons family ...\n";
	}
	cout<<"\n";

	if(SimpsonFamily.count("Bart Simpson"))
	{
		cout<<"Bart Simpson is a member of The Simpsons family ...\n";
	}
	else
	{
		cout<<"Bart Simpson is not a member of The Simpsons family ...\n";
	}
	cout<<"\n";

	SimpsonFamily.clear(); // This will clear the map.

	cout<<boolalpha;

	cout<<"After clearing the Simpson Family map: \n";
	cout<<"SimpsonFamily.empty(): "<<SimpsonFamily.empty()<<"\n\n";

	map<string, set<string>> SimpsonFriends {{"Bart Simpson", {"Milhouse Van Houten"}}, {"Homer J Simpson", {"Barney Gumble", "Carl Carlson"}}, {"Lisa Simpson", {}}};

	SimpsonFriends["Lisa Simpson"].insert("Milhouse Van Houten");
	SimpsonFriends["Marge Bouvier"].insert("Luann Van Houten"); // This will add "Marge Bouvier" to the map.

	cout<<"Simpson Friends: ";
	display(SimpsonFriends);
	cout<<"\n\n";

	map<string, set<string>>::iterator simpson_friends_it = SimpsonFriends.find("Lisa Simpson"); // We could also use "auto simpson_friends_it = SimpsonFriends.find("Lisa Simpson");".

	if(simpson_friends_it != SimpsonFriends.end())
	{
		SimpsonFriends.erase(simpson_friends_it);
	}

	cout<<"Simpson Friends after deleting \"Lisa Simpson\": \n";

	cout<<"Simpson Friends: ";
	display(SimpsonFriends);
	cout<<"\n\n";

	map<int, int> dice_output_1 {{1, 1}, {6, 1}, {1, 2}, {2, 1}, {3, 1}, {6, 2}};

	cout<<"Dice output 1 [map]: ";
	display<int, int>(dice_output_1);
	cout<<"\n\n";

	multimap<int, int> dice_output_2 {{1, 1}, {6, 1}, {1, 2}, {2, 1}, {3, 1}, {6, 2}}; // std::multimap are ordered by key. They allow duplicate elements. All iterators are available.

	cout<<"Dice Output 2 [multimap]: ";
	display<int, int>(dice_output_2);
	cout<<"\n\n";

	unordered_map<int, int> dice_output_3 {{1, 1}, {6, 1}, {1, 2}, {2, 1}, {3, 1}, {6, 2}}; // std::unordered_map are unordered. No duplicate elements are allowed. No reverse iterators are allowed.

	cout<<"Dice Output 3 [unordered map]: ";
	display<int, int>(dice_output_3);
	cout<<"\n\n";

	unordered_multimap<int, int> dice_output_4 {{1, 1}, {6, 1}, {1, 2}, {2, 1}, {3, 1}, {6, 2}}; // std::unordered_multimap are unordered. They allow duplicate elements. No reverse iterators are allowed.

	cout<<"Dice output 4 [unordered_multimap]: ";
	display<int, int>(dice_output_4);
	cout<<"\n\n";

	return 0;
}