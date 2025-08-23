/*
Created by  : Vaisakh Dileep
Date        : 24, December, 2020
Description : Inline function.
*/

#include<iostream>

using namespace std;

inline int add_numbers(int a, int b) // Even if you don't provide inline keyword, compilers are smart enough to do it for you.
{
    return a + b;
}

int main()
{
// Function calls have a certain amount of overhead. using "inline", we can avoid function call overhead, it will generate inline assembly code, it is faster.

    int result {0};

    result = add_numbers(100, 200);

    cout<<"Result: "<<result<<"\n";

    return 0;
}