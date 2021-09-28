/*
Created by  : Vaisakh Dileep
Date        : 26, December, 2020
Description : This program helps to understand pointer arithmetics in C++.
*/

#include<iostream>

#include<string>

using namespace std;

int main()
{
/*
++ - Increments the pointer to point to the next array element.
-- - Decrements the pointer to point to the previous array element.

+ - Increments the pointer value by n * sizeof(type).
- - Decrements the pointer value by n * sizeof(type).
If the other operand is a pointer then it will evaluate only if the two pointers, points to the same data type.

== and != - Determines if two pointers point to the same location.
*/

    string s1 {"Homer"};
    string s2 {"Homer"};

    string *ptr1 {&s1};
    string *ptr2 {&s2};
    string *ptr3 {&s1};

    cout<<boolalpha;

    cout<<"ptr1 == ptr2: "<<(ptr1 == ptr2)<<"\n"; // See even though the value inside "s1" and "s2" are equal, it is false because "s1" and "s2" are stored in different memory locations.
    cout<<"ptr1 == ptr3: "<<(ptr1 == ptr3)<<"\n\n"; // Always include logical expressions inside parethesis when printing.

    cout<<"*ptr1 == *ptr2: "<<(*ptr1 == *ptr2)<<"\n";
    cout<<"*ptr1 == *ptr3: "<<(*ptr1 == *ptr3)<<"\n\n";

    int scores[] {100, 98, 88, 99, -1}; // Here '-1' represents the end of the array.

    int *scores_ptr {scores};

    cout<<"Looping through the array: ";

    while(*scores_ptr != -1)
    {
        cout<<*scores_ptr<<"  ";

        scores_ptr++; // This will make "score_ptr" point to the next array element.
    }

    cout<<"\n\n";

    scores_ptr = scores;

    cout<<"Looping through the array: ";

    while(*scores_ptr != -1)
    {
        cout<<*scores_ptr++<<"  "; // Here both '*' and '++' have same precedence but associativity is from right to left, therefore first "score_ptr" is incremented and then dereferenced.
    }

    cout<<"\n\n";

// The below code segment explains the use-case for subtracting two pointers.
    char name[] {"Refrigerator"}; // C-style string.

    char *char_ptr1 {nullptr};
    char *char_ptr2 {nullptr};

    char_ptr1 = &name[0];
    char_ptr2 = &name[11];

    cout<<"In the string "<<name<<", "<<*char_ptr2<<" is "<<(char_ptr2 - char_ptr1)<<" characters away from "<<*char_ptr1<<".\n\n";

    int style[] {1, 2, 3, 4, 5};

    int *int_ptr1 {nullptr};
    int *int_ptr2 {nullptr};

    int_ptr1 = &style[0];
    int_ptr2 = &style[4];

    cout<<"In the integer array, "<<*int_ptr1<<" is "<<(int_ptr2 - int_ptr1)<<" indices away from "<<*int_ptr2<<"\n";

    return 0;
}