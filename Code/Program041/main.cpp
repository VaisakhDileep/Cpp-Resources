/*
Created by  : Vaisakh Dileep
Date        : 26, December, 2020
Description : Reference.
*/

#include<iostream>

#include<vector>

#include<string>

using namespace std;

class const_ref_class
{
    const int &ref; // Including a constant l-value reference, might cause some strange behaviour(we cannot create an object until we overload the default constructor).

public:
    const_ref_class(int num)
        : ref {num} // We need to provide the value of "ref" in the initialization list.
    {
    }
};

int main()
{
// Reference : It is an alias for a variable. It must be initialized to a variable when declared. It cannot be null. Once initialized it cannot be made to refer to a different variable. It can be thought of as a constant pointer that is automatically dereferenced.

    int number {100};

    int &ref_1 {number};

    cout<<"number             : "<<number<<"\n";
    cout<<"Reference to number: "<<ref_1<<"\n\n";

    number = 200;

    cout<<"number             : "<<number<<"\n";
    cout<<"Reference to number: "<<ref_1<<"\n\n";

    ref_1 = 300;

    cout<<"number             : "<<number<<"\n";
    cout<<"Reference to number: "<<ref_1<<"\n\n";

    vector<string> simpson_family = {"Homer Simpson", "Lisa Simpson", "Bart Simpson", "Maggie Simpson", "Marge Bouvier"};

    cout<<"simpson_family[Before]: ";
    for(auto character : simpson_family)
    {
        cout<<character<<"    ";
    }
    cout<<"\n";

/*
    for(auto characters : simpson_family) // Here characters are passed as copies and changing this won't change simpson_family.
    {
        characters = " ";
    }
*/

    for(auto &characters : simpson_family) // This will work because here it is passed by reference.
    {
        characters = " ";
    }

    cout<<"simpson_family[After]: ";
    for(auto characters : simpson_family) // We can also use "for(auto const &characters : simpson_family)".
    {
        cout<<characters<<" _ ";
    }
    cout<<"\n\n";

    // int &ref_2 {10}; // This will given an error. L-value references can only point to l-values.

    const int &ref_3 {10}; // This is possible only for const l-value references.

    const_ref_class ref_object {10}; // Object containing a const l-value reference.

    const int &ref_4 {number};

    cout<<"number                      : "<<number<<"\n";
    cout<<"constant reference to number: "<<ref_4<<"\n\n";

    // ref_4 = 500; // This will give an error since it is a constant reference.

    number = 500; // This is Ok.

    cout<<"number                      : "<<number<<"\n";
    cout<<"constant reference to number: "<<ref_4<<"\n";

    return 0;
}