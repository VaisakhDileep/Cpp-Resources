/*
Created by  : Vaisakh Dileep
Date		: 14, December, 2020
Description : This program helps to understand the structure of a C++ program.
*/

// Preprocessor: Preprocessor processes the source code before the compiler sees it. Preprocessor removes all the comments and looks for the preprocessor directive. Preprocessor does not understand C++.

// Preprocessor directives: Preprocessor directives give instruction to the compiler to preprocess the information before actual compilation. They start with '#'.

#include<iostream>

// Comments: They never reach the compiler, preprocessor removes it.

// This is a single-line comment.

/*
This
is
a
multi-line
comment.
*/

int main() // Every C++ program should have exactly one main() function, it is the starting point for the program execution.
{
// For reference on C++ programming: https://en.cppreference.com/w/

	int number;

	std::cout<<"Enter any integer number: ";

	std::cin>>number;

	std::cout<<"number: "<<number<<std::endl;

	/*
	Keywords: For reference on C++ keywords: https://en.cppreference.com/w/cpp/keyword
			  In the above stretch of code the keywords are: int, return
	*/

	/*
	Identifier: It is a name used to identify a variable,function, class, module, or any other use-defined item. An identifier starts with a letter(a-z, A-Z) or an underscore(_) followed by zero or more letters(a-z, A-Z), underscore(_) or digits(0-9).
				In the above stretch of code the identifiers are: number
	*/

	/*
	Operators: Operators are symbols that perform operations on variables and values. For reference on C++ operators: https://en.cppreference.com/w/cpp/language/expressions
	*/

	/*
	Punctuators: They have semantic and syntactic meaning to the compiler but do not by themselves specify an operation that yields a value.
				 The following are considered as punctuators: ! % ^ & * ( ) - + = { } | ~ [ ] \ ; ' : " < > ? , . / #
	*/

	return 0;
}

/*
int main(int argc, char *argv[]) // Here "argc" is the number of arguments and "argv" is the array of string arguments provided at the command line.
// int main(int argc, char **argv) // Also supported.
{
	std::cout<<"Name of the program: "<<argv[0]<<std::endl; // First argument is the name of the program.

	for(int i {1}; i < argc; i++)
	{
		std::cout<<argv[i]<<" ";
	}

	std::cout<<std::endl;

	std::cout<<"argv[argc]: "<<((argv[argc] == nullptr)? "nullptr" : argv[argc])<<std::endl; // "argv[argc]" is always "nullptr".
}
*/