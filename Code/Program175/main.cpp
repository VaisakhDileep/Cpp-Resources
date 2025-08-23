/*
Created by  : Vaisakh Dileep
Date        : 6, October, 2023
Description : Dynamic_cast.
*/

#include<iostream>

using namespace std;

// dynamic_cast is used for safe downcasting at run-time. dynamic_cast works only on polymorphic base class since it uses this information to decided safe downcasting.

// Downcasting -> Casting a base class pointer(or reference) to a derived class pointer(or reference) is known as downcasting.
// Upcasting -> Casting a derived class pointer(or reference) to a base class pointer(or reference) is known as upcasting.

class Base {
public:
    void virtual say_hello() { // dynamic_cast works only on polymorphic classes. If we don't have 
        cout << "Hello!, from Base class.\n";
    }
};

class Derived_1: public Base {
public:
    void say_hello() {
        cout << "Hello!, from Derived_1 class.\n";
    }
};

class Derived_2: public Base {
public:
    void say_hello() {
        cout << "Hello!, from Derived_2 class.\n";
    }
};

int main() {
    Derived_1 d1 {};
    d1.say_hello();
    cout << "\n";

    Base *b_ptr {dynamic_cast<Base *>(&d1)};
    if(b_ptr != nullptr) {
        cout << "Casting was successful.\n";
        b_ptr->say_hello();
    } else {
        cout << "Casting was not successful\n";
    }
    cout << "\n";

    Derived_1 *d1_ptr {dynamic_cast<Derived_1 *>(b_ptr)};
    if(d1_ptr != nullptr) {
        cout <<"Casting was successful\n";
        d1_ptr->say_hello();
    } else {
        cout << "Casting was not successful\n";
    }
    cout << "\n";

    Derived_2 *d2_ptr {dynamic_cast<Derived_2 *>(b_ptr)};
    if(d2_ptr != nullptr) {
        cout << "Casting was successful.\n";
        d2_ptr->say_hello();
    } else {
        cout << "Casting was not successful\n"; // Notice here casting was not successful. This is because derived_1 pointer was upcasted to a base pointer. Trying to downcast a base pointer to one of its other derived class would result in dynamic_cast returning nullptr.
    }
    cout << "\n";

    try {
        Base &b_ref {dynamic_cast<Base &>(d1)};
        cout << "Casting was successful.\n";
        b_ref.say_hello();
    } catch(std::exception &e) {
        cout << "Casting was not successful\n";
        cout << e.what() << "\n";
    }
    cout << "\n";

    try {
        Base &b_ref {dynamic_cast<Base &>(d1)};
        Derived_1 &d1_ref {dynamic_cast<Derived_1 &>(b_ref)};
        cout << "Casting was successful.\n";
        d1_ref.say_hello();
    } catch(std::exception &e) {
        cout << "Casting was not successful, Reason: ";
        cout << e.what() << "\n";
    }
    cout << "\n";

    try {
        Base &b_ref {dynamic_cast<Base &>(d1)};
        Derived_2 &d2_ref {dynamic_cast<Derived_2 &>(b_ref)}; // If dynamic_cast fails to cast a reference, we get an exception.
        cout << "Casting was successful.\n";
        d2_ref.say_hello();
    } catch(std::exception &e) {
        cout << "Casting was not successful, Reason: ";
        cout << e.what() << "\n";
    }

    return 0;
}