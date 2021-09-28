/*
Created by  : Vaisakh Dileep
Date        : 17, September, 2021
Description : This program helps to understand lambda expressions in C++.
*/

#include<iostream>

using namespace std;

/*
Syntax for lambda expressions:
    []() mutable noexcept -> data_type {}

    []: Capture clause. It will capture variables from the surrounding scope.
    (): Parameter list(optional).
    mutable: Specifier(optional).
    noexcept: Exception specification, make sure to add parameter list when using noexcept(Optional).
    -> data_type: Return type(optional).
    {}: Lambda body.
*/

int main()
{
    auto hello_world_lambda_1 {[]() {cout<<"Hello World!\n";}};

    hello_world_lambda_1();

    string text {"Hello World!\n"};

    auto hello_world_lambda_2 {[text]() {cout<<text; /*text = "";*/}}; // Notice here that trying to change "text" will result in an error.

    hello_world_lambda_2();

    auto hello_world_lambda_3 {[&text]() {cout<<text; text = "";}}; // Here we are passing "text" as a reference, so we can change it.

    hello_world_lambda_3();
    cout<<"\n";

    string first_name {"Blake"}, last_name {"Langermann"};

    auto print_name_lambda_1 {[=]() {cout<<first_name<<" "<<last_name<<"\n";}}; // Here '=' in the capture clause will collect all the variables from the surrounding scope.

    cout<<"print_name_lambda_1: ";
    print_name_lambda_1();

    auto print_name_lambda_2 {[&]() {first_name = "Jessica"; last_name = "Gray"; cout<<first_name<<" "<<last_name<<"\n";}}; // Here '&' in the capture clause will collect all the variables from the surrounding scope as reference.

    cout<<"print_name_lambda_2: ";
    print_name_lambda_2();

    auto print_name_lambda_3 {[&, first_name]() {/*first_name = ""*/; last_name = "Langermann"; cout<<first_name<<" "<<last_name<<"\n";}}; // Here all the variables in the surrounding scope except "first_name" is passed by reference. "first_name" is passed by copy.

    cout<<"print_name_lambda_3: ";
    print_name_lambda_3();

    auto print_name_lambda_4 {[=, &last_name]() {/*first_name = ""*/; last_name = "Gray"; cout<<first_name<<" "<<last_name<<"\n";}}; // Here all the variables in the surrounding scope except "last_name" is passed by copy. "last_name" is passed by reference.

    cout<<"print_name_lambda_4: ";
    print_name_lambda_4();

    auto print_name_lambda_5 {[=]() mutable {first_name = "Sullivan"; last_name = "Knoth"; cout<<first_name<<" "<<last_name<<"\n";}}; // Using "mutable", we can change the copied values inside the lambda expression, however they won't be reflected outside the lambda expression.

    cout<<"print_name_lambda_5: ";
    print_name_lambda_5();
    cout<<"\n";

    cout<<"First Name: "<<first_name<<"\n"; // Notice the variables remain unaltered.
    cout<<"Last Name: "<<last_name<<"\n\n";

    auto sum_lambda_1 {[](int num1, int num2) {cout<<"sum_lambda_1: "<<(num1 + num2)<<"\n";}}; // We can pass arguments to the lambda expression.

    sum_lambda_1(2, 5);

    auto sum_lambda_2 {[](int num1, int num2) -> int {return num1 + num2;}}; // No need to include "-> int" if the return type is obvious.

    cout<<"sum_lambda_2: "<<sum_lambda_2(10, 20)<<"\n\n";

    auto divide_lambda {[](int num1, int num2) -> double {if(num2 == 0) {throw string {"ERROR"};} return double(num1) / num2;}};

    // cout<<"divide_lambda(10, 0): "<<divide_lambda(10, 0)<<"\n"; // This will generate an exception.

    cout<<"divide_lambda(10, 3): "<<divide_lambda(10, 3)<<"\n\n";

    auto multiply_lambda {[](int num1, int num2) noexcept -> int {return num1 * num2;}}; // We can use "noexcept", if the lambda expression does not create an exception or contains some function that might call an exception. We can use "noexcept()" to detect it later.

    cout<<"multiply_lambda(10, 22): "<<multiply_lambda(10, 22)<<"\n\n";

    int i {0};

    [&]() {i=100;}(); // We can create a lambda expression like this too, it will run only if we include "()" at the end.

    cout<<"i: "<<i<<"\n";

    return 0;
}