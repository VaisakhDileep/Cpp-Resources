/*
Created by  : Vaisakh Dileep
Date        : 29, December, 2020
Description : This program helps to understand class member access modifiers in C++.
*/

#include<iostream>

#include<string>

using namespace std;

class Account // All members of the class are private by default.
{
private:
    string name;
    double balance;

public:
    bool withdraw(double amount);
    bool deposit(double amount);
};

int main()
{
/*
Class Member Access Modifiers:
1. Public: Accessible everywhere.
2. Private: Accessible only by members or friends of the class.
3. Protected: Used with inheritance.
*/

/*
Syntax for public:

class Class_Name
{
public:
    // declaration(s);
}
*/

/*
Syntax for private:

class Class_Name
{
private:
    // declaration(s); // When accessing a private member outside the class, a compiler error is generated.
}
*/

/*
Syntax for protected:

class Class_Name
{
protected;
    // declaration(s);
}
*/

    Account homer_account;

    // homer_account.name = "Vaisakh"; // This will give a compiler error because "name" is a private member of "Account".

    // cout<<"Name: "<<homer_account.name; // We can't access private members either.

    Account *marge_account = new Account();

    // marge_account->name = "Marge"; // This will give a compiler error because "name" is a private member of "Account".

    // cout<<"Name: "<<marge_account->name; // We can't access private members with pointers either.

    return 0;
}