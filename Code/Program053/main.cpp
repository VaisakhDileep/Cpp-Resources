/*
Created by  : Vaisakh Dileep
Date		: 1, January, 2021
Description : This program helps to understand the problems regarding shallow copy in C++.
*/

// Note this program should have crashed but apparently my os has some kind of method where the deleted memory block can be accessed later, refer "Program054" for demonstration. **** This is an unexpected behaviour, avoid shallow copy at any cost ****.

#include<iostream>

using namespace std;

class Shallow
{
private:
	int *data; // raw pointer
public:
	Shallow(int shallow_data); // Constructor

	Shallow(const Shallow &source); // Copy Constructor

	~Shallow(); // Destructor

	void set_data(int shallow_data); // Setters

	int get_data(); // Getters
};

Shallow::Shallow(int shallow_data)
{
	data = new int;

	*data = shallow_data;

	cout<<"Constructor called.\n";
}

Shallow::Shallow(const Shallow &source)
	:data {source.data} // Here notice only the pointer is copied and not what it is pointing to, so deleting the pointer deletes the allocated memory.
{
	cout<<"Copy constructor called.\n";
}

Shallow::~Shallow()
{
	delete data;

	cout<<"Destructor called.\n";
}

void Shallow::set_data(int shallow_data)
{
	*data = shallow_data;
}

int Shallow::get_data()
{
	return *data;
}

void display_shallow(Shallow);

int main()
{
	Shallow data_one {100};

	cout<<"\n";

	cout<<"*** data_one after creating ***\n";
	cout<<"-------------------------------\n";
	display_shallow(data_one); // Here copy constructor is called but both "data" here points to the same location.
	cout<<"-------------------------------\n\n";

	Shallow data_two {data_one};

	cout<<"\n";

	cout<<"*** data_two after creating ***\n";
	cout<<"-------------------------------\n";
	display_shallow(data_two); // Here copy constructor is called but both "data" here points to the same location.
	cout<<"-------------------------------\n\n";

	data_two.set_data(1000); // Here "data" in both "data_one" and "data_two" will be updated(not what we were expecting).

	cout<<"*** data after updating ***\n";
	cout<<"-------------------------------\n";

	cout<<"data_one: \n";
	display_shallow(data_one);
	cout<<"\n";

	cout<<"data_two: \n";
	display_shallow(data_two);
	cout<<"\n";

	cout<<"-------------------------------\n\n";

	return 0;
} // Here destructors for all the objects are called so sometimes the program will crash because we are freeing the allocated memory for one which the other copied object might be sharing.

void display_shallow(Shallow shallow)
{
	cout<<"Data: "<<shallow.get_data()<<"\n";
}