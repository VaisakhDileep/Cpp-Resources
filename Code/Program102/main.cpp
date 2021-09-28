/*
Created by  : Vaisakh Dileep
Date        : 7, February, 2021
Description : This program helps to understand functors(function objects) in C++.
*/

#include<iostream>

#include<algorithm> // For std::transform()

using namespace std;

int increment(int x)
{
    return x + 1;
}

class Increment
{
private:
    int num; // Value to be incremented.
public:
    Increment(int num)
    {
        this->num = num;
    }

    int operator()(int increment_value) const // This is the overloaded () operator.
    {
        return num + increment_value;
    }
};

int main()
{
// Functors are objects that can be treated as though they are a function or a function pointer. Functors are commonly used along with STL.

// For more information about std::transform refer "http://www.cplusplus.com/reference/algorithm/transform/"

    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int size = sizeof(digits) / sizeof(digits[0]);

    transform(digits, digits + size, result, increment); // Here we are using function pointers, here we can't pass any parameters to the increment function.

    cout<<"Result [Case 1]: [ ";

    for(int i {0}; i < size; i++)
    {
        cout<<result[i]<<" ";
    }

    cout<<"]\n\n";

    transform(digits, digits + size, result, Increment {5}); // Notice here when using functors we can use additional parameters, which becomes handy when we want to increment more than 1 to the individual elements.

    cout<<"Result [Case 2]: [ ";

    for(int i {0}; i < size; i++)
    {
        cout<<result[i]<<" ";
    }

    cout<<"]\n\n";

    Increment increment_by_10(10);

    transform(digits, digits + size, result, increment_by_10); // Notice here we are passing the object.

    cout<<"Result [Case 3]: [ ";

    for(int i {0}; i < size; i++)
    {
        cout<<result[i]<<" ";
    }

    cout<<"]\n\n";

    return 0;
}