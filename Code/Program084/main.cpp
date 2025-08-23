/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2021
Description : Custom deleter.
*/

#include<iostream>

#include<memory>

using namespace std;

class Test
{
private:
    int data;
public:
    Test() // No-args Constructor
        : data {0}
    {
        cout<<"No-args constructor called for Test.\n";
    }

    Test(int data) // Overloaded Constructor
        : data {data}
    {
        cout<<"Overloaded constructor called for Test ["<<data<<"]\n";
    }

    int get_data() const
    {
        return data;
    }

    ~Test() // Destructor
    {
        cout<<"Destructor called for Test ["<<data<<"]\n";
    }
};

void delete_function(Test *raw_pointer)
{
    cout<<"Using custom deleter function.\n";

    delete raw_pointer;
}

int main()
{
// C++ smart pointers allow us to provide custom deleters. We can declare custom deleters by using Functions, Lambdas. We can't use custom deleters when using specialized functions like "make_unique()", "make_shared()", ... etc.

/*
Syntax for using custom deleters(using functions):

void deleter_function(Class_Name *raw_pointer) // "Class_Name" could also be "Data_Type".
{
    // ... Code ...

    delete raw_pointer; // Make sure to delete.
}

shared_ptr<Class_Name> ptr {new Class_Name {}, deleter_function}; // Creating a shared pointer object. "Class_Name" could also be "Data_Type".
*/

/*
Syntax for using custom deleters(using lambdas):

shared_ptr<Class_Name> ptr(new Class_Name {100}, [](Class_Name *raw_pointer) {
    // ... Code ...

    delete raw_pointer; }); // "Class_Name" could also be "Data_Type".
*/
    {
        shared_ptr<Test> test_1 {new Test {100}, delete_function};
    }

    cout<<"\n";

    {
        shared_ptr<Test> test_2 {new Test {200}, [](Test *raw_pointer) {
            cout<<"Using custom deleter lambda function.\n";
            delete raw_pointer; }};
    }

    return 0;
}