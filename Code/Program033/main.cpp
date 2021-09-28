/*
Created by  : Vaisakh Dileep
Date        : 24, December, 2020
Description : This program helps to understand recursive functions in C++.
*/

#include<iostream>

#include<vector>

#include<cctype>

using namespace std;

unsigned long long factorial(unsigned long long num)
{
    if (num == 0)
    {
        return 1; // Base case
    }

    return num * factorial(num - 1); // Recursive case
}

unsigned long long fibonacci(unsigned long long num)
{
    if (num <= 1)
    {
        return num; // Base case
    }

    return fibonacci(num - 1) + fibonacci(num - 2); // Recursive case
}

void display_menu();
char get_selection();

void handle_display(const vector<int> &v);
void display_vector(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
double calculate_mean(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_smallest(const vector<int> &v);

void handle_quit();
void handle_unknown();

int main()
{
// Definition for factorial 0! = 1 (Base case) and n! = n * (n-1)! (Recursive case).
    cout<<"factorial(8): "<<factorial(8)<<"\n";

// Definition for Fibonacci series Fib(0) = 0, Fib(1) = 1 (Base case) and Fib(n) = Fib(n - 1) + Fib(n - 2) (Recursive case).
    cout<<"fibonacci(30): "<<fibonacci(30)<<"\n";

// Recursive functions are resource intensive. Anything that can be done recursively can be done iteratively.

// Functions, Menus, Vectors, Largest, Smallest and Mean.
    vector<int> numbers;

    char selection {};

    do
    {
        display_menu();

        selection = get_selection();

        switch (selection)
        {
            case 'P':
                    handle_display(numbers);

                    break;

            case 'A':
                    handle_add(numbers);

                    break;

            case 'M':
                    handle_mean(numbers);

                    break;

            case 'S':
                    handle_smallest(numbers);

                    break;

            case 'L':
                    handle_largest(numbers);

                    break;

            case 'Q':
                    handle_quit();

                    break;

            default:
                    handle_unknown();
        }
    }while(selection != 'Q');

    cout<<"\n";

    return 0;
}

void display_menu()
{
    cout<<"\n";

    cout<<"P - Print numbers.\n";
    cout<<"A - Add a number.\n";
    cout<<"M - Displays mean of the numbers.\n";
    cout<<"S - Displays the smallest number.\n";
    cout<<"L - Displays the largest number.\n";
    cout<<"Q - Quit.\n";

    cout<<"Enter your choice: ";
}

char get_selection()
{
    char selection {};

    cin>>selection;

    return toupper(selection);
}

void handle_display(const vector<int> &v)
{
    if(v.size() == 0)
    {
        cout<<"[]-the list is empty.\n";
    }
    else
    {
        display_vector(v);
    }
}

void display_vector(const vector<int> &v)
{
    cout<<"[ ";

    for(auto number : v)
    {
        cout<<number<<" ";
    }

    cout<<"]\n";
}

void handle_add(vector<int> &v)
{
    int number_to_add {};

    cout<<"Enter an integer to add to the vector: ";

    cin>>number_to_add;

    v.push_back(number_to_add);

    cout<<number_to_add<<" added successfully.\n"; 
}

void handle_mean(const vector<int> &v)
{
    if(v.size() == 0)
    {
        cout<<"Unable to calculate mean - vector is empty.\n";
    }
    else
    {
        cout<<"The mean is "<<calculate_mean(v)<<".\n";
    }
}

double calculate_mean(const vector<int> &v)
{
    int total {};

    for(auto number : v)
    {
        total += number;
    }

    return static_cast<double> (total) / v.size();
}

void handle_smallest(const vector<int> &v)
{
    if(v.size() != 0)
    {
        int smallest = v.at(0);

        for(auto number : v)
        {
            if(smallest > number)
            {
                smallest = number;
            }
        }

        cout<<"The smallest element in the vector is "<<smallest<<".\n";
    }
    else
    {
        cout<<"Unable to find the smallest element in the vector - vector is empty.\n";
    }
}

void handle_largest(const vector<int> &v)
{
    if(v.size() != 0)
    {
        int largest = v.at(0);

        for(auto number:v)
        {
            if(largest < number)
            {
                largest = number;
            }
        }

        cout<<"The largest element in the vector is "<<largest<<".\n";
    }
    else
    {
        cout<<"Unable to find the largest element in the vector - vector is empty.\n";
    }
}

void handle_quit()
{
    cout<<"Goodbye ... \n";
}

void handle_unknown()
{
    cout<<"Unknown option ... \n";
}