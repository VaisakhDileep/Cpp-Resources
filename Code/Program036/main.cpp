/*
Created by  : Vaisakh Dileep
Date        : 25, December, 2020
Description : This program helps to understand the relationship between arrays and pointers in C++.
*/

#include<iostream>

using namespace std;

int main()
{
// The value of the array name is the address of the first element in the array and the value of the pointer variable is an address. Therefore if the pointer points to the same datatypes as the array element then the pointer and array name can be used interchangeably(almost).

    int scores[] {100, 94, 98};

    cout<<"scores : "<<scores<<"\n";
    cout<<"*scores: "<<*scores<<"\n\n";

    cout<<"scores[0]: "<<scores[0]<<"\n"; // We can use the subscript operator to access the array elements.
    cout<<"scores[1]: "<<scores[1]<<"\n";
    cout<<"scores[2]: "<<scores[2]<<"\n\n";

    cout<<"*(scores + 0): "<<*(scores + 0)<<"\n"; // We can use pointer arithemetics to access the array elements.
    cout<<"*(scores + 1): "<<*(scores + 1)<<"\n";
    cout<<"*(scores + 2): "<<*(scores + 2)<<"\n\n";

/*
        Subscript Notation              Offset Notation
        array_name[index]   ------> *(array_name + index)
        pointer_name[index] ------> *(pointer_name + index)
*/

    int *scores_ptr {scores};

    cout<<"scores_ptr : "<<scores_ptr<<"\n";
    cout<<"*scores_ptr: "<<*scores_ptr<<"\n\n";

    cout<<"scores_ptr[0]: "<<scores_ptr[0]<<"\n"; // We can use the subscript operator to access the array elements.
    cout<<"scores_ptr[1]: "<<scores_ptr[1]<<"\n";
    cout<<"scores_ptr[2]: "<<scores_ptr[2]<<"\n\n";

    cout<<"*(scores_ptr + 0): "<<*(scores_ptr + 0)<<"\n"; // We can use pointer arithemetics to access the array elements.
    cout<<"*(scores_ptr + 1): "<<*(scores_ptr + 1)<<"\n";
    cout<<"*(scores_ptr + 2): "<<*(scores_ptr + 2)<<"\n\n";

    return 0;
}