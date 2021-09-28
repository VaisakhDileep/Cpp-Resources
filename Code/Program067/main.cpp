/*
Created by  : Vaisakh Dileep
Date        : 12, January, 2021
Description : This program helps to understand operator overloading using global functions in C++.
*/

#include<iostream>

#include<vector>

#include "stringv3.hpp"

using namespace std;

void compare_fruits(stringv3, stringv3);

int main()
{
// Note: Including both member and non-member operator overloading functions will result in an error.

/*
Syntax for overloading unary operators using global functions:
ReturnType operatorOp(Type &obj); // Where "Op" corresponds to the unary operator.

Some examples for overloading unary operators using global functions:
Number operator-(const Number &obj);
Number &operator++(Number &obj); // pre-increment
Number operator++(Number &obj, int); // post-increment
bool operator!(const Number &obj);
*/

/*
Syntax for overloading binary operators using global functions:
ReturnType operatorOp(const Type &lhs, const Type &rhs); // Where "Op" corresponds to the binary operator.

Some examples for overloading binary operators using global functions:
Number operator+(const Number &lhs, const Number &rhs);
Number operator-(const Number &lhs, const Number &rhs);
Number operator==(const Number &lhs, const Number &rhs);
Number operator<(const Number &lhs, const Number &rhs);
*/
    {
        cout<<"------------------------- Calling Constructors -------------------------\n\n";

        stringv3 empty; // No-args constructor called
        empty.display();

        stringv3 also_empty {}; // No-args constructor called here too
        also_empty.display();

        stringv3 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv3 ElHomo {Homer}; // Copy constructor called
        ElHomo.display();

        vector<stringv3> TheSimpsons;

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

    {
        cout<<"------------------------- Calling Copy Assignment Operator -------------------------\n\n";

        stringv3 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv3 ElHomo = Homer; // This is not assignment but initialization, it is equivalent to "stringv3 ElHomo {Homer}".
                                // Copy constructor called
        ElHomo.display();

        stringv3 Max_Payne {"Max Payne"}; // Overloaded constructor called
        Max_Payne.display();

        Max_Payne = "Guy Incognito"; // Step through the debugger to understand this line of code. Here fist a temporary object is created and the overloaded constructor is called to construct it, after that the temporary object is then assigned to "Max_Payne"(copy assigned) after that the destructor is called for the temporary object.
        Max_Payne.display();

        Max_Payne = stringv3 {"Max Power"}; // This is equivalent to the above line of code. ***** NOTE: Move assignment operator overides the expected output. Make sure to comment out the Move Assignment *****.
        Max_Payne.display();

        Homer = ElHomo = Max_Payne; // Copy assignment called

        Homer.display();
        ElHomo.display();
        Max_Payne.display();
    }

    {
        cout<<"------------------------- Calling Move Assignment Operator -------------------------\n\n";

        stringv3 Homer {"Homer J Simpson"}; // Overloaded constructor called
        Homer.display();

        stringv3 ElHomo {}; // No-args constructor called
        ElHomo = "Max Payne"; // First the overloaded constructor is called to construct a temporary object and then the move assignment is called.
        ElHomo.display();

        Homer = ElHomo = "Guy Incognito"; // First the overloaded constructor is called to construct a temporary object and then the move assignment is called for "ElHomo" and then the copy assignment is called for "Homer".
    }

    {
        cout<<"------------------------- Calling Unary Operators -------------------------\n\n";

        stringv3 Homer {"HOMER"}; // Overloaded constructor called
        Homer.display();

        stringv3 Homer_lower_case {}; // No-args constructor called

        Homer_lower_case = -Homer; // Unary - operator called
        Homer_lower_case.display();

        stringv3 Homer_upper_case {}; // No-args constructor called

        Homer_upper_case = +Homer_lower_case; // Unary + operator called
        Homer_upper_case.display();

        stringv3 homer {"homer"}; // Overloaded constructor called

        stringv3 temp {}; // No-args constructor called

        temp = homer++; 

        cout<<"homer  : "<<homer<<"\n";
        cout<<"homer++: "<<temp<<"\n\n";

        stringv3 marge {"marge"}; // Overloaded constructor called

        temp = ++marge;

        cout<<"marge  : "<<marge<<"\n";
        cout<<"++marge: "<<temp<<"\n\n";
    }

    {
        cout<<"------------------------- Calling Binary Operators -------------------------\n\n";

        stringv3 First_Name {"Homer"}; // Overloaded constructor called
        First_Name.display();

        stringv3 Middle_Name {"Jay"}; // Overloaded constructor called
        Middle_Name.display();

        stringv3 Last_Name {"Simpson"}; // Overloaded constructor called
        Last_Name.display();

        stringv3 Full_Name_v1 {}; // No-args constructor called

        Full_Name_v1 = First_Name + " " + Middle_Name + " " + Last_Name;
        Full_Name_v1.display();

        stringv3 Full_Name_v2 {}; // No-args constructor called

        Full_Name_v2 = "Homer " + Middle_Name + " " + Last_Name; // Unlike using member methods, this will work.
        Full_Name_v2.display();

        stringv3 Full_Name_v3 {}; // No-args constructor called

        // Full_Name_v3 = "Homer " + "Jay Simpson"; // Here using two consecutive string literals will give an error.

        stringv3 Full_Name_v4 {}; // No-args constructor called

        Full_Name_v4 = stringv3 {"Homer "} + stringv3 {"Jay Simpson"}; // This is possible

        cout<<"Homer: "<<(stringv3 {"Doh "} * 5)<<"\n"; // Repeat operator called

        stringv3 Bart {}; // No-args constructor

        Bart += "El Barto "; // += operator called

        Bart *= 3; // *= operator called

        Bart.display();

        stringv3 fruit_1 {"Bannanna"}; // Overloaded constructor called
        fruit_1.display();

        stringv3 fruit_2 {"Apple"}; // Overloaded constructor called
        fruit_2.display();

        stringv3 fruit_3 {"Bannanna"}; // Overloaded constructor called
        fruit_3.display();

        compare_fruits(fruit_1, fruit_2);
        compare_fruits(fruit_1, fruit_3);
        compare_fruits(fruit_1, "Apple");
        compare_fruits("Apple", fruit_1);
        compare_fruits("U.S.A", "U.S.A"); // Notice here all combinations work

        cout<<"\n"<<(fruit_1 == fruit_2)<<" [fruit_1 == fruit_2]\n";
        cout<<"\n"<<(fruit_1 == "Bannanna")<<" [fruit_1 == \"Bannanna\"]\n";
        cout<<"\n"<<("Bannanna" == fruit_1)<<" [\"Bannanna\" == fruit_1]\n";
        // cout<<"\n"<<("Bannanna" == "Bannanna")<<" [\"Bannanna\" == \"Bannanna\"]\n"; // This won't work, atleast one should be an object.
        cout<<"\n"<<(stringv3 {"Bannanna"} == stringv3 {"Bannanna"})<<" [stringv3 {\"Bannanna\"} == stringv3 {\"Bannanna\"}}]\n";
        // cout<<(fruit_1 == fruit_2 == fruit_3)<<" [fruit_1 == fruit_2 == fruit_3]\n"; // We can't chain equality operator.

        cout<<"\n"<<(fruit_1 != fruit_2)<<" [fruit_1 != fruit_2]\n";
        cout<<"\n"<<(fruit_1 > fruit_2)<<" [fruit_1 > fruit_2]\n";
        cout<<"\n"<<(fruit_2 < fruit_2)<<" [fruit_2 < fruit_2]\n";
    }
/*
It doesn't make sense to implement stream insertion and extraction operator as member methods because then we have to use "cin" and "cout" at the rhs of the equation which is not traditional.
egs:
Homer<<cout;
Homer>>cin;
*/

/*
Syntax for overloading stream insertion operator(<<):
std::ostream &operator<<(std::ostream &os, const Class_Name &obj)
{
    os<<obj.str;

    return os; // For chaining << operator
}
*/

/*
Syntax for overloading stream extraction operator(>>):
std::istream &operator>>(std::istream &is, Class_Name &obj)
{
    char *buff = new char[1000];

    is>>buff;

    obj = Class_Name {buff};

    delete[] buff;

    return is;
}
*/

    {
        cout<<"------------------------- Calling Stream Insertion And Extraction Operators -------------------------\n\n";

        stringv3 Simpson_Character_1 {}, Simpson_Character_2 {}, Simpson_Character_3 {}; // No-args constructor called

        cout<<"Enter any three of your favourite Simpsons characters seperated by spaces: ";

        cin>>Simpson_Character_1>>Simpson_Character_2>>Simpson_Character_3;

        cout<<"The three Simpsons characters you have entered are: "<<Simpson_Character_1<<", "<<Simpson_Character_2<<", "<<Simpson_Character_3<<"\n";
    }

    return 0;
}

void compare_fruits(stringv3 fruit_1, stringv3 fruit_2)
{
    cout<<"\n-------------------------\n";
    cout<<fruit_1.get_string()<<((fruit_1 == fruit_2) ? " == " : " !=")<<fruit_2.get_string()<<"\n";
    cout<<"-------------------------\n\n";
}