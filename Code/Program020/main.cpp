/*
Created by  : Vaisakh Dileep
Date        : 20, December, 2020
Description : This program helps to understand C-style strings in C++.
*/

#include<iostream>

#include<cstring> // This library contains different functions to manipulate and compare C-style strings.

using namespace std;

int main()
{
// C-style Strings: They are implemented as an array of characters, these strings are terminated by the null character('\0').

    char my_name[] {"Homer"}; // Here "my_name" is an example for C-style strings, it is stored in memroy as "Homer\0".

    int iterator {0};

    cout<<"Name: ";

    while(my_name[iterator] != '\0')
    {
        cout<<my_name[iterator]; // C-style Strings behaves just like arrays when accessing.

        ++iterator;
    }

    cout<<"\n";

    // cout<<my_name<<"\n"; // We can print like this too.

    char my_neighbour[10] {"Flander"}; // Here "my_neighbour" is an example of C-style string, it is stored in memory as "Flander\0\0\0\0"(initialization occurs at every char element).

    iterator = 0;

    cout<<"Neighbour: ";

    while(my_neighbour[iterator] != '\0')
    {
        cout<<my_neighbour[iterator]; // C-style Strings behave just like arrays when accessing.

        ++iterator;
    }

    cout<<"\n";

    my_neighbour[7] = 's'; // This is possible.

    iterator = 0;

    cout<<"Neighbour(after adding 's' at the end): ";

    while(my_neighbour[iterator] != '\0')
    {
        cout<<my_neighbour[iterator]; // C-style Strings behave just like arrays when accessing.

        ++iterator;
    }

    cout<<"\n";

    char my_boss[8]; // It's best practice to use "char my_boss[8] {}", when using this format all the char elements in the string are initialized to null character('\0').

    // my_boss = "Burns"; // We can't initialize like this because "my_boss" contains random values and some of them may be null character(we don't know).

    cout<<"Boss(without initializing): "<<my_boss<<"\n";

    strcpy(my_boss, "Burns"); // This is accepted.

    cout<<"Boss(after copying): "<<my_boss<<"\n";

    char my_son[8];

    my_son[0] = 'B';
    my_son[1] = 'A';
    my_son[2] = 'R';
    my_son[3] = 'T';

    cout<<"Son(without null character): " <<my_son<<"\n"; // This is will print even after the bound until it meets the null character.

    my_son[4] = '\0';

    cout<<"Son(with null character): "<<my_son<<"\n";

    return 0;
}