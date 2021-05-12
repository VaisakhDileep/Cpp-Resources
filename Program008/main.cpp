/*
Created by  : Vaisakh Dileep
Date		: 17, December, 2020
Description : This program helps to understand expressions, statements and operators in C++.
*/

#include<iostream>

using namespace std;

int main()
{
/*
Expressions: They are the sequence of operators and operands that specifies a computation and returns a value.
			egs: 32 (literal), test_scores (variable), 1.5 * 3.2 (multiplication), a > b (relational expression), a = b(assignment expression)
*/

/*
Statements: A statement is a complete line of code that performs some action, they are terminated by ';' and usually contains expressions in them.
		   egs: int x; (declaration), test_number = 12; (assignment), 1.5 + 32.3; (expression), if(a > b) cout<<"a is greater than b"; (if statement), ; (null statement).
*/

/*
Operators can be grouped as:
1. Assignment Operator.
2. Arithmetic Operator.
3. Increment/Decrement Operator.
4. Relational Operator.
5. Logical Operator.
6. Member access Operator(Accessing an array using []).
*/

// Assignment Operator(=): Syntax lhs = rhs, where rhs is an expression that evaluates to a value, the value of rhs should be type compatible with lhs.
	int number_1 {0};

	int number_2 {0}; // Here '0' is not assigned but initialized.

	number_1 = 100; // This is an assignment statement, here rhs is an expression('100' is an integer literal) and it evaluates to '100' which is then passed to lhs.
/*
Every assignment statement has an r-value and l-value.

l-value(locator-value): It refers to the memory location which identifies an object.It may be at the right hand or the left hand side of the assignment operator('='). l-value often represents an identifier.

r-value: It refers to the data value that is stored at some address in memory. An r-value is an expression that can't have a value assigned to it, which means r-value can only appear on the right hand side of the assignment operator('='), but never the left hand side of the operator.

In the above statement(line no 37), "number_1" is the l-value and '100' is the r-value (because '100' is an integer literal and does not have a memory address associated with it).
*/

	cout<<"number_1: "<<number_1<<"\n";
	cout<<"number_2: "<<number_2<<"\n\n";

	number_1 = number_2 = 200; // We can chain assignment operator it is evaluated from right to left.

	cout<<"number_1: "<<number_1<<"\n";
	cout<<"number_2: "<<number_2<<"\n\n";

/*
Arithmetic Operator:
	+ - Addition
	- - Subtraction
	* - Multiplication
	/ - Division
	% - Modulo or Remainder
	
	+, -, *, / --> These operators are overloaded to work with multiple types such as int, double, etc.

	% --> Only for integer types.
*/
	int operand_1 {200}, operand_2 {100}, result {0};

	result = operand_1 + operand_2; // Addition.

	cout<<operand_1<<" + "<<operand_2<<" = "<<result<<"\n";

	result = operand_1 - operand_2; // Subtraction

	cout<<operand_1<<" - "<<operand_2<<" = "<<result<<"\n";

	result = operand_1 * operand_2; // Multiplication

	cout<<operand_1<<" * "<<operand_2<<" = "<<result<<"\n";

	result = operand_1 / operand_2; // Division

	cout<<operand_1<<" / "<<operand_2<<" = "<<result<<"\n";

	result = operand_1 % operand_2; // Modulo or Remainder

	cout<<operand_1<<" % "<<operand_2<<" = "<<result<<"\n\n";

// Follow PEMDAS(Parenthesis Exponent Multiplication Division Addition Subtraction) rule when dealing with multiple operators in an expression.

	cout<<"(1 / 5): "<<(1 / 5)<<"\n";

	cout<<"(1.0 / 5.0): "<<(1.0 / 5.0)<<"\n";

/*
Increment and Decrement Operator: They are used with integers, floating points and pointers. They increment or decrement the operand by '1'.
	++ - Increment Operator
	-- - Decrement Operator

	++a or --a ----> Prefix Notation
	a++ or a-- ----> Postfix Notation
*/

	int counter {0};

	cout<<"counter    : "<<counter<<"\n";

	cout<<"counter++  : "<<counter++<<"\n"; // Here first counter is evaluated to give '0' and then it is incremented.

	counter = 0;

	cout<<"++counter  : "<<++counter<<"\n"; // Here, first counter is incremented and then evaluated to give '1'.

	counter = 0;

	cout<<"counter + 1: "<<(counter + 1)<<"\n\n"; // Here, first (counter + 1) is evaluted to give '1'.

/*
	b = ++a; is equivalent to: a = a + 1; b = a;

	b = a++; is equivalent to: b = a; a = a + 1;
*/

/*
Mixed Type Expression and Conversion:

C++ operations occur on same type operands. If operands are of different types, C++ converts one(coercion). The lower type gets converted to a higher type(promotion).

Implicit type conversion(coercion) heirarchy: bool -> char -> short int -> int -> unsigned int -> long -> unsigned -> long long -> float -> double -> long double.

If coercion is not possible, then compiler will generate an error.
*/

// Example for promotion:

	cout<<"2 * 5.7: "<<(2 * 5.7)<<"\n"; // Here '2' is promoted to '2.0' and then evaluated

// Example for demotion:

	int flag {0};

	flag = 100.2; // Here 100.2 is demoted to 100 and then evaluated.

	cout<<"flag: "<<flag<<"\n";

// Implicit type conversion has a problem. Consider the following code.

	int total_amount {100}, total_number {8};

	double average {0.0};

	average = total_amount / total_number; // Here since "total_amount" and "total_number" are integers, the result is also an integer, this integer is then type casted to float and then assigned to "average".

	cout<<"average: "<<average<<"\n"; // This is not the desired output.

	average = static_cast<double>(total_amount) / static_cast<double>(total_number); // Here we use explicit type casting.

	cout<<"average: "<<average<<"\n"; // We get the desired output.

	average = (double)total_amount / (double)total_number; // Here we use C-style explicit type casting, prefer "static_cast" over this.

	cout<<"average: "<<average<<"\n\n";

// Testing for equality: '==' and '!=', they evaluate to either "true" or "false"('1' or '0').

	// cout<<" 100 == 200 : "<<100 == 200<<"\n"; // Always make sure to add parenthesis when using ==, otherwise it may give an error.

	cout<<"100 == 200: "<<(100 == 200)<<"\n";
	cout<<"100 != 200: "<<(100 != 200)<<"\n\n";

	cout<<boolalpha; // This will make sure sure True is represented by "true" rather '1' and False is represented by "false" rather than '0'.

	cout<<"100 == 200: "<<(100 == 200)<<"\n";
	cout<<"100 != 200: "<<(100 != 200)<<"\n\n";

	cout<<noboolalpha; // This will reset False as '0' and True as '1'.

	cout<<"100 == 200: "<<(100 == 200)<<"\n";
	cout<<"100 != 200: "<<(100 != 200)<<"\n\n";

/*
Relational Operators:
	>   - Greater than
	>=  - Greater than or equal to
	<   - Lesser than
	<=  - Lesser than or equal to
	<=> - Three-way comparison
*/

	cout<<boolalpha;

	cout<<"10 > 20 : "<<(10 > 20)<<"\n";
	cout<<"10 >= 20: "<<(10 >= 20)<<"\n";
	cout<<"10 < 20 : "<<(10 < 20)<<"\n";
	cout<<"10 <= 20: "<<(10 <= 20)<<"\n\n";

/*
Logical Operators:
	not - !  - negation    (unary)
	and - && - Logical and (binary, "true" only when both the inputs are "true")
	or  - || - Logical or  (binary, "false" only when both the inputs are "false")

Precedence of Logical Operators: not > and > or.
*/

	cout<<"!true                 : "<<(!true)<<"\n";

	cout<<"not true              : "<<(not true)<<"\n";

	cout<<"(10 < 20) and (10 > 5): "<<((10 < 20) and (10 > 5))<<"\n";

	cout<<"(10 < 20) && (10 > 5) : "<<((10 < 20) && (10 > 5))<<"\n";

	cout<<"(10 > 20) or (10 < 5) : "<<((10 > 20) or (10 < 5))<<"\n";

	cout<<"(10 > 20) || (10 < 5) : "<<((10 > 20) || (10 < 5))<<"\n\n";

/*
Short circuit Evaluation: C++ stops evaluating when the result is known.

expression_1 && expression_2 && expression_3: If expression_1 is "false", then there is no point in evaluating the other expressions, it will result in "false".

expression_1 || expression_2 || expression_3: If expression_1 is "true", then there is no point in evaluating the other expressions, it will result in "true".
*/

/*
Bitwise Operation:
	&  - Binary AND              --> It copies a bit to the result if it exists in both operands.
	|  - Binary OR               --> It copies a bit if it exists in either operands.
	^  - Binary XOR              --> It copies the bit if it is set in one operand but not both.
	~  - Binary One's Complement --> It is an unary operator, it flips the bits.
	<< - Binary Left Shift       --> It moves the left operand's bits left by the number specified by the right operand.
	>> - Binary Right Shift      --> It moves the left operand's bits right by the number specified by the right operand.
*/

// Consider variables a and b:
	int a {60}, b {13}; // a --> 0011 1100, b --> 0000 1101
	
	cout<<"a & b   : "<<(a & b)<<"\n";		//    0011 1100
											//    0000 1101
											//   -----------
											//    0000 1100 (12)
	
	cout<<"a | b   : "<<(a | b)<<"\n";		//    0011 1100
											//    0000 1101
											//   -----------
											//    0011 1101 (61)
	
	cout<<"a ^ b   : "<<(a ^ b)<<"\n";		//    0011 1100
											//    0000 1101
											//   -----------
											//    0011 0001 (49)
						
	cout<<"~a	   : "<<~a<<"\n";			//    0011 1100
											//   -----------
											//    1100 0011 (-61), One's Complement.
	
	cout<<"a << 2  : "<<(a << 2)<<"\n";		//    0011 1100
											//   -----------
											//    1111 0000 (240)
	
	cout<<"a >> 2  : "<<(a >> 2)<<"\n\n";   //    0011 1100
											//   ----------- 
											//    0000 1111 (15)
/*

Compound Assignment operators:
			Arithmetic Operations
	+= ---> lhs += rhs; ---> lhs = lhs + rhs;
	-= ---> lhs -= rhs; ---> lhs = lhs - rhs;
	*= ---> lhs *= rhs; ---> lhs = lhs * rhs;
	/= ---> lhs /= rhs; ---> lhs = lhs / rhs;
	%= ---> lhs %= rhs; ---> lhs = lhs % rhs;

			Bitwise Operations
	>>= ---> lhs >>= rhs; ---> lhs = lhs >> rhs;
	<<= ---> lhs <<= rhs; ---> lhs = lhs << rhs;
	&=  ---> lhs &= rhs;  ---> lhs = lhs & rhs;
	^=  ---> lhs ^= rhs;  ---> lhs = lhs ^ rhs;
	|=  ---> lhs |= rhs;  ---> lhs = lhs | rhs;
*/

/*
Change Caluclator: This program computes the change for the amount given.
	1 dollar  = 100 cents
	1 quarter = 25 cents
	1 dime    = 10 cents
	1 nickel  = 5 cents
	1 penny   = 1 cent
*/

	const int dollar_value {100}, quarter_value {25}, dime_value {10}, nickel_value {5};

	int dollars {}, quarters {}, dimes {}, nickels {}, pennies {}; // {} automatically initializes the variables to '0'.

	int balance {};

	cout<<"Enter the amount in cents: ";

	cin>>balance;

	dollars = balance / dollar_value;
	balance %= dollar_value;

	quarters = balance / quarter_value;
	balance %= quarter_value;

	dimes = balance / dime_value;
	balance %= dime_value;

	nickels = balance / nickel_value;
	balance %= nickel_value;

	pennies = balance;

	cout<<"The change to be provided is: \n";

	cout<<"DOLLARS : "<<dollars<<"\n";
	cout<<"QUARTERS: "<<quarters<<"\n";
	cout<<"DIMES   : "<<dimes<<"\n";
	cout<<"NICKELS : "<<nickels<<"\n";
	cout<<"PENNIES : "<<pennies<<"\n\n";

	return 0;
}