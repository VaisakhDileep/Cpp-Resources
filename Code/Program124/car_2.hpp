#include<iostream>

#include "Horn_2.hpp"

using namespace std;

class Car_2 // In our case it is not necessary to include header guards for "Car_2.hpp" but it is a good programming practice to do so.
{
public:
	Horn_2 H;

	void say()
	{
		cout<<"Vroom Vroom !!";
	}
};