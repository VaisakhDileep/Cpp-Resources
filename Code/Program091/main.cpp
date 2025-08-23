/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2021
Description : std::exception class hierarchy.
*/

#include<iostream>

#include<string>

#include<memory>

using namespace std;

class IllegalBalanceException: public exception // std::exception
{
public:
    IllegalBalanceException() noexcept = default; // "noexcept" tells the compiler that the method does not throw any exception.

    ~IllegalBalanceException() = default;

    virtual const char *what() const noexcept
    {
        return "Illegal Balance Exception";
    }
};

class InsufficientFundException: public exception
{
public:
    InsufficientFundException() noexcept = default;

    ~InsufficientFundException() = default;

    virtual const char *what() const noexcept
    {
        return "Insufficient Fund Exception";
    }
};

class Account
{
private:
    string name {};
    double balance {};
public:
    Account(string name, double balance)
        : name {name}, balance {balance}
    {
        if(balance < 0)
        {
            throw IllegalBalanceException {};
        }
    }

    void withdraw(double amount)
    {
        if((balance - amount) < 0)
        {
            throw InsufficientFundException {};
        }

        balance -= amount;
    }

    string get_name()
    {
        return name;
    }

    double get_balance()
    {
        return balance;
    }
};

int main()
{
// C++ provides a class hierarchy for exception classes, where "std::exception" is the base class, all subclasses implement the "what()" virtual function. We can create our own user-defined exception subclass.

// Please refer: https://en.cppreference.com/w/cpp/error/exception

/*
Syntax for what() virtual function:
virtual const char *what() const noexcept;
*/
    try
    {
        Account account_1 {"Homer", -100};

        cout<<"Account object created successfully.\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }
    catch(InsufficientFundException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }

    try
    {
        Account account_2 {"Marge", 200}; // Notice we can't access this object outside the try block.

        cout<<"Account object created successfully.\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }
    catch(InsufficientFundException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }

    unique_ptr<Account> account_2;

    try
    {
        account_2 = make_unique<Account>("Marge", 200); // Notice here we can access the object even outside the try block since we are using pointers.

        cout<<"Account object created successfully.\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }
    catch(InsufficientFundException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }

    try
    {
        account_2->withdraw(100);

        cout<<"Successfully updated account balance for "<<account_2->get_name()<<"\n";

        cout<<"Remaining Balance: "<<account_2->get_balance()<<"\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }
    catch(InsufficientFundException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }

    try
    {
        account_2->withdraw(102);

        cout<<"Successfully updated account balance for "<<account_2->get_name()<<"\n";

        cout<<"Remaining Balance: "<<account_2->get_balance()<<"\n\n";
    }
    catch(IllegalBalanceException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }
    catch(InsufficientFundException &ex)
    {
        cerr<<ex.what()<<"\n\n";
    }

    return 0;
}