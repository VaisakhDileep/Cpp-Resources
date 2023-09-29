/*
Created by  : Vaisakh Dileep
Date        : 19, June, 2022
Description : This program helps to understand curiously recurring template pattern(CRTP) in C++.
*/

#include<iostream>

using namespace std;

/*
General form of CRTP pattern:

template<typename T>
class Base {
    ...
}

class Derived: public Base<Derived> {
    ...
}
*/

template<typename T>
class Base {
public:
    void print() { // Notice here we are not performing dynamic polymorphism, therefore function names need not match.
        static_cast<T*>(this)->print_state();
    }
};

class State_1: public Base<State_1> {
public:
    void print_state() {
        cout<<"State 1";
    }
};

class State_2: public Base<State_2> {
public:
    void print_state() {
        cout<<"State 2";
    }
};

class State_3: public Base<State_3> {
public:
    void print_state() {
        cout<<"State 3";
    }
};

template<typename T>
void print_state(Base<T> base_object) {
    base_object.print(); // Notice here we achieved dynamic polymorphism without using virtual function.
}

int main() {
    State_1 state_1_object;
    State_2 state_2_object;
    State_3 state_3_object;

    state_1_object.print_state();
    cout<<"\n";
    state_2_object.print_state();
    cout<<"\n";
    state_3_object.print_state();
    cout<<"\n\n";

    print_state(state_1_object);
    // print_state<State_1>(state_1_object); // This is also valid.
    cout<<"\n";

    print_state(state_2_object);
    // print_state<State_2>(state_2_object); // This is also valid.
    cout<<"\n";

    print_state(state_3_object);
    // print_state<State_3>(state_3_object); // This is also valid.
    cout<<"\n";

    return 0;
}