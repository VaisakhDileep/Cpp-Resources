/*
Created by  : Vaisakh Dileep
Date		: 2, January, 2021
Description :  This program helps to understand constant objects in C++.
*/

#include<iostream>

#include<string>

using namespace std;

// --------------- Name Prototype One ---------------

class NamePrototypeOne
{
private:
	string name;
public:
	int age;

	string get_name(); // Getters

	void set_name(string name); // Setters
};

string NamePrototypeOne::get_name()
{
	return name;
}

void NamePrototypeOne::set_name(string name)
{
	this->name = name;
}

// --------------- Name Prototype Two ---------------

class NamePrototypeTwo
{
private:
	string name;
public:
	int age;

	NamePrototypeTwo(); // Constructor

	string get_name() const; // Here "const" checks if the function changes the attributes or not, if it changes then it generates a compiler error.

	void set_name(string name); // Here we can't use "const" because we are changing the "name" attribute.
};

NamePrototypeTwo::NamePrototypeTwo()
{
}

string NamePrototypeTwo::get_name() const
{
	return name;
}

void NamePrototypeTwo::set_name(string name)
{
	this->name = name;
}

int main()
{
	NamePrototypeOne Homer;

	Homer.age = 39;
	Homer.set_name("Homer J Simpson");

	cout<<"Name: "<<Homer.get_name()<<"\n\n";

	const NamePrototypeOne Bart {};

	// const NamePrototypeOne test; // We can't use uninitialized constant objects.

	// const int variable; // whatever type they are always initialize constant variables.

	// Bart.age = 10; // Even though age is a public member attribute, we can't change it because Bart is a constant object.

	// cout<<"Name: "<<Bart.get_name()<<"\n\n"; // Here even though the member method "get_name()" doesn't change any attributes, still we end up with an error.

// Solving the above problem using "NamePrototypeTwo".
	const NamePrototypeTwo Lisa; // Notice here we didn't have to include "{}" like earlier because we have included our own user-defined constructor.

	// Lisa.age = 8; // As usual this will give an error because "Lisa" is a constant object.

	cout<<"Name: "<<Lisa.get_name()<<"\n\n"; // This will work here.

	return 0;
}