/*
Created by  : Vaisakh Dileep
Date        : 8, January, 2021
Description : This program helps to understand operator overloading in C++.
*/

// Note: This program is continued in "Program067" because we can't use member methods to overload stream insertion and extraction operator(in the traditional way).

#include<iostream>

#include<vector>

#include "stringv2.hpp"

using namespace std;

void compare_fruits(stringv2, stringv2);

int main()
{
/*
Operator Overloading: It means using traditional operators(+, =, *, etc.) with user-defined types. Operator overloading is not done automatically(except for the assignment operator).

Suppose we have a "Number" class that models any number.
Then,
    Number result = multiply(add(a, b), divide(c, d)); // Using functions

                    ..... or .....

    Number result = (a.add(b)).multiply(c.divide(d)); // Using member methods

                    ..... or .....

    Number result = (a + b) * (c / d); // Using operator overloading

Majority of C++ operators can be overloaded except for:
:: ------> Scope Resolution operator
:? ------> Conditional operator
.* ------> Pointer to a member operator
. -------> dot operator
sizeof --> sizeof operator
    
Rules for operator overloading:
1. Precedence and associativity cannot be changed.
2. 'arity' cannot be changed(cannot make division operator unary).
3. Cannot overload operators for primary types(int, double, etc.).
4. Can't create new operators.
5. [], (), ->, = must be declared as member methods.
6. Other operators can be declared as member methods or global functions.
*/
    {
        cout<<"------------------------- Calling Constructors -------------------------\n\n";

        stringv2 empty; // No-args constructor called
        empty.display();

        stringv2 also_empty {}; // No-args constructor called here too
        also_empty.display();

        stringv2 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv2 ElHomo {Homer}; // Copy constructor called
        ElHomo.display();

        vector<stringv2> TheSimpsons;

        TheSimpsons.push_back("Homer J Simpson");
        TheSimpsons.push_back("Marge Bouvier");
        TheSimpsons.push_back("Bartholomew J Simpson");
        TheSimpsons.push_back("Lisa J Simpson");
        TheSimpsons.push_back("Maggie J Simpson");

        for(auto &character : TheSimpsons)
        {
            character.display();
        }
    }

/*
Overloading the Copy Assignment Operator(=): C++ provides a default assignment operator used for assigning one object to another(default is memberwise assignment[shallow copy]).

Syntax for overloading the copy assignment operator(deep copy):
    Type &Type::operator=(const Type &rhs);
*/
    {
        cout<<"------------------------- Calling Copy Assignment Operator -------------------------\n\n";

        stringv2 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv2 ElHomo = Homer; // This is not assignment but initialization, it is equivalent to "stringv2 ElHomo {Homer}".
                                // Copy constructor called
        ElHomo.display();

        stringv2 Max_Payne {"Max Payne"}; // Overloaded constructor called
        Max_Payne.display();

        Max_Payne = "Guy Incognito"; // Step through the debugger to understand this line of code. Here first a temporary object is created and the overloaded constructor is called to construct it, after that the temporary object is then assigned to "Max_Payne"(copy assigned) after that the destructor is called for the temporary object.
        Max_Payne.display();

        Max_Payne = stringv2 {"Max Power"}; // This is equivalent to the above line of code. ***** NOTE: Move assignment operator overides the expected output. Make sure to comment out the Move Assignment code *****.
        Max_Payne.display();

        Homer = ElHomo = Max_Payne; // Copy assignment can be chained.

        Homer.display();
        ElHomo.display();
        Max_Payne.display();
    }

/*
Overloading the Move Assignment Operator(=) : If we don't provide an overloaded move assignment, then the copy assignment is called.

Syntax for overloading the move assignment:
Type &Type::operator=(Type &&rhs);
*/
    {
        cout<<"------------------------- Calling Move Assignment Operator -------------------------\n\n";

        stringv2 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv2 ElHomo {}; // No-args constructor called

        ElHomo = "Max Payne"; // First the overloaded constructor is called to construct a temporary object and then the move assignment is called.
        ElHomo.display();

        Homer = ElHomo = "Guy Incognito"; // First the overloaded constructor is called to construct a temporary object and then the move assignment is called for "ElHomo" and then the copy assignment is called for "Homer".
    }

/*
Overloading unary operator:

Syntax for overloading unary operator:
ReturnType Type::operatorOp(); // Where "Op" corresponds to the unary operator.

Unary Operators: -, +, ++, --, &, *(Dereferencing), sizeof, !(NOT), ~(One's Complement)

Some examples of member method declaration for overloaded unary operators:
Number Number::operator-();
Number Number::operator++(); // pre-increment
Number Number::operator++(int); // post-increment
bool Number::operator!();
*/
    {
        cout<<"------------------------- Calling Unary Operators -------------------------\n\n";

        stringv2 Homer {"HOMER J SIMPSON"}; // Overloaded constructor called
        Homer.display();

        stringv2 Homer_lower_case {}; // No-args constructor called

        Homer_lower_case = -Homer; // Unary - operator called
        Homer_lower_case.display();

        stringv2 Homer_upper_case {}; // No-args constructor called

        Homer_upper_case = +Homer_lower_case; // Unary + operator called
        Homer_upper_case.display();
    }

/*
Overloading binary operator:

Syntax for overloading binary operator:
ReturnType Type::operatorOp(const &Type rhs); // Where "Op" corresponds to the binary operator.

Binary Operators ---> Refer https://www.tutorialspoint.com/cplusplus/cpp_operators.htm

Some examples of member method declaration for overloaded binary operators:
Number Number::operator+(const &Number rhs);
Number Number::operator-(const &Number rhs);
bool Number::operator==(const &Number rhs);
bool Number::operator<(const &Number rhs);
*/
    {
        cout<<"------------------------- Calling Binary Operators -------------------------\n\n";

        stringv2 First_Name {"Homer"}; // Overloaded constructor called
        First_Name.display();

        stringv2 Middle_Name {"Jay"}; // Overloaded constructor called
        Middle_Name.display();

        stringv2 Last_Name {"Simpson"}; // Overloaded constructor called
        Last_Name.display();

        stringv2 Full_Name_v1 {}; // No-args constructor called

        Full_Name_v1 = First_Name + "." + " " + "." + Middle_Name + "." + " " + "." + Last_Name;
        Full_Name_v1.display();

        stringv2 Full_Name_v2 {}; // No-args constructor called

        // Full_Name_v2 = "Homer " + Middle_Name + " " + Last_Name; // This will give an error. Please note that the left most part of the rhs should always be an object.

        stringv2 fruit_1 {"Bannanna"}; // Overloaded constructor called
        fruit_1.display();

        stringv2 fruit_2 {"Apple"}; // Overloaded constructor called
        fruit_2.display();

        stringv2 fruit_3 {"Bannanna"}; // Overloaded constructor called
        fruit_3.display();

        compare_fruits(fruit_1, fruit_2);
        compare_fruits(fruit_1, fruit_3);
        compare_fruits(fruit_1, "Apple");
        compare_fruits("Apple", fruit_1);
        compare_fruits("U.S.A", "U.S.A"); // Notice here all combinations work.

        cout<<"\n"<<(fruit_1 == fruit_2)<<" [fruit_1 == fruit_2]\n";
        cout<<(fruit_1 == "Bannanna")<<" [fruit_1 == \"Bannanna\"]\n\n";
        // cout<<("Bannanna" == fruit_1)<<" [\"Bannanna\" == fruit_1]\n"; // This will create an error. Please note that the left most part of the rhs should always be an object.
        // cout<<(fruit_1 == fruit_2 == fruit_3)<<" [fruit_1 == fruit_2 == fruit_3]\n"; // We can't chain equality operator.
    }
    return 0;
}

void compare_fruits(stringv2 fruit_1, stringv2 fruit_2)
{
    cout<<"\n-------------------------\n";
    cout<<fruit_1.get_string()<<((fruit_1 == fruit_2) ? " == " : " != ")<<fruit_2.get_string()<<"\n";
    cout<<"-------------------------\n\n";
}