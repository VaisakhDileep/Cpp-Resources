/*
Created by  : Vaisakh Dileep
Date        : 22, October, 2021
Description : Reinterpret_cast.
*/

#include<iostream>

using namespace std;

struct st
{
    long long int A;

    char B;

    int C;

    char D;
};

int main()
{
// Syntax: reinterpret_cast<new_type>(expression)

/*
Uses of reinterpret_cast:
1. It allows pointers to be converted into any other pointer type.
2. It allows integral type to be converted into any pointer type.
3. It allows pointer types to be converted to integral types.
*/

    int int_variable {65};

    int *int_variable_ptr {&int_variable};

    char *char_variable_ptr {reinterpret_cast<char*>(int_variable_ptr)};

    cout<<"*int_variable_ptr: "<<(*int_variable_ptr)<<"\n";

    cout<<"*char_variable_ptr: "<<(*char_variable_ptr)<<"\n"; // Here both "int_variable_ptr" and "char_variable_ptr" point to "int_variable"

    // For best results initialize "memory_location" with the address stored in "int_variable_ptr".
    uintptr_t memory_location {0x61fdf4}; // "uintptr_t" can hold any pointer that the operating system supports(it varies with the operating system so that we can safely hold the pointer value).

    int *int_pointer_to_memory_location {reinterpret_cast<int*>(memory_location)};

    char *char_pointer_to_memory_location {reinterpret_cast<char*>(memory_location)};

    cout<<"*int_pointer_to_memory_location: "<<(*int_pointer_to_memory_location)<<"\n";

    cout<<"*char_pointer_to_memory_location: "<<(*char_pointer_to_memory_location)<<"\n\n";

// reinterpret_cast vs pointer to constant values:
    const int *int_ptr_to_constant {&int_variable};

    // char *char_ptr_1 {reinterpret_cast<char*>(int_ptr_to_constant)}; // This will give an error since "reinterpret_cast" cannot work with pointer to constant values(the reinterpreted pointer can change the value of "constant_int_ptr").

    const char *char_ptr_2 {reinterpret_cast<const char*>(int_ptr_to_constant)}; // This will work since "reinterpret_cast" will reinterpret it to another pointer to constant values(values inside both the pointers cannot be changed).

// reinterpret_cast vs constant pointer:
    int *const constant_int_ptr {&int_variable}; // constant pointer.

    char *char_ptr_3 {reinterpret_cast<char*>(constant_int_ptr)}; // This will work, constant pointers can still be reinterpreted to other non-constant pointers.

    char *const char_ptr_4 {reinterpret_cast<char *const>(constant_int_ptr)}; // This will work, the reinterpreted pointers is also a constant pointer.

// Using reinterpret_cast to interate over struct elements. The below piece of code is implementation specific, it might not work for some os, make sure to comment it out.

    st st_object {7, 'Y', 9, 'Z'};

/*
For my os:
long long int -> 8 bytes
int           -> 4 bytes
char          -> 1 byte

struct st // In order to understand how structure padding works refer "Program138/main.cpp".
{
// current memory offset: 0
    long long int A; // since the memory offset(0) is a multiple of the size of long long int(8), we can place 'A' at 0.

// current memory offset: 8
    char B; // since the memory offset(8), is a multiple of the size of char(1), we can place 'B' at 8.

// current memory offset: 9
    char[3] pad_B; // We add padding here, so that we get the memory offset as a multiple of 4, so that we can place 'C' at 12.

// current memory offset: 12
    int C; // Since the memory offset(12) is a multiple of the size of int(4), we can place 'C' at 12.

// current memory offset: 16
    char D; // Since the memory offset(13) is a multiple of the size of char(1), we can place 'D' at 13.

// current memory offset: 17
    // The Largest data-type in "st" is long long long int(8), 17 is not a multiple of 8, therefore we need to add padding to make it a multiple of 8.
    char pad_D[7];

// current memory offset: 24

// size of "st" is 24.
}
*/

    cout<<(sizeof(st_object))<<"\n";

    cout<<"sizeof(st_object): "<<sizeof(st_object)<<"\n";

    st *st_object_ptr {&st_object};

    long long int *itr_to_find_A {reinterpret_cast<long long int*>(st_object_ptr)};

    cout<<"st_object.A: "<<(*itr_to_find_A)<<"\n";

    itr_to_find_A++; // We moved to offset 8.

    char *itr_to_find_B {reinterpret_cast<char*>(itr_to_find_A)};

    cout<<"st_object.B: "<<(*itr_to_find_B)<<"\n";

    itr_to_find_B += 4; // Inorder to iterate over the padding. We moved to offset 12.

    int *itr_to_find_C {reinterpret_cast<int*>(itr_to_find_B)};

    cout<<"st_object.C: "<<(*itr_to_find_C)<<"\n";

    itr_to_find_C++; // We moved to offset 16.

    char *itr_to_find_D {reinterpret_cast<char*>(itr_to_find_C)};

    cout<<"st_object.D: "<<(*itr_to_find_D)<<"\n";

    return 0;
}