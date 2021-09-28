/*
Created by  : Vaisakh Dileep
Date        : 16, December, 2020
Description : This program helps to understand arrays in C++.
*/

#include<iostream>

using namespace std;

int main()
{
// Arrays: All elements in the array must be of the same type, they are stored contiguously(sequentially) in memory. First element in the array is indexed as '0'.

/*
Syntax for Array declaration:
    DataType array_name[constant number of elements];
*/

    int test_scores[10];

    const int days_in_year {365};

    double peak_temperatures[days_in_year];

// There are many ways to initialize an array.
    int test1[5] {0}; // Initializes '0' for all the elements in the array or just use {}.

    int test2[5] {1, 2}; // Initializes '1' for the first element, '2' for the second element and '0' for all the other elements.

    int test3[5] {1, 2, 3, 4, 5}; // All elements are initialized here.

    int test4[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Here compiler automatically computes the size of the array based on the initialization list.

/*
Syntax for accessing an element in an array:
    array_name[element_index]
*/

    cout<<"test1: ";

    for(int i {0}; i < 5; i++)
    {
        cout<<test1[i]<<" ";
    }

    cout<<"\n";

    cout<<"test2: ";

    for(int i {0}; i < 5; i++)
    {
        cout<<test2[i]<<" ";
    }

    cout<<"\n";

    cout<<"test3: ";

    for(int i {0}; i < 5; i++)
    {
        cout<<test3[i]<<" ";
    }

    cout<<"\n";

    cout<<"test4: ";

    for(int i {0}; i < 10; i++)
    {
        cout<<test4[i]<<" ";
    }

    cout<<"\n\n";

    cout<<"test1[20]: "<<test1[20]<<"\n\n"; // C++ arrays don't have bound checking, so it will give some random number.

// Name of the array represents the location(address) of the first element of the array.

/*
Syntax for 2-D Array declaration:
    DataType array_name[dim1_size][dim2_size];
*/

    const int rows {3}, columns {4};

    int two_dim_array[rows][columns]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2}};

    cout<<"two_dim_array: \n";

    for(int i {0}; i < rows; i++)
    {
        for(int j {0}; j < columns; j++)
        {
            cout<<two_dim_array[i][j]<<" ";
        }

        cout<<"\n";
    }

    return 0;
}