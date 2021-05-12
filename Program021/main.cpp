/*
Created by  : Vaisakh Dileep
Date		: 20, December, 2020
Description : This program helps to understand C-style string functions in C++.
*/

#include<iostream>

#include<cstring> // This library contains different C-style string functions.
#include<cstdlib> // It contains functions that convert C-style strings to integer, float, long etc...

#include<ios> // For <stream_size>

#include<limits> // For numeric_limits

#include<cctype>

using namespace std;

int main()
{
// Note : All C-style strings are null terminated('\0').

	char string_1[20] {"Homer"};

	char string_2[20];

	strcpy(string_2, string_1);

	cout<<"String 1: "<<string_1<<"\n";
	cout<<"String 2(after copying from string 1): "<<string_2<<"\n";

	strcat(string_1, " J Simpson");

	cout<<"String 1(after concatenating \"J Simpson\"): "<<string_1<<"\n";

	cout<<"Length of String 1: "<<strlen(string_1)<<"\n"; // strlen() returns of type size_t(it is a kind of unsigned int, it guarantees that it will contain the biggest object the host system can hold).

// strcmp returns '0' if all the elements in a string are lexicographically(like order in a dictionary) equal, returns > 0 if the corresponding char element in the left string is lexicographically greater than the right string. Returns < 0 if the corresponding char element in the left string is lexicographically lesser than the right string.

	cout<<"strcmp(\"a\", \"a\"): "<<strcmp("a", "a")<<"\n";
	cout<<"strcmp(\"b\", \"a\"): "<<strcmp("b", "a")<<"\n";
	cout<<"strcmp(\"a\", \"b\"): "<<strcmp("a", "b")<<"\n";

	char first_name[20] {}, last_name[20] {}, full_name[45] {};

	cout<<"Enter your first name: ";

	cin>>first_name; // Here "cin" will input each character at a time, so it's possible for user to  assign using "cin".

	cout<<"Enter your last name: ";

	cin>>last_name;

	strcpy(full_name, first_name);
	strcat(full_name, " ");
	strcat(full_name, last_name);

	cout<<"Your full name is "<<full_name<<"\n";

	cout<<"Enter your full name: ";

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This will clear the input buffer.

	cin.getline(full_name, 45); // Here the first parameter is where the input gets stored and the second parameter is the limit. Using getline() spaces will be included.

	cout<<"Your full name is "<<full_name<<"\n";

	char input[25] {};

	cout<<"Enter the string to capitalize: ";

	cin.getline(input, 25);

	for(size_t i {0}; i < strlen(input); ++i)
	{
		if(isalpha(input[i]))
		{
			input[i] = toupper(input[i]);
		}
	}

	cout<<"Capitalized representation: "<<input<<"\n";

	return 0;
}