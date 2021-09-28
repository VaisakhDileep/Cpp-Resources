/*
Created by  : Vaisakh Dileep
Date        : 15, May, 2021
Description : This program helps to understand std::distance function in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

int main()
{
// std::distance(): It will give the total number of elements between the two iterators. Time complexity is O(1) for random-access iterators and O(n) for other iterators.

/*
Syntax for std::distance():
    int dist = std::distance(InputIterator first, InputIterator last);

    Here,
    first: iterator to the first element in the container.
    last: iterator to the last element in the container.

    dist: Number of elements between first and last.
*/

    vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout<<"values: [ ";
    for(auto value : values)
    {
        cout<<value<<" ";
    }
    cout<<"]\n";

    vector<int>::iterator first_element_it {values.begin()};

    vector<int>::iterator last_element_it {values.end() - 1};

    cout<<"Number of elements between "<<*first_element_it<<" and "<<*last_element_it<<": "<<distance(first_element_it, last_element_it)<<"\n"; // Element pointed by the "last_element_it" will not be counted.
    cout<<"Number of elements between "<<*last_element_it<<" and "<<*first_element_it<<": "<<distance(last_element_it, first_element_it)<<"\n"; // Finding the distance in the reverse direction will result in a negative value.

    return 0;
}