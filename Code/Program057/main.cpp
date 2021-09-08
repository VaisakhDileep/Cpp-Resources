/*
Created by  : Vaisakh Dileep
Date		: 2, January, 2021
Description : This program helps to understand the difference between l-value reference and r-value reference in C++.
*/

#include<iostream>

using namespace std;

void printReferenceValue(int &);

void printReferenceValue(int &&);

int main()
{
/*
l-value: It refers to a memory location which identifies an object.

r-value: It refers to the data value that is stored at some address in the memory. Temporary objects are r-value.

r-value Properties:
1. r-value references extends the lifespan of the temporary object to which they are assigned.
2. Non-const r-value references allow you to modify the r-value.
*/
	int dummy {10};

	int &l_value_reference = dummy; // This is an l-value reference.

	int &&r_value_reference = 999; // This is an r-value reference.

	cout<<"Address of dummy            : "<<&dummy<<"\n";
	cout<<"Address of l_value_reference: "<<&l_value_reference<<"\n";
	cout<<"Address of r_value_reference: "<<&r_value_reference<<"\n\n";

/*
	int &l_value_reference_2 = 100; // This will give an error, because we can't assign an r-value to an l-value reference.
	int &&r_value_reference_2 = dummy; // This will give an error, because we can't assign an l-value to an r-value reference.
*/

/*
Uses of r-value reference:
1. They are used when working with move constructor and move assignment.
*/

	printReferenceValue(dummy);

	printReferenceValue(999);

	return 0;
}

void printReferenceValue(int &value)
{
	cout<<"Value[l-value-reference]: "<<value<<"\n";
}

void printReferenceValue(int &&value)
{
	cout<<"Value[r-value-reference]: "<<value<<"\n";
}