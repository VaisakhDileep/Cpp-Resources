/*
Created by  : Vaisakh Dileep
Date		: 8, September, 2021
Description : This program helps to understand header guards in C++.
*/

#include<iostream>

#include "car_1.hpp" // "car_1.hpp" also includes "horn_1.hpp".

#include "horn_1.hpp" // Inorder to prevent "horn_1.hpp" from begin included again, we need to provide a header guard for "horn_1.hpp".

#include "car_2.hpp" // "car_2.hpp" also includes "horn_2.hpp".

#include "horn_2.hpp" // Inorder to prevent "horn_2.hpp" from begin included again, we need to provide a header guard for "horn_2.hpp".

using namespace std;

int main()
{
	car_1 A {};

	A.say();

	cout<<"\n";

	A.H.say();
	cout<<"\n";

	car_2 B {};

	B.say();

	cout<<"\n";

	B.H.say();
	cout<<"\n";

	return 0;
}