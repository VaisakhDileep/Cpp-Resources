/*
Created by  : Vaisakh Dileep
Date        : 23, December, 2020
Description : This program helps to understand scope rules in C++.
*/

#include<iostream>

using namespace std;

void local_function(int x);

void static_function();

int variable {0}; // This is a global variable as it is declared outside all classes and functions.

int main()
{
// Every identifier has a scope.

// Local or Block scope: They are the identifiers that are declared inside {}. Function parameters have block scope.

// Function local variables are only active while the function is executing, they are not preserved between function calls.
// An exception for it is using keyword static. egs--> static int value {10}; // Only initialized once when the first function call happens. Its values is preserved between function calls.

// Global scope: They are visible to all parts of the program after the global identifier has been declared.

    int variable {100};

    cout<<"'variable' inside main() function: "<<variable<<"\n";

    { // This creates a new level of scope.

        cout<<"'variable' inside the inner block of the main() function: "<<variable<<"\n"; // Inner block can access the outer block identifiers.

        int variable {200};

        cout<<"local instance of 'variable' inside the inner block of the main() function: "<<variable<<"\n"; // Inner block identifier overides the outer block identifer if they have the same name.
    }

    cout<<"'variable' inside main() function: "<<variable<<"\n"; // Changes made in the inner block won't be reflected in the outer block.

    local_function(16);

    static_function();
    static_function();
    static_function();
    static_function();

    return 0;
}

void local_function(int x)
{
    cout<<"'variable' inside local() function before creating: "<<variable<<"\n"; // This will print the global variant of 'local' variable.

    int variable {250}; // This is local to "local_function". It overides the global variant of "variable".

    cout<<"'variable' inside local() function: "<<variable<<"\n";

    variable = x;

    cout<<"'variable' inside local() function after assigning: "<<variable<<"\n";
}

void static_function()
{
    static int count {1}; // This is only initialized once during the first call.

    cout<<"This function has been called "<<count<<" times.\n";

    count++;
}