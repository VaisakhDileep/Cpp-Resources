/*
Created by  : Vaisakh Dileep
Date		: 11, February, 2021
Description : This program helps to understand std::set in STL associative containers in C++.
*/

#include<iostream>

#include<set> // For std::set and std::multiset

#include<unordered_set> // For std::unordered_set and std::unordered_multiset

#include<utility> // For std::pair

using namespace std;

class Person
{
	friend ostream &operator<<(ostream &os, const Person &person);

	string name;
	int age;
public:
	Person() : name {"None"}, age {0} {}

	Person(string name, int age) : name {name}, age {age} {}

	bool operator<(const Person &rhs) const
	{
		return (this->age < rhs.age);
	}

	bool operator==(const Person &rhs) const
	{
		return ((this->name == rhs.name) and (this->age == rhs.age));
	}
};

ostream &operator<<(ostream &os, const Person &person)
{
	os<<"\""<<person.name<<"\""<<":"<<person.age;

	return os;
}

template<typename T>
void display(const set<T> &s)
{
	cout<<"[ ";

	for(const auto &elem : s)
	{
		cout<<elem<<" ";
	}

	cout<<"]";
}

int main()
{
/*
Associative containers are a collection of stored objects that allow fast retrieval using a key. STL provides Sets and Maps for Associative containers. They are usually implemented as a balanced binary tree or hashsets, therefore most operations are very efficient.

The different variants of std::set are:
1. std::set
2. std::unordered_set
3. std::multiset
4. std::unordered_multiset

std::set are similar to mathematical set. They are ordered by key. Duplicate elements are not allowed in std::set.

All iterators are available and invalidate when the corresponding element is deleted.

For more information on std::set: "https://en.cppreference.com/w/cpp/container/set"
*/
	set<int> test_1 = {1, 3, 4, 5, 2};

	cout<<"test 1: ";
	display(test_1); // Notice here all the elements in the set are ordered.
	cout<<"\n\n";

	test_1 = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};

	cout<<"test 1: ";
	display(test_1); // Notice here the elements are ordered and the duplicate ones are removed.
	cout<<"\n\n";

	cout<<"Size     [test 1]: "<<test_1.size()<<"\n";
	cout<<"Max Size [test 1]: "<<test_1.max_size()<<"\n\n";

// Note: std::sets do not have the concept of back and front.

	test_1.insert(10);
	test_1.insert(10); // This won't make any changes since '10' is already present in the set.

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	if(test_1.count(10)) // For regular "std::set" .count() will either return '0' or '1'.
	{
		cout<<"------------ 10 is present in the set ------------\n";
	}
	else
	{
		cout<<"---------- 10 is not present in the set ----------\n";
	}
	cout<<"\n";

	if(test_1.count(11))
	{
		cout<<"------------ 11 is present in the set ------------\n";
	}
	else
	{
		cout<<"---------- 11 is not present in the set ----------\n";
	}
	cout<<"\n";

	set<Person> SimpsonFamily {{"Homer J Simpson", 39}, {"Marge Bouvier", 36}, {"Bart Simpson", 10}};

	SimpsonFamily.emplace("Lisa Simpson", 8);
	SimpsonFamily.emplace("Hugo Simpson", 10); // When inserting into a set, we generally use the "operator<()" to check whether it is arranged or not. Since "operator<()" only checks for age, "Hugo Simpson"(Bart's evil twin in Treehouse of Horror) and "Bart Simpson" have the same age, therefore "Hugo Simpson" is ignored.
	SimpsonFamily.emplace("Maggie Simpson", 1);
	SimpsonFamily.emplace("Abraham Simpson", 83);

	cout<<"Simpson Family: ";
	display(SimpsonFamily); // As you can see all the characters are arranged by their age.
	cout<<"\n\n";

	set<Person>::iterator simpson_family_it = SimpsonFamily.find(Person {"Bart Simpson", 10}); // Use this instead of "std::find()", because ".find()" is optimized for sets because of their complex data-structure. We could also use "auto simpson_family_it = SimpsonFamily.find(Person {"Bart Simpson", 10});".

	if(simpson_family_it != SimpsonFamily.end())
	{
		cout<<*simpson_family_it<<" is found successfully.\n";
	}
	else
	{
		cout<<"Sorry could not find the element.\n";
	}
	cout<<"\n";

	simpson_family_it = SimpsonFamily.find(Person {"XXXXXXXXXX", 83}); // Here notice that we don't need to provide "name" to ".find()", we just have to pass "age", because ".find()" only works with "operator<()".

	if(simpson_family_it != SimpsonFamily.end())
	{
		cout<<*simpson_family_it<<" is found successfully.\n";
	}
	else
	{
		cout<<"Sorry could not find the element.\n";
	}
	cout<<"\n";

	SimpsonFamily.erase(simpson_family_it); // This will erase the element pointed to by the iterator(Abraham Simpson).

	cout<<"Simpson Family: ";
	display(SimpsonFamily);
	cout<<"\n\n";

	set<char> options {'A', 'B', 'C'};

	cout<<"Options: ";
	display(options);
	cout<<"\n\n";

	cout<<boolalpha;

	cout<<"Adding 'D' to the set: \n";

	pair<set<char>::iterator, bool> result_pair = options.insert('D'); // We could also use "auto result_pair = options.insert('D');".

	cout<<"First  [pair<set<char>::iterator, bool>]: "<<*(result_pair.first)<<"\n"; // First corresponds to the iterator to the element added or to the duplicate element.
	cout<<"Second [pair<set<char>::iterator, bool>]: "<<result_pair.second<<"\n"; // Second corresponds to whether it was successfully inserted or not.

	cout<<"Options: ";
	display(options);
	cout<<"\n\n";

	cout<<"Adding 'A' to the set: \n";

	result_pair = options.insert('A');

	cout<<"First  [pair<set<char>::iterator, bool>]: "<<*(result_pair.first)<<"\n";
	cout<<"second [pair<set<char>::iterator, bool>]: "<<result_pair.second<<"\n";

	cout<<"Options: ";
	display(options);
	cout<<"\n\n";

	multiset<char> red_or_blue {'r', 'b', 'r', 'r', 'r', 'b'}; // std::multiset are sorted by key, but they allow duplicate elements. All iterators are available.
// For more information on std::multiset refer: "https://en.cppreference.com/w/cpp/container/multiset"

	cout<<"Red or Blue: [ ";
	for(const auto &elem : red_or_blue)
	{
		cout<<elem<<" ";
	}
	cout<<"]\n\n";

	unordered_set<int> dice_output {1, 1, 3, 3, 4, 4, 5, 6, 2}; // std::unordered_set are unordered, no duplicate elements are allowed. Elements cannot be modified, they must be erased and the new element is then inserted. No reverse iterators are allowed.
// For more information on std::unordered_set refer : "https://en.cppreference.com/w/cpp/container/unordered_set"

	cout<<"Output of the dice by the order of first occurrance of face: [ ";
	for(const auto &elem : dice_output)
	{
		cout<<elem<<" ";
	}
	cout<<"]\n\n";

	unordered_multiset<int> dice_output_2 {1, 1, 3, 3, 4, 4, 5, 6, 2}; // std::unordered_multiset are unordered, duplicate elements are allowed here. No reverse iterators are allowed.
// For more information on std::unordered_multiset refer : "https://en.cppreference.com/w/cpp/container/unordered_multiset"

	cout<<"Output of the dice : [ ";
	for(const auto &elem : dice_output_2)
	{
		cout<<elem<<" ";
	}
	cout<<"]\n\n";

	return 0;
}