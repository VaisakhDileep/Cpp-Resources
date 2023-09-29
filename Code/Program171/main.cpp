/*
Created by  : Vaisakh Dileep
Date        : 21, January, 2023
Description : This program helps to understand parameter pack in C++.
*/

#include<iostream>

using namespace std;

template<typename... TPack> // Variadic function template.
void variadic_func(TPack... args) {
    if(sizeof...(TPack) == 0) { // We can also replace "sizeof...(TPack)" with "sizeof...(args)". "sizeof..." will return the count of the number of elements in the parameter pack.
        cout << "argument count: 0\n";
    }
    else if(sizeof...(TPack) == 1) {
        cout << "argument count: 1\n";
    }
    else if(sizeof...(TPack) == 2) {
        cout << "argument count: 2\n";
    }
}

template<typename... TPack> // Variadic class template.
class variadic_class {
public:
    variadic_class() {
        if(sizeof...(TPack) == 0) {
            cout << "argument count: 0\n";
        }
        else if(sizeof...(TPack) == 1) {
            cout << "argument count: 1\n";
        }
        else if(sizeof...(TPack) == 2) {
            cout << "argument count: 2\n";
        }
    }
};

template<typename T, typename... TPack>
void print_func_result(T arg, TPack... remaining_args) {
    if constexpr(sizeof...(remaining_args) != 0) { // When using recursive variadic function, we have to use "if constexpr" instead of "if".
        cout << arg << " ";

        print_func_result(remaining_args...);
    }
    else {
        cout << arg;
    }
}

template<typename A, typename B, typename... TPack>
void test_func_1(A A_str, B B_str, TPack... C_strs) {
    print_func_result(A_str, B_str, C_strs...);
}

template<typename... TPack>
void test_func_2(TPack... args)
{
    cout << "print_func_result(args...)         : ";
    print_func_result(args...);
    cout << "\n";

    cout << "print_func_result(++args...)       : "; // When using the increment operator on the parameter pack, this will increment all the elements present in the parameter pack. Changes made here will persist for later parameter packs as well.
                                                     // We could also use "args++...", but then the parameter pack will only get incremented after we have passed it into the variadic function.
    print_func_result(++args...);
    cout << "\n";

    cout << "print_func_result(0, 1, ++args...) : ";
    print_func_result(0, 1, ++args...);
    cout << "\n";

    cout << "print_func_result(++args..., 9, 10): ";
    print_func_result(++args..., 9, 10);
    cout << "\n";
}

template<typename... TPack>
void test_func_3(TPack... args) {
    cout << "print_func_result(&args...)        : "; // When expanding the parameter pack, the individual elements will be passed as memory location.
    print_func_result(&args...);
    cout << "\n";
}

template<typename... TPack>
void test_func_4(TPack... args) {
    int int_args[10] {0, args..., 6}; // When using initialization list we can expand the parameter pack.

    cout << "test_func_4: ";

    for(int arg : int_args) {
        cout << arg << " ";
    }
}

int main() {
    variadic_func();
    variadic_func(0);
    variadic_func(0,1);
    cout << "\n";

    variadic_class<> var_class_obj_0 {};
    variadic_class<int> var_class_obj_1 {};
    variadic_class<int, int> var_class_obj_2 {};
    cout << "\n";

    cout << "test_func_1(\"one\", \"two\", \"three\", \"four\", \"five\", \"six\"): ";
    test_func_1("one", "two", "three", "four", "five", "six");
    cout << "\n\n";

    test_func_2(0, 1, 2, 3, 4, 5);

    int one {1}, two {2}, three {3}, four {4}, five {5}, six {6};

    test_func_3(one, two, three, four, five, six);
    cout << "\n";

    test_func_4(1, 2, 3, 4, 5);

    return 0;
}