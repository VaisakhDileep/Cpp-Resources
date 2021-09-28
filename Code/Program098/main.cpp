/*
Created by  : Vaisakh Dileep
Date        : 5, February, 2021
Description : This program helps to understand generic programming using Macros in C++.
*/

#include<iostream>

#define MAX(a, b) ((a > b) ? (a) : (b)) // This is an example of generic programming using macros(make sure to enclose everything by parenthesis, otherwise it may not give the desired output).

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

char max(char a, char b)
{
    return (a > b) ? a : b;
} // As you can see here this method is tedious and will waste a lot of time.

int main()
{
/*
Generic Programming: Writing code that works with a variety of types as argument, as long as those argument types meet specific syntactic and semantic requirements.

Generic Programming can be achieved by: Macros[not recommended], Function templates, Class Templates.
*/

/*
Macros are C++ preprocessor directives. They have no type information specified. They follow simple substitution.

Consider the following block of code:

Before compiling:
#define MAX_SIZE 100
#define PI 3.14159

if(num > MAX_SIZE)
{
    std::cout<<"Too Big";
}

double area = PI * r * r;

After compiling :
// #define Max_SIZE 100 // Removed
// #define PI 3.14159 // Removed

if(num > 100)
{
    std::cout<<"Too Big";
}

double area = 3.14159 * r * r;
*/
    cout<<"max(10, 20)  : "<<max(10, 20)<<"\n";
    cout<<"max(1.2, 1.8): "<<max(1.2, 1.8)<<"\n";
    cout<<"max('A', 'D'): "<<max('A', 'D')<<"\n\n";

    cout<<"MAX(10, 20)  : "<<MAX(10, 20)<<"\n";
    cout<<"MAX(1.2, 1.8): "<<MAX(1.2, 1.8)<<"\n";
    cout<<"MAX('A', 'D'): "<<MAX('A', 'D')<<"\n\n";

    return 0;
}