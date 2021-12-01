/*
Created by  : Vaisakh Dileep
Date        : 1, December, 2021
Description : This program helps to understand '%n' special format specifier in printf() in C++.
*/

#include<iostream>

using namespace std;

int main()
{
    int char_count {};

    printf("Vanilla Sky%n 2001\n", &char_count); // '%n' will load "char_count" with the value equal to the number of characters that have been printed by "printf()" before the occurrance of '%n'.

    cout<<"char_count: "<<char_count<<"\n\n";

    char city[] {"Chicago"};

    printf("%s%n\n", city, &char_count); // This way we can get the number of characters in a C-style string.

    cout<<"char_count: "<<char_count<<"\n\n";

    string country {"Bharat"};

    printf("%s%n\n", country.c_str(), &char_count); // This way we can get the number of characters in a C++ string.

    cout<<"char_count: "<<char_count<<"\n";

    return 0;
}