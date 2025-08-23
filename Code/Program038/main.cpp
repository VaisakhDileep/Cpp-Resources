/*
Created by  : Vaisakh Dileep
Date        : 26, December, 2020
Description : Constant pointer, pointer to constant and constant pointer to constant.
*/

#include<iostream>

using namespace std;

int main()
{
/*
There are:
1. Pointers to constants.
2. Constant pointers.
3. Constant pointers to constants.
*/

    int max_limit {100}, min_limit {10};

    const int *ptr_to_constant_1 {&max_limit}; // Pointer to constants

    // *ptr_to_constant_1 = 90; // This will give an error because the variable that is being pointed by the constant pointer can't be changed.

    ptr_to_constant_1 = &min_limit; // This will work.

    int *const constant_ptr_1 {&max_limit}; // Constant pointer

    *constant_ptr_1 = 90; // This will work.

    // constant_ptr_1 = &min_limit; // This will give an error.

    const int *const constant_ptr_to_constant_1 {&max_limit}; // Constant pointer to constants

    // *constant_ptr_to_constant_1 = 90; // This will give an error.

    // constant_ptr_to_constant_1 = &min_limit; // This will give an error.

// When the pointer is actually pointing to a constant object.
    int const const_int_variable {1};

    // int *regular_ptr {&const_int_variable}; // This will give an error since this pointer can change the value of "const_int_variable".

    const int *ptr_to_constant_2 {&const_int_variable}; // This is valid, since pointer to constants can't change the value being pointed to.

    // *ptr_to_constant_2 = 2; // pointer to constants will prevent this from happening.

    // int *const constant_ptr_2 {&const_int_variable}; // This will give an error since this pointer can change the value of "const_int_variable".

    const int *const constant_ptr_to_constant_2 {&const_int_variable}; // This is valid, since constant pointer to constants can't change the value being pointed to.

    return 0;
}