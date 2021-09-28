/*
Created by  : Vaisakh Dileep
Date        : 7, February, 2021
Description : This program helps to understand STL iterators in C++.
*/

#include<iostream>

#include<vector>

#include<set> // For std::set

#include<iterator>

#include<map> // For std::map

using namespace std;

int main()
{
/*
Iterators allows abstracting an arbitrary container as a sequence of elements. They are objects that work like pointers by design. Most container classes can be traversed with iterators(except stack and queues).

For std::vector, we can randomly access the elements(using [] and .at()), so we don't necessarily need iterators, but for other STL containers we need them.
*/

/*
Syntax for declaring an iterator:
container_type::iterator_type iterator_name;

egs:
std::vector<int>::iterator it1;
std::list<std::string>::iterator it2;
std::map<std::string, std::string>::iterator it3;
std::set<char>::iterator it4;
*/

/*
For the vector std::vector<int> vec {1, 2, 3};
             -----------------
             | 1 | 2 | 3 |   |
             -----------------
             :               :
             :               :
vec.begin()<-:               :-> vec.end() [location after the last element]
*/

// Refer "C++STL-IteratorOperations" in "Additional Resources" for the different operators supported on iterators.

    vector<int> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int>::iterator digits_it;

    digits_it = digits.begin();
    cout<<"First element in digits vector              : "<<*digits_it<<"\n";

    ++digits_it;
    cout<<"After incrementing the iterator             : "<<*digits_it<<"\n";

    --digits_it;
    cout<<"After decrementing the iterator             : "<<*digits_it<<"\n";

    digits_it += 2;
    cout<<"After adding 2 to the iterator              : "<<*digits_it<<"\n";

    digits_it -= 2;
    cout<<"After subracting 2 from the iterator        : "<<*digits_it<<"\n";

    digits_it = digits.end() - 1;
    cout<<"Last element in digits vector               : "<<*digits_it<<"\n";

    *digits_it = -1; // We can even update the elements in the container using iterators.
    cout<<"Last element in digits vector after updating: "<<digits[9]<<"\n\n";

    vector<int> vec {1, 2, 3};

    vector<int>::iterator vec_it = vec.begin(); // Here we are creating and initializing an iterator at the same time(we could replace it with "auto vec_it = vec.begin()").

    cout<<"vec: [ ";

    while(vec_it != vec.end())
    {
        cout<<*vec_it<<" ";
        
        ++vec_it;
    }

    cout<<"]\n\n";

    cout<<"vec: [ ";

    for(auto it = vec.begin(); it != vec.end(); it++) // Here we can use "auto" if we are delcaring and initializing the iterator at the same time.
    {
        cout<<*it<<" ";
    }

    cout<<"]\n\n";

    set<string> suits {"Clubs", "Hearts", "Spades", "Diamonds"};

    auto set_it = suits.begin();

    cout<<"suits: [ ";

    while(set_it != suits.end())
    {
        cout<<*set_it<<" ";

        ++set_it;
    }

    cout<<"]\n\n";


    vector<int>::reverse_iterator vec_rev_it = vec.rbegin();

    cout<<"vec: [ ";

    while(vec_rev_it != vec.rend())
    {
        cout<<*vec_rev_it<<" ";

        ++vec_rev_it;
    }

    cout<<"]\n\n";
/*	
Use:
    begin() and end() for iterator [vector<int>::iterator]
Use:
    cbegin() and cend() for const_iterator [vector<int>::const_iterator]
Use:
    rbegin() and rend() for reverse_iterator [vector<int>::reverse_iterator]
Use:
    crbegin() and crend() for const_reverse_iterator [vector<int>::const_reverse_iterator]
*/
    vector<int> months {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    vector<int>::const_iterator month_it = months.begin(); // or we could use "auto month_it = months.cbegin()"

    // *month_it = -1; // This will give an error because it is a "const_iterator".

    map<string, int> simpson_family {{"Homer J Simpson", 39}, {"Marge Bouvier", 36}, {"Bart Simpson", 10}, {"Lisa Simpson", 8}, {"Maggie Simpson", 1}};

    auto simpson_family_it = simpson_family.begin();

    cout<<":::::::::::::::::::: Simpson Family ::::::::::::::::::::\n";

    while(simpson_family_it != simpson_family.end())
    {
        cout<<"Name: "<<simpson_family_it->first<<"\n";
        cout<<"Age : "<<simpson_family_it->second<<"\n\n";

        ++simpson_family_it;
    }

    return 0;
}