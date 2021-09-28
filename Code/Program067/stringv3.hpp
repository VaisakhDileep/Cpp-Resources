#ifndef _STRINGV3_H_
#define _STRINGV3_H_

#include<iostream>

class stringv3
{
    friend stringv3 operator-(const stringv3 &obj); // We declare this as a friend function because this will save us time declaring getter functions.
    friend stringv3 operator+(const stringv3 &obj);

    friend stringv3 &operator++(stringv3 &obj); // ++s1; --> Here notice we are returning by reference.

    friend stringv3 operator++(stringv3 &obj, int); // s1++; --> Here notice we aren't returning by reference, because we aren't returning the original object(original object is incremented) but we are returning a copy of the object before it was incremented.

    friend bool operator==(const stringv3 &lhs, const stringv3 &rhs);
    friend bool operator!=(const stringv3 &lhs, const stringv3 &rhs);
    friend bool operator<(const stringv3 &lhs, const stringv3 &rhs);
    friend bool operator>(const stringv3 &lhs, const stringv3 &rhs);

    friend stringv3 operator+(const stringv3 &lhs, const stringv3 &rhs);
    friend stringv3 operator*(const stringv3 &lhs, int rhs);

    friend stringv3 &operator+=(stringv3 &lhs, const stringv3 &rhs); // Notice here we are returning by reference.
    friend stringv3 &operator*=(stringv3 &lhs, int rhs); // Notice here we are returning by reference.

    friend std::ostream &operator<<(std::ostream &os, const stringv3 &rhs); // Stream insertion operator
    friend std::istream &operator>>(std::istream &is, stringv3 &rhs); // Stream extraction operator
private:
    static int object_count; // Counts the number of active objects.

    int id; // Each object has a unique ID, helpful to identify constructor and destructor calls.
    char *str;
public:
    stringv3(); // No-args constructor
    stringv3(const char *str); // Overloaded constructor

    stringv3(const stringv3 &source); // Copy constructor

    stringv3(stringv3 &&source); // Move constructor

    ~stringv3(); // Destructor

// Note overloading assignment operator(=) should always be included as member methods.
    stringv3 &operator=(const stringv3 &rhs); // Copy assignment

    stringv3 &operator=(stringv3 &&rhs); // Move assignment

    int get_length() const; // Getter
    const char *get_string() const; // Here since we are returning a pointer we need to make sure not to change it, so we need to return it as const(now only a constant pointer can be assigned to it).

    void display() const;
};

#endif