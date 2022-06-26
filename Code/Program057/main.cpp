/*
Created by  : Vaisakh Dileep
Date        : 2, January, 2021
Description : This program helps to understand the difference between l-value reference and r-value reference in C++.
*/

#include<iostream>

using namespace std;

void printReferenceValue_1(int &);

void printReferenceValue_2(int &&);

void printReferenceValue_3(int &);
void printReferenceValue_3(int &&);

void printReferenceValue_4(const int &);

int main()
{
/*
l-value: It refers to a memory location which identifies an object.

r-value: It refers to the data value that is stored at some address in the memory. Temporary objects are r-value.

r-value Properties:
1. r-value references extends the lifespan of the temporary object to which they are assigned.
2. Non-const r-value references allow you to modify the r-value.
*/
    int dummy {10};

    int &l_value_reference = dummy; // This is an l-value reference.

    int &&r_value_reference = 999; // This is an r-value reference.

    cout<<"Address of dummy            : "<<&dummy<<"\n";
    cout<<"Address of l_value_reference: "<<&l_value_reference<<"\n";
    cout<<"Address of r_value_reference: "<<&r_value_reference<<"\n\n";

/*
    int &l_value_reference_2 = 100; // This will give an error, because we can't assign an r-value to an l-value reference.
    int &&r_value_reference_2 = dummy; // This will give an error, because we can't assign an l-value to an r-value reference.
*/

/*
Uses of r-value reference:
1. They are used when working with move constructor and move assignment.
*/

    printReferenceValue_1(dummy);
    // printReferenceValue_1(999); // This will give an error since "printReferenceValue_1" only handles l-value reference.
    cout<<"\n";

    // printReferenceValue_2(dummy); // This will give an error since "printReferenceValue_2" only handles r-value reference.
    printReferenceValue_2(999);
    cout<<"\n";

    printReferenceValue_3(dummy);
    printReferenceValue_3(999); // This works but over here we used function overloading.
    cout<<"\n";

    printReferenceValue_4(dummy);
    printReferenceValue_4(999); // We achieved the same result as above without using function overloading.

    return 0;
}

void printReferenceValue_1(int &value)
{
    cout<<"Inside printReferenceValue_1 -> ";
    cout<<"Value: "<<value<<"\n";
}

void printReferenceValue_2(int &&value)
{
    cout<<"Inside printReferenceValue_2 -> ";
    cout<<"Value: "<<value<<"\n";
}

void printReferenceValue_3(int &value)
{
    cout<<"Inside printReferenceValue_3 -> ";
    cout<<"Value: "<<value<<"\n";
}

void printReferenceValue_3(int &&value)
{
    cout<<"Inside printReferenceValue_3 -> ";
    cout<<"Value: "<<value<<"\n";
}

void printReferenceValue_4(const int &value) // This will catch both l-value reference and r-value reference. Using "const int &" will extend the life-time of stack base temporary(r-value) references.
{
    cout<<"Inside printReferenceValue_4 -> ";
    cout<<"Value: "<<value<<"\n";
}