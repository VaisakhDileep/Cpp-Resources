/*
Created by  : Vaisakh Dileep
Date        : 4, October, 2021
Description : This program helps to understand the extern keyword in C++.
*/

#include<iostream>

#include "add.hpp"

using namespace std;

extern int add(int, int); // The definition of the function might be present in this program or in some other program which the linker might link to later.

int add(int, int); // Function declaration, compiler treats it as "extern int add(int, int)".

extern int l_variable_1 {10}; // Since we already defined the variable this won't be an "extern" variable anymore. Only possible in the global scope.

int i {10};

void func()
{
    extern int i;

    // extern int j {10}; // This will given an error, since 'j' is an "extern" variable and we can't initialize it in the local scope.

    cout<<"i: "<<i<<"\n";
}

int main()
{
// extern variables(external variables) are the variables that are defined outside any function block.

// In C++ a variable or a function can be declared multiple number of times, but can only be defined once.

    extern int e_variable; // "extern" will tell tell the compiler that the definition of the variable is present somewhere else. Linker later connects it.

    extern int e_variable; // We can have duplicate declarations in our program, but should only have one definition..

    cout<<"add(10, 30): "<<add(10, 30)<<"\n";

    func();

    return 0;
}