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

    short short_variable {65};

    printf("short_variable: %hi\n\n", short_variable); // For printing short variables, we use '%hi' as the format specifier.

    unsigned short unsigned_short_variable {74};

    printf("unsigned_short_variable: %hu\n\n", unsigned_short_variable); // For printing unsigned short variables, we use '%hu' as the format specifier.

    int int_variable {10};

    printf("int_variable: %d\n", int_variable); // For printing signed int variables, we use '%d' as the format specifier.
    printf("int_variable: %i\n\n", int_variable); // For printing signed int variables, we could also use '%i' as the format specifier.
// Note: '%d' and '%i' also works for "short", "unsigned short", "int" and "long".

    unsigned int unsigned_int_variable {2};

    printf("unsigned_int_variable: %u\n\n", unsigned_int_variable); // For printing unsigned int variables, we use '%u' as the format specifier.
// Note: '%u' also works for "unsigned int" and "unsigned long".

    unsigned long int unsigned_long_int_variable {1000};

    printf("unsigned_long_int_variable: %lu\n\n", unsigned_long_int_variable); // For printing unsigned long int variables, we use '%lu' as the format specifier.
// Note: '%lu' also works for "unsigned int" and "unsigned long".

    long int long_int_variable {872};

    printf("long_int_variable: %ld\n", long_int_variable); // For printing long int variables, we use '%ld' as the format specifier.
    printf("long_int_variable: %li\n\n", long_int_variable); // For printing long int variables, we could also use '%li' as the format specifier.

    long long int long_long_int_variable {9999};

    printf("long_long_int_variable: %lld\n", long_long_int_variable); // For printing long long int variable, we use '%lld' as the format specifier.
    printf("long_long_int_variable: %lli\n\n", long_long_int_variable); // For printing long long int variable, we could also use '%lli' as the format specifier.

    float float_variable {3.4};

    printf("float_variable: %f\n\n", float_variable); // For printing float variables, we use '%f' as the format specifier.

    double double_variable {4.6};

    printf("double_variable: %lf\n\n", double_variable); // For printing double variables, we use '%lf' as the format specifier.

    long double long_double_variable {9.7};

    printf("long_double_variable: %Lf\n\n", long_double_variable); // For printing long double variables, we use '%Lf' as the format specifier.

    char c_style_string[] {"Zachariah Trench"};

    printf("c_style_string: %s\n\n", c_style_string); // For printing C-style strings, we use '%s' as the format specifier.

    string str_object {"Casper Darling"};

    printf("str_object: %s\n\n", str_object.c_str()); // For printing C++ strings, we need to convert it into a C-style string first.

    printf("int_variable(octal representation): %o\n\n", int_variable); // For printing int variables in octal representation, we use '%o' as the format specifier.
// Note: '%o' is also applicable for "short", "unsigned short", "int", "unsigned int" and "long".

    printf("int_variable(hexadecimal representation): %x\n", int_variable); // For printing int variables in hexadecimal representation(lower-case), we use '%x' as the format specifier.
    printf("int_variable(hexadecimal representation): %X\n\n", int_variable); // For printing int variables in hexadecimal representation(upper-case), we use '%X' as the format specifier.
// Note: '%x' and '%X' is also applicable for "short", "unsigned short", "int", "unsigned int" and "long".

    printf("float_variable(exponential format): %e\n", float_variable); // For printing float variables in exponential format(lower-case), we use '%e' as the format specifier.
    printf("float_variable(exponential format): %E\n\n", float_variable); // For printing float variables in exponential format(upper-case), we use '%E' as the format specifier.
// Note: '%e' and '%E' is also applicable for "float" and "double".

    int *int_ptr {new int {0}};

    float *float_ptr {new float {0.0}};

    double *double_ptr {new double {0.0}};

    printf("*int_ptr   : %p\n", int_ptr); // Inorder to print the memory address(hexadecimal representation), we use '%p' as the format specifier.
    printf("*float_ptr : %p\n", float_ptr);
    printf("*double_ptr: %p\n\n", double_ptr); // Similarly for other data-types.

    printf("&int_variable   : %p\n", (void *)(&int_variable)); // If we are '&' to extract the memory address, then make sure to convert it to "void *".
    printf("&float_variable : %p\n", (void *)(&float_variable));
    printf("&double_variable: %p\n\n", (void *)(&double_variable)); // Similarly for other data-types.

// Difference between '%f', '%e' and '%g': If the exponent value is lesser than -4 or greater than the precision '%g' will default to '%e' else it will be represented using '%f'. If there are any padded '0's, it will removed when using '%g'.

    float_variable = 0.0001;

    printf("float_variable(0.0001): %f\n", float_variable);
    printf("float_variable(0.0001): %e\n", float_variable);
    printf("float_variable(0.0001): %g\n\n", float_variable); // Notice here that all the padded '0's which were present when using '%f' were removed. '%g' format is similar to '%f'.

    float_variable = 0.00001;

    printf("float_variable(0.00001): %f\n", float_variable);
    printf("float_variable(0.00001): %e\n", float_variable);
    printf("float_variable(0.00001): %g\n", float_variable); // Notice here that all the padded '0's which were present when using '%e' were removed.'%g' format is similar to '%e'.
    printf("float_variable(0.00001): %G\n\n", float_variable); // '%G' will use the upper-case exponential format.

    float_variable = 100000.0001;

    printf("float_variable(100000.0001): %f\n", float_variable);
    printf("float_variable(100000.0001): %e\n", float_variable);
    printf("float_variable(100000.0001): %g\n\n", float_variable); // "100000.0001" in exponential form is "1.000000001 * 10^9", since the default precision is '6', it is rounded to "100000".

    float_variable = 1000000.0001;

    printf("float_variable(1000000.0001): %f\n", float_variable);
    printf("float_variable(1000000.0001): %e\n", float_variable);
    printf("float_variable(1000000.0001): %g\n", float_variable); // "1000000.0001" in exponential form is "1.00000000001 * 10^10", since the default precision is '6', it is rounded to "1 * 10^6".
    printf("float_variable(1000000.0001): %.7g\n\n", float_variable); // Notice here that since we increased precision to '7', it is displayed in decimal format.

// flags supported in printf():
    int_variable = 15;

    printf("int_variable(octal form)     : %#o\n", int_variable); // '#o' is the octal flag. It will add '0' before the octal representation.

    printf("int_variable(hexadecimal)    : %#x\n", int_variable); // '#x' is also the hexadecimal flag. It will add '0x' before the hexadecimal representation.

    printf("int_variable(right justified): %10d\n", int_variable); // By default the values printed are right justified.

    printf("int_variable(left justified) : %-10d\n", int_variable); // '-' will left justify the value.

    printf("int_variable(zero padded)    : %010d\n", int_variable); // Adding '0' after '%' will pad the extra spaces with '0'(right-justified, so the '0's will added in the beginning).

    printf("int_variable(with sign)      : %+d\n\n", int_variable); // '+' will add a positive sign before positive numbers.

// width field: It is the minimum width required to display the value.
    int_variable = 100;

    printf("int_variable(width = 1): %1d\n", int_variable); // '1' is the minimum width, but our input already has a width of '3'. So '3' is chosen as the width to be displayed.
    printf("int_variable(width = 3): %3d\n", int_variable);
    printf("int_variable(width = 5): %5d\n\n", int_variable); // By default the value to be printed is right justified.

// precision field: It determines the accuracy of the real number. It is the number of digits after the decimal point.
    float_variable = 12.77777777777777777777;

    printf("float_variable(precision = default): %f\n", float_variable); // By default the precision is '6'. The last decimal digit will be rounded.
    printf("float_variable(precision = 2)      : %.2f\n\n", float_variable); // Inorder to have a precision of '2' we need to use '.2' before the format specifier.

    int printf_output {printf("Object of Power\n")}; // printf() outputs the number of characters successfully outputted to the console.

    cout<<"printf_output: "<<printf_output<<"\n";

    return 0;
}