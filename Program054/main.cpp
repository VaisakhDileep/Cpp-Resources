/*
Created by  : Vaisakh Dileep
Date		: 1, January, 2021
Description : This program checks if the freed dynamically allocated memory can be accessed after the delete operation in C++.
*/

// This program might crash in some os.

#include<iostream>

using namespace std;

int main()
{
	int *pointer_one = new int;

	*pointer_one = 9999;

	cout<<"pointer_one: "<<*pointer_one<<"\n";

	int *pointer_two {pointer_one};

	delete pointer_one;

	cout<<"pointer_two: "<<*pointer_two<<"\n"; // We can access the memory location even after it is freed. Please avoid such usage as it may crash sometimes.

	return 0;
}