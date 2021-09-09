/*
Created by  : Vaisakh Dileep
Date		: 10, September, 2021
Description : This program helps to understand std::random_shuffle function in C++.
*/

#include<iostream>

#include<vector>

#include<algorithm> // For random_shuffle().

#include<ctime> // For time().

class random_shuffle_generator // Our own custom random shuffle generator.
{
public:
	int operator()(int i)
	{
		return rand() % i;
	}
};

using namespace std;

int main()
{
	vector<int> vec {1, 2, 3, 4, 5};

	vector<int> random_shuffled_vec_1 {vec}, random_shuffled_vec_2 {vec};

	srand(static_cast<unsigned int>(time(nullptr))); // "time(nullptr)" return "time_t". Without this line(seeding the "rand()" function), each time we compile and run the program we get the same output.

	cout<<"vec: ";
	for(int i {0}; i < vec.size(); i++)
	{
		cout<<vec.at(i)<<" ";
	}
	cout<<"\n";

	random_shuffle(random_shuffled_vec_1.begin(), random_shuffled_vec_1.end());

	cout<<"random_shuffled_vec_1: ";
	for(int i {0}; i < random_shuffled_vec_1.size(); i++)
	{
		cout<<random_shuffled_vec_1.at(i)<<" ";
	}
	cout<<"\n";

	random_shuffle(random_shuffled_vec_2.begin(), random_shuffled_vec_2.end());

	cout<<"random_shuffled_vec_2: ";
	for(int i {0}; i < random_shuffled_vec_2.size(); i++)
	{
		cout<<random_shuffled_vec_2.at(i)<<" "; // Each time we run "random_shuffle()", even for identical arrays we get different results.
	}
	cout<<"\n\n";

	random_shuffled_vec_1 = random_shuffled_vec_2 = vec;

	random_shuffle(random_shuffled_vec_1.begin(), random_shuffled_vec_1.end(), random_shuffle_generator {}); // Using custom random index generator.

	cout<<"random_shuffled_vec_1: ";
	for(int i {0}; i < random_shuffled_vec_1.size(); i++)
	{
		cout<<random_shuffled_vec_1.at(i)<<" ";
	}
	cout<<"\n";

	random_shuffle(random_shuffled_vec_2.begin(), random_shuffled_vec_2.end(), random_shuffle_generator {});

	cout<<"random_shuffled_vec_2: ";
	for(int i {0}; i < random_shuffled_vec_2.size(); i++)
	{
		cout<<random_shuffled_vec_2.at(i)<<" ";
	}
	cout<<"\n";

	return 0;
}