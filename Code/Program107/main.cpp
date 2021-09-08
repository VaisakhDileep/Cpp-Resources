/*
Created by  : Vaisakh Dileep
Date		: 10, February, 2021
Description : This program helps to understand std::deque in STL sequence containers in C++.
*/

#include<iostream>

#include<deque> // For std::deque

using namespace std;

template<typename T>
void display(const deque<T> &d)
{
	cout<<"[ ";

	for(const auto &elem : d)
	{
		cout<<elem<<" ";
	}

	cout<<"]";
}

int main()
{
/*
Deques(double ended queue) are of dynamic size, they can contract and expand as needed. Elements are not stored in contiguous memory.

Deques are like a linked list of vectors. Don't use deques if you have to insert into the middle, use "std::list" for that.

For more information on std::deque refer: "https://en.cppreference.com/w/cpp/container/deque"

Time Complexities of different operations on std::deque:
1. Direct element access -> Constant time.
2. Rapid insertion and deletion at the front and back -> Constant time.
3. Insertion or removal of elements other than at the front or back -> Linear time.

All iterators are available and may invalidate.
*/
	deque<int> test_1 {1, 2, 3, 4, 5}; // Using initialization list. "std::deque" also supports emplace_back() when dealing with objects like in the case of std::vector.

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	deque<int> test_2(10, 0); // Overloaded constructor style initialization. Here it will assign '0' to all the elements in the deque of size '10'.

	test_2[0] = 1;

	test_2.at(1) = 2; // .at() will do bound checking.

	cout<<"test 2: ";
	display(test_2);
	cout<<"\n\n";

	test_1.push_back(6); // We can push from the back.

	test_1.push_front(0); // We can push from the front too.

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	cout<<"---------- test 1 ----------\n";
	cout<<"Front   : "<<test_1.front()<<"\n";
	cout<<"Back    : "<<test_1.back()<<"\n";
	cout<<"Size    : "<<test_1.size()<<"\n";
	cout<<"Max Size: "<<test_1.max_size()<<"\n\n";

	test_1.pop_back(); // We can pop the element from the back.

	test_1.pop_front(); // We can also pop the element from the front.

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	deque<int> result = {0};

	cout<<"Pushing all the even numbers to the right of the deque and all the odd numbers to the left of the deque: \n";

	for(const auto &elem : test_1)
	{
		if(elem % 2 == 0)
		{
			result.push_back(elem);
		}
		else
		{
			result.push_front(elem);
		}
	}

	cout<<"Result: ";
	display(result);
	cout<<"\n\n";

	test_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	result.clear();

	cout<<"Pushing all the elements of test 1 to the back of result(empty deque): \n";

	for(const auto &elem : test_1)
	{
		result.push_back(elem);
	}

	cout<<"result: ";
	display(result);
	cout<<"\n\n";

	result.clear();

	cout<<"Pushing all the elements of test 1 to the front of result(empty deque): \n";

	for(const auto &elem : test_1)
	{
		result.push_front(elem);
	}

	cout<<"result: ";
	display(result);
	cout<<"\n\n";

	result.clear();

	cout<<"Pushing all the elements of test 1 to the back of result(empty deque) using std::copy: \n";

	copy(test_1.begin(), test_1.end(), back_inserter(result));

	cout<<"result: ";
	display(result);
	cout<<"\n\n";

	result.clear();

	cout<<"Pushing all the elements of test 1 to the front of result(empty deque) using std::copy: \n";

	copy(test_1.begin(), test_1.end(), front_inserter(result)); // "front_inserter()" constructs a front-insert iterator that inserts new elements at the beginning of the container. A front-insert inserter is a special type of output iterator designed to allow algorithms that usually overwrite elements(such as copy) to instead insert new elements automatically at the beginning of the container.

	cout<<"result: ";
	display(result);
	cout<<"\n\n";

	return 0;
}