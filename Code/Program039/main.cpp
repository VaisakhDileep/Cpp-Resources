/*
Created by  : Vaisakh Dileep
Date        : 26, December, 2020
Description : Pass pointer to a function.
*/

#include<iostream>

#include<vector>

#include<string>

using namespace std;

void double_data(int *int_ptr);

void swap(int *x, int *y);

void display_vector(const vector<string> *v); // "const" prevents the vector from being modified.

void display_array(const int *array, int sentinel); // "const" prevents the array from being modified.

int main()
{
    int value {10};

    int *int_ptr {nullptr};

    cout<<"Value: "<<value<<"\n";

    double_data(&value);

    cout<<"Value: "<<value<<"\n";

    int_ptr = &value;

    double_data(int_ptr);

    cout<<"Value: "<<value<<"\n\n";

    int x {100}, y {200};

    cout<<"x: "<<x<<"\t y: "<<y<<"\n";

    swap(&x, &y);

    cout<<"x: "<<x<<"\t y: "<<y<<"\n\n";

    vector<string> simpson_family {"Homer Simpson", "Marge Bouvier", "Lisa Simpson", "Bart Simpson", "Maggie Simpson"};

    display_vector(&simpson_family);

    int scores[] {100, 90, 97, 98, 92, -1}; // Here -1 is like a sentinel(end of the array).

    display_array(scores, -1); // Name of the array represents the address of the first element of the array.

    return 0;
}

void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

void display_vector(const vector<string> *v)
{
    for(auto str : *v)
    {
        cout<<str<<"\t";
    }

    cout<<"\n";
}

void display_array(const int *array, int sentinel)
{
    while(*array != sentinel)
    {
        cout<<*array++<<" "; // This will point to next element('*' and '++' have the same precedence but associativity is from right to left.).
    }
    cout<<"\n\n";
}