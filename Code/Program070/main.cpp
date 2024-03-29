/*
Created by  : Vaisakh Dileep
Date        : 16, January, 2021
Description : This program helps to understand the problem with declaring constructors and destructors when inheriting in C++.
*/

#include<iostream>

using namespace std;

class Base {
private:
    int base_value;
public:
    Base() { // No-args constructor
        cout << "No-args constructor called for Base.\n";
        base_value = 0;
    }
    Base(int base_value) { // Overloaded constructor
        cout << "Overloaded constructor called for Base.\n";
        this->base_value = base_value;
    }

    ~Base() { // Destructor
        cout << "Destructor called for Base.\n";
    }
};

class Derived_1: public Base {
private:
    int derived_1_value;
public:
    Derived_1() { // No-args constructor
        cout << "No-args constructor called for Derived_1.\n";
        derived_1_value = 0;
    }
    Derived_1(int derived_1_value) { // Overloaded constructor
        cout << "Overloaded constructor called for Derived_1.\n";
        this->derived_1_value = derived_1_value;
    }

    ~Derived_1() { // Destructor
        cout << "Destructor called for Derived_1.\n";
    }
};

class Derived_2: public Base {
    using Base::Base; // This will allow us to use the overloaded constructor of the base class(not a preferable method).
private:
    int derived_2_value;
public:
    Derived_2() { // No-args constructor
        cout << "No-args constructor called for Derived_2.\n";
        derived_2_value = 0;
    }

    ~Derived_2() { // Destructor
        cout << "Destructor called for Derived_2.\n";
    }
};

int main() {
/*
When a Derived object is created:
1. Base class constructor is executed first.
2. Derived class constructor is executed later.

When a Derived object is destroyed:
1. Derived class destructor is executed first.
2. Base class destructor is executed later.
3. Each destructor should free resources allocated in it's own constructors.
*/

/*
A derived class does not inherit:
1. Base class constructors.
2. Base class destructor.
3. Base class overloaded assignment operators.
4. Base class friend functions.

However,
C++11 allows explicit inheritance of base 'non-special' constructors by using the statement "using Base::Base;" in the derived class declaration.
*/
    {
        cout << "No-args constructor for base class: \n";
        Base test_1_base {}; // No-args constructor is called.
    }
    cout << "\n";

    {
        cout << "No-args constructor for derived class(prototype 1): \n";
        Derived_1 test_1_derived_1 {}; // No-args constructor is called for derived class(no-args constructor called for base class).
    }
    cout << "\n";

    {
        cout << "No-args constructor for derived class(prototype 2): \n";
        Derived_2 test_1_derived_2 {}; // No-args constructor is called.
    }
    cout << "\n";

    {
        cout << "Overloaded constructor for base class: \n";
        Base test_2_base {50}; // Overloaded constructor is called.
    }
    cout << "\n";

    {
        cout << "Overloaded constructor for derived class(prototype 1): \n";
        Derived_1 test_2_derived_1 {100}; // Step through the debugger to understand this line of code.
                                          // Overloaded constructor called for derived class(no-args constructor called for base class).
    }
    cout << "\n";

    {
        cout << "Overloaded constructor for derived class(prototype 2): \n";

        Derived_2 test_2_derived_2 {200}; // Overloaded constructor for base class is called(including overloaded constructor for derived class will override it).
    }

    return 0;
}