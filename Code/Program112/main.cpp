/*
Created by  : Vaisakh Dileep
Date        : 12, February, 2021
Description : This program helps to understand std::stack in STL container adapters in C++.
*/

#include<iostream>

#include<list>

#include<vector>

#include<stack> // For std::stack

using namespace std;

template<typename T>
void display(stack<T> s) // Notice here we are passing by value, since the only way we can display a stack is to pop and display all of its elements, this may result in an empty stack at the end.
{
    T top_elem;

    cout<<"[ ";
    while(!s.empty())

    {
        top_elem = s.top();

        s.pop();

        cout<<top_elem<<" ";
    }
    cout<<"]";
}

int main()
{
/*
std::stack is a Last-in First-out(LIFO) data-structure. They are implemented as an adapter over other STL containers such as vectors, lists or deques. All operations occur at the end of the stack(top). No iterators are supported.

The operations performed on std::stack are:
1. push  - Insert an element at the top of the stack.
2. pop   - Remove an element from the top of the stack.
3. top   - Access the top-most element in the stack.
4. empty - It will return true if the stack is empty.
5. size  - It will give the number of elements in the stack.
*/
    stack<int> test_1; // By default stacks are stored as deques.
    stack<int, vector<int>> test_2; // We can explicitly choose the container.
    stack<int, list<int>> test_3;
    stack<int, deque<int>> test_4; // Notice here we do not include the deque library(#include<deque>).

    for(int i : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
    {
        test_1.push(i);
    }

    test_1.top() = -1; // We can change the top-most element like this.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"Top  [test 1]: "<<test_1.top()<<"\n";
    cout<<"Size [test 1]: "<<test_1.size()<<"\n\n";

    cout<<"test 1 after removing the top-most element: \n";

    test_1.pop();

    cout<<"Top  [test 1]: "<<test_1.top()<<"\n";
    cout<<"Size [test 1]: "<<test_1.size()<<"\n\n";

    while(!test_1.empty()) // This is how we clear a stack.
    {
        test_1.pop();
    }

    cout<<"test 1 after clearing all the elements: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"Size [test 1]: "<<test_1.size()<<"\n\n";

    return 0;
}