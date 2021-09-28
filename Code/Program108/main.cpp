/*
Created by  : Vaisakh Dileep
Date        : 10, February, 2021
Description : This program helps to understand std::list in STL sequence containers in C++.
*/

#include<iostream>

#include<list> // For std::list

#include<algorithm>

#include<string>

#include<iterator>

using namespace std;

class Person // Note: When we are using objects as STL parameters, make sure to overload the default constructor, < operator, == operator.
{
    friend ostream &operator<<(ostream &os, const Person &person);

    string name;
    int age;
public:
    // Person() = default;

    Person() : name {"XXXXXXXXXX"}, age {0} {}

    Person(string name, int age) : name {name}, age {age} {}

    bool operator<(const Person &rhs) const
    {
        return (this->age < rhs.age);
    }

    bool operator==(const Person &rhs) const
    {
        return ((this->name == rhs.name) and (this->age == rhs.age));
    }
};

ostream &operator<<(ostream &os, const Person &person)
{
    os<<"\""<<person.name<<"\""<<":"<<person.age;

    return os;
}

template<typename T>
void display(const list<T> &l)
{
    cout<<"[ ";

    for(const auto &elem : l)
    {
        cout<<elem<<" ";
    }

    cout<<"]";
}

int main()
{
/*
lists are of dynamic size, they are bidirectional(doubly-linked). Direct element access is not provided(.at() and [] are not supported).

Time complexities of different operations in std::list:
1. Rapid insertion and deletion of elements anywhere in the container -> Constant time.

For more information refer: "https://en.cppreference.com/w/cpp/container/list"

All iterators are available and invalidate when corresponding element is deleted.
*/

/*
Lists are represented like this:
        ---------      ---------      ---------
        |       |<-----|       |<-----|       |
        |   1   |      |   2   |      |   3   |
        |       |----->|       |----->|       |
        ---------      ---------      ---------
            ^                             ^
            |                             |
   front()__|                             |__end()
*/

    list<int> test_1 {0, 1, 2, 3, 4, 5}; // Using initialization list.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"---------- test 1 ----------\n";
    cout<<"Front: "<<test_1.front()<<"\n";
    cout<<"Back : "<<test_1.back()<<"\n\n";

    test_1.push_back(6);
    test_1.push_front(-1);

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    test_1.pop_back();
    test_1.pop_front();

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    list<Person> SimpsonFamily;

    SimpsonFamily.resize(6); // When resizing make sure to overload the default constructor to avoid unexpected outputs.

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    SimpsonFamily.clear();

    Person Homer {"Homer J Simpson", 39};

    SimpsonFamily.push_back(Homer);
    SimpsonFamily.push_back(Person {"Marge Bouvier", 36}); // We can also use "push_front()".
    SimpsonFamily.emplace_back("Bart Simpson", 10); // We can also use "emplace_front()".
    SimpsonFamily.emplace_back("Lisa Simpson", 8);
    SimpsonFamily.emplace_back("Maggie Simpson", 1);
    SimpsonFamily.emplace_front("Abraham Simpson", 83);

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    SimpsonFamily.sort();

    cout<<"After sorting the Simpson Characters by their age: \n";

    cout<<"Simpson Family: ";
    display(SimpsonFamily); 
    cout<<"\n\n";

    test_1.clear();

    test_1 = {1, 2, 3, 7, 8, 9};

    cout<<"test 1 with missing values: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    list<int> missing_values = {4, 5, 6};

    list<int>::iterator test_1_it = find(test_1.begin(), test_1.end(), 7); // We could also use "auto test_1_it = find(test_1.begin(), test_1.end(), 7);".

    if(test_1_it != test_1.end())
    {
        test_1.insert(test_1_it, missing_values.begin(), missing_values.end());
    }

    cout<<"test 1 after adding the missing values: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    test_1.erase(test_1_it); // Notice here the iterator is still pointing to '7' in the list.

    cout<<"test 1 after erasing the iterator value: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"test 1 after inserting back that iterator value: \n";

    test_1_it = find(test_1.begin(), test_1.end(), 8);

    test_1.insert(test_1_it, 7);

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"*test_1_it [initially]   : "<<*test_1_it<<"\n";

    advance(test_1_it, -4);

    cout<<"*test_1_it [advancing -4]: "<<*test_1_it<<"\n";

    advance(test_1_it, 2);

    cout<<"*test_1_it [advancing 2] : "<<*test_1_it<<"\n\n";

    cout<<"Traversing test_1 in the forward direction: \n";

    cout<<"test 1: [ ";
    for(test_1_it = test_1.begin(); test_1_it != test_1.end(); test_1_it++)
    {
        cout<<*test_1_it<<" ";
    }
    cout<<"]\n\n";

    cout<<"Traversing test_1 in the backward direction: \n";

    cout<<"test 1: [ ";
    auto test_1_it_real_end = test_1.end();
    advance(test_1_it_real_end, -1);

    auto test_1_it_real_begin = test_1.begin();
    advance(test_1_it_real_begin, -1);

    for(test_1_it = test_1_it_real_end; test_1_it != test_1_it_real_begin; test_1_it--) // As you can see this is a tedious method.
    {
        cout<<*test_1_it<<" ";
    }
    cout<<"]\n\n";

    cout<<"Traversing test_1 in the backward direction [using rbegin() and rend()]: \n";
    cout<<"test 1:[ ";
    for(list<int>::reverse_iterator test_1_rev_it = test_1.rbegin(); test_1_rev_it != test_1.rend(); test_1_rev_it++) // We could also use "auto test_1_rev_it = test_1.rbegin()".
    {
        cout<<*test_1_rev_it<<" "; // This is supported in lists because they are doubly linked, whereas it is not supported in forward_list.
    }
    cout<<"]\n\n";

    return 0;
}