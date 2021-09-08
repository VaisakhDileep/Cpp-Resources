/*
Created by  : Vaisakh Dileep
Date		: 26, December, 2020
Description : This program helps to understand references in C++.
*/

#include<iostream>

#include<vector>

#include<string>

using namespace std;

void print(const int *const array, size_t size);

int *merge(const int *const array1, const int *const array2, size_t size1, size_t size2);

int main()
{
// Reference : It is an alias for a variable. It must be initialized to a variable when declared. It cannot be null. Once initialized it cannot be made to refer to a different variable. It can be thought of as a constant pointer that is automatically dereferenced.

	int number {100};

	int &ref {number};

	cout<<"Number             : "<<number<<"\n";
	cout<<"Reference to number: "<<ref<<"\n\n";

	number = 200;

	cout<<"Number             : "<<number<<"\n";
	cout<<"Reference to number: "<<ref<<"\n\n";

	ref = 300;

	cout<<"Number             : "<<number<<"\n";
	cout<<"Reference to number: "<<ref<<"\n\n";

	vector<string> simpson_family = {"Homer Simpson", "Lisa Simpson", "Bart Simpson", "Maggie Simpson", "Marge Bouvier"};

/*
	for(auto characters : simpson_family) // Here characters are passed as copies and changing this won't change simpson_family.
	{
		characters = " ";
	}
*/

	for(auto &characters : simpson_family) // This will work because here it is passed by reference.
	{
		characters = " ";
	}

	for(auto characters : simpson_family) // We can also use "for(auto const &characters : simpson_family)".
	{
		cout<<characters<<" _ ";
	}

	cout<<"\n\n";

// Array Merger.
	const size_t array1_size {5}, array2_size {3};

	int array1[array1_size] {1, 2, 3, 4, 5}, array2[array2_size] {6, 7, 8};

	int *merged_array {merge(array1, array2, array1_size, array2_size)};

	print(array1, array1_size);
	cout<<"  U  ";
	print(array2, array2_size);
	cout<<" ---> ";
	print(merged_array, (array1_size + array2_size));

	cout<<"\n";

	return 0;
}

void print(const int *const array, size_t size)
{
	cout<<"[ ";

	for(size_t i {0}; i < size; ++i)
	{
		cout<<array[i]<<" ";
	}

	cout<<"]";
}

int *merge(const int *const array1, const int *const array2, size_t size1, size_t size2)
{
	int *new_array {};

	int position {0};

	new_array = new int[size1 + size2];

	for(size_t i {0}; i < size1 ; ++i)
	{
		new_array[position] = array1[i];

		++position;
	}

	for(size_t i {0}; i < size2; ++i)
	{
		new_array[position] = array2[i];

		++position;
	}

	return new_array;
}