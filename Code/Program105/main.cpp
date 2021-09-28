/*
Created by  : Vaisakh Dileep
Date        : 8, February, 2021
Description : This program helps to understand std::array in STL sequence containers in C++.
*/

#include<iostream>

#include<array> // This header file is required to include std::array.

#include<algorithm> // For std::sort()

#include<numeric> // For std::accumulate()

using namespace std;

void display_array_size_5(const array<int, 5> &arr) // Displays an integer array of size '5'.
{
    cout<<"[ ";

    for(auto i : arr)
    {
        cout<<i<<" ";
    }

    cout<<"]\n";
}

int main()
{
/*
std::array are of fixed size(the size must be known at compile-time). We can also access the underlying raw array whenever we need. All iterators are available and do not invalidate.

std::array objects are more efficient to pass to functions unlike raw arrays which might get complicated when passing to a function.

For more information on std::array refer: "https://en.cppreference.com/w/cpp/container/array"
*/
    array<int, 5> test_1 {1, 2, 3, 4, 5}; // Note: For C++11 use "array<int, 5> test_1 {{1, 2, 3, 4, 5}}"

    cout<<"test 1: ";
    display_array_size_5(test_1);

    array<int, 5> test_2 {5, 4}; // This will initialize the first two elements with '1' and '2' and the rest of the elements will be intialized with '0'.

    cout<<"test 2: ";
    display_array_size_5(test_2);
    cout<<"\n";

    // array<int, 5> test_3 {1, 2, 3, 4, 5, 6}; // This will give an error because we have specified that the size of the array is '5' but the number of elements given to the arrays is '6'.

    cout<<"Size of test 1: "<<test_1.size()<<"\n";
    cout<<"Size of test 2: "<<test_2.size()<<"\n\n";

    cout<<"Max size of test 1: "<<test_1.max_size()<<"\n";
    cout<<"Max size of test 2: "<<test_2.max_size()<<"\n\n";

    test_2[2] = 3;

    test_2.at(3) = 2; // .at() will do bound checking, so prefer this over [].

    cout<<"test 2: ";
    display_array_size_5(test_2);
    cout<<"\n";

    cout<<"Front of test 1: "<<test_1.front()<<"\tBack of test 1: "<<test_1.back()<<"\n";
    cout<<"Front of test 2: "<<test_2.front()<<"\tBack of test 2: "<<test_2.back()<<"\n\n";

    test_1.swap(test_2); // "test_2.swap(test_1)" is also valid, it will swap the two arrays.

    cout<<"test 1: ";
    display_array_size_5(test_1);

    cout<<"test 2: ";
    display_array_size_5(test_2);
    cout<<"\n";

    test_2.fill(0); // This will make all the elements in the array '0'.

    cout<<"test 2: ";
    display_array_size_5(test_2);
    cout<<"\n";

    int *test_ptr = test_1.data(); // We can get back the raw array whenever we want, but only do it if it's really necessary.

    test_ptr[4] = 1;

    cout<<"test 1: [ ";
    for(int i {0}; i < 5; i++)
    {
        cout<<test_ptr[i]<<" ";
    }
    cout<<"]\n\n";

    sort(test_1.begin(), test_1.end());

    cout<<"test 1: ";
    display_array_size_5(test_1);
    cout<<"\n";

    array<int, 5>::iterator min_value = min_element(test_1.begin(), test_1.end()); // We could also use "auto min_value = min_element(test_1.begin(), test_1.end())".
    array<int, 5>::iterator max_value = max_element(test_1.begin(), test_1.end()); // We could also use "auto max_value = max_element(test_1.begin(), test_1.end())".

    cout<<"[test 1] Max: "<<*max_value<<"\tMin: "<<*min_value<<"\n\n";

    int sum = accumulate(test_1.begin(), test_1.end(), 0);

    cout<<"[test 1] Sum: "<<sum<<"\n\n";

    test_2 = {1, 1, 1, 1, 1};

    int count_ones = count(test_2.begin(), test_2.end(), 1);

    cout<<"[test 2] Count[1's]: "<<count_ones<<"\n\n";

    int count_even = count_if(test_1.begin(), test_1.end(), [](int x) { return (x % 2 == 0); });

    cout<<"[test 1] Count[even]: "<<count_even<<"\n\n";

    array<int, 5>::iterator adjacent_test_1 = adjacent_find(test_1.begin(), test_1.end()); // We could use "auto adjacent_test_1 = adjacent_find(test_1.begin(), test_1.begin())"

    if(adjacent_test_1 != test_1.end())
    {
        cout<<"Adjacent values are present in test 1.\n";
    }
    else
    {
        cout<<"No adjacent values are present in test 1.\n";
    }
    cout<<"\n";

    array<int, 5>::iterator adjacent_test_2 = adjacent_find(test_2.begin(), test_2.end()); // We could use "auto adjacent_test_2 = adjacent_find(test_2.begin(), test_2.begin())"

    if(adjacent_test_2 != test_2.end())
    {
        cout<<"Adjacent values are present in test 2.\n";
    }
    else
    {
        cout<<"No adjacent values are present in test 2.\n";
    }
    cout<<"\n";

    array<int, 0> test_4 {};

    cout<<boolalpha;

    cout<<"test_4.empty(): "<<test_4.empty()<<"\n\n";

    return 0;
}