/*
Created by  : Vaisakh Dileep
Date        : 21, December, 2020
Description : This program helps to understand C++ strings.
*/

#include<iostream>

#include<string> // This library is needed to use C++ strings.

#include<ios>

#include<limits>

#include<cstring>

using namespace std;

int main()
{

// C++ strings are part of the Standard Template Library, so use "std" namespace. C++ strings are objects.

// C++ strings like C-style strings are stored continuously in memory, but C++ strings can grow and shrink in size unlike C-style strings.

    string s1; // This is an empty string but initialized, so no garbage values unlike C-style string.

    string s2 {"Vaisakh"}; // Even though "Vaisakh" is a C-style string literal, it is casted to a C++ string.

    string s3 {s2}; // Here we can initialize a C++ string with a C++ string(it is passed by value so "s3" has it's own copy).

    string s4 {"Diorite", 4}; // Here it will store the first 4 characters in "Diorite".

    string s5 {s3, 0, 2}; // Here it will store from index '0' to index '2'(not including).

    string s6 (10, 'O'); // This is constructor type initialization, it will store 'O' 10 times.

    string s7 = "Vaisakh " 
                "Dileep "; // We can assign a string using multiple lines like this.

    cout<<"s1: "<<s1<<"\n";
    cout<<"s2: "<<s2<<"\n";
    cout<<"s3: "<<s3<<"\n";
    cout<<"s4: "<<s4<<"\n";
    cout<<"s5: "<<s5<<"\n";
    cout<<"s6: "<<s6<<"\n";
    cout<<"s7: "<<s7<<"\n\n";

    string name;

    name = "Homer J Simpson"; // This is possible in C++ strings unlike strcpy() in C-style strings.
    name = "Ned Flanders"; // This is possible unlike C-style strings, we can reassign them.

    cout<<"Name: "<<name<<"\n\n";

// Concatenation (+):
    string first_name {"Montgomery"}, last_name {"Burns"};

    cout<<"Full Name: "<<first_name + last_name<<"\n"; // Here we can use concatenation operation between C++ strings.

    cout<<"Full Name: "<<first_name + " " + last_name<<"\n"; // Here we can use concatenation operation between C++ string and C-style string literals.

    cout<<"Full Name: "<<first_name + ' ' + last_name<<"\n\n"; // Here we can use concatenation operation between C++ string and a character literal.

    // cout<<"Full Name : "<< "Montgomery" + " " + "Burns"<<"\n"; // Here we can't use concatenation operation because all the strings here are C-style literals.

// Accessing string elements([] or at()):
    string family_name {"Shrute"};

    family_name.at(0) = 'G';

    cout<<"family_name[0]: "<<family_name[0]<<"\n";
    cout<<"family_name.at(0): "<<family_name.at(0)<<"\n\n";

// Using range-based for loop:
    string lowercase_alphabets {"abcdefghijklmnopqrstuvwxyz"};

    string uppercase_alphabets {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    string digits {"0123456789"};

    for (int ascii : lowercase_alphabets)
    {
        cout<<"  "<<static_cast<char>(ascii)<<" --> "<<ascii<<"\n";
    }
    cout<<"\n";

    for(int ascii : uppercase_alphabets)
    {
        cout<<"  "<<static_cast<char>(ascii)<<" --> "<<ascii<<"\n";
    }
    cout<<"\n";

    for(int ascii : digits)
    {
        cout<<"  "<<static_cast<char>(ascii)<<" --> "<<ascii<<"\n";
    }
    cout<<"\n";

// Comparing (==, !=, >, >=, <, <=): Here the characters are compared lexicographically. We can compare two string objects, a string object and C-style string literal, a string object and C-style string variable.

    string fruit1 {"Apple"}, fruit2 {"Banana"}, fruit3 {"Kiwi"}, fruit4 {"apple"}, fruit5 {fruit1};

    cout<<boolalpha;

    cout<<fruit1 + " == " + fruit5 + ": "<<(fruit1 == fruit5)<<"\n";
    cout<<fruit1 + " != " + fruit2 + ": "<<(fruit1 != fruit2)<<"\n";
    cout<<fruit1 + " < " + fruit2 + ": "<<(fruit1 < fruit2)<<"\n";
    cout<<fruit2 + " > " + fruit1 + ": "<<(fruit2 > fruit1)<<"\n";

/*
Substrings - substr()

Syntax of substr():
    object.substr(start_index, length)
*/
    string sentence {"Biggus Dingus"};

    cout<<"Word 1: "<<sentence.substr(0, 6)<<"\n";

    cout<<"Word 2: "<<sentence.substr(7, 6)<<"\n";

/*
Finding - find(), it returns the index of the substring.

Syntax of find():
    object.find(search_string)
*/

    cout<<"Index of Biggus: "<<sentence.find("Biggus")<<"\n";

    cout<<"Index of Dingus: "<<sentence.find("Dingus")<<"\n\n";

    // cout<<"Index of xyz   : "<<sentence.find("xyz")<<"\n";

    if(sentence.find("xyz") == string::npos) // "npos" means no position.
    {
        cout<<"Index of xyz: **NOT PRESENT**\n\n";
    }

    cout<<"Index of i: "<<sentence.find('i')<<"\n";

    cout<<"Index of i after index 4: "<<sentence.find('i', 4)<<"\n\n";
/*
Erasing - erase(),  it removes a substring of characters.

Syntax of erase():
    object.erase(start_index, length)
*/

    cout<<"Erasing Biggus: "<<sentence.erase(0, 6)<<"\n"; // This will erase "Biggus" from the sentence.

// Clearing - clear(). It will delete all the characters in the string.

    sentence.clear();

    cout<<"Sentence after clearing: "<<sentence<<"\n\n";

// Compund concatenation operator(+=): This is valid in C++ strings.
    sentence += "Ivan Morris";

    cout<<"Sentence after compound concatenation: "<<sentence<<"\n\n";

// Length - length(). It returns the length of the string.
    cout<<"Length of the sentence: "<<sentence.length()<<"\n\n";

// Stream Insertion(>>) and Stream Extraction(<<): It works perfectly for C++ strings.
    string something;

    cout<<"Enter something and terminate it by 'x': ";

    getline(cin, something, 'x'); // This is another version of getline(), It will read until we reach 'x'(by default it will read until we reach '\n'). 'x' is the delimiter.

    cout<<"You have entered : "<<something<<"\n\n";

/*
getline() vs std::cin.getline():
In std::cin.getline(), getline() is a member function of cin. It is mainly used for C-style strings.
In getline(cin, ..), getline is a free function. It is mainly used for C++ strings.
*/

// c_str(): It is used to get the underlying C-style string.
    string director {"Zachariah Trench"};

    const char *director_c_string_immutable {director.c_str()}; // The result will be of "const char *", so we can't manipulate it.

    cout<<"director_c_string_immutable: "<<director_c_string_immutable<<"\n";

    char director_c_string_mutable[] {};

    strcpy(director_c_string_mutable, director_c_string_immutable); // Inorder to make it mutable we can make a copy.

    director_c_string_mutable[10] = 'D';

    cout<<"director_c_string_mutable  : "<<director_c_string_mutable<<"\n\n";

// Substitution Cipher.
    string  alphabets {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    string key {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"};

    string secret_message;

    cout<<"Enter secret message: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, secret_message);

    string encrypted_message;

    cout<<"Encrypting message .... \n\n";

    for (char c : secret_message)
    {
        size_t position = alphabets.find(c);

        if(position != string::npos)
        {
            char new_char {key.at(position)};

            encrypted_message += new_char;
        }
        else
        {
            encrypted_message += c;
        }
    }

    cout<<"Encrypted message: "<<encrypted_message<<"\n";

    return 0;
}