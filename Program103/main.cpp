/*
Created by  : Vaisakh Dileep
Date		: 8, February, 2021
Description : This program helps to understand STL algorithms in C++.
*/

#include<iostream>

#include<vector>

#include<algorithm> // For std::find()

#include<string>

#include<cctype> // For std::transform()

using namespace std;

void square(int x)
{
	cout<<(x * x)<<" ";
}

struct Square
{
	void operator()(int x) // Here we are overloading the "()" operator.
	{
		cout<<(x * x)<<" ";
	}
};

class Enemy
{
private:
	string name;
	int difficulty;
public:
	Enemy(string name, int difficulty)
		: name {name}, difficulty {difficulty}
	{
	}

	bool operator==(Enemy rhs) // Also make sure to overload the "<" operator when using objects with STL algorithms.
	{
		return ((this->difficulty == rhs.difficulty) and (this->name == rhs.name));
	}
};

int main()
{
/*
STL algorithms work on sequences of container elements provided to them by an iterator. STL has many useful algorithms.

For more information on STL algorithms refer: "http://www.cplusplus.com/reference/algorithm/"

All STL algorithms expect iterators as arguments. Different containers support different types of iterators.
*/

/*
Iterator Invalidation:
Iterators point to container elements, it is possible iterators become invalid during processing. Suppose in between iteration we clear the vector, then the iterator will generate an undefined behaviour because the iterator is pointing to an invalid location.
*/
	vector<int> vec {1, 2, 3};

	vector<int>::iterator result_it = find(vec.begin(), vec.end(), 3); // Here we could also use "auto result_it = find(vec.begin(), vec.end(), 3)".

	if(result_it != vec.end()) // "std::find()" returns an iterator to the first occurrence of the element in the container. If the element is found then it will return a valid iterator, otherwise it will return an iterator to the end of the container.
	{
		cout<<*result_it<<" was found successfully !!! \n\n";
	}
	else
	{
		cout<<"No such element exist in the vector ... \n\n";
	}

	result_it = find(vec.begin(), vec.end(), -1);

	if(result_it != vec.end())
	{
		cout<<*result_it<<" was found successfully !!! \n\n";
	}
	else
	{
		cout<<"No such element exist in the vector ... \n\n";
	}

// Note: When we are passing an object to find, then make sure to override the equality operator(operator==), otherwise it will not work.

	vector<Enemy> outlast_2 {Enemy {"Sullivan Knote", 0}, Enemy {"Val", 10}, Enemy {"Father Loutermilch", 20}, Enemy {"Martha", 50}};

	vector<Enemy>::iterator outlast_it = find(outlast_2.begin(), outlast_2.end(), Enemy {"Val", 10});

	if(outlast_it != outlast_2.end())
	{
		cout<<"Enemy found successfully !!! \n\n";
	}
	else
	{
		cout<<"No such enemy found in the game ... \n\n";
	}

	outlast_it = find(begin(outlast_2), end(outlast_2), Enemy {"Jessica Langermann", 100}); // Note instead of "outlast_2.begin()" we can use "std::begin(outlast_2)" and instead of "outlast_2.end()" we can use "std::end(outlast_2)".

	if(outlast_it != outlast_2.end())
	{
		cout<<"Enemy found successfully !!! \n\n";
	}
	else
	{
		cout<<"No such enemy found in the game ... \n\n";
	}
/*
For some functions in STL algorithms we need to provide some extra informations for them to work, this extra information may be:
1. Functor(function object).
2. Function pointer.
3. Lambda Expresssion(post C++11).
*/
	vector<int> even_numbers {0, 2, 4, 6, 8};

	cout<<"Result 1: [ "; 
	for_each(even_numbers.begin(), even_numbers.end(), square); // Here we are passing a function pointer.
	cout<<"]\n";

	cout<<"Result 2: [ ";
	for_each(even_numbers.begin(), even_numbers.end(), Square {}); // Here we are passing a functor.
	cout<<"]\n";

	cout<<"Result 3: [ ";
	for_each(even_numbers.begin(), even_numbers.end(), [](int x) { cout<<(x * x)<<" "; }); // Here we are passing a lambda function.
	cout<<"]\n\n";

	vector<int> data {1, 3, 4, 1, 2, 1, 1, 2, 1, 6, 1, 0, 2};

	int count_1_data = count(data.begin(), data.end(), 1);
	cout<<"1 is repeated "<<count_1_data<<" number of times in the data vector.\n";

	int count_even_data = count_if(data.begin(), data.end(), [](int x) { return x % 2 == 0; });
	cout<<"There are "<<count_even_data<<" even numbers present in the data vector.\n";

	int count_odd_data = count_if(data.begin(), data.end(), [](int x) { return x % 2 != 0; });
	cout<<"There are "<<count_odd_data<<" odd numbers present in the data vector.\n\n";

	cout<<"[ ";
	for(auto i : data)
	{
		cout<<i<<" ";
	}
	cout<<"]  ----- After Replacing '1' with '10' -----  [ ";

	replace(data.begin(), data.end(), 1, 10);

	for(auto i : data)
	{
		cout<<i<<" ";
	}
	cout<<"]\n\n";

	if(all_of(data.begin(), data.end(), [](int x) { return x > 10; })) // This will check if all elements in the vector are greater than '10'.
	{
		cout<<"All elements in the data vector are greater than 10.\n";
	}
	else
	{
		cout<<"Not all elements in the data vector are greater than 10.\n";
	}

	if(all_of(data.begin(), data.end(), [](int x) { return x < 11; })) // This will check if all elements in the vector are lesser than '11'.
	{
		cout<<"All elements in the data vector are lesser than 11.\n";
	}
	else
	{
		cout<<"Not all elements in the data vector are lesser than 11.\n";
	}

	cout<<"\n";

	vector<char> alphabets {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	vector<char> upper_case_alphabets {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'};

	transform(alphabets.begin(), alphabets.end(), upper_case_alphabets.begin(), ::toupper); // Here '::' represents global scope or the ones that does not have a namespace declared, for more information refer "Program104".

	cout<<"Lower-case alphabets: [ ";
	for(auto i : alphabets)
	{
		cout<<i<<" ";
	}
	cout<<"]\n";

	cout<<"Upper-case alphabets: [ ";
	for(auto i : upper_case_alphabets)
	{
		cout<<i<<" ";
	}
	cout<<"]\n\n";

	return 0;
}