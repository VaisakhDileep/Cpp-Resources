/*
Created by  : Vaisakh Dileep
Date        : 20, December, 2020
Description : This program helps to understand character functions in C++.
*/

#include<iostream>

#include<cctype> // This library contains functions for testing characters and converting characters.

using namespace std;

int main()
{
    cout<<"'a' is a letter               : "<<isalpha('a')<<"\n"; // True if 'a' is a letter.
    cout<<"'a' is a letter or digit      : "<<isalnum('a')<<"\n"; // True if 'a' is a letter or digit.
    cout<<"'1' is a digit                : "<<isdigit('1')<<"\n"; // True if '1' is a digit.
    cout<<"'a' is a lowercase letter     : "<<islower('a')<<"\n"; // True if 'a' is a lowercase letter.
    cout<<"'A' is an uppercase letter    : "<<isupper('A')<<"\n"; // True if 'A' is an uppercase letter.
    cout<<"'a' is a printable character  : "<<isprint('a')<<"\n"; // True if 'a' is a printable character.
    cout<<"';' is a punctuation character: "<<ispunct(';')<<"\n"; // True if ';' is a punctuation 
    cout<<"' ' is a whitespace           : "<<isspace(' ')<<"\n\n"; // True if ' ' is a whitespace.

// Here the function will return a non-zero value if it evaluate to "true" otherwise '0'("false").

    cout<<"Lowercase equivalent of 'A': "<<char(tolower('A'))<<"\n";
    cout<<"Uppercase equivalent of 'a': "<<char(toupper('a'))<<"\n\n"; // We use char() because toupper() returns an ascii value(integer) rather than a char type.

    return 0;
}