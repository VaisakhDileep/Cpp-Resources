/*
Created by  : Vaisakh Dileep
Date        : 17, December, 2020
Description : This program helps to understand vectors in C++.
*/

#include<iostream>

#include<vector> // We need to include this header file to include vectors in our program.

using namespace std; // We need to use std namespace for vectors since they are part of the Standard Template Library.

int main()
{
// In modern C++ prefer vectors over arrays.

// Vectors: It is part of the Standard Template Library, it is like an array that can grow and shrink in size at execution time. It is an object-oriented template class.

    vector<int> test_scores(5); // Here '5' is the size of the vector. Unlike arrays, vectors are automatically initialized to '0', if they are "int" or "float", null character if "char".

    cout<<"test_scores before initialization: ";

    for(int i {0}; i < 5; i++)
    {
        cout<<test_scores[i]<<" ";
    }

    cout<<"\n";

    vector<int> seven_eleven(7, 11); // Here '7' is the size of the vector and '11' is value to be initialized.

    cout<<"seven_eleven: ";

    for(int i {0}; i < 7; i++)
    {
        cout<<seven_eleven[i]<<" ";
    }

    cout<<"\n";

    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    
    cout<<"vowels: ";

    for(int i = 0; i < 5; i++)
    {
        cout<<vowels[i]<<" ";
    }

    cout<<"\n";

// Accessing an element using .at(index) function in vectors.

    cout<<"First element in vowels: "<<vowels.at(0)<<"\n";

// Using .push_back(element) we can add a new element at the end of the vector.

    test_scores.push_back(32);
    test_scores.push_back(43);

    cout<<"The last two elements which we added to test scores are "<<test_scores.at(5)<<" and "<<test_scores.at(6)<<".\n"; // .at() provides bounds checking it will give an error and exception.

    // The .size() function helps to find the size of the vector.

    cout<<"The size of test scores is "<<test_scores.size()<<".\n";

    // 2-D Vectors:

    vector<vector<int>> two_dim_vector_1 {
        {2, 3, 1, 4},
        {1, 3, 4, 5},
        {4, 5, 5, 1}};

    cout<<"two_dim_vector_1: \n";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<two_dim_vector_1.at(i).at(j)<<" ";
        }

        cout<<"\n";
    }

// We can also push back another vector.

    vector<int> first_row {1, 2, 3, 4, 5};
    vector<int> second_row {6, 7, 8, 9, 0};
    vector<int> third_row {1, 2, 3, 4, 5};
    vector<int> fourth_row {6, 7, 8, 9, 0};

    vector<vector<int>> two_dim_vector_2;

    two_dim_vector_2.push_back(first_row);
    two_dim_vector_2.push_back(second_row);
    two_dim_vector_2.push_back(third_row);
    two_dim_vector_2.push_back(fourth_row);

    cout<<"two_dim_vector_2: \n";

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout<<two_dim_vector_2.at(i).at(j)<<" ";
        }

        cout<<"\n";
    }

    return 0;
}