/*
Created by  : Vaisakh Dileep
Date		: 23, December, 2020
Description : This program helps to understand how to pass arrays to user-defined functions in C++.
*/

#include<iostream>

using namespace std;

void print_array(const int numbers[], size_t size); // Since array name represents the address of the first element in the array, arrays are not copied but passed by address.

// Also since we pass by address we don't have any idea on the size of the array(we also have to pass the size of the array).

void zero_array(int numbers[], size_t size); // Since we are passing the actual array we can permanently change the original array(by adding "const" keyword we can prevent that).

int main()
{
	int my_numbers[] {1, 2, 3, 4, 5};

	cout<<"Original array: ";
	print_array(my_numbers, 5);
	cout<<"\n";

	zero_array(my_numbers, 5);

	cout<<"After resetting the original array: ";
	print_array(my_numbers, 5);
	cout<<"\n";

	return 0;
}

void print_array(const int numbers[], size_t size)
{
	for(size_t i {0}; i < size; ++i)
	{
		cout<<numbers[i]<<" ";
	}
}

void zero_array(int numbers[], size_t size)
{
	for(size_t i {0}; i < size; ++i)
	{
		numbers[i] = 0;
	}
}