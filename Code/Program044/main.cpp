/*
Created by  : Vaisakh Dileep
Date        : 30, December, 2020
Description : This program helps to understand implementation of member methods in C++.
*/

#include<iostream> // '<>' here means that we are including system header files and the compiler knows where they are located.

#include "AccountPrototypeThree.h" // '""' here means include header files that are local to the file.

#define Flag 100 // This will define "Flag" as '100'.

#ifndef Flag
#define Flag 99 // Because "Flag" is already defined this will not execute.
#endif

// --------------- Account Prototype One ---------------

class AccountPrototypeOne // This is how to implement methods inside the class.
{
private:
    double balance;
public:
    void set_balance(double account_balance)
    {
        balance = account_balance;
    }

    double get_balance()
    {
        return balance;
    }
};

// --------------- Account Prototype Two ---------------

class AccountPrototypeTwo // This is how to implement methods outside the class.
{
private:
    double balance;
public:
    void set_balance(double account_balance); // This is a method prototype.
    double get_balance();
};

void AccountPrototypeTwo::set_balance(double account_balance)
{
    balance = account_balance;
}

double AccountPrototypeTwo::get_balance()
{
    return balance;
}

using namespace std;

int main()
{
/*
Member methods have access to member attributes ,so we don't have to pass them as arguments.

The following methods can be used to implement member methods in C++ classes:
1. Can be implemented inside the class declaration, but here the method is implicitly inline. So if the method is large don't go for this method.
2. Can be implemented outside the class declaration, here we need to use scope resolution --> Class_Name::method_name.
3. Can be separately specified from implementation --> .h is for class declaration, .cpp is for the class implementation.
*/
    cout<<"Flag: "<<Flag<<"\n\n";

    AccountPrototypeOne accountOne;
    AccountPrototypeTwo accountTwo;
    AccountPrototypeThree accountTree;

    accountOne.set_balance(100);
    accountTwo.set_balance(101);
    accountTree.set_balance(102);

    cout<<"Balance: "<<accountOne.get_balance()<<"\n";
    cout<<"Balance: "<<accountTwo.get_balance()<<"\n";
    cout<<"Balance: "<<accountTree.get_balance()<<"\n\n";

    return 0;
}