/*
Created by  : Vaisakh Dileep
Date		: 13, February, 2021
Description : This program helps to understand std::priority_queue in STL container adapters in C++.
*/

#include<iostream>

#include<queue> // For std::priority_queue

using namespace std;

class Person
{
	friend ostream &operator<<(ostream &os, const Person &person);

	string name;
	int age;
public:
	Person() : name {"None"}, age {0} {};

	Person(string name, int age) : name {name}, age {age} {};

	bool operator<(const Person &rhs) const // This is used for sorting the priority_queue.
	{
		return (this->age < rhs.age);
	}

	bool operator==(const Person &rhs) const
	{
		return ((this->name == rhs.name) and (this->age == rhs.age));
	}
};

ostream &operator<<(ostream &os, const Person &person)
{
	os<<"\""<<person.name<<"\""<<":"<<person.age;

	return os;
}

template<typename T>
void display(priority_queue<T> pq) // Here notice we are passing a copy.
{
	cout<<"[ ";

	while(!pq.empty())
	{
		T top_elem = pq.top();

		pq.pop();

		cout<<top_elem<<" ";
	}

	cout<<"]";
}

int main()
{
/*
std::priority_queue allows insertion and removal of elements in order from the front of the container. Elements are stored internally as a vector by default.

std::priority_queue internally use heap data structure for storing the elements(not the heap for dynamic memory allocation).

Elements in std::priority_queue are inserted in a priority order(largest value will always be at the front). No iterators are supported in std::priority_queue.

The operations performed on std::priority_queue are:
1. push  - Insert an element into the priority_queue in a sorted order.
2. pop   - Remove the top-most element(greatest).
3. top   - Access the top-most element(greatest).
4. empty - It will return true if the priority_queue is empty.
5. size  - It will return the number of elements present in the queue.
*/
	priority_queue<int> test_1;

	for(int i : {5, 4, 3, 2, 1, 1, 9, 8, 7, 6})
	{
		test_1.push(i);
	}

	cout<<"test 1: ";
	display(test_1);
	cout<<"\n\n";

	cout<<"Size [test 1]: "<<test_1.size()<<"\n";
	cout<<"Top  [test 1]: "<<test_1.top()<<"\n\n";

	cout<<"After popping an element from test 1: \n";

	test_1.pop();

	cout<<"Size [test 1]: "<<test_1.size()<<"\n";
	cout<<"Top  [test 1]: "<<test_1.top()<<"\n\n";

	priority_queue<Person> SimpsonFamily;

	for(Person i : {Person {"Homer J Simpson", 39}, Person {"Marge Bouvier", 36}, Person {"Bart Simpson", 10}, Person {"Maggie Simpson", 1}, Person {"Lisa Simpson", 8}, Person {"Abraham Simpson", 83}})
	{
		SimpsonFamily.push(i);
	}

	cout<<"Simpson Family: ";
	display(SimpsonFamily); // Notice here that the Simpson Characters are sorted by their age.
	cout<<"\n\n";

	cout<<"Simpson Family after clearing all the elements: \n";

	while(!SimpsonFamily.empty()) // This is how we clear a priority_queue.
	{
		SimpsonFamily.pop();
	}

	cout<<"Simpson Family: ";
	display(SimpsonFamily);
	cout<<"\n";

	cout<<"Size [Simpson Family]: "<<SimpsonFamily.size()<<"\n\n";

	return 0;
}