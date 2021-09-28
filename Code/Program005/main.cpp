/*
Created by  : Vaisakh Dileep
Date        : 15, December, 2020
Description : This program helps to understand variables and constants in C++.
*/

#include<iostream>

#include<climits> // For refrence on <climits>: https://www.cplusplus.com/reference/climits/

#include<cfloat> // For reference on <cfloat>: https://www.cplusplus.com/reference/cfloat/

#define FIFTY_SIX 56

using namespace std;

int global_variable; // This is a global variable, it can be accessed from anywhere in the program. It is automatically initialized to '0'.

int main()
{
// Variable: It is an abstraction for a memory location. It allows programmers to use meaningful names and not memory addresses. Variables have type(integer, real number, Person, Car, Account) and value(10, 0.23, Vaisakh, BMW M8, Vaisakh_s_Account).

    int age;

    age = 21;

/*
Syntax for variable declaration:
    VariableType variable_name;

Rules for naming a variable:
1. Cannot name variables using C++ keywords.
2. C++ variables should always start with either a letter(a-z or A-Z) or an underscore(_), but never a number(0-9).
3. C++ variable name can include letters(a-z or A-Z), numbers(0-9), underscore(_).
4. Multiple variables of the same name should never be declared in the same scope.
*/

    // int age; // This will create an error because we already declared age above.

// There are many ways to initialize a declared variable.
    int test_1; // Uninitialized variable, may contain junk values.

    int test_2 = 2; // C-like initialization

    int test_3(3); // Constructor-like initialization

    int test_4 {4}; // C++ List-like initialization

    cout<<"test_1: "<<test_1<<"\n";
    cout<<"test_2: "<<test_2<<"\n";
    cout<<"test_3: "<<test_3<<"\n";
    cout<<"test_4: "<<test_4<<"\n\n";

    int global_variable {10}; // Local variant of "global_variable".

    cout<<"Global variable: "<<global_variable<<"\n"; // Local variant of "global_variable" overshadows the global variant of "global_variable".

    cout<<"Global variable: "<<::global_variable<<"\n\n"; // Here global variant will be called.

// C++ Primitive Data Types:
    char char_8_bit_variable {}; // 8-bit
    char16_t char_16_bit_variable {}; // 16-bit
    char32_t char_32_bit_variable {}; // 32-bit
    wchar_t char_wide_variable {};

    signed short int int_signed_short_variable {}; // 16-bit
    signed int int_signed_variable {}; // 32-bit
    signed long int int_signed_long_variable {}; // 32-bit(for my system)
    signed long long int int_signed_long_long_variable {}; // 64-bit
// Note: We don't necessarily have to include "signed" because integers are by default "signed".

    unsigned short int int_unsigned_short_variable {}; // 16-bit
    unsigned int int_unsigned_variable {}; // 32-bit
    signed long int int_unsigned_long_variable {}; // 32-bit
    signed long long int int_unsigned_long_long_variable {}; // 64-bit

    float float_variable {}; // Precision: 7 decimal digits.
    double double_variable {}; // Precision: 15 decimal digits.
    long double double_long_variable {}; // Precision: 19 decimal digits.

    bool bool_variable {}; // 8-bit. 'true' and 'false' are C++ keywords.

    signed long int population = 7'600'000'000; // We can use ticks after C++14 for better readability, it will be ignored during the compiling process.

    // signed long int population {7'600'000'000}; // This will give a compiler error which prevents the overflow from every happening(perks of using C++ List-like initialization).

    cout<<"population: "<<population<<"\n"; // Here an overflow happens and we get an unexpected output.

    bool flag = true;

    cout<<"flag: "<<flag<<"\n\n"; // Here even though we pass "true" as the value to "bool_variable", we get output as '1'.

// sizeof() operator: It determines the size in bytes of a type or a variable.
    cout<<"sizeof(char): "<<sizeof(char)<<" bytes.\n";
    cout<<"sizeof(char16_t): "<<sizeof(char16_t)<<" bytes.\n";
    cout<<"sizeof(char32_t): "<<sizeof(char32_t)<<" bytes.\n";
    cout<<"sizeof(wchar_t): "<<sizeof(wchar_t)<<" bytes.\n\n";

    cout<<"sizeof(signed short int): "<<sizeof(signed short int)<<" bytes.\n";
    cout<<"sizeof(signed int): "<<sizeof(signed int)<<" bytes.\n";
    cout<<"sizeof(signed long int): "<<sizeof(signed long int)<<" bytes.\n";
    cout<<"sizeof(signed long long int): "<<sizeof(signed long long int)<<" bytes.\n\n";

    cout<<"sizeof(unsigned short int): "<<sizeof(unsigned short int)<<" bytes.\n";
    cout<<"sizeof(unsigned int): "<<sizeof(unsigned int)<<" bytes.\n";
    cout<<"sizeof(unsigned long int): "<<sizeof(unsigned long int)<<" bytes.\n";
    cout<<"sizeof(unsigned long long int): "<<sizeof(unsigned long long int)<<" bytes.\n\n";

    cout<<"sizeof(float): "<<sizeof(float)<<" bytes.\n";
    cout<<"sizeof(double): "<<sizeof(double)<<" bytes.\n";
    cout<<"sizeof(long double): "<<sizeof(long double)<<" bytes.\n\n";

    cout<<"sizeof(bool): "<<sizeof(bool)<<" bytes.\n\n";

    cout<<"sizeof char_8_bit_variable: "<<sizeof char_8_bit_variable<<" bytes.\n"; // We don't need to introduce parenthesis when dealing with variables.
    cout<<"sizeof char_16_bit_variable: "<<sizeof char_16_bit_variable<<" bytes.\n";
    cout<<"sizeof char_32_bit_variable: "<<sizeof char_32_bit_variable<<" bytes.\n";
    cout<<"sizeof char_wide_variable: "<<sizeof char_wide_variable<<" bytes.\n\n";

    cout<<"sizeof int_signed_short_variable: "<<sizeof int_signed_short_variable<<" bytes.\n";
    cout<<"sizeof int_signed_variable: "<<sizeof int_signed_variable<<" bytes.\n";
    cout<<"sizeof int_signed_long_variable: "<<sizeof int_signed_long_variable<<" bytes.\n";
    cout<<"sizeof int_signed_long_long_variable: "<<sizeof int_signed_long_long_variable<<" bytes.\n\n";

    cout<<"sizeof int_unsigned_short_variable: "<<sizeof int_unsigned_short_variable<<" bytes.\n";
    cout<<"sizeof int_unsigned_variable: "<<sizeof int_unsigned_variable<<" bytes.\n";
    cout<<"sizeof int_unsigned_long_variable: "<<sizeof int_unsigned_long_variable<<" bytes.\n";
    cout<<"sizeof int_unsigned_long_long_variable: "<<sizeof int_unsigned_long_long_variable<<" bytes.\n\n";

    cout<<"sizeof float_variable: "<<sizeof float_variable<<" bytes.\n";
    cout<<"sizeof double_variable: "<<sizeof double_variable<<" bytes.\n";
    cout<<"sizeof double_long_variable: "<<sizeof double_long_variable<<" bytes.\n\n";

// Finding minimum values for different data types using "climits".
    cout<<"MINIMUM VALUES:\n";

    cout<<"char: "<<CHAR_MIN<<"\n\n";

    cout<<"signed short int: "<<SHRT_MIN<<"\n";
    cout<<"signed int: "<<INT_MIN<<"\n";
    cout<<"signed long int: "<<LONG_MIN<<"\n";
    cout<<"signed long long int: "<<LLONG_MIN<<"\n\n"; // minimum value for signed and unsigned int types are same.

    cout<<"float: "<<FLT_MIN<<"\n";
    cout<<"double: "<<DBL_MIN<<"\n";
    cout<<"long double: "<<LDBL_MIN<<"\n\n";

// Finding maximum values for different data types using "climits".
    cout<<"MAXIMUM VALUES:\n";

    cout<<"char: "<<CHAR_MAX<<"\n\n";

    cout<<"signed short int: "<<SHRT_MAX<<"\n";
    cout<<"signed int: "<<INT_MAX<<"\n";
    cout<<"signed long int: "<<LONG_MAX<<"\n";
    cout<<"signed long long int: "<<LLONG_MAX<<"\n\n";

    cout<<"unsigned short int: "<<USHRT_MAX<<"\n";
    cout<<"unsigned int: "<<UINT_MAX<<"\n";
    cout<<"unsigned long int: "<<ULONG_MAX<<"\n";
    cout<<"unsigned long long int: "<<ULLONG_MAX<<"\n\n";

    cout<<"float: "<<FLT_MAX<<"\n";
    cout<<"double: "<<DBL_MAX<<"\n";
    cout<<"long double: "<<LDBL_MAX<<"\n\n";

// Constants: Same like variables, but their value cannot change once declared.

    // Literal Constants:
    int literal_constant {12}; // Here '12' is a literal constant.

    // Integer literal prefixes: 0b(Binary), 0(Octal), 0x(Hexadecimal).
    cout<<"Decimal equivalent of Binary 10: "<<0b10<<"\n";
    cout<<"Decimal equivalent of Octal 10: "<<010<<"\n";
    cout<<"Decimal equivalent of Hexadecimal 10: "<<0x10<<"\n\n";

    // Integer literal suffixes: U(unsigned), L(long), LL(long long).
    cout<<"-21U: "<<-21U<<"\n";
    cout<<"-21L: "<<-21L<<"\n";
    cout<<"-21LL: "<<-21LL<<"\n";
    cout<<"-21UL: "<<-21UL<<"\n";
    cout<<"-21ULL: "<<-21ULL<<"\n\n";

    // Float literal suffixes: F(float), L(long double).
    cout<<"12.1F: "<<12.1F<<"\n";
    cout<<"12.1L: "<<12.1L<<"\n\n";

    // Escape code: They are character literal constants. egs: \n(newline), \t(tab), \r(return), \'(single quote), \"(double quote), \\(backslash).

// Declared Constants: Use "const" keyword.
    const double declared_constant {10.2}; // Value cannot be changed after declaring.

    // const int number_days_in_year; // This will give an error because we cannot use an uninitialized constant variable in our program.

// Defined Constants: #defined constants. See line no '13'. This method is not recommended with modern C++.

    cout<<"FIFTY_SIX: "<<FIFTY_SIX<<"\n";

    return 0;
}