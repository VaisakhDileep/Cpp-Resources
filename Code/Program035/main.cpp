/*
Created by  : Vaisakh Dileep
Date        : 25, December, 2020
Description : This program helps to understand dynamic memory allocation in C++.
*/

#include<iostream>

using namespace std;

int main()
{
    int *int_ptr {nullptr};

    int_ptr = new int; // This allocates an integer in the heap.

    *int_ptr = 0; // This will assign '0' to the newly created integer in the heap, otherwise it contains some garbage data.

    cout<<"value pointed by int_ptr: "<<*int_ptr<<"\n";

    delete int_ptr; // This deallocates memory so that it can be used later, otherwise it will cause memory leak.

// Using new[], we can allocate storage for an array.
    int *array_int_ptr {nullptr};

    size_t size {};

    cout<<"How big do you want the array to be: ";

    cin>>size;

    array_int_ptr = new int[size]; // This allocates memory(contiguously) for an array in the heap.

    for(int i = 0; i < size; ++i)
    {
        array_int_ptr[i] = 0; // This will assign '0' to the newly created integer in the heap, otherwise it contains some garbage data in it.
                            // Notice here we didn't use '*' for dereferencing because array name represents the address of the first element in the array which is "array_int_ptr".
    }

    cout<<"Value pointed by array_int_ptr: \n";

    for(int i = 0; i < size; ++i)
    {
        cout<<(i + 1)<<" ."<<*(array_int_ptr + 1)<<"\n";
    }

    delete[] array_int_ptr; // This deallocates memory so that it can be used later.

// The below piece of code will generate an exception because we have run out of heap memory, so we need to use delete to deallocated memory otherwise it will result in memory leak.
/*
    while(true)
    {
        array_int_ptr = new int[size];
    }
*/

    return 0;
}