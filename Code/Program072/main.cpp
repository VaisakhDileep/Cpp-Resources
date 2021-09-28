/*
Created by  : Vaisakh Dileep
Date        : 17, January, 2021
Description : This program helps to understand how copy/move constructors and overloaded assignment(=) works when inheriting in C++.
*/

#include<iostream>

using namespace std;

class Base
{
private:
    int value;
public:
    Base()
        : value {0}
    {
        cout<<"No-args constructor called for Base.\n";
    }

    Base(int value)
        : value {value}
    {
        cout<<"Overloaded{int} constructor called for Base.\n";
    }

    Base(const Base &other)
        : value {other.value}
    {
        cout<<"Copy constructor called for Base.\n";
    }

    Base &operator=(const Base &rhs)
    {
        cout<<"Copy assignment called for Base.\n";

        if(this == &rhs)
        {
            return *this;
        }

        value = rhs.value;

        return *this;
    }
};

class Derived: public Base
{
private:
    int double_value;
public:
    Derived()
        : Base {}, double_value {0}
    {
        cout<<"No-args constructor called for Derived.\n";
    }

    Derived(int value)
        : Base {value}, double_value {2 * value}
    {
        cout<<"Overloaded{int} constructor called for Derived.\n";
    }

    Derived(const Derived &other)
        : Base {other}, double_value {other.double_value} // Here "other" is sliced when passing to Base(step through the debugger to understand how slicing works).
    {
        cout<<"Copy constructor called for Derived.\n";
    }

    Derived &operator=(const Derived &rhs)
    {
        cout<<"Copy assignment called for Derived.\n";

        if(this == &rhs)
        {
            return *this;
        }

        Base::operator=(rhs); // This will call the Base's assignment operator.
                            // Here rhs is sliced when passing to Base.
        double_value = rhs.double_value;

        return *this;
    }
};

class Derived_2: public Base // This class generates a compiler generated default copy constructor and copy assignment for us. Notice here the base class's versions are the one's overloaded by us.
{
private:
    int triple_value;
public:
    Derived_2()
        : triple_value {0}
    {
        cout<<"No-args constructor called for Derived 2.\n";
    }

    Derived_2(int value)
        : Base {}, triple_value {3 * value}
    {
        cout<<"Overloaded{int} constructor called for Derived 2.\n";
    }
};

int main()
{
// Copy/Move constructors and overloaded assignment(=) operator are not inherited from the Base class but we can explicitly invoke the Base class versions from the Derived class.

/*
Syntax for explicitly calling Base class's copy constructor:
Derived::Derived(const Derived &other)
    : Base(other), {Derived class's initialization list}
                // Here notice we are passing "other"(which is a derived class object). This is possible because derived "Is-A" base class. The derived object is then sliced(except the base class members all others members are deleted).
{
    // Code
}
*/

/*
If you don't define the copy/move constructors and overloaded assignment(=) operator then the compiler will create them and automatically call the base class's version.

If you provide the copy/move constructor then make sure to invoke the Base class's version explicitly.

The same applies for move constructor and move assignment.
*/
    {
        Base base_temp {}; // No-args constructor called
        cout<<"\n";

        Base base_ten {10}; // Overloaded{int} constructor called
        cout<<"\n";

        Base base_ten_copy {base_ten}; // Copy constructor called
        cout<<"\n";

        base_temp = base_ten; // Copy assignment called
        cout<<"\n";
    }

    cout<<"\n";

    {
        Derived derived_temp {}; // No-args constructor called
        cout<<"\n";

        Derived derived_ten {10}; // Overloaded{int} constructor called
        cout<<"\n";

        Derived derived_ten_copy {derived_ten}; // Copy constructor called
        cout<<"\n";

        derived_temp = derived_ten; // Copy assignment called
        cout<<"\n";
    }

    cout<<"\n";

    {
        Derived_2 derived_2_temp {}; // No-args constructor called
        cout<<"\n";

        Derived_2 derived_2_ten {10}; // Overloaded{int} constructor called
        cout<<"\n";

        Derived_2 derived_2_ten_copy {derived_2_ten}; // Copy constructor called
        cout<<"\n";

        derived_2_temp = derived_2_ten; // Copy assignment called
        cout<<"\n";
    }

    return 0;
}