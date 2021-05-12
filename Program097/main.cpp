/*
Created by  : Vaisakh Dileep
Date		: 5, February, 2021
Description : This program helps to understand Standard Template Library in C++.
*/

#include<iostream>

#include<vector>

#include<algorithm>

#include<numeric> // For accumulate()

using namespace std;

int main()
{
/*
STL is a library of powerful, reusable, adaptable, generic classes and functions. They are implemented using C++ templates. They implement some common data-structures and algorithms.

STL was founded by Alexander Stepanov in 1994.
*/

/*
Advantages of STL:
1. Assortment of commonly used containers.
2. Time and size complexity is known.
3. They are tried and tested multiple times.
4. They are consistent, fast and type-safe.
5. They are extensible.
*/

/*
Elements of STL:
1. Containers:
	They are a collection of objects or primitive types.
	For more information refer: "https://www.cplusplus.com/reference/stl/"
	egs: array, vector, deque, stack, set, map, etc..

2. Algorithms [about 60]:
	They are functions for processing sequences of elements from containers.
	For more information refer: "https://www.cplusplus.com/reference/algorithm/"
	egs: find, max, count, accumulate, sort, etc..

3. Iterators:
	They are used to generate sequences of elements from containers.
	For more information refer: "https://www.cplusplus.com/reference/iterator/"
	egs: begin(), end(), advance() etc..

Also refer Functors and Allocators which are also elements in STL.
*/

/*
The different types of containers are:
1. Sequence containers [order is important]: array, vector, list, forward_list, deque.
2. Associative containers [pre-defined or no order at all]: set, multi set, map, multi map
3. Container adaptors [doesn't support iterators so can't be used with STL algorithms]: stack, queue, priority_queue
*/

/*
The different types of Iterators:
1. Input iterators: From the container to the program.
2. Output iterators: From the program to the container.
3. Forward iterators: Navigate one item at a time in one direction.
4. Bi-directional iterators: Navigate one item at a time in both direction.
5. Random access iterators: Directly access a container item [subscript in vector].
*/

/*
The different types of Algorithms:
1. Non-Modifying
2. Modifying
*/
	vector<int> v {1, 5, 3, 2, 4};

	sort(v.begin(), v.end()); // Here .begin() and .end() are iterators.

	cout<<"V: ";
	for(auto elem : v)
	{
		cout<<elem<<" ";
	}

	cout<<"\n\n";

	reverse(v.begin(), v.end());

	cout<<"V: ";
	for(auto elem : v)
	{
		cout<<elem<<" ";
	}

	cout<<"\n\n";

	int int_sum {};

	int_sum = accumulate(v.begin(), v.end(), 0); // Here '0' is the initial value(If you put '0.0' then it will return in double).

	cout<<"Sum: "<<int_sum<<"\n\n";

	return 0;
}