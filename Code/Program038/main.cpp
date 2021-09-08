/*
Created by  : Vaisakh Dileep
Date		: 26, December, 2020
Description : This program helps to understand constant pointers, pointers to constants and constant pointers to constants in C++.
*/

#include<iostream>

using namespace std;

int main()
{
/*
There are:
1. Pointers to constants.
2. Constant pointers.
3. Constant pointers to constants.
*/

	int max_limit {100}, min_limit {10};

	const int *ptr_to_constant {&max_limit}; // Pointer to constants

	// *ptr_to_constant = 90; // This will give an error because the variable that is being pointed by the constant pointer can't be changed.

	ptr_to_constant = &min_limit; // This will work.

	int *const constant_ptr {&max_limit}; // Constant pointer

	*constant_ptr = 90; // This will work.

	// constant_ptr = &min_limit; // This will give an error.

	const int * const constant_ptr_to_constant {&max_limit}; // Constant pointer to constants

	// *constant_ptr_to_constant = 90; // This will give an error.

	// constant_ptr_to_constant = &min_limit; // This will give an error.

	return 0;
}