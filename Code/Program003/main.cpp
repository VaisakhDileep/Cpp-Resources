/*
Created by  : Vaisakh Dileep
Date		: 14, December, 2020
Description : This program helps to understand namespaces in C++.
*/

#include<iostream>

using namespace std; // This makes the things under the std namespace available without having to prefix "std::".

/*
using std::cout; // "using namespace std;" not only brings in "cin", "cout", "endl" but a lot others which is hard to keep track of. This is a better alternative.
using std::cin;
using std::endl;
*/

namespace firstSpace // Custom namespace
{
	void func()
	{
		cout<<"Inside first namespace."<<endl;
	}
}

namespace secondSpace // Custom namespace
{
	void func()
	{
		cout<<"Inside second namespace."<<endl;
	}
}

int main()
{
// Namespace: It is a declarative region that provides a scope to the identifiers inside it. They are used to organize code.

	cout<<"Inside main function."<<endl; // See here we don't have to include "std::" anywhere.

	firstSpace::func(); // '::' is the scope resolution operator.
	secondSpace::func();

	using namespace secondSpace; // This makes "func()" default to "secondSpace" namespace, don't have to include "secondSpace::".

	func();

	using namespace firstSpace;

	// func(); // Here the compiler doesn't know which namespace to look at.

	return 0;
}