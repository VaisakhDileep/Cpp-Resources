/*
Created by  : Vaisakh Dileep
Date		: 3, July, 2021
Description : This program helps to understand how to convert a STL container into a heap data structure in C++.
*/

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

int main()
{
// For Max Heap:
	vector<int> vec_1 {10, 30, 50, 60, 15};

	make_heap(vec_1.begin(), vec_1.end()); // By default it will create max heap.

	cout<<"vec_1: ";
	for(int elem : vec_1)
	{
		cout<<elem<<" ";
	}
	cout<<"\n\n";

	cout<<"vec_1.front(): "<<vec_1.front()<<"\n\n"; // This will give the largest element, since we created a max heap.

	vec_1.push_back(70);

	push_heap(vec_1.begin(), vec_1.end()); // For reordering the max heap, after pushing an element into the container.

	cout<<"vec_1 [after pushing '70' into the max heap]: ";
	for(int elem : vec_1)
	{
		cout<<elem<<" ";
	}
	cout<<"\n\n";

	pop_heap(vec_1.begin(), vec_1.end()); // This will remove the largest element from the max heap and reorders the max heap.

	cout<<"vec_1 [after poping the largest element in the max heap]: ";
	for(int elem : vec_1)
	{
		cout<<elem<<" "; // Notice here that the removed element is at the end of the vector.
	}
	cout<<"\n\n";

	vec_1.pop_back(); // Make sure to pop out the last element from the vector after performing "pop_heap()".

	vec_1.push_back(80);

	cout<<"is_heap(vec_1.begin(), vec_1.end() - 1): "<<is_heap(vec_1.begin(), vec_1.end() - 1)<<"\n"; // "is_heap()" will check whether the container is a heap or not.

	cout<<"is_heap(vec_1.begin(), vec_1.end()): "<<is_heap(vec_1.begin(), vec_1.end())<<"\n";

	cout<<"is_heap_until(vec_1.begin(), vec_1.end()): "<<*(is_heap_until(vec_1.begin(), vec_1.end()))<<"\n\n"; // "is_heap_until()" will return an iterator to the position till the container is a heap.

	vector<int>::iterator vec_1_it {is_heap_until(vec_1.begin(), vec_1.end())};

	cout<<"vec_1: ";
	for(vector<int>::iterator it {vec_1.begin()}; it != vec_1_it; it++) // We can traverse through the max heap like this too.
	{
		cout<<*it<<" ";
	}
	cout<<"\n\n";

// For Min Heap:
	vector<int> vec_2 {40, 50, 70, 10, 5};

	make_heap(vec_2.begin(), vec_2.end(), greater<> {}); // Here it will create min heap.

	cout<<"vec_2: ";
	for(int elem : vec_2)
	{
		cout<<elem<<" ";
	}
	cout<<"\n\n";

	cout<<"vec_2.front(): "<<vec_2.front()<<"\n\n"; // This will give the smallest element, since we created a min heap.

	vec_2.push_back(0);

	push_heap(vec_2.begin(), vec_2.end(), greater<> {}); // For reordering the min heap, after pushing an element into the container.

	cout<<"vec_2 [after pushing '0' into the min heap]: ";
	for(int elem : vec_2)
	{
		cout<<elem<<" ";
	}
	cout<<"\n\n";

	pop_heap(vec_1.begin(), vec_1.end(), greater<> {}); // This will remove the smallest element from the min heap and reorders the min heap.

	cout<<"vec_2 [after poping the smallest element in the min heap]: ";
	for(int elem : vec_2)
	{
		cout<<elem<<" ";
	}
	cout<<"\n\n";

	vec_2.pop_back(); // Make sure to pop out the last element from the vector after performing "pop_heap()".

	vec_2.push_back(-5);

	cout<<"is_heap(vec_2.begin(), vec_2.end() - 1, greater<> {}): "<<is_heap(vec_1.begin(), vec_1.end() - 1, greater<> {})<<"\n"; // "is_heap()" will check whether the container is a heap or not.

	cout<<"is_heap(vec_2.begin(), vec_2.end(), greater<> {}): "<<is_heap(vec_2.begin(), vec_2.end(), greater<> {})<<"\n";

	cout<<"is_heap_until(vec_2.begin(), vec_2.end()): "<<*(is_heap_until(vec_2.begin(), vec_2.end(), greater<> {}))<<"\n\n"; // "is_heap_until()" will return an iterator to the position till the container is a heap.

	vector<int>::iterator vec_2_it {is_heap_until(vec_2.begin(), vec_2.end(), greater<> {})};

	cout<<"vec_2: ";
	for(vector<int>::iterator it {vec_2.begin()}; it != vec_2_it; it++) // We can iterate through the min heap like this too.
	{
		cout<<*it<<" ";
	}
	cout<<"\n";

	return 0;
}