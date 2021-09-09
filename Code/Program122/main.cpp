/*
Created by  : Vaisakh Dileep
Date		: 29, July, 2021
Description : This program helps to understand the goto statement in C++.
*/

#include<iostream>

using namespace std;

int main()
{
	int num {};

zero:
	cout<<"Enter a non-zero number: ";

	cin>>num;

	if(num > 0)
	{
		goto positive; // "goto" statement is like an unconditional jump statement. It can be used to jump from anywhere to anywhere within a function.
	}
	else if(num < 0)
	{
		goto negative;
	}
	else if(num == 0)
	{
		goto zero;
	}

positive:
	cout<<"+ve \n";

	return 0;

negative:
	cout<<"-ve \n";

	return 0;
}