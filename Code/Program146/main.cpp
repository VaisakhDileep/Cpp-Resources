/*
Created by  : Vaisakh Dileep
Date        : 20, November, 2021
Description : This program helps to understand regex_search() with std::match_result<string> in C++.
*/

#include<iostream>

#include<regex>

using namespace std;

int main()
{
    regex re_1 {"(a+)(b+)(c+)"}; // Notice here there are 3 groups.

/*
    1   2   3    ----------> How indexing happens.
    (a*)(b*)(c*)
*/

    match_results<string::const_iterator> match_rslt {}; // We could also use "std::smatch match_rslt {}". "std::smatch" is a typdef for "std::match_results<string::const_iterator>".

    bool found {};

    string str {"ssabcabc"};

    found = regex_search(str, match_rslt, re_1); // When passing the string to match("str"), make sure to pass it as a string container variable.

/*
    std::smatch m {}; // Suppose 'm' is the smatch object.

// The different members inside std::smatch are:
    m[0].str() -> It will hold the entire match.

    m[1].str()
        .
        .
    m[i].str() -> It will hold the match for the i'th group(groups are represented inside "()" in the regular expression).
        .
        .
    m[n - 1].str()

    m.prefix() -> It is everything before the first matched character.
    m.suffix() -> It is everything after the last matched character.
*/

    cout<<"match_rslt[0]: "<<match_rslt[0].str()<<"\n"; // The entire matched string.
    cout<<"match_rslt[0]: "<<match_rslt.str()<<"\n"; // We could also use this format.
    cout<<"match_rslt[0]: "<<match_rslt.str(0)<<"\n\n"; // We could also use this format.


    cout<<"match_rslt.prefix(): "<<match_rslt.prefix()<<"\n\n"; // All the remaining characters before the matched string.

    cout<<"match_rslt.suffix(): "<<match_rslt.suffix()<<"\n\n"; // All the remaining characters after the matched string.

    cout<<"match_rslt[1]: "<<match_rslt[1].str()<<"\n"; // This will print the 1st group match.
    cout<<"match_rslt[1]: "<<match_rslt.str(1)<<"\n"; // We could also use this format.
    cout<<"match_rslt[2]: "<<match_rslt[2].str()<<"\n"; // This will print the 2nd group match.
    cout<<"match_rslt[2]: "<<match_rslt.str(2)<<"\n"; // We could also use this format.
    cout<<"match_rslt[3]: "<<match_rslt[3].str()<<"\n"; // This will print the 3rd group match.
    cout<<"match_rslt[3]: "<<match_rslt.str(3)<<"\n\n"; // We could also use this format.

    for(int i {0}; i < match_rslt.size(); i++)
    {
        cout<<"match_rslt["<<i<<"]: "<<match_rslt[i].str()<<"\n";
    }

    return 0;
}