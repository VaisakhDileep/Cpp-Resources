/*
Created by  : Vaisakh Dileep
Date		: 2, January, 2021
Description : This program helps to understand move constructors in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

class Move
{
private:
	int *data; // raw pointer
public:
	Move(int move_data); // Constructor

	Move(const Move &source); // Copy Constructor

	Move(Move &&source) noexcept; // Move Constructor --> Steal the data and then null out the source pointer.

	~Move(); // Destructor

	void set_data(int move_data); // Setter

	int get_data(); // Getter
};

Move::Move(int move_data)
{
	data = new int;

	*data = move_data;

	cout<<"Constructor called for "<<*data<<"\n";
}

Move::Move(const Move &source)
	:Move {*source.data} // Delegating constructor
{
	cout<<"Copy constructor called for "<<*data<<"\n"; // We are doing deep copy here.
}

Move::Move(Move &&source) noexcept
	:Move {*source.data}
{
	source.data = nullptr;

	cout<<"Move constructor called for "<<*data<<"\n";
}

Move::~Move()
{
	if (data != nullptr)
	{
		cout<<"Destructor called for "<<*data<<"\n";
	}
	else
	{
		cout<<"Destructor called for nullptr\n";

		// cout<<*data; // Trying this will the make the program crash because "nullptr" points nowhere.
	}
}

int main()
{
	int total = 100 + 200; // Here first "100 + 200" is evaluated and '300' is stored in an unnamed temp value(r-value), this value is then passed to the variable "total"(l-value) and then the temp value is discarded.

// Sometimes copy constructors are called many times due to the copy semantics in C++. Copy constructor doing deep copying can have a significant performance bottleneck.

// Move constructor moves an object rather than copying it. It is optional but recommended when you have a raw pointer.

	vector<Move> move_vector;

	move_vector.push_back(Move {1}); // Here "Move {1}" is an r-value.
	cout<<"\n";

	move_vector.push_back(Move {2});
	cout<<"\n";

	move_vector.push_back(Move {3});
	cout<<"\n";

	move_vector.push_back(Move {4}); // Here we can't predict how many copy constructors are being called(please comment the move constructor),copy constructors are called more than the number of vector elements.
	cout<<"\n";

	move_vector.push_back(Move {5});
	cout<<"\n";

	move_vector.push_back(Move {6});
	cout<<"\n";

	move_vector.push_back(Move {7});
	cout<<"\n";

	move_vector.push_back(Move {8});
	cout<<"\n";

	move_vector.push_back(Move {9});
	cout<<"\n";

// Commenting out the move constructor we notice that copy constructor will be called which may have a performance impact in the above code.

	return 0;
}