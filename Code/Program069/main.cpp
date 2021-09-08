/*
Created by  : Vaisakh Dileep
Date		: 16, January, 2021
Description : This program helps to understand the protected access-specifier in C++.
*/

#include<iostream>

using namespace std;

class Base // Base class
{
public:
	int public_int_variable {};

protected:
	int protected_int_variable {};

private:
	int private_int_variable {};
};

class Derived_public: public Base // Public inheritance
{
	void access_base_elements()
	{
		public_int_variable = 0; // Access-specifier: public

		protected_int_variable = 0; // Access-specifier: protected

		// private_int_variable = 0; // This will give an error
	}
};

class Derived_protected: protected Base // Protected inheritance
{
	void acccess_base_elements()
	{
		public_int_variable = 0; // Access-specifier: protected

		protected_int_variable = 0; // Access-specifier: protected

		// private_int_variable = 0; // This will give an error
	}
};

class Derived_private: private Base // Private inheritance
{
	void access_base_elements()
	{
		public_int_variable = 0; // Access-specifier: private

		protected_int_variable = 0; // Access-specifier: private

		// private_int_variable = 0; // This will give an error
	}
};

int main()
{
/*
Syntax for using protected access specifier:
Class Base
{
protected:
	// protected Base class members ....
}
*/

/*
Protected class members can be accessible:
1. From the Base class itself.
2. From the Derived classes to the Base class.
But,
They are not accessible by the objects of Base or Derived class.
*/

/*
Public Inheritance:
Base class                                      Derived class

public: a            Public Inheritance         public: a
protected: b   ------------------------------>  protected: b
private: c                                      c: Not accessible


Protected Inheritance:
Base class                                      Derived class

public: a          Protected Inheritance        protected: a
protected: b   ------------------------------>  protected: b
private: c                                      c: Not accessible

Private Inheritance:
Base class                                      Derived class

public: a           Private Inheritance         private: a
protected: b   ------------------------------>  private: b
private: c                                      c: Not accessible
*/
	Base base_object {};

	base_object.public_int_variable = 0;
	// base_object.protected_int_variable = 0; // The commented statements will generate an error.
	// base_object.private_int_variable = 0;

	Derived_public derived_public_object {};

	derived_public_object.public_int_variable = 0;
	// derived_public_object.protected_int_variable = 0;
	// derived_public_object.private_int_variable = 0;

	Derived_protected derived_protected_object {};

	// derived_protected_object.public_int_variable = 0;
	// derived_protected_object.protected_int_variable = 0;
	// derived_protected_object.private_int_variable = 0;

	Derived_private derived_private_object {};

	// derived_private_object.public_int_variable = 0;
	// derived_private_object.protected_int_variable = 0;
	// derived_private_object.private_int_variable = 0;

	return 0;
}