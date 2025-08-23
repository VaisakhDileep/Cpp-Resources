/*
Created by  : Vaisakh Dileep
Date        : 7, June, 2021
Description : Union.
*/

#include<iostream>

using namespace std;

union Value
{
    char character;

    int ascii_value;
};

int main()
{
// Unions: Unions are a user-defined data type. All members of the union share the same memory location. Size of the union is the size of the largest data element.

    Value val_1 {'a'};

    cout<<"val_1: \n";
    cout<<"character: "<<val_1.character<<"\n";
    cout<<"ascii_value: "<<val_1.ascii_value<<"\n\n"; // See here we can simultaneously get the ascii value and ascii representation of the character.

    cout<<"sizeof val_1: "<<sizeof val_1<<"\n"; // Size of the union will be the size of "int", which is the largest data type in the union.
    cout<<"sizeof val_1.character: "<<sizeof val_1.character<<"\n";
    cout<<"sizeof val_1.ascii_value: "<<sizeof val_1.ascii_value<<"\n";

    return 0;
}