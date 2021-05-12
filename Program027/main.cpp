/*
Created by  : Vaisakh Dileep
Date		: 22, December, 2020
Description : This program helps to understand default argument values in C++ user-defined functions.
*/

#include<iostream>

using namespace std;

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping_cost = 10.0); // It's best practice to add default valued parameters during function prototyping.

int main()
{
// Parameters with default values should always be at the tail of the parameter list.
	double cost {0};

	cost = calc_cost(200.0);

	cout<<"Your total: "<<cost<<"\n";

	cost = calc_cost(100.0, 0.08);

	cout<<"Your total: "<<cost<<"\n";

	cost = calc_cost(100.0, 0.08, 20);

	cout<<"Your total: "<<cost<<"\n";

	return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping_cost)
{
	return base_cost += (base_cost * tax_rate) + shipping_cost;
}