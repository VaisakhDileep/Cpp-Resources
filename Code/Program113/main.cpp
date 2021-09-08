/*
Created by  : Vaisakh Dileep
Date		: 12, February, 2021
Description : This program helps to understand std::queue in STL container adapters in C++.
*/

#include<iostream>

#include<queue> // For std::queue

#include<list> // For std::list

using namespace std;

template<typename T>
void display(queue<T> q) // Notice here we are passing as a copy.
{
	T top_elem;

	cout<<"[ ";

	while(!q.empty())
	{
		top_elem = q.front(); // In queue elements are popped from the front.

		q.pop();

		cout<<top_elem<<" ";
	}

	cout<<"]";
}

int main()
{
/*
std::queue is a First-in First-out(FIFO) data-structure. Implemented as an adapter over other STL containers like list or deque.

Elements in a queue are pushed at the back and popped from the front. No iterators are supported.

The operations performed on std::queue are:
1. push  - Insert an element at the back of the queue.
2. pop   - Remove an element from the front of the queue.
3. front - Access the element at the front.
4. back  - Access the element at the back.
5. empty - It will returns true if the queue is empty.
6. size  - It will return the number of elements present in the queue.
*/
	queue<int> test_1; // By default std::deque is used as the container.
	queue<int, list<int>> test_2;
	queue<int, deque<int>> test_3; // Notice here we do not include the deque library(#include<deque>).

	for(int i : {0, 1 ,2, 3, 4, 5, 6, 7, 8, 9})
	{
		test_1.push(i);
	}

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	cout<<"Front [test 1]: "<<test_1.front()<<"\n"; // .front() returns a reference, so we can update the first element.
	cout<<"Back  [test 1]: "<<test_1.back()<<"\n"; // .back() returns a reference, so we can update the last element.
	cout<<"Size  [test 1]: "<<test_1.size()<<"\n\n";

	cout<<"test 1 after pushing -1 into it: \n"; // Notice here that the elements are pushed from the back.

	test_1.push(-1);

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	cout<<"test 1 after popping an element from it: \n"; // Notice here that the elements are popped from the front.

	test_1.pop();

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	while(!test_1.empty()) // This is how we clear a queue.
	{
		test_1.pop();
	}

	cout<<"test 1 after clearing all the elements: \n";

	cout<<"test 1 : ";
	display(test_1);
	cout<<"\n";

	cout<<"Size [test 1]: "<<test_1.size()<<"\n";

	return 0;
}