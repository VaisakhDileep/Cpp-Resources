/*
Created by  : Vaisakh Dileep
Date        : 7, January, 2021
Description : This program helps to understand pointer to functions in C++.
*/

#include<iostream>

using namespace std;

void test() {
    cout << "Inside the test function .... \n";
}

void function1() {
    cout << "Inside Function 1 ... \n";
}

void function2(void(*function_ptr)()) {
    function_ptr();
}

int add(int, int);

void swap(int*, int*);

int main() {
// Function pointers: Function pointers are used to point to functions. It basically stores the address of the function. They are mainly used for event-driven applications, callbacks, and even for storing functions in arrays.

/*
Syntax for declaring function pointers:
    return_type (*func_ptr) (parameter_1_type, parameter_2_type); // This function pointers can point to any function that takes two parameters(of type "parameter_1_type" and "parameter_2_type") and returns a value(of type "return_type").
*/

    printf("Address of the main(): %p\n", main); // Function name corresponds to the memory address of the function. In order to get the result we need to use the "printf()" function.
    printf("Address of the main(): %#x\n", main); // The above result is same as this, so the result is in hexadecimal format.
    printf("Address of the main(): %p\n\n", &main); // We could also use the &(address of) operator before the function name.
    printf("Address of test(): %#x\n\n", test);

    int(*fun_add_ptr)(int, int); // Declaring the function pointer.

    fun_add_ptr = add; // "fun_add_ptr" is pointing to the "add" function.

    printf("Address of add(): %#x\n\n", add);
    printf("Address stored in fun_add_ptr: %#x\n\n", fun_add_ptr);

    int sum = fun_add_ptr(3, 2);

    cout << "sum: " << sum << "\n\n";

    void(*fun_swap_ptr)(int*, int*); // Declaring the function pointer.

    fun_swap_ptr = swap; // "fun_swap_ptr" is pointing to the "swap" function.

    int x {10}, y {20};

    cout << "x: " << x << "\ty: " << y << "\n";
    fun_swap_ptr(&x, &y);
    cout << "x: " << x << "\ty: " << y << "\n\n";

/*
Passing functions as arguments: We can pass function as arguments using function pointers.
    return_type fun(return_type(*func_ptr)()) {
        // ...
    }

    int main() {
        func(function_name);
        // ...
    }
*/
    function2(function1);

    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}

void swap(int *num1, int *num2) {
    int temp {*num1};

    *num1 = *num2;
    *num2 = temp;
}