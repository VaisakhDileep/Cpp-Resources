/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2020
Description : This program helps to understand enumerations(enum) in C++.
*/

#include<iostream>

using namespace std;

int main()
{
// Enumeration is a user-defined data type that is used to assign names to integer constants. It makes the program easy to read and maintain.

    enum season {spring, summer, autumn, winter}; // By default spring = 0, summer = 1, autumn = 2, winter = 3.

    // int spring = 1; // This will give an error we cannot redeclare any enumerated integer constants.
// Here season is just a blueprint.

    season s {}; // Here "s" is a variable of enumerated type.

    s = spring;
    cout<<"s{spring}: "<<s<<"\n";

    s = season::summer; // This is also valid.
    cout<<"s{summer}: "<<s<<"\n";

    s = autumn;
    cout<<"s{autumn}: "<<s<<"\n";

    s = winter;
    cout<<"s{winter}: "<<s<<"\n\n";

// We can also assign custom values to enumeration types.
    enum colors {violet, indigo, blue = 5, green, yellow, orange, red = 1}; // Here violet = 0 (default), indigo = 1 (default), blue = 5 (user-defined), green = 6 (default), yellow = 7 (default), orange = 8 (default), red = 1 (user-defined).

    colors rainbow {};

    rainbow = violet;
    cout<<"rainbow{violet}: "<<rainbow<<"\n";

    rainbow = indigo;
    cout<<"rainbow{indigo}: "<<rainbow<<"\n";

    rainbow = blue;
    cout<<"rainbow{blue}  : "<<rainbow<<"\n";

    rainbow = green;
    cout<<"rainbow{green} : "<<rainbow<<"\n";

    rainbow = yellow;
    cout<<"rainbow{yellow}: "<<rainbow<<"\n";

    rainbow = orange;
    cout<<"rainbow{orange}: "<<rainbow<<"\n";

    rainbow = red;
    cout<<"rainbow{red}   : "<<rainbow<<"\n";

    return 0;
}