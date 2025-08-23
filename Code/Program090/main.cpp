/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2021
Description : Class level exception handling.
*/

#include<iostream>

#include<string>

using namespace std;

class IllegalBalanceException
{
public:
    IllegalBalanceException() = default; // Default constructor

    ~IllegalBalanceException() = default; // Default destructor
};

class Account
{
private:
    string name {};
    double balance {};
public:
    Account(string name, double balance) // Overloaded constructor
        : name {name}, balance {balance}
    {
        if(balance < 0)
        {
            throw IllegalBalanceException {};
        }
    }

    double get_balance()
    {
        return balance;
    }
};

int main()
{
/*
Exceptions can be thrown from within a class.
1. From methods: They work the same way as they do for functions.
2. From constructor: Sometimes constructor may fail(during initialization, if no memory is there or unable to open a particular file). Since constructors do not return any value, we can throw an exception to warn the user if the constructor failed to initialize the object.
3. From destructor: Do not throw exception from destructor.
*/
    try
    {
        Account account_1 {"Homer", -100};

        cout<<"Successfully created the Account object.\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cout<<"Sorry can't initialize the object -- NegativeBalanceException.\n\n";
    }

    try
    {
        Account account_2 {"Homer", 100};

        cout<<"Successfully created the Account object.\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cout<<"Sorry can't initialize the object -- NegativeBalanceException.\n\n";
    }

    return 0;
}