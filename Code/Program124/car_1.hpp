#include<iostream>

#include "Horn_1.hpp"

using namespace std;

class Car_1 // In our case it is not necessary to include header guards for "Car_1.hpp" but it is a good programming practice to do so.
{
public:
    Horn_1 H;

    void say()
    {
        cout<<"Vroom Vroom !!";
    }
};