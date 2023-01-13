/*
Created by  : Vaisakh Dileep
Date        : 20, January, 2021
Description : This program helps to understand virtual functions in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

// Note: Virtual functions are used 

class Account
{
public:
    virtual void withdraw(double amount)
    {
        cout<<"withdraw() called from Account class.\n";
    }

    virtual ~Account()
    {
        cout<<"Destructor called from Account class.\n";
    }
};

class Savings: public Account
{
public:
    virtual void withdraw(double amount) // It is not necessary to provide virtual keyword in derived class, but it is a good programming practice to do so.
    {
        cout<<"withdraw() called from Savings class.\n";
    }

    virtual ~Savings() // Not necessary only base destructor need to be virtual, the derived classes need not be declared virtual but it is good programming practice to do so.
    {
        cout<<"Destructor called from Savings class.\n";
    }
};

class Checking: public Account
{
public:
    virtual void withdraw(double amount)
    {
        cout<<"withdraw() called from Checking class.\n";
    }

    virtual ~Checking()
    {
        cout<<"Destructor called from Checking class.\n";
    }
};

class Trust: public Savings
{
public:
    virtual void withdraw(double amount)
    {
        cout<<"withdraw() called from Trust class.\n";
    }

    virtual ~Trust()
    {
        cout<<"Destructor called from Trust class.\n";
    }
};

void display(Account &account) // This will work because derived "Is-A" base class.
{
    cout<<"Output: ";

    account.withdraw(0.0);
}

int main()
{
/*
Virtual functions are bound dynamically(Dynamic Polymorphism). Virtual functions are overriden, they allow us to treat all objects generally as objects of Base class(abstraction).

Note: Virtual functions are virtual all the way down the hierarchy from the Base point(so don't need to include virtual keyword for the classes below the Base class)
Note: Dynamic polymorphism only works with pointers and references.
Note: Virtual functions cannot be global or static, since virtual function relies on object to determine which implementation to choose.


Syntax for declaring virtual functions:
class Base
{
public:
    virtual return_type method_name(parameters);
    // ... code ...
};

Note: In order for virtual functions to work the function signature and return type should match exactly.
*/

/*
The class hierarchy used is:
       Account
          ^
          |
     _____|_____
     |         |
  Savings   Checking
     ^
     |
   Trust
*/

/*
If a derived class is deleted via the base class pointer and the class has a non-virtual destructor, then this will give give a warning(it will only call the base class's destructor not the derived class's).

If a base class destructor is virtual then all derived class destructors are virtual as well.

Note: If you have virtual functions, then make sure to use virtual destructors as well.
*/
    Account *account_1 = new Account();
    Account *account_2 = new Savings();
    Account *account_3 = new Checking();
    Account *account_4 = new Trust();

    vector<Account*> account_vector = {account_1, account_2, account_3, account_4};

    for(auto account_pointer : account_vector) // See this helps us achieve abstraction, we just have to create a base class object and store them in a vector, it is handled differently with the help of virtual functions.
    {
        account_pointer->withdraw(100);

        cout<<"\n";
    }

    cout<<"\n";

    for(auto account_pointer : account_vector)
    {
        display(*account_pointer);
    }

    cout<<"\n";

    delete account_1;
    cout<<"\n";

    delete account_2;
    cout<<"\n";

    delete account_3;
    cout<<"\n";

    delete account_4;
    cout<<"\n";

    Account account_5;
    Savings account_6;
    Checking account_7;
    Trust account_8;

    Account &account_9 = account_5;
    Account &account_10 = account_6;
    Account &account_11 = account_7;
    Account &account_12 = account_8;

    account_9.withdraw(200);
    cout<<"\n";

    account_10.withdraw(200);
    cout<<"\n";

    account_11.withdraw(200);
    cout<<"\n";

    account_12.withdraw(200);
    cout<<"\n";

    return 0;
}