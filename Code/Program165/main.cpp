/*
Created by  : Vaisakh Dileep
Date        : 25, February, 2022
Description : This program helps to understand name mangling in C++.
*/

#include<iostream>

using namespace std;

void function() // In my os it is internally named as "_Z8functionv"(names might vary when running in a different os).
{
    cout<<"void function()\n";
}

void function(char c) // In my os it is internally named as "_Z8functionc".
{
    cout<<"void function(char c)\n";
}

void function(int x) // In my os it is internally named as "_Z8functioni".
{
    cout<<"void function(int x)\n";
}

void function(int x, int y) // In my os it is internally named as "_Z8functionii".
{
    cout<<"void function(int x, int y)\n";
}

// Name mangling is the encoding of function and variable names into unique names so that the linker can separate common names in the language.

int main()
{
/*
Inorder to view how "name mangling" actually works:

1. Compile the program using "g++ -c main.cpp main.o".
2. Run "nm main.o".
*/
    return 0;
}