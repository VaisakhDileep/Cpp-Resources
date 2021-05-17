/*
Created by  : Vaisakh Dileep
Date		: 15, May, 2021
Description : This program helps to understand std::unique function in C++.
*/

#include<iostream>

#include<vector>

#include<algorithm> // For std::unique()

using namespace std;

bool check_duplicate_ones(int a, int b)
{
	if(a == b == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
// std::unique(): It is used to remove duplicates of any element present consecutively in a range.

/*
Syntax for std::unique():
	ForwardIterator it = unique(ForwardIterator first, ForwardIterator last);

	Here,
	first: Forward iterator to the first element in the container.
	second: Forward iterator to the last element in the container.

	it: It is an iterator to the element that follows the last element not removed.
*/
	vector<int> values {1, 1, 1, 2, 2, 2, 2, 2, 3, 4};

	vector<int>::iterator values_it {unique(values.begin(), values.end())};

	cout<<"values: [ ";
	for(auto value: values)
	{
		cout<<value<<" ";
	}
	cout<<"]\n"; // Notice here that all the removed elements are still present at the end of the vector.

	values.resize(distance(values.begin(), values_it)); // "std::unique()" does not do any resizing, so make sure to resize.

	cout<<"values: [ ";
	for(auto value: values)
	{
		cout<<value<<" ";
	}
	cout<<"]\n";

/*
Syntax for using pre-defined function along with std::unique():
	ForwardIterator it = unique(ForwardIterator first, ForwardIterator last, function_pointer/functor/lambda_function); // Make sure it is a binary function(true(1) or false(0)).

	Here,
	first: Forward iterator to the first element in the container.
	second: Forward iterator to the last element in the container.
	function_pointer/functor/lambda_function: It accepts two elements in the container as arguments. If it returns true then the elements are equivalent and one of them is removed. The function cannot modify any of the values in the container. If it returns false then the elements are not equivalent and nothing is done.

	it: It is an iterator to the element that follows the last element not removed.
*/
	vector<int> bits {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1};

	vector<int>::iterator bits_it {unique(bits.begin(), bits.end())};

	bits.resize(distance(bits.begin(), bits_it));

	cout<<"bits: [ ";
	for(auto bit: bits)
	{
		cout<<bit<<" ";
	}
	cout<<"]\n";

// Note: In order to remove duplicate elements in a container make sure to sort them first.

	return 0;
}