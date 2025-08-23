/*
Created by  : Vaisakh Dileep
Date        : 13, December, 2020
Description : Print "Hello, World!" and demonstrate some of the errors in C++.
*/

#include<iostream> // This library helps to include input and output in our program, it is a preprocessor directive.

extern int x; // "extern" keyword tells the computer that a variable is defined in another source module(outside the current) scope. The linker then finds the actual declaration and sets up the "extern" variable to point to the local declaration.

// "Compiling + Linking" is called Building.

int main() { // "main" function is where the program execution starts.

    std::cout << "Hello, World!" << std::endl; // "endl" gives a newline. "Hello, World!" is a string literal. '<<' is the stream insertion operator.

// Compiler Errors are classified as Syntax Error and Semantic Error.

/*
Syntax Error: Occurs when something is wrong with the structure of the program.
         egs: Forgetting to put ';' at the end of the statement.
*/

/*
Semantic Error: Occurs when something is wrong with the meaning of our program.
           egs: Trying to add an integer and a string.
*/

// The below code segment demonstrates compiler warning.
    int junk;

    std::cout << "junk: " << junk << std::endl; // An uninitialized variable will generate a warning.

    int unused = 100; // An unused variable will generate a warning.

// The below code segment demonstrates linker error.
    // std::cout << "x: " << x; // This will give a linker error. Compiling process happens as usual. "x" is an "extern variable".

/*
Runtime Error: They occur when the program is executing. These errors can cause the program to crash, we can deal with these errors using exception handling.
          egs: Divide by zero, File not found, Out of memory.
*/

/*
Logical Error: These are bugs that cause programs to run incorrectly. They are mistakes made by the programmer.
*/

// The below piece of code demonstrates logical error.
    int age = 18;

    if(age > 18) {
        std::cout << "You are eligible to vote!" << std::endl; // This piece of code was intended to check for voting eligibility(age should be greater than or equal to 18). If "age == 18" we won't get output, this is a logical error and can be corrected.
    }
    else {
        std::cout << "Sorry, you are not eligible to vote!" << std::endl;
    }
    return 0;
}