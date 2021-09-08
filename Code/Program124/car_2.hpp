#include<iostream>

#include "horn_2.hpp"

using namespace std;

class car_2 // In our case it is not necessary to include header guards for "car_2.hpp" but it is a good programming practice to do so.
{
public:
	horn_2 H;

	void say()
	{
		cout<<"Vroom Vroom !!";
	}
};