/*
Created by  : Vaisakh Dileep
Date        : 2, January, 2021
Description : This program helps to understand the difference between l-value reference and r-value reference in C++.
*/

#include<iostream>

using namespace std;

int & getReference();

void printReferenceValue_1(int &);
void printReferenceValue_2(int &&);
void printReferenceValue_3(int &);
void printReferenceValue_3(int &&);
void printReferenceValue_4(const int &);

int main() {
/*
l-value: It refers to a memory location which identifies an object.
r-value: It refers to the data value that is stored at some address in the memory. Temporary objects are r-value.

r-value Properties:
1. r-value references extends the lifespan of the temporary object to which they are assigned.
2. Non-const r-value references allow you to modify the r-value.
*/
    int dummy {10};

    int &l_value_reference  = dummy; // This is an l-value reference.
    int &&r_value_reference = 999; // This is an r-value reference.

    const int &const_l_value_reference = dummy; // This is a constant l-value reference. It can catch both l-value as well as r-values.
    const int &const_r_value_reference = 999;

    cout << "dummy                  : " << dummy << "\n";
    cout << "l_value_reference      : " << l_value_reference << "\n";
    cout << "r_value_reference      : " << r_value_reference << "\n";
    cout << "const_l_value_reference: " << const_l_value_reference << "\n";
    cout << "const_r_value_reference: " << const_r_value_reference << "\n\n";

    cout << "Address of dummy            : " << &dummy << "\n";
    cout << "Address of l_value_reference: " << &l_value_reference << "\n";
    cout << "Address of r_value_reference: " << &r_value_reference << "\n\n";

/*
    int &l_value_reference_2  = 100; // This will give an error, because we can't assign an r-value to an l-value reference.
    int &&r_value_reference_2 = dummy; // This will give an error, because we can't assign an l-value to an r-value reference.
*/

    int &l_value_reference_3 = r_value_reference; // This won't give an error. We can assign a r-value reference variable to a l-value reference variable.


    cout << "Address of l_value_reference_3: " << &l_value_reference_3 << "\n";
    cout << "Address of r_value_reference  : " << &r_value_reference << "\n\n";

/*
Uses of r-value reference:
1. They are used when working with move constructor and move assignment.
*/

    printReferenceValue_1(dummy);
    // printReferenceValue_1(999); // This will give an error since "printReferenceValue_1" only handles l-value reference.
    cout << "\n";

    // printReferenceValue_2(dummy); // This will give an error since "printReferenceValue_2" only handles r-value reference.
    printReferenceValue_2(999);
    cout << "\n";

    printReferenceValue_3(dummy);
    printReferenceValue_3(999); // This works but here we used function overloading.
    cout << "\n";

    printReferenceValue_4(dummy);
    printReferenceValue_4(999); // We achieved the same result as above without using function overloading.

/*
    int &x = getReference();

    cout << "x: " << x;
*/ // This code demonstrates the dangling reference problem. Running this code will result in undefined behaviour.

    return 0;
}

int & getReference() {
    int x {10};

    return x;
} // Here we are trying to return a reference to 'x'. 'x' is a local variable to "getReference()" function which will go out of scope. We can't extend the life of a local variable after the function scope ends.

void printReferenceValue_1(int &value) {
    cout << "printReferenceValue_1 -> " << "Value: " << value << "\n";
}

void printReferenceValue_2(int &&value) {
    cout << "printReferenceValue_2 -> " << "Value: " << value << "\n";
}

void printReferenceValue_3(int &value) {
    cout << "printReferenceValue_3 -> " << "Value: " << value << "\n";
}

void printReferenceValue_3(int &&value) {
    cout << "printReferenceValue_3 -> " << "Value: " << value << "\n";
}

void printReferenceValue_4(const int &value) { // This will catch both l-value and r-value. Using "const int &" will extend the life-time of stack base temporary(r-value).
    cout << "printReferenceValue_4 -> " << "Value: " << value << "\n";
}