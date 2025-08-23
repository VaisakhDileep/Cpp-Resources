/*
Created by  : Vaisakh Dileep
Date        : 20, November, 2021
Description : Regex_search.
*/

#include<iostream>

#include<regex>

using namespace std;

int main()
{
// regex_search(): It will check if the given expression is found anywhere in the target sequence.
    cout<<boolalpha;

    regex re_1 {"abc"}; // This regex will match for any string that has "abc" in it.

    cout<<"regex_search(\"cabc\", \"abc\"): "<<regex_search("cabc", re_1)<<"\n"; // This will match.
    cout<<"regex_search(\"caba\", \"abc\"): "<<regex_search("caba", re_1)<<"\n\n"; // This won't match.

    regex re_2 {"^abc"}; // '^' is a special character(assertion). It says that the pattern should be matched from the beginning of the line. This regex will match for any string that starts with "abc".

    cout<<"regex_search(\"abcd\", \"^abc\"): "<<regex_search("abcd", re_2)<<"\n"; // This will match.
    cout<<"regex_search(\"dabc\", \"^abc\"): "<<regex_search("dabc", re_2)<<"\n\n"; // This won't match.

    regex re_3 {"abc$"}; // '$' is a special character(assertion). It says that the pattern should be matched from the end of the line. This regex will match for any string that ends with "abc".

    cout<<"regex_search(\"cabc\", \"abc$\"): "<<regex_search("cabc", re_3)<<"\n"; // This will match.
    cout<<"regex_search(\"abcd\", \"abc$\"): "<<regex_search("abcd", re_3)<<"\n\n"; // This won't match.

    return 0;
}