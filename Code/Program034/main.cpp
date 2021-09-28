/*
Created by  : Vaisakh Dileep
Date        : 25, December, 2020
Description : This program helps to understand pointers in C++.
*/

#include<iostream>

#include<string>

#include<vector>

using namespace std;

int main()
{
// A pointers is a variable whose value is an address and this address can be of another variable or a function.

/*
Syntax for declaring a pointer:

variable_type *pointer_name;
        ... or ...
variable_type* pointer_name;
*/

/*
    int *int_ptr;

    double *double_ptr;

    char *char_ptr;

    string *string_ptr; // Here the above pointers point to some random place and can be dangerous.
*/

// Syntax for initializing a pointer to point to nowhere: variable_type *pointer_name {nullptr};

    int *int_ptr {nullptr};

    double *double_ptr {nullptr};

    char *char_ptr {nullptr};

    string *string_ptr {nullptr}; // Here it will point to nowhere. "nullptr" is introduced in c++11.

    vector<string> *vector_string_ptr {nullptr};

    unsigned long long *unsigned_long_long_ptr {nullptr};

// Caution : Always initialize pointers.

// Address Operator (&): It is an unary operator and it evaluates to the address of the operand.

    int target {10};

    cout<<"Value of target  : "<<target<<"\n";
    cout<<"Size of target   : "<<sizeof target<<"\n";
    cout<<"Address of target: "<<&target<<"\n\n";

    int *p; // Here read from right to left --> "p" points to "int".

    cout<<"Value of p  : "<<p<<"\n"; // Here it points to some random location.
    cout<<"Address of p: "<<&p<<"\n"; // Pointers also have addresses, just like variables.
    cout<<"Size of p   : "<<sizeof p<<"\n\n"; // Here the size of the pointer is the size of addresses in the system.

    p = nullptr; // Here "p" points to nowhere.

    cout<<"Value of p after initializing: "<<p<<"\n\n"; // Here it points to nowhere, ie. '0'.

    cout<<"Size of integer pointer           : "<<sizeof int_ptr<<"\n";
    cout<<"Size of double pointer            : "<<sizeof double_ptr<<"\n";
    cout<<"Size of character pointer         : "<<sizeof char_ptr<<"\n";
    cout<<"Size of string pointer            : "<<sizeof string_ptr<<"\n";
    cout<<"Size of vector pointer            : "<<sizeof vector_string_ptr<<"\n";
    cout<<"Size of unsigned long long pointer: "<<sizeof unsigned_long_long_ptr<<"\n\n"; // All are of same size.

// Dereferencing a pointer(*) :
    int score {100};

    int *score_ptr {&score};

    cout<<"Score variable has a value                  : "<<score<<"\n";
    cout<<"Score pointer points to a variable of value : "<<*score_ptr<<"\n\n";

    *score_ptr = 200;

    cout<<"Score variable has a value                 : "<<score<<"\n";
    cout<<"Score pointer points to a variable of value: "<<*score_ptr<<"\n\n";

    score = 300;

    cout<<"Score variable has a value                 : "<<score<<"\n";
    cout<<"Score pointer points to a variable of value: "<<*score_ptr<<"\n\n";

    vector<string> simpson_family = {"Homer J Simpson", "Bart Simpson", "Lisa Simpson", "Marge Bouvier", "Maggie Simpson"};

    vector<string> *simpson_family_ptr {&simpson_family};

    cout<<"The Simpson Family: \n";

    for(int i {0}; i < (*simpson_family_ptr).size(); i++) // Here '.' operator has higher precedence than '*' operator so make sure to use parenthesis.
    {
        cout<<(i + 1)<<". "<<(*simpson_family_ptr).at(i)<<"\n";
    }

    return 0;
}