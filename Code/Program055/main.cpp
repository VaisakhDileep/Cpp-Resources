/*
Created by  : Vaisakh Dileep
Date        : 1, January, 2021
Description : This program helps to understand deep copying in C++.
*/

#include<iostream>

using namespace std;

class Deep
{
private:
    int *data; // raw pointer
public:
    Deep(int deep_data); // Constructor

    Deep(const Deep &source); // Copy Constructor

    ~Deep(); // Destructor

    void set_data(int deep_data); // Setters

    int get_data(); // Getters
};

Deep::Deep(int deep_data)
{
    data = new int;

    *data = deep_data;
}

/*
Deep::Deep(const Deep &source) // This is how we do deep copy.
{
    data = new int;

    *data = *source.data; // --> *source.data <=> *(source.data)

    cout<<"Copy constructor called.\n";
}
*/

Deep::Deep(const Deep &source)
    :Deep(*source.data) // We can use constructor delegation.
{
    cout<<"Copy constructor called.\n";
}

Deep::~Deep()
{
    delete data;

    cout<<"Destructor called.\n";
}

void Deep::set_data(int deep_data)
{
    *data = deep_data;
}

int Deep::get_data()
{
    return *data;
}

void display_deep(Deep deep);

int main()
{
// When dealing with pointers always use deep copy.
    Deep data_one {100};

    cout<<"\n";

    cout<<"*** data_one after creating ***\n";
    cout<<"-------------------------------\n";
    display_deep(data_one);
    cout<<"-------------------------------\n\n";

    Deep data_two {data_one};

    cout<<"\n";

    cout<<"*** data_two after creating ***\n";
    cout<<"-------------------------------\n";
    display_deep(data_two);
    cout<<"-------------------------------\n\n";

    data_two.set_data(1000); // Here unlike shallow copy only "data" in "data_two" will be changed.

    cout<<"*** data after updating ***\n";
    cout<<"-------------------------------\n";

    cout<<"data_one: \n";
    display_deep(data_one);
    cout<<"\n";

    cout<<"data_two: \n";
    display_deep(data_two);
    cout<<"\n";

    cout<<"-------------------------------\n\n";

    return 0;
}

void display_deep(Deep deep)
{
    cout<<"Data: "<<deep.get_data()<<"\n";
}