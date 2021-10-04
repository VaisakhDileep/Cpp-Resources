#ifndef _GREETINGS_PROTOTYPE_2_HPP_
#define _GREETINGS_PROTOTYPE_2_HPP_

// This header file only contains the function and variable declaration.

#include<iostream>

using namespace std;

void greet_world(); // Function declaraion.

extern int lucky_number_1; // "extern" variables is equivalent to forward declaring variables, it will tell the linker to look for the variable.

const int lucky_number_2 {77}; // "const" variables won't be defined elsewhere, so linker is OK with it.

void greet_me(string name); // Function declaration.

#endif