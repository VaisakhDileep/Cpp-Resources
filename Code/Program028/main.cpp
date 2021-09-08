/*
Created by  : Vaisakh Dileep
Date		: 22, December, 2020
Description : This program helps to understand function overloading in C++ user-defined functions.
*/

#include<iostream>

#include<string>

#include<vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>); // Note: We can put default argument in only one overloaded function(doing that in more than one function will generate a compiler error).

int main()
{
// function overloading is an example of polymorphism. It helps in abstraction. It simply means using the same name for functions that have different parameter types.

/*
	int get_value();

	double get_value();

	cout<<get_value()<<"\n"; // Here it will give an error because compiler can't decide which version to use here, so don't try to overload return type.
*/

	print(100); // int

	print('A'); // Character is always promoted to int.

	print(12.3); // double

	print(12.3F); // Float is promoted to double.

	print("Lake Life"); // Here "Lake Life" is a C-style string literal. It is converted to a C++ string.

	string episode {"Lake Life"}; // C++ string.

	print(episode);

	vector <string> world_cities {"New York", "Mumbai", "Tokyo", "Delhi"};

	print(world_cities); // Vector of strings.

	return 0;
}

void print(int num)
{
	cout<<"Printing int: "<<num<<"\n";
}

void print(double num)
{
	cout<<"Printing double: "<<num<<"\n";
}

void print(string s)
{
	cout<<"Printing string: "<<s<<"\n";
}

void print(string s1, string s2)
{
	cout<<"Printing 2 strings: "<<s1<<" and "<<s2<<"\n";
}

void print(vector<string> v)
{
	cout<<"Printing vector of strings: ";

	for(auto s:v)
	{
		cout<<s<<" ";
	}

	cout<<"\n";
}