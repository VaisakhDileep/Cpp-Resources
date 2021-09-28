/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2020
Description : This program helps to understand while loops in C++.
*/

#include<iostream>

using namespace std;

int main()
{

/*
Syntax for while loop:

while (expression)
    statement;

    ... or ...

while (expression)
{
    statement(s);
}
*/
    int i {0};

    while(i <= 10)
    {
        if(i % 2 == 0)
        {
            cout<<i<<" ";
        }

        i++;
    }

    cout<<"\n";

    int scores[] {100, 90, 92, 97, 95, 99};

    i = 0;

    while(i < 6)
    {
        cout<<scores[i]<<" ";

        i++;
    }

    cout<<"\n";

    int input {};

    cout<<"Enter 5: ";

    cin>>input;

    while(input != 5)
    {
        cout<<"I could do this all day, Enter 5: ";

        cin>>input;
    }

    cout<<"\n";

// Bound Checking: This program does bound checking.
    int number {};

    const int max {10}, min {5};

    bool done {false};

    while(!done)
    {
        cout<<"Enter an integer between "<<min<<" and "<<max<<": ";

        cin>>number;

        if(number >= max || number <= min)
        {
            cout<<"Out of range. Enter Again.\n";
        }
        else
        {
            cout<<"Thank You !!\n";

            done = true;
        }
    }

    return 0;
}