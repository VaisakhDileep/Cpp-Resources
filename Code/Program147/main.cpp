/*
Created by  : Vaisakh Dileep
Date        : 23, November, 2021
Description : This program helps to understand printf() in C++.
*/

#include<iostream>

using namespace std;

int main()
{
/*
printf() format:
    int printf(const char* format, ...);

"format" contains a "format specifier", "format specifier" generally starts with '%'.

Generally "format specifier" is represented as:
    %[flags][width][.precision][length]specifier
*/

    char char_variable {'a'};

    printf("char_variable: %c\n\n", char_variable); // For printing char variables, we use '%c' as the format specifier.

// Note: '%c' also works for "char" and "unsigned char".

    int int_variable {1};

    printf("int_variable: %d\n", int_variable); // For printing signed int variables, we use '%d' as the format specifier.
    printf("int_variable: %i\n\n", int_variable); // For printing signed int variables, we could also use '%i' as the format specifier.

// Note: '%d' and '%i' also works for "short", "unsigned short", "int" and "long".

    unsigned int unsigned_int_variable {2};

    printf("unsigned_int_variable: %u\n\n", unsigned_int_variable); // For printing unsigned int variables, we use '%u' as the format specifier.

// Note: '%u' also works for "unsigned int" and "unsigned long".

    float float_variable {3.4};

    printf("float_variable: %f\n\n", float_variable); // For printing float variables, we use '%f' as the format specifier.

    double double_variable {4.6};

    printf("double_variable: %lf\n\n", double_variable); // For printing double variables, we use '%lf' as the format specifier.

    long double long_double_variable {9.7};

    printf("long_double_variable: %Lf\n\n", long_double_variable); // For printing long double variables, we use '%Lf' as the format specifier.

    char c_style_string[] {"Zachariah Trench"};

    printf("c_style_string: %s", c_style_string); // For printing C-style strings, we use "%s" as the format specifier.

    string str_object {"Casper Darling"};

    printf("str_object: %s", str_object.c_str()); // For printing C++ strings, we need to convert it into a C-style string first.

    return 0;
}