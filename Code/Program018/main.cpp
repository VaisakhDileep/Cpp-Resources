/*
Created by  : Vaisakh Dileep
Date		: 19, December, 2020
Description : This program helps to understand nested loops in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

int main()
{
	for(int outer_val {1}; outer_val <= 2; ++outer_val) // Outer loop
		for(int inner_val {1}; inner_val <= 3; ++inner_val) // Inner loop
			cout<<outer_val<<", "<<inner_val<<"\n";

	cout<<"\n\n";

// Multiplication Table: This program prints the multiplication table.
	for(int num1 {1}; num1 <= 10; ++num1)
	{
		for(int num2 {1}; num2 <= 10; ++num2)
		{
			cout<<num1<<" * "<<num2<<" = "<<num1 * num2<<"\n";
		}

		cout<<"----------------\n";
	}

	int grid[5][3] {}; // Here all the elements in the 2-D array are initialized to '0'.

	for(int row {0}; row < 5; ++row)
	{
		for(int column {0}; column < 3; ++column)
		{
			grid[row][column] = 100; // Here we will set all the the elements in the 2-D array to '100'.
		}
	}

	cout<<"\n\n";

	for(int row {0}; row < 5; ++row) // Using nested for loop to display 2-D arrays.
	{
		for(int column {0}; column < 3; ++column)
		{
			cout<<grid[row][column]<<" ";
		}

		cout<<"\n";
	}

	cout<<"\n\n";

	vector<vector<int>> vector_2d
	{
		{1},
		{1, 2},
		{1, 2, 3},
		{1, 2, 3, 4},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5, 6},
		{1, 2, 3, 4, 5, 6, 7},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8, 9}
	};

	for(auto vec : vector_2d) // Displaying a 2-D vector.
	{
		for(auto val : vec)
		{
			cout<<val<<"  ";
		}

		cout<<"\n";
	}

	cout<<"\n";

// Menus, Vectors, Largest, Smallest and Mean.

	vector<int> numbers {};

	char choice {};

	do{
		cout<<"1- Print numbers.\n";
		cout<<"2- Add a number.\n";
		cout<<"3- Display the mean of the numbers.\n";
		cout<<"4- Display the smallest number.\n";
		cout<<"5- Display the largest number.\n";
		cout<<"6- Quit.\n\n";

		cout<<"Enter your choice: ";

		cin>>choice;

		if(choice == '1')
		{
			if(numbers.size() == 0)
			{
				cout<<"[] - The list is empty\n";
			}
			else
			{
				cout<<"[ ";

				for(auto num : numbers)
				{
					cout<<num<<" ";
				}

				cout<<"]\n";
			}
		}
		else if(choice == '2')
		{
			int num_to_add {};

			cout<<"Enter an integer to add to the list: ";

			cin>>num_to_add;

			numbers.push_back(num_to_add);

			cout<<num_to_add<<" added.\n";
		}
		else if(choice == '3')
		{
			if(numbers.size() == 0)
			{
				cout<<"Unable to calculate mean - list is empty.\n";
			}
			else
			{
				int total {};

				for(auto num : numbers)
				{
					total += num;
				}

				cout<<"The mean is: "<<static_cast<double>(total) / numbers.size()<<"\n";
			}
		}
		else if(choice == '4')
		{
			if(numbers.size() == 0)
			{
				cout<<"Unable to determine the smallest element - list is empty.\n";
			}
			else
			{
				int smallest {numbers.at(0)};

				for(auto num : numbers)
				{
					if(num < smallest)
					{
						smallest = num;
					}
				}

				cout<<"The smallest number is "<<smallest<<".\n";
			}
		}
		else if(choice == '5')
		{
			if(numbers.size() == 0)
			{
				cout<<"Unable to determine the largest element - list is empty.\n";
			}
			else
			{
				int largest = numbers.at(0);

				for(auto num : numbers)
				{
					if(num > largest)
					{
						largest = num;
					}
				}

				cout<<"The largest number is "<<largest<<".\n";
			}
		}
		else if(choice == '6')
		{
			cout<<"Goodbye ... \n";
		}
		else
		{
			cout<<"Invalid Choice.\n\n";
		}
	}while(choice != '6');

	return 0;
}