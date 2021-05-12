/*
Created by  : Vaisakh Dileep
Date		: 5, February, 2021
Description : This program helps to understand generic programming using Function Templates in C++.
*/

#include<iostream>

#include<string>

using namespace std;

struct Person
{
	string name;
	int age;

	bool operator>(const Person &rhs) const
	{
		return this->age > rhs.age;
	}
};

ostream &operator<<(ostream &os, const Person &person) // This need not be a friend function because all members in struct are public by default.
{
	os<<person.name;

	return os;
}

template<typename T> // Here "T" is user-defined, it is the template parameter. Note: We can also use "class" instead of "typename".
T Max(T num1, T num2)
{
	return (num1 > num2) ? num1 : num2; // Here this is just a blueprint, the function is created only during compile-time.
}

template<typename T1, typename T2>
void display(T1 data1, T2 data2)
{
	cout<<"Data 1: "<<data1<<"\n";
	cout<<"Data 2: "<<data2<<"\n";
}

int main()
{
// C++ template is a blueprint and it is compiled during compile-time and not run-time. Compiler generates the appropriate function / class from the blueprint. It is used to achieve Generic-programming / Meta-programming.
	int num1 {10};
	int num2 {2};

	Person Homer {"Homer J Simpson", 39}; // This kind of initialization is possible in struct.
	Person Burns {"Montgomery Burns", 81};

	cout<<"Max<int>(num1, num2)     : "<<(Max<int>(num1, num2))<<"\n\n";
	cout<<"Max(num1, num2)          : "<<(Max(num1, num2))<<"\n\n"; // Here compiler will automatically deduce the type.
	cout<<"Max<double>(1.0, 7.0)    : "<<(Max<double>(1.0, 7.0))<<"\n\n";
	cout<<"Max<char>('A', 'Z')      : "<<(Max<char>('A', 'Z'))<<"\n\n";
	cout<<"Max<Person>(Homer, Burns): "<<(Max<Person>(Homer, Burns))<<"\n\n\n";

	cout<<"display<int, double>(1, 0.1): \n";
	display<int, double>(1, 0.1);
	cout<<"\n";

	cout<<"display<int, Person>(num1, Homer): \n";
	display<int, Person>(num1, Homer);
	cout<<"\n";

	return 0;
}