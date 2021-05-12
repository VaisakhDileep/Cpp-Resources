/*
Created by  : Vaisakh Dileep
Date		: 26, December, 2020
Description : This program helps to understand how to return a pointer from a function in C++.
*/

#include<iostream>

using namespace std;

/*
int *function1()
{
	int size {};

	return &size;
}

int *function2()
{
	int size{};

	int *int_ptr {&size};

	return int_ptr;
}
*/ // These functions return local variable, so don't use them because local variable destroys themselves after they run out of scope.

// Prototypes:
int *largest_int(int *int_ptr1, int *int_ptr2);

int *create_array(size_t size, int init_value); // Returning dynamically allocated memory.

void display_array(const int *const array, size_t size);

int main()
{
// Syntax for function returning a pointer: DataType *function(); (never return a pointer to a local function variable).
	int number_1 {100}, number_2 {200};

	int *largest_number {nullptr};

	largest_number = largest_int(&number_1, &number_2);

	cout<<"Largest number: "<<*largest_number<<"\n\n";

	int *class_marks {nullptr};

	size_t size {};

	int init_value {};

	cout<<"How many integers would you like to allocate: ";

	cin>>size;

	cout<<"Enter the value you like to initialize the array with: ";

	cin>>init_value;

	class_marks = create_array(size, init_value);

	display_array(class_marks, size);

	delete[] class_marks; // always free the heap memory.

/*
Potential Pointer pitfalls:
1. Uninitialized pointers:
	int *int_ptr; // This is an uninitialized pointer.
	*int_ptr = 100; // This might change some critical memory parts.
2. Dangling pointers: They are the pointers that point to a memory that is invalid. Consider two pointers that point to the same data. One pointer releases the data with delete, but the other pointer continues accessing the released data.
					   Another example is when the function returns a pointer to a local variable to the function.
3. Not checking if new failed: If new failed then an exception is thrown, we need to use exception handling to catch that exception.
4. Leaking memory : Forgetting to release allocated memory with delete results in memory leak or orphan memory. If you lose pointer to the storage allocated on the heap you have no other way to get the storage back.
*/

	return 0;
}

int *largest_int(int *int_ptr1, int *int_ptr2) // Here it is possible because "int_ptr1" and "int_ptr2" are pointing to main variables.
{
	if(*int_ptr1 > *int_ptr2)
	{
		return int_ptr1;
	}
	else
	{
		return int_ptr2;
	}
}

int *create_array(size_t size, int init_value = 0)
{
	int *new_storage {nullptr};

	new_storage = new int[size];

	for(size_t i {0}; i < size; i++)
	{
		*(new_storage + i) = init_value; // can also use subscript notation.
	}

	return new_storage;
}

void display_array(const int *const array, size_t size)
{
	for(size_t i {0}; i < size; i++)
	{
		cout<<array[i]<<" ";
	}

	cout<<"\n";
}