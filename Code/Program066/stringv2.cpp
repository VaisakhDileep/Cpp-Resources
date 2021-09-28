#include<iostream>

#include<cstring>

#include "stringv2.hpp"

using namespace std;

int stringv2::object_count {0};

stringv2::stringv2() // No-args constructor
    : str {nullptr}
{
    object_count++;

    id = object_count;

    cout<<"No-args constructor called ---["<<id<<"]---\n";

    str = new char[1];

    *str = '\0';
}

stringv2::stringv2(const char *str) // Overloaded constructor
    : str {nullptr} // this->str is not necessary here(it will give an error)
{
    object_count++;

    id = object_count;

    cout<<"Overloaded constructor called ---["<<id<<"]---\n";

    if(str == nullptr)
    {
        this->str = new char[1];

        *(this->str) = '\0';
    }
    else
    {
        this->str = new char[strlen(str) + 1];

        strcpy(this->str, str);
    }
}

stringv2::stringv2(const stringv2 &source) // Copy constructor
    : str {nullptr}
{
    object_count++;

    id = object_count;

    cout<<"Copy constructor called ---["<<id<<"]---\n";

    this->str = new char[strlen(source.str) + 1];

    strcpy(this->str, source.str);
}

stringv2::stringv2(stringv2 &&source) // Move constructor
    :str {source.str}
{
    object_count++;

    id = object_count;

    cout<<"Move constructor called ---["<<id<<"]---\n";

    source.str = nullptr;
}

stringv2::~stringv2() // Destructor
{
    object_count--;

    cout<<"Destructor called ---["<<id<<"]---\n";

    delete[] str;
}

stringv2 &stringv2::operator=(const stringv2 &rhs) // Copy assignment
{
    cout<<"Copy assignment called ---["<<(this->id)<<"]---\n";

    if(this == &rhs)
    {
        return *this; // This is useful when chaining assignment operator.
    }
    else
    {
        delete[] this->str;

        this->str = new char[strlen(rhs.str) + 1];

        strcpy(this->str, rhs.str);

        return *this; // This is useful when chaining assignment operator.
    }
}

stringv2 &stringv2::operator=(stringv2 &&rhs) // Move assignment
{
    cout<<"Move assignment called ---["<<(this->id)<<"]---\n";

    if(this == &rhs)
    {
        return *this; // This is useful when chaining assignment operator.
    }
    else
    {
        delete[] this->str;

        this->str = rhs.str; // Steal the pointer.

        rhs.str = nullptr;

        return *this; // This is useful when chaining assignment operator.
    }
}

stringv2 stringv2::operator-() const // Unary - Operator
{
    char *buff = new char[strlen(this->str) + 1]; // Make sure to find a way to delete this allocated heap memory, otherwise it will cause memory leak when the pointer runs out of scope.

    strcpy(buff, this->str);

    for(size_t i {0}; i < strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }

    stringv2 temp {buff}; // Here we create a temporary object so that we can pass this object as return, we can now destroy the heap memory before the pointer runs out of scope[The temporary object is destroyed with the help of destructor, so no need to worry about the temporary object].

    delete[] buff;

    return temp;
}

stringv2 stringv2::operator+() const // Unary + Operator
{
    char *buff = new char[strlen(this->str) + 1];

    strcpy(buff, this->str);

    for(size_t i {0}; i < strlen(buff); i++)
    {
        buff[i] = toupper(buff[i]);
    }

    stringv2 temp {buff};

    delete[] buff;

    return temp;
}

stringv2 stringv2::operator+(const stringv2 &rhs) const // Binary + Operator
{
    char *buff = new char[strlen(this->str) + strlen(rhs.str) + 1];

    strcpy(buff, this->str);

    strcat(buff, rhs.str);

    stringv2 temp {buff};

    delete[] buff;

    return temp;
}

bool stringv2::operator==(const stringv2 &rhs) const // Binary Equality Operator
{
    return (strcmp(this->str, rhs.str) == 0);
}

int stringv2::get_length() const
{
    return strlen(str);
}

const char *stringv2::get_string() const
{
    return str;
}

void stringv2::display() const
{
    cout<<"\n-------------------------\n";
    cout<<"String: "<<str<<"\n";
    cout<<"Length: "<<get_length()<<"\n";
    cout<<"ID    : "<<id<<"\n";
    cout<<"-------------------------\n\n";
}