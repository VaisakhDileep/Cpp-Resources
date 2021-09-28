#include<iostream>

#include<cstring>

#include "stringv3.hpp"

using namespace std;

int stringv3::object_count {0};

stringv3::stringv3() // No-args constructor
    : str {nullptr}
{
    object_count++;

    id = object_count;

    // cout<<"No-args constructor called ---["<<id<<"]---\n";

    str = new char[1];

    *str = '\0';
}

stringv3:: stringv3(const char *str) // Overloaded constructor
    : str {nullptr} // "this->str" is not necessary here(it will give an error)
{
    object_count++;

    id = object_count;

    // cout<<"Overloaded constructor called --["<<id<<"]---\n";

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

stringv3::stringv3(const stringv3 &source) // Copy constructor
    : str {nullptr}
{
    object_count++;

    id = object_count;

    // cout<<"Copy constructor called ---["<<id<<"]---\n";

    this->str = new char[strlen(source.str) + 1];

    strcpy(this->str, source.str);
}

stringv3::stringv3(stringv3 &&source) // Move constructor
    : str {source.str}
{
    object_count++;

    id = object_count;

    // cout<<"Move constructor called ---["<<id<<"]---\n";

    source.str = nullptr;
}

stringv3::~stringv3() // Destructor
{
    object_count--;

    // cout<<"Destructor called ---["<<id<<"]---\n";

    delete[] str;
}

stringv3 &stringv3::operator=(const stringv3 &rhs) // Copy assignment
{
    // cout<<"Copy assignment called ---["<<(this->id)<<"]---\n";

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

stringv3 &stringv3::operator=(stringv3 &&rhs) // Move assignment
{
    // cout<<"Move assignment called ---["<<(this->id)<<"]---\n";

    if(this == &rhs)
    {
        return *this; // This is useful when chaining assignment operator.
    }
    else
    {
        delete[] this->str;

        this->str = rhs.str; // Steal the pointer

        rhs.str = nullptr;

        return *this; // This is useful when chaining assignment operator.
    }
}

int stringv3::get_length() const
{
    return strlen(str);
}

const char *stringv3::get_string() const
{
    return str;
}

void stringv3::display() const
{
    cout<<"\n-------------------------\n";
    cout<<"String: "<<str<<"\n";
    cout<<"Length: "<<get_length()<<"\n";
    cout<<"ID    : "<<id<<"\n";
    cout<<"-------------------------\n\n";
}

// Friend functions:
stringv3 operator-(const stringv3 &obj) // Unary - Operator
{
    char *buff = new char[strlen(obj.str) + 1];

    strcpy(buff, obj.str);

    for(size_t i {0}; i < strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }

    stringv3 temp {buff};

    delete[] buff;

    return temp;
}

stringv3 operator+(const stringv3 &obj) // Unary + Operator
{
    char *buff = new char[strlen(obj.str) + 1];

    strcpy(buff, obj.str);

    for(size_t i {0}; i < strlen(buff); i++)
    {
        buff[i] = toupper(buff[i]);
    }

    stringv3 temp {buff};

    delete[] buff;

    return temp;
}

stringv3 &operator++(stringv3 &obj) // Unary Pre-Increment(++s) Operator
{
    obj.str[0] = toupper(obj.str[0]);

    return obj;
}

stringv3 operator++(stringv3 &obj, int) // Unary Post-Increment(s++) Operator
{
    stringv3 temp {obj};

    ++obj; // We call the pre-increment operator to increment the object.

    return temp; // This is the copy of the object before the increment.
}

bool operator==(const stringv3 &lhs, const stringv3 &rhs) // Binary == Operator
{
    return(strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const stringv3 &lhs, const stringv3 &rhs) // Binary != Operator
{
    return!(strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const stringv3 &lhs, const stringv3 &rhs) // Binary < Operator
{
    return(strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const stringv3 &lhs, const stringv3 &rhs) // Binary > Operator
{
    return(strcmp(lhs.str, rhs.str) > 0);
}

stringv3 operator+(const stringv3 &lhs, const stringv3 &rhs) // Binary + Operator
{
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];

    strcpy(buff, lhs.str);

    strcat(buff, rhs.str);

    stringv3 temp {buff};

    delete[] buff;

    return temp;
}

stringv3 operator*(const stringv3 &lhs, int rhs)
{
    stringv3 temp;

    for(int i = 0; i < rhs; i++)
    {
        temp = temp + lhs;
    }

    return temp;
}

stringv3 &operator+=(stringv3 &lhs, const stringv3 &rhs)
{
    lhs = lhs + rhs;

    return lhs;
}

stringv3 &operator*=(stringv3 &lhs, int rhs)
{
    lhs = lhs * rhs;

    return lhs;
}

ostream &operator<<(ostream &os, const stringv3 &rhs) // Binary Stream Insertion(<<) Operator
{
    os<<rhs.str;

    return os; // This is useful when chaining stream insertion operators.
}

istream &operator>>(istream &is, stringv3 &rhs) // Binary Stream Extraction(>>) Operator
{
    char *buff = new char[1000];

    is>>buff;

    rhs = stringv3 {buff};

    delete[] buff;

    return is;
}