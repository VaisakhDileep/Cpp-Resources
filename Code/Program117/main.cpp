/*
Created by  : Vaisakh Dileep
Date        : 18, May, 2021
Description : This program helps to understand std::tuple in STL container adapters in C++.
*/

#include<iostream>

#include<tuple>

using namespace std;

int main()
{
// A tuple holds a number of elements of different data-types as one object. They are similar to C-style structures(struct). Elements are accesses in the order they are created in the tuple.

    tuple<char, int, float> tuple_element {'A', 1, 1.10};

    cout<<"tuple_element: "<<get<0>(tuple_element)<<", "<<get<1>(tuple_element)<<", "<<get<2>(tuple_element)<<"\n"; // Make sure to pass the index as the template parameter.

    get<0>(tuple_element) = 'B'; // This is how we modify tuple elements.

    cout<<"tuple_element: "<<get<0>(tuple_element)<<", "<<get<1>(tuple_element)<<", "<<get<2>(tuple_element)<<"\n\n";

    cout<<"size of tuple_element: "<<tuple_size<decltype(tuple_element)>::value<<"\n\n"; // To find the number of elements in the tuple.

    tuple<char, int, int> duplicate_tuple_element_1 {'A', 1, 1};

    // tuple_element.swap(duplicate_tuple_element_1); // tuples should have the same template argument list in order to swap.

    tuple<char, int, float> duplicate_tuple_element_2 = make_tuple('Z', 9, 9.9); // We can initialize like this too.

    cout<<"tuple_element: "<<get<0>(tuple_element)<<", "<<get<1>(tuple_element)<<", "<<get<2>(tuple_element)<<"\n";
    cout<<"duplicate_element_2: "<<get<0>(duplicate_tuple_element_2)<<", "<<get<1>(duplicate_tuple_element_2)<<", "<<get<2>(duplicate_tuple_element_2)<<"\n\n";

    tuple_element.swap(duplicate_tuple_element_2);

    cout<<"tuple_element: "<<get<0>(tuple_element)<<", "<<get<1>(tuple_element)<<", "<<get<2>(tuple_element)<<"\n";
    cout<<"duplicate_element_2: "<<get<0>(duplicate_tuple_element_2)<<", "<<get<1>(duplicate_tuple_element_2)<<", "<<get<2>(duplicate_tuple_element_2)<<"\n\n";

    char char_value {};
    int int_value {};
    float float_value {};

    tie(char_value, int_value, float_value) = tuple_element; // We can copy different tuple elements using the tie function.

    cout<<"tied_elements: "<<char_value<<", "<<int_value<<", "<<float_value<<"\n";

    int int_value_1{};

    tie(ignore, int_value_1, ignore) = tuple_element; // We can use this format if we want to tie only the integer value in the tuple. "ignore" will tell the tie function to ingore the corresponding element in the tuple.

    cout<<"int_value_1 in tied_elements: "<<int_value_1<<"\n";

    tuple<char, int> tuple_1 {'A', 1};

    tuple<float, string> tuple_2 {1.1, "Vaisakh"};

    tuple<char, int, float, string> result {tuple_cat(tuple_1, tuple_2)}; // We could also use "auto result {tuple_cat(tuple_1, tuple_2)};"

    cout<<"result: "<<get<0>(result)<<", "<<get<1>(result)<<", "<<get<2>(result)<<", "<<get<3>(result)<<"\n";

    return 0;
}