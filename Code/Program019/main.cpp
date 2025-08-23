/*
Created by  : Vaisakh Dileep
Date        : 20, December, 2020
Description : Character functions.
*/

#include<iostream>

#include<cctype> // This library contains functions for testing characters and converting characters.

using namespace std;

int main()
{
    cout<<"'a' is a letter               : "<<isalpha('a')<<"\n"; // True(a non-zero value) if 'a' is a letter.
    cout<<"'a' is a letter or digit      : "<<isalnum('a')<<"\n"; // True(a non-zero value) if 'a' is a letter or digit.
    cout<<"'1' is a digit                : "<<isdigit('1')<<"\n"; // True(a non-zero value) if '1' is a digit.
    cout<<"'a' is a lowercase letter     : "<<islower('a')<<"\n"; // True(a non-zero value) if 'a' is a lowercase letter.
    cout<<"'A' is an uppercase letter    : "<<isupper('A')<<"\n"; // True(a non-zero value) if 'A' is an uppercase letter.
    cout<<"'a' is a printable character  : "<<isprint('a')<<"\n"; // True(a non-zero value) if 'a' is a printable character.
    cout<<"';' is a punctuation character: "<<ispunct(';')<<"\n"; // True(a non-zero value) if ';' is a punctuation 
    cout<<"' ' is a whitespace           : "<<isspace(' ')<<"\n\n"; // True(a non-zero value) if ' ' is a whitespace.

// Here the function will return a non-zero value if it evaluate to "true" otherwise '0'("false").

    if(isalpha('a') == true)
    {
        cout<<"'a' is an alphabet\n\n";
    }
    else
    {
        cout<<"'a' is not an alphabet\n\n";
    } // Notice here we don't get the correct result, this is because "is_alpha()" does not return "true" but a non-zero value(not necessarily '1') and "true" literal has a value of '1'.

    if(isalpha('a') != false) // we could also simply use "if(isalpha('a'))", if we want the correct result.
    {
        cout<<"'a' is an alphabet\n\n";
    }
    else
    {
        cout<<"'a' is not an alphabet\n\n";
    } // Notice here we got the correct result.

    cout<<"Lowercase equivalent of 'A': "<<char(tolower('A'))<<"\n";
    cout<<"Uppercase equivalent of 'a': "<<char(toupper('a'))<<"\n"; // We use char() because toupper() returns an ascii value(integer) rather than a char type.

    return 0;
}