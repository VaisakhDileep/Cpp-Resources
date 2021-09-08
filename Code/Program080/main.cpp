/*
Created by  : Vaisakh Dileep
Date		: 22, January, 2021
Description : This program helps to understand interfaces in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

// ------------------------------ Scenario-1 ------------------------------

class Account_1
{
	friend ostream &operator<<(ostream &os, const Account_1 &account_1); // It doesn't make sense to call insertion and extraction operators as member functions.
																		 // friend functions are not inherited.
public:
	virtual void withdraw(double withdraw_amount)
	{
		cout<<"Withdraw called from Account_1.\n";
	}

	virtual ~Account_1() = default; // Equivalent to "virtual ~Account_1() {}"
};

ostream &operator<<(ostream &os, const Account_1 &account_1)
{
	os<<"Account_1";

	return os;
}

class Savings_1: public Account_1
{
	friend ostream &operator<<(ostream &os, const Savings_1 &savings_1);

public:
	virtual void withdraw(double withdraw_amount)
	{
		cout<<"Withdraw called from Savings_1.\n";
	}

	virtual ~Savings_1() {}
};

ostream &operator<<(ostream &os, const Savings_1 &savings_1)
{
	os<<"Savings_1";

	return os;
}

class Checking_1: public Account_1
{
	friend ostream &operator<<(ostream &os, const Checking_1 &checking_1);

public:
	virtual void withdraw(double withdraw_amount)
	{
		cout<<"Withdraw called from Checking_1.\n";
	}

	virtual ~Checking_1() {}
};

ostream &operator<<(ostream &os, const Checking_1 &checking_1)
{
	os<<"Checking_1";

	return os;
}

class Trust_1: public Savings_1
{
	friend ostream &operator<<(ostream &os, const Trust_1 &trust_1);

public:
	virtual void withdraw(double withdraw_amount)
	{
		cout<<"Withdraw called from Trust_1.\n";
	}

	virtual ~Trust_1() {}
};

ostream &operator<<(ostream &os, const Trust_1 &trust_1)
{
	os<<"Trust_1";

	return os;
}

// ------------------------------ Scenario-2 ------------------------------

class I_Printable // Interface names are usually represented as I_*******.
{
	friend ostream &operator<<(ostream &os, const I_Printable &obj);

public:
	virtual void print(ostream &os) const = 0; // Pure virtual functions
};

ostream &operator<<(ostream &os, const I_Printable &obj)
{
	obj.print(os);

	return os;
}

class Account_2: public I_Printable
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"Withdraw called from Account_2.\n";
	}

	virtual void print(ostream &os) const override
	{
		os<<"Account_2";
	}

	virtual ~Account_2() {}
};

class Savings_2: public Account_2
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"Withdraw called from Savings_2.\n";
	}

	virtual void print(ostream &os) const override
	{
		os<<"Savings_2";
	}

	virtual ~Savings_2() {}
};

class Checking_2: public Account_2
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"Withdraw called from Checking_2.\n";
	}

	virtual void print(ostream &os) const override
	{
		os<<"Checking_2";
	}

	virtual ~Checking_2() {}
};

class Trust_2: public Savings_2
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"Withdraw called from Trust_2.\n";
	}

	virtual void print(ostream &os) const override
	{
		os<<"Trust_2";
	}

	virtual ~Trust_2() {}
};

// ------------------------------ Scenario-3 ------------------------------

class Dog: public I_Printable // We can use "I_Printable" interface for other classes as well, which needs to print.
{
public:
	virtual void print(ostream &os) const override
	{
		os<<"Woof, Woof, Woof, Woof ..... ";
	}
};

int main()
{
// C++ does not provide true interfaces, but we use abstract classes and pure virtual functions to achieve it.

	Account_1 *account_1_object = new Account_1();
	Account_1 *savings_1_object = new Savings_1();
	Account_1 *checking_1_object = new Checking_1();
	Account_1 *trust_1_object = new Trust_1();

	vector<Account_1*> account_1_vector = {account_1_object, savings_1_object, checking_1_object, trust_1_object};

	for(const auto account : account_1_vector)
	{
		account->withdraw(100); // Methods are dynamically bound.
	}

	cout<<"\n";

	for(const auto account : account_1_vector)
	{
		cout<<*account<<"\n"; // Friend functions are not dynamically bound.
	}

	cout<<"\n";

	delete account_1_object;
	delete savings_1_object;
	delete checking_1_object;
	delete trust_1_object;

	Account_2 *account_2_object = new Account_2();
	Account_2 *savings_2_object = new Savings_2();
	Account_2 *checking_2_object = new Checking_2();
	Account_2 *trust_2_object = new Trust_2();

	vector<Account_2*> account_2_vector = {account_2_object, savings_2_object, checking_2_object, trust_2_object};

	for(const auto account : account_2_vector)
	{
		account->withdraw(100); // Methods are dynamically bound.
	}

	cout<<"\n";

	for(const auto account : account_2_vector)
	{
		cout<<*account<<"\n";
	}

	cout<<"\n";

	Dog *spike = new Dog();

	cout<<"Spike says: "<<*spike<<"\n\n";

	return 0;
}