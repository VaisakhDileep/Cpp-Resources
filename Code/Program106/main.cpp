/*
Created by  : Vaisakh Dileep
Date        : 8, February, 2021
Description : This program helps to understand std::vector in STL sequence containers in C++.
*/

#include<iostream>

#include<vector> // For std::vector

#include<algorithm> // For std::sort

using namespace std;

class Person
{
private:
    friend ostream &operator<<(ostream &os, const Person &person);

    string name;
    int age;
public:
    Person() = default;

    Person(string name, int age)
    {
        this->name = name;

        this->age = age;
    }

    bool operator<(const Person &rhs) const // We need to include the overloaded '==' and overloaded '<' whenever we want to use a user-defined object with STL algorithms.
    {
        return this->age < rhs.age;
    }

    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name) and (this->age == rhs.age);
    }
};

ostream &operator<<(ostream &os, const Person &person)
{
    os<<"\""<<person.name<<"\""<<":"<<person.age;

    return os;
}

template<typename T>
void display(const vector<T> &vec)
{
    cout<<"[ ";

    for(const auto &elem : vec)
    {
        cout<<elem<<" ";
    }

    cout<<"]";
}

int main()
{
/*
Vectors are dynamic in size, they are handled automatically. They can expand and contract as needed. Elements in a vector are stored contiguously in memory as in arrays.

Time Complexities for different operations on vectors:
1. Direct element access -> Constant time.
2. Rapid insertion and deletion at the back -> Constant time.
3. Insertion or removal of elements(other than at the back) -> Linear time.

All iterators are available and may invalidate.
*/

// For more information refer: "https://en.cppreference.com/w/cpp/container/vector"

    vector<int> test_1 {1, 2, 3, 4, 5}; // Here we are using an initialization list.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    vector<int> test_2(10, 1); // Here '10' 1's will be inserted into the vector(overloaded constructor is called).

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    cout<<"For test 1: \n";
    cout<<"Size of the vector              : "<<test_1.size()<<"\n"; // size() returns the actual size of the vector.
    cout<<"Maximum size the vector can hold: "<<test_1.max_size()<<"\n";
    cout<<"Capacity of the vector          : "<<test_1.capacity()<<"\n\n"; // capacity() returns the amount of space the vector is actually using. It is either equal to or greater than what the size() returns. If the number of elements in the vector exceeds the capacity, then the vector is reallocated.

    test_1.push_back(6);

    cout<<"For test 1: \n";
    cout<<"Size of the vector              : "<<test_1.size()<<"\n";
    cout<<"Maximum size the vector can hold: "<<test_1.max_size()<<"\n";
    cout<<"Capacity of the vector          : "<<test_1.capacity()<<"\n\n"; // This might vary with different computers but in my computer the size exceeds the capacity so it is reallocated and the new capacity becomes doubled.

    test_1.shrink_to_fit(); // From C++11

    cout<<"For test 1: \n";
    cout<<"Size of the vector              : "<<test_1.size()<<"\n";
    cout<<"Maximum size the vector can hold: "<<test_1.max_size()<<"\n";
    cout<<"Capacity of the vector          : "<<test_1.capacity()<<"\n\n"; // Here notice that the capacity shrinks to the size of the vector.

    test_1.reserve(100);

    cout<<"For test 1: \n";
    cout<<"Size of the vector              : "<<test_1.size()<<"\n";
    cout<<"Maximum size the vector can hold: "<<test_1.max_size()<<"\n";
    cout<<"Capacity of the vector          : "<<test_1.capacity()<<"\n\n"; // Here notice that we are increasing the capacity to '100'.

    test_1[0] = -1;

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    test_1.at(0) = 1; // .at() is preferred as it does bound checking.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n\n";

    vector<Person> SimpsonFamily;

    Person Homer {"Homer J Simpson", 39};
    SimpsonFamily.push_back(Homer); // Here "Homer" is copied.

    SimpsonFamily.push_back(Person {"Marge Bouvier", 36}); // Here the temporary object is first created and then moved.

    SimpsonFamily.emplace_back("Bart Simpson", 10); // Here the values we pass to emplace_back() are used to construct the object, it is better than copying and moving.
    SimpsonFamily.emplace_back("Lisa Simpson", 8);
    SimpsonFamily.emplace_back("Maggie Simpson", 1);

    cout<<"Simpson Family: ";
    display(SimpsonFamily);
    cout<<"\n\n";

    cout<<"For Simpson Family: \n";
    cout<<"Front: "<<SimpsonFamily.front()<<"\n";
    cout<<"Back : "<<SimpsonFamily.back()<<"\n\n";

    SimpsonFamily.pop_back();

    cout<<"Simpson Family: ";
    display(SimpsonFamily); // Notice here that "Maggie" is missing from the vector.
    cout<<"\n\n";

    test_2.clear(); // This will delete all the elements in the vector.

    cout<<"For test 2: \n";
    cout<<"Size of the vector              : "<<test_2.size()<<"\n";
    cout<<"Maximum size the vector can hold: "<<test_2.max_size()<<"\n";
    cout<<"Capacity of the vector          : "<<test_2.capacity()<<"\n\n";

    test_2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    vector<int>::iterator test_2_it = test_2.begin(); // We could use "auto test_2_it = test_2.begin();"

    while(test_2_it != test_2.end())
    {
        if((*test_2_it % 2) == 0) // This will erase all the even numbers in the vector.
        {
            test_2.erase(test_2_it);
        }
        else
        {
            test_2_it++; // Make sure to increment only if it doesn't erase, otherwise we will end up incrementing twice.
        }
    }

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    cout<<"test 1 and test 2 before swapping: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    test_1.swap(test_2); // We could also use "test_2.swap(test_1);". Note: we can swap even if the arrays are of different size, but they should always be of the same type.

    cout<<"test 1 and test 2 after swapping: \n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    test_2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout<<"test 2 before sorting: \n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    sort(test_2.begin(), test_2.end());

    cout<<"test 2 after sorting: \n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    test_1 = {11, 12, 13, 14, 15};

    cout<<"test 1 and test 2 before copying(std::copy()) :\n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    copy(test_1.begin(), test_1.end(), back_inserter(test_2)); // This will insert all the elements of "test_1" to the back of "test_2".
// back_inserter constructs a back-insert iterator, that inserts new elements at the end of the container. back-insert iterator is a special type of output iterator designed to allow algorithms that usually overwrite elements to instead insert new elements automatically at the end of the container.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    test_1 = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    test_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"test 1 and test 2 before copying(std::copy_if()) :\n";

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    copy_if(test_1.begin(), test_1.end(), back_inserter(test_2), [](int x) { return (x > 10); }); // This will insert the elements of "test_1" to the back of "test_2" only if they are greater than '10'.

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2 : ";
    display(test_2);
    cout<<"\n\n";

    test_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"Multiplying the corresponding elements of test 1 and test 2:\n";

    vector<int> result {};

    cout<<"test 1: ";
    display(test_1);
    cout<<"\n";

    cout<<"test 2: ";
    display(test_2);
    cout<<"\n\n";

    transform(test_1.begin(), test_1.end(), test_2.begin(), back_inserter(result), [](int x, int y) { return x * y; });

    cout<<"Result: ";
    display(result);
    cout<<"\n\n";

    cout<<"Inserting 3 in between 2 and 4 in test 1:\n";

    test_1 = {0, 1, 2, 4 ,5, 6, 7, 8, 9, 10};

    cout<<"Before[test 1]: ";
    display(test_1);
    cout<<"\n\n";

    vector<int>::iterator test_1_it = find(test_1.begin(), test_1.end(), 4); // We could also use "auto test_1_it = find(test_1.begin(), test_1.end(), 4);".

    if(test_1_it != test_1.end())
    {
        test_1.insert(test_1_it, 3);
    }
    else
    {
        cout<<"Sorry, not able to find the element to iterate on ...\n";
    }

    cout<<"After[test 1]: ";
    display(test_1);
    cout<<"\n\n";

    cout<<"Inserting {3, 4, 5, 6, 7} in between 2 and 8 in test 1:\n";

    test_1 = {1, 2, 8, 9, 10};

    vector<int> missing_elements = {3, 4, 5, 6, 7};

    cout<<"Before[test 1]: ";
    display(test_1);
    cout<<"\n\n";

    test_1_it = find(test_1.begin(), test_1.end(), 8);

    if(test_1_it != test_1.end())
    {
        test_1.insert(test_1_it, missing_elements.begin(), missing_elements.end());
    }
    else
    {
        cout<<"Sorry, not able to find the element to iterate on ...\n";
    }

    cout<<"After[test 1]: [ ";
    for_each(test_1.begin(), test_1.end(), [](int x) { cout<<x<<" "; }); // We can also use "std::for_each()" to iterate over the contents of the vector.
    cout<<"]\n\n";

    test_1 = {}; // Here we clear the vector.

    cout<<boolalpha;

    cout<<"test_1.empty()[after clearing the vector]: "<<test_1.empty()<<"\n";

    return 0;
}