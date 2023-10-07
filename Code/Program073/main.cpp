/*
Created by  : Vaisakh Dileep
Date        : 18, January, 2021
Description : This program helps to understand how to redefine(override) Base class methods in C++.
*/

#include<iostream>

using namespace std;

// ------------------------------ Account ------------------------------
class Account {
    friend ostream &operator<<(ostream &os, const Account &account);

protected:
    double account_balance;
public:
    Account(); // No-args constructor
    Account(double account_balance); // Overloaded(double) constructor

    void deposit(double amount);
    void withdraw(double amount);
};

Account::Account() // No-args constructor
    : Account {0.0} { // Delegating constructor
    cout << "No-args constructor called for Account.\n";
}

Account::Account(double account_balance) // Overloaded(double) constructor
    : account_balance {account_balance} {
    cout << "Overloaded(double) constructor called for Account.\n";
}

void Account::deposit(double amount) {
    account_balance += amount;
}

void Account::withdraw(double amount) {
    if((account_balance - amount) >= 0) {
        account_balance -= amount;
    }
}

ostream &operator<<(ostream &os, const Account &account) {
    os << "Account balance: " << account.account_balance << "\n";

    return os;
}

// ------------------------------ Savings Account ------------------------------
class Savings_Account: public Account {
    friend ostream &operator<<(ostream &os, const Savings_Account &account);

protected:
    double interest_rate;
public:
    Savings_Account(); // No-args constructor
    Savings_Account(double account_balance, double interest_rate); // Overloaded(double, double) constructor

    void deposit(double amount);
    // withdraw() is inherited from Base class
};

Savings_Account::Savings_Account() // No-args constructor
    : Savings_Account {0.0, 0.0} {
    cout << "No-args constructor called for Savings Account.\n";
}

Savings_Account::Savings_Account(double account_balance, double interest_rate)// Overloaded(double, double) constructor
    : Account {account_balance}, interest_rate {interest_rate} {
    cout << "Overloaded(double, double) constructor called for Savings Account.\n";
}

void Savings_Account::deposit(double amount) { // This will redefine(override) the Base class's deposit method.
    amount = amount + (interest_rate / 100) * amount;

    Account::deposit(amount); // This will invoke Base class's deposit method.
}

ostream &operator<<(ostream &os, const Savings_Account &account) {
    os << "Savings account balance: " << account.account_balance << "\nInterest rate: " << account.interest_rate << "\n";

    return os;
}

int main() {
    Account Homer;

    Homer.deposit(100.0); // Here since "Homer" is a base class("Account") object base class's version of deposit is called.
    cout << "\n" << Homer;

    Savings_Account Marge;

    Marge.deposit(200.0); // Here since "Marge" is a derived class("Savings_Account") object derived class's version of deposit is called.
    cout << "\n" << Marge;

// Binding of method calls is done during the compile time. Default binding method for C++ is static.
    Account *Bart = new Savings_Account(); // Here since "Savings_Account" Is-A "Account", this is possible.
    // Savings_Account *Lisa = new Account(); // Every Savings_Account can be an Account, but every Account cannot be a Savings_Account.

    Bart->deposit(1000.0); // Here since "Bart" is a base class("Account") object base class's version of deposit is called(static binding). Dynamic binding can be used here if we want to invoke the derived class's version of deposit.
    cout << "\n" << *Bart;
/*
Multiple Inheritance: Multiple Inheritance happens when a derived class inherits from two or more Base classes at the same time.

Syntax for Multiple Inheritance:
class Derived_Class_1: access_specifier Base_Class_1, access_specifier Base_Class_2 {
    // ... Code ...
};

When both the access_specifiers are public, then we can say that "Derived_Class_1" Is-A "Base_Class_1" and "Derived_Class_1" Is-A "Base_Class_2".
*/
    return 0;
}