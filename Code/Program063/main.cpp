/*
Created by  : Vaisakh Dileep
Date        : 7, January, 2021
Description : This program helps to understand pointer to functions in C++.
*/

#include<iostream>

using namespace std;

void empty()
{
    cout<<"Inside the empty function .... \n";
}

void function1()
{
    cout<<"Inside Function 1 ... \n";
}

void function2(void(*function_ptr)())
{
    function_ptr();
}

int add(int, int);

void swap(int*, int*);

int main()
{
// Function pointers: Function pointers are used to point to functions. It basically stores the address of the function. They are mainly used for event-driven applications, callbacks, and even for storing functions in arrays.

/*
Syntax for declaring function pointers:
    Return_Type(*FuncPtr)(Parameter_1_Type, Parameter_2_Type); // --> This function pointers can point to any function that takes two parameters(of type "Parameter_1_Type" and "Parameter_2_Type") and returns a value(of type "Return_Type").
*/

    cout<<"Address of the main function: "<<main<<"\n"; // Function name corresponds to the memory address of the function.
    cout<<"Address of the main function: "<<&main<<"\n\n"; // Or we could use &(address of) operator.

    cout<<"Address of empty function: "<<&empty<<"\n\n";

    int(*fun_add_ptr)(int, int); // Declaring the function pointer.

    fun_add_ptr = add; // "fun_add_ptr" is pointing to the "add" function.

    cout<<"Address of add function: "<<&add<<"\n\n";

    cout<<"Address stored in fun_add_ptr: "<<fun_add_ptr<<"\n\n";

    int sum = fun_add_ptr(3, 2);

    cout<<"sum: "<<sum<<"\n\n";

    void(*fun_swap_ptr)(int*, int*); // Declaring the function pointer.

    fun_swap_ptr = swap; // "fun_swap_ptr" is pointing to the "swap" function.

    int x {10}, y {20};

    cout<<"x: "<<x<<"\ty: "<<y<<"\n";

    fun_swap_ptr(&x, &y);

    cout<<"x: "<<x<<"\ty: "<<y<<"\n";

/*
Passing functions as arguments: We can pass function as arguments using function pointers.
    Return_Type fun1(Return_Type(*FuncPtr)())
    {
        // ...
    }

    int main()
    {
        func1(function_name);

        // ...
    }
*/
    function2(function1);

    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}

void swap(int *num1, int *num2)
{
    int temp {*num1};

    *num1 = *num2;
    *num2 = temp;
}