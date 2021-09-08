#ifndef _STRINGV2_H_
#define _STRINGV2_H_

class stringv2
{
private:
	static int object_count; // Counts the number of active objects.

	int id; // Each object has a unique ID, helpful to identify constructor and destructor calls.
	char *str;
public:
	stringv2(); // No-args constructor
	stringv2(const char *str); // Overloaded constructor

	stringv2(const stringv2 &source); // Copy constructor

	stringv2(stringv2 &&source); // Move constructor

	~stringv2(); // Destructor

	stringv2& operator=(const stringv2 &rhs); // Copy assignment
	stringv2& operator=(stringv2 &&rhs); // Move assignment

	stringv2 operator-() const; // Unary - Operator ---> Used to convert to lower-case representation.
	stringv2 operator+() const; // Unary + Operator ---> Used to convert to upper-case representation.

	stringv2 operator+(const stringv2 &rhs) const; // Binary + Operator ---> Used for concatenation.
	bool operator==(const stringv2 &rhs) const; // Binary Equality Operator ---> Used to compare two strings.

	int get_length() const; // Getter
	const char *get_string() const; // Here since we are returning a pointer we need to make sure not to change it, so we need to return it as const(now only a constant pointer can be assigned to it).

	void display() const;
};
#endif