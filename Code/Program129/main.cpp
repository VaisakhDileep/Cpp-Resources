/*
Created by  : Vaisakh Dileep
Date        : 3, October, 2021
Description : This program helps to understand the duplicate definition problem when working with header files in C++.
*/

#include<iostream>

// #include "greetings_prototype_1.hpp" // This will give a linker error.

#include "greetings_prototype_2.hpp"

/*
Prototype 1:

greetings_prototype_1.hpp
-------------------------
#ifndef _GREETINGS_PROTOTYPE_1_HPP_
#define _GREETINGS_PROTOTYPE_1_HPP_

#include<iostream>

using namespace std;

void greet_world(); // Forward declaration.

void greet_world(); // We can have duplicate forward declarations as well.

int lucky_number_1; // "lucky_number_1" will be defined in "greetings_prototype_1.cpp" and "main.cpp". Linker will report an error.

const int lucky_number_2 {78}; // "constant" variables wont't be defined elsewhere, so linker is OK with it.

void greet_me(string name) // "greet_me(string name)" will be defined in "greetings_prototype_1.cpp" and "main.cpp". Linker will reprot an error.
{
    cout<<"Hello, "<<name<<"!!\n";
}

#endif

greetings_prototype_1.cpp
-------------------------
#include "greetings_prototype_1.hpp"

using namespace std;

void greet_world()
{
    cout<<"Hello, World!!\n";
}

Chain of Events:
----------------
1. First "greetings_prototype_1.cpp" will be compiled. "#include "greetings_prototype_1.hpp" will be replaced by the header files contents.
2. After "greetings_prototype_1.cpp" is compiled "main.cpp" is compiled(header guard fails here since "greetings_prototype_1.cpp" is already compiled, so header guard is no longer active in "main.cpp"). This will create duplicate function and variable definitions which the compiler might not detect.
3. "greetings_prototype_1.cpp" is compiled to "greetings_prototype_1.o" and "main.cpp" is compiled to "main.o".
4. The linker will try to link "greetings_prototype_1.o" and "main.o", but since there are duplicate definitions, it will give a linker error.
*/

// A possible solution is to include all the variable and function declarations in a ".hpp" file and keep the defintions in a separate .cpp file having the same name as the header file(prototype 2).

using namespace std;

int main()
{
    cout<<"lucky_number_1: "<<lucky_number_1<<"\n";
    cout<<"lucky_number_2: "<<lucky_number_2<<"\n";

    greet_me("Vaisakh Dileep");

    greet_world();

    return 0;
}