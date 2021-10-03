#ifndef _GREETINGS_PROTOTYPE_1_HPP_
#define _GREETINGS_PROTOTYPE_1_HPP_

#include<iostream>

using namespace std;

void greet_world(); // Forward declaration.

void greet_world(); // We can have duplicate forward declarations as well.

int lucky_number_1; // "lucky_number_1" will be defined in "greetings_prototype_1.cpp" and "main.cpp". Linker will report an error.

const int lucky_number_2 {77}; // "const" variables wont't be defined elsewhere, so linker is OK with it.

void greet_me(string name) // "greet_me(string name)" will be defined in "greetings_prototype_1.cpp" and "main.cpp". Linker will reprot an error.
{
    cout<<"Hello, "<<name<<"!!\n";
}

#endif