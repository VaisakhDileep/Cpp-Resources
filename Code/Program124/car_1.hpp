#include<iostream>

#include "horn_1.hpp"

using namespace std;

class car_1 // In our case it is not necessary to include header guards for "car_1.hpp" but it is a good programming practice to do so.
{
public:
	horn_1 H;

	void say()
	{
		cout<<"Vroom Vroom !!";
	}
};