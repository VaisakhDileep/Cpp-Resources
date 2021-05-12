/*
Created by  : Vaisakh Dileep
Date		: 19, January, 2021
Description : This program helps to understand polymorphism in C++.
*/

#include<iostream>

#include<memory>

using namespace std;

class Base
{
public:
	void say_hello() const
	{
		cout<<"Hello, from Base class";
	}
};

class Derived: public Base
{
public:
	void say_hello() const
	{
		cout<<"Hello, from Derived class";
	}
};

void add_asterisk(const Base &object)
{
	cout<<"* ";

	object.say_hello();

	cout<<" *\n";
}

int main()
{
/*
There are two types of polymorphism:
1. Compile-time / early-binding / static-binding[default].
2. Run-time / late-binding / dynamic-binding.

								:-----> Function Overloading
Compile-time Polymorphism ------:
								:-----> Operator Overloading

Run-time Polymorphism ---> Function Overriding

Run-time polymorphism is achieved by:
1. Inheritance
2. Base class pointers or reference
3. Virtual functions
*/
	Base base_object_1;

	base_object_1.say_hello(); // Base's method is called
	cout<<"\n";

	Derived derived_object_1;

	derived_object_1.say_hello(); // Derived's method is called
	cout<<"\n";

	Base *base_pointer_1 = new Derived(); // This is possible since Derived "Is-A" Base.

	base_pointer_1->say_hello();
	cout<<"\n";

	unique_ptr<Base> base_unique_pointer_1 = make_unique<Derived>(); // This is possible since Derived "Is-A" Base.

	base_unique_pointer_1->say_hello();
	cout<<"\n";

	add_asterisk(base_object_1);

	add_asterisk(derived_object_1); // This is possible since Derived "Is-A" Base(slicing).

// In all the above examples we use static binding.

	delete base_pointer_1; // We need to deallocate the dynamically created objects, however we don't have to do it for smart pointers.

	return 0;
}