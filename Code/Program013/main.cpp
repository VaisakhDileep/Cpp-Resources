/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2020
Description : This program helps to understand for loops in C++
*/

#include<iostream>

#include<vector>

using namespace std;

int main()
{
/*
Syntax for "for loops":

for(initialization; condition; increment) // initialization is only done once.
    statement;

                ... or ...

for(initialization; condition; increment)
{
    statement(s);
}
*/

    for(int i {1}, j {5}; i <= 5; ++i, ++j)
    {
        cout<<i<<" * "<<j<<": "<<(i * j)<<"\n";
    }

    cout<<"\n";

/*
    for(;;)
        cout<<"Endless loop\n"; //--> This loop will repeat forever.
*/

    for(int i {1}; i <= 150; ++i)
    {
        cout<<"* "<<((i % 10 == 0) ? "\n" : "  ");
    }

    cout<<"\n";

    vector<int> first_5_even_numbers {0, 2, 4, 6, 8};

    cout<<"first_5_even_numbers: ";

    for(int i {0}; i < first_5_even_numbers.size(); ++i) // --> Notice here there is a warning telling that we should change "i" to unsigned(unsigned int i {}), size can never be negative.
    {
        cout<<first_5_even_numbers[i]<<" ";
    }

    cout<<"\n\n";

/*
Syntax for range-based for loops:

for(var_type var_name : sequence)
    statement;

        ... or ...

for(var_type var_name : sequence)
{
    statement(s);
}
*/

    int scores[] {100, 90, 97, 99, 89, 93};

    cout<<"scores: ";

    for(int score : scores) // We can replace it like "for(auto score : scores)", here auto will automatically fix the variable type according to the collection.
    {
        cout<<score<<" ";
    }

    cout<<"\n\n";

    for (auto c : "Vaisakh Dileep" ) // Here string is also a collection type.
        cout<<c<<" ";

    cout<<"\n\n";

    for (auto val : {1, 2, 3, 4, 5, 6, 7, 8, 9}) // Here {1, 2, 3, 4, 5, 6, 7, 8, 9} is also a collection.
        cout<<val<<" ";

    cout<<"\n\n";

    return 0;
}