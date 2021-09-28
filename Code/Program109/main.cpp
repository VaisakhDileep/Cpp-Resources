/*
Created by  : Vaisakh Dileep
Date        : 11, February, 2021
Description : This program helps to understand std::forward_list in STL sequence containers in C++.
*/

#include<iostream>

#include<algorithm>

#include<forward_list> // For std::forward_list

using namespace std;

class Person
{
    friend ostream &operator<<(ostream &os, const Person &person);

    string name;
    int age;
public:
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
}

template<typename T>
void display(const forward_list<T> &fl)
{
    cout<<"[ ";

    for(const auto &elem : fl)
    {
        cout<<elem<<" ";
    }

    cout<<"]";
}

int main()
{
/*
Forward lists are of dynamic size. They are uni-directional(singly-linked). std::forward_list has a lesser overhead than std::list.

Direct element access is not provided(.at() and [] are not supported).

For more information refer: "https://en.cppreference.com/w/cpp/container/forward_list"

Time complexities of different operations in std::forward_list:
1. Rapid insertion and deletion of elements anywhere in the container -> Constant time.

Reverse iterators are not available, iterators invalidate when corresponding element is deleted.
*/

/*
Forward lists are represented as:
        ---------      ---------      ---------
        |       |      |       |      |       |
        |   1   |----->|   2   |----->|   3   |
        |       |      |       |      |       |
        ---------      ---------      ---------
            ^
            |
  front() __|
*/
    forward_list<int> test_1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    // cout<<"Size [test_1]    : "<<test_1.size()<<"\n"; // .size() is not available for std::forward_list.
    cout<<"Max Size [test_1]: "<<test_1.max_size()<<"\n";
    cout<<"Front [test_1]   : "<<test_1.front()<<"\n";
    // cout<<"Back [test_1]    : "<<test_1.back()<<"\n"; // .back() is not available for std::forward_list.
    cout<<"\n";

    cout<<"Adding 0 to the front of the Forward List: \n";

    test_1.push_front(0); // This will add '0' to the front of the forward_list.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"After poping the element from the front of the Forward List: \n";

    test_1.pop_front(); // This will remove the element from the front of the forward_list.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    forward_list<Person> SimpsonFamily;

    SimpsonFamily.resize(6);

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    SimpsonFamily.clear();

    Person Homer {"Homer J Simpson", 39};

    SimpsonFamily.push_front(Homer);
    SimpsonFamily.push_front(Person {"Marge Bouvier", 36});
    SimpsonFamily.emplace_front("Bart Simpson", 10);
    SimpsonFamily.emplace_front("Lisa Simpson", 8);
    SimpsonFamily.emplace_front("Maggie Simpson", 1);
    SimpsonFamily.emplace_front("Abraham Simpson", 83);

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    cout<<"Simpson Family after sorting the elements according to their age: \n";

    SimpsonFamily.sort();

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    forward_list<int>::iterator test_1_it = find(test_1.begin(), test_1.end(), 3); // We could also use "auto test_1_it = find(test_1.begin(), test_1.end(), 3);".

    cout<<"test 1 after inserting -1 in front of 3: \n";

    test_1.insert_after(test_1_it, -1);

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    test_1.insert_after(test_1_it, -2); // '-2' will be added in front of '-1'.
    test_1.emplace_after(test_1_it, -3); // '-3' will be added in front of '-2'.

    cout<<"test 1 after inserting -2 and -3 in front of -1: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"test 1 after removing all the added elements: \n";

    test_1.erase_after(test_1_it); // This will remove '-3'.
    test_1.erase_after(test_1_it); // This will remove '-2'.
    test_1.erase_after(test_1_it); // This will remove '-1'.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    return 0;
}