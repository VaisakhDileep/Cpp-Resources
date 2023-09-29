/*
Created by  : Vaisakh Dileep
Date        : 19, January, 2021
Description : This program helps to understand constexpr in C++.
*/

#include<iostream>

using namespace std;

// constexpr is available post C++11.

// We use "constexpr" for performance improvement by doing the computations at the compile-time(compiling happens only once) rather than at the run-time(We can run the program multiple times).

/*
Rules for declaring constexpr functions:
1. constexpr functions should only have one return statement.
2. constexpr functions should refer only constant global variables.
3. constexpr functions should only call other constexpr functions not simple functions.
4. constexpr functions should not be of void type and some operators like(++s) are not allowed in constexpr functions.
*/

constexpr int constexpr_product(int x, int y)
{
    return (x * y);
}

/*
constexpr vs inline functions:
Inline functions request compiler to extend at run-time and saves time due to function call overheads, however expressions are always evaluated at run-time. constexpr functions are different, here expressions are evaluated at compile-time.
*/

int main()
{
    int number_1 {10}, number_2 {20};

    int constexpr number_3 {30}, number_4 {40};

    // int constexpr number_5; // Notice here we can't use uninitialized constexpr variables.

    // number_3 = 50; // We can't change the value of "number_3" since it is a constexpr variable.

    int result {};

    result = constexpr_product(number_1, number_2);
    cout<<"Result: "<<result<<"\n";

    result = constexpr_product(number_3, number_4);
    cout<<"Result: "<<result<<"\n";

    number_2 = 30;

    result = constexpr_product(number_1, number_2);
    cout<<"Result: "<<result<<"\n";

    result = constexpr_product(4, 6);
    cout<<"Result: "<<result<<"\n";

    cout<<"Enter any two numbers: ";
    cin>>number_1>>number_2;

    result = constexpr_product(number_1, number_2);
    cout<<"Result: "<<result<<"\n";

    return 0;
}