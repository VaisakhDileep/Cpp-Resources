/*
Created by  : Vaisakh Dileep
Date        : 12, February, 2023
Description : This program helps to understand how to declare static data-members inside template classes in C++.
*/

#include<iostream>

using namespace std;

template<typename T>
class temp_class_1 {
public:
    static int class_create_count;

    T val;

    temp_class_1() {
        class_create_count++;

        cout << "temp_class_1 constructor has been called " << class_create_count << " number of times.\n";
    }
};

template<typename T>
class temp_class_2 {
public:
    static int class_create_count;

    T val;
    int int_var;

    temp_class_2() {
        class_create_count++;

        cout << "temp_class_2 constructor has been called " << class_create_count << " number of times.\n";
    }
};

template<typename T>
class temp_class_3 {
public:
    static int class_create_count;

    int int_var;
    T val;

    temp_class_3() {
        class_create_count++;

        cout << "temp_class_3 constructor has been called " << class_create_count << " number of times.\n";
    }
};

template<typename T>
int temp_class_1<T>::class_create_count = 0;

template<typename T>
int temp_class_2<T>::class_create_count = 0;

template<typename T>
int temp_class_3<T>::class_create_count = 0;

int main() {
    temp_class_1<string> string_temp_class_1_obj_1 {};
    temp_class_1<string> string_temp_class_1_obj_2 {};
    temp_class_1<string> string_temp_class_1_obj_3 {};
    cout << "\n";

    temp_class_1<char *> char_ptr_temp_class_1_obj_1 {};
    temp_class_1<char *> char_ptr_temp_class_1_obj_2 {};
    temp_class_1<char *> char_ptr_temp_class_1_obj_3 {};
    cout << "\n";

/*
    temp_class_1<char[]> char_array_temp_class_1_obj_1 {};
    temp_class_1<char[]> char_array_temp_class_1_obj_2 {};
    temp_class_1<char[]> char_array_temp_class_1_obj_3 {};
    cout << "\n";
*/
// This will give an error since we can't have a flexible array member(char []) for an empty class.

/*
    temp_class_2<char[]> char_array_temp_class_2_obj_1 {};
    temp_class_2<char[]> char_array_temp_class_2_obj_2 {};
    temp_class_2<char[]> char_array_temp_class_2_obj_3 {};
    cout << "\n";
*/
// Even though the class is not empty(we have an int_var), this will given an error since we have to place the flexible array member(char []) at the end of the class.

    temp_class_3<char[]> char_array_temp_class_3_obj_1 {};
    temp_class_3<char[]> char_array_temp_class_3_obj_2 {};
    temp_class_3<char[]> char_array_temp_class_3_obj_3 {};
    cout << "\n";
// This will work fine.

    temp_class_1<const char *> const_char_ptr_temp_class_1_obj_1 {};
    temp_class_1<const char *> const_char_ptr_temp_class_1_obj_2 {};
    temp_class_1<const char *> const_char_ptr_temp_class_1_obj_3 {};
    cout << "\n";

    temp_class_1<int> int_temp_class_1_obj_1 {};
    temp_class_1<int> int_temp_class_1_obj_2 {};
    temp_class_1<int> int_temp_class_1_obj_3 {};

    return 0;
}