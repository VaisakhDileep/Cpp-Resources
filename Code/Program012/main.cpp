/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2020
Description : This program helps to understand conditional operator(?:) in C++.
*/

#include<iostream>

using namespace std;

int main()
{

/*
Syntax for Conditional Operator:
    (cond_expr) ? expr1 : expr2; --> if "cond_expr" is true then value of "expr1" is returned, if "cond_expr" is false then value of "expr2" is returned.
*/
    int a {20}, b {10}, score {93}, result {};

    result = (a > b) ? a : b;

    cout<<"(a > b) ? a : b --> "<<result<<"\n";

    result = (a < b) ? (b - a) : (a - b);

    cout<<"(a < b) ? (b - a) : (a - b) --> "<<result<<"\n";

    result = (b != 0) ? (a / b) : 0;

    cout<<"(b != 0) ? (a / b) : 0 --> "<<result<<"\n";

    cout<<((score > 90) ? "Excellent\n" : "Good\n"); // Always enclose conditional operator with parenthesis when printing.

// Odd or Even: This program checks if a number is odd or even.
    int num {};

    cout<<"Enter any number you wish: ";

    cin>> num;

    cout<<num<<" is "<<((num % 2 == 0) ? "EVEN.\n" : "ODD.\n");

// Largest and Smallest: This program finds the largest and smallest number.
    int number_1 {}, number_2 {};

    cout<<"Enter two numbers seperated by spaces: ";

    cin>>number_1>>number_2;

    if (number_1 != number_2)
    {
        cout<<"LARGEST : "<<((number_1 > number_2) ? number_1 : number_2)<<"\n";

        cout<<"SMALLEST: "<<((number_1 < number_2) ? number_1 : number_2)<<"\n";
    }
    else
    {
        cout<<"The numbers you have entered are same.\n";
    }

    return 0;
}