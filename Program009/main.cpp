/*
Created by  : Vaisakh Dileep
Date		: 18, December, 2020
Description : This program helps to understand if statements in C++..
*/

#include<iostream>

#include<iomanip> // For precision

using namespace std;

int main()
{
// { ... } -> This creates a block statement, variables declared in this block are of local scope.

/*
Syntax for if statement:
if(expr)
	statement; --> if "expr" evaluates to "true" then statement is evaluated, for multiple statements use { }(blocks).
*/

// Boundary Checking: This program does boundary checking.
	int num {};

	const int max {20}, min {10};

	cout<<"Enter a number between "<<min<<" and "<<max<<": ";

	cin>>num;

	if(num < min)
	{
		int difference {}; // Here "difference" is local to the if statement block.

		difference = min - num;

		cout<<"You are "<<difference<<" distance away from the range.\n";
	}
	if (num > max)
	{
		int difference {};

		difference = num - max;

		cout<<"You are "<<difference<<" distance away from the range.\n";
	}
	if ((num == min) || (num == max))
	{
		cout<<"You are at the boundary.\n";
	}

	if ((num < max) && (num > min))
	{
		cout<<"You are inside the range.\n";
	}

/*
Syntax for if-else statement:
if(expr)
	statement 1;
else
	statement 2; --> if "expr" is true then statement 1 is evaluated, if "expr" is false then statement 2 if evaluated.
*/

/*
Syntax for if-"else if"-else statement:
if(expr1)
	statement 1;
else if(expr2)
	statement 2;
		.
		.
		.
else
	statement n;
*/

// Grade Calculator: This program calculates the grade given the score.
	double score {};

	cout<<"Enter Your Score: ";

	cin>>score;

	cout<<"Your grade: ";

	if(score > 90)
	{
		cout<<"A\n";
	}
	else if (score > 80)
	{
		cout<<"B\n";
	}
	else if (score > 70)
	{
		cout<<"C\n";
	}
	else if (score > 60)
	{
		cout<<"D\n";
	}
	else
	{
		cout<<"F\n";
	}

/*
Consider the following segment,
if(expr1)
	if (expr2)
		statement1;
	else
		statement2; --> This is called the dangling else problem, two else statements for one if statement. C++ overcomes this problem by fixing the else statement to the nearest if statement or we can choose which if statement to connect to by using blocks { }.
*/

/*
Shipping Cost Calculator.

Input package dimensions(length, width, height) from the user in inches. All dimensions must be less than or equal to 10.

Base cost is $2.50. If volume is greater than 100 cubic inches there is a 10% surcharge. If volume is greater than 500 cubic inches there is a 25% surcharge.
*/

	int length_package {}, width_package {}, height_package {};

	double base_cost {2.50};

	const int max_dimension {10};

	const int tier1_threshold {100}, tier2_threshold {500};

	const double tier1_surcharge {0.10}, tier2_surcharge{0.25};

	int package_volume {};

	cout<<"WELCOME TO THE PACKAGE COST CALCULATOR: \n";

	cout<<"Enter length, width and height of the package separated by spaces: ";

	cin>>length_package>>width_package>>height_package;

	if((length_package > max_dimension) || (width_package > max_dimension) || (height_package > max_dimension))
	{
		cout<<"Sorry, package rejected - exceeded dimension.\n";
	}
	else
	{
		double package_cost {};

		package_volume = length_package * width_package * height_package;

		package_cost = base_cost;

		if(package_volume > tier2_threshold)
		{
			package_cost += package_cost * tier2_surcharge;

			cout<<"\n\nAdding Tier 2 surcharge.\n";
		}
		else if(package_volume > tier1_threshold)
		{
			package_cost += package_cost * tier1_surcharge;

			cout<<"\n\nAdding Tier 1 surcharge.\n";
		}

		cout<<fixed<<setprecision(2); // Sets precision to 2

		cout<<"The Volume of your package is: "<<package_volume<<"\n";

		cout<<"Your package will cost: "<<package_cost<<"\n";
	}

	return 0;
}
