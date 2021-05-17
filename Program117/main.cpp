/*
Created by  : Vaisakh Dileep
Date		: 16, May, 2021
Description : This program helps to understand std::tuple in STL container adapters in C++.
*/

#include<iostream>

#include<tuple>

using namespace std;

int main()
{
// A tuple can hold a number of elements of different data-types as one object. The are similar to C-like structures(struct). The elements are accessed by the order in which they are initialized in the template parameter.

	tuple<int, char, float> tuple_element {1, 'A', 1.1};

	cout<<"tuple_element: "<<get<0>(tuple_element)<<", "<<get<1>(tuple_element);

	re;
}