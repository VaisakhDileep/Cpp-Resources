/*
Created by  : Vaisakh Dileep
Date        : 6, February, 2021
Description : This program helps to understand generic programming using Class Templates in C++.
*/

#include<iostream>

#include<string>

#include<vector>

using namespace std;

// Note: Template classes are typically completely contained in header files. We can include a template class in a '.h' file, we don't need a '.cpp' file because template classes are just a blueprint and it is compiled later.

template<typename T1, typename T2> // We can replace "typename" with class.
class My_Pair_Class // There is a similar function "std::pair()" which comes with the <utility> header file.
{
private:
    T1 first;
    T2 second;
public:
    My_Pair_Class(T1 first, T2 second)
    {
        this->first = first;

        this->second = second;
    }

    T1 get_first()
    {
        return first;
    }

    T2 get_second()
    {
        return second;
    }
};

template<typename T1, typename T2> // We can also use struct templates
struct My_Pair_Struct
{
    T1 first;
    T2 second;
};

template<typename T, int N> // Here "N" is a non-type template parameter.
class Array // Since C++11 the STL has "std::array" which is a template-based array class, use "std::array" instead of raw arrays because "std::array" contains special algorithms and iterators specified by STL.
{
private:
    int size {N};

    T values[N];

    friend ostream &operator<<(ostream &os, const Array<T, N> &array) // Overloading the << operator.
    {
        os<<"[ ";

        for(const auto &elem : array.values)
        {
            os<<elem<<" ";
        }

        os<<"]";

        return os;
    }
public:
    Array() = default;

    Array(T initial_value)
    {
        for(auto &elem : values)
        {
            elem = initial_value;
        }
    }

    void fill(T value)
    {
        for(auto &elem : values)
        {
            elem = value;
        }
    }

    int get_size() const
    {
        return size;
    }

    T &operator[](int index) // Overloading the [] operator.
    {
        return values[index]; // Here we are returning by reference because suppose we have "1_D_Array[4] = 1", then by precedence the overloaded '[]' is evaluated first, which translates to "1_D_Array.values[4] = 1" and then the '=' opearator is evaluated, here if it was returning a copy then it will not work as we are assigning to a copy and not to the original one.
    }
};

int main()
{
// Note: We can not use two classes with the same name in the same namespace in C++, unlike functions.

// Class template is similar to function templates, they allow us to plug in any data type. Compiler generates the appropriate class from the blueprint. C++ templates are used to create generic classes.

// Class templates becomes complicated when inheritance and dynamic polymorphism comes up.

    My_Pair_Class<int, double> Pair1 {1, 2.1};

    cout<<":::::::::: Pair 1 ::::::::::\n";
    cout<<"First : "<<Pair1.get_first()<<"\n";
    cout<<"Second: "<<Pair1.get_second()<<"\n\n";

    My_Pair_Class<string, string> Pair2 {"Burns", "Curns"};

    cout<<":::::::::: Pair 2 ::::::::::\n";
    cout<<"First : "<<Pair2.get_first()<<"\n";
    cout<<"Second: "<<Pair2.get_second()<<"\n\n";

    My_Pair_Struct<int, double> Pair3 {1, 2.1};

    cout<<":::::::::: Pair 3 ::::::::::\n";
    cout<<"First : "<<Pair3.first<<"\n";
    cout<<"Second: "<<Pair3.second<<"\n\n";

    My_Pair_Struct<string, string> Pair4 {"Burns", "Curns"};

    cout<<":::::::::: Pair 4 ::::::::::\n";
    cout<<"First : "<<Pair4.first<<"\n";
    cout<<"Second: "<<Pair4.second<<"\n\n";

    My_Pair_Struct<string, My_Pair_Struct<string, string>> Pair5 {"Burns", {"Curns", "Fruit Bat Man"}};

    cout<<":::::::::: Pair5 ::::::::::\n";
    cout<<"First : "<<Pair5.first<<"\n";
    cout<<"Second: "<<Pair5.second.first<<", "<<Pair5.second.second<<"\n\n";

    vector<My_Pair_Struct<string, int>> SimpsonFamily;

    SimpsonFamily.push_back(My_Pair_Struct<string, int> {"Homer J Simpson", 39});
    SimpsonFamily.push_back(My_Pair_Struct<string, int> {"Marge Bouvier", 36});
    SimpsonFamily.push_back(My_Pair_Struct<string, int> {"Lisa Simpson", 8});
    SimpsonFamily.push_back(My_Pair_Struct<string, int> {"Bart Simpson", 10});
    SimpsonFamily.push_back(My_Pair_Struct<string, int> {"Maggie Simpson", 1});

    cout<<":::::::::::::::::::: Simpson Family ::::::::::::::::::::\n";

    for(const auto &character : SimpsonFamily)
    {
        cout<<"Name: "<<character.first<<"\n";
        cout<<"Age : "<<character.second<<"\n\n";
    }

    cout<<"\n";

    Array<string, 5> SimpsonFamilyArray {"XXXXXXXXXX"};

    cout<<":::::::::::::::::::: Simpson Family Array Before Assigning ::::::::::::::::::::\n";

    for(int i {0}; i < SimpsonFamilyArray.get_size(); i++)
    {
        cout<<(i + 1)<<". "<<SimpsonFamilyArray[i]<<"\n";
    }

    cout<<"\n";

    SimpsonFamilyArray[0] = "Homer J Simpson";
    SimpsonFamilyArray[1] = "Marge Bouvier";
    SimpsonFamilyArray[2] = "Bart Simpson";
    SimpsonFamilyArray[3] = "Lisa Simpson";
    SimpsonFamilyArray[4] = "Maggie Simpson";

    cout<<":::::::::::::::::::: Simpson Family Array After Assigning ::::::::::::::::::::\n";

    for(int i {0}; i < SimpsonFamilyArray.get_size(); i++)
    {
        cout<<(i + 1)<<". "<<SimpsonFamilyArray[i]<<"\n";
    }

    cout<<"\n";

    SimpsonFamilyArray.fill("");

    cout<<":::::::::::::::::::: Simpson Family Array After Deleting ::::::::::::::::::::\n";

    for(int i = 0; i < SimpsonFamilyArray.get_size(); i++)
    {
        cout<<(i + 1)<<". "<<SimpsonFamilyArray[i]<<"\n";
    }

    cout<<"\n";

    Array<int, 10> index {0};

    for(int i {0}; i < index.get_size(); i++)
    {
        index[i] = i;
    }

    cout<<"Index: "<<index<<"\n\n";

    return 0;
}