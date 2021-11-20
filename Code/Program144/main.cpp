/*
Created by  : Vaisakh Dileep
Date        : 16, November, 2021
Description : This program helps to understand regex_match() in C++.
*/

#include<iostream>

#include<regex>

using namespace std;

// Regular Expression: It is a specific pattern that provides concise and flexible means to match strings of text(particular characters, words, patterns).

int main()
{
// regex_match(): It will check whether the target sequence matches the regular expression.
    cout<<boolalpha;

    regex re_1 {"abc"}; // This regex will only match for "abc".

    cout<<"regex_match(\"abc\", \"abc\") : "<<regex_match("abc", re_1)<<"\n"; // This will match.
    cout<<"regex_match(\"ABC\", \"abc\") : "<<regex_match("ABC", re_1)<<"\n"; // This won't match.
    cout<<"regex_match(\"abcd\", \"abc\"): "<<regex_match("abcd", re_1)<<"\n\n"; // This won't match.

    regex re_2 {"abc", regex_constants::icase}; // "regex_constraints::icase" will ignore case. This regex will match for "abc", "Abc", "aBc", "abC", "ABc", ...

    cout<<"regex_match(\"abc\", \"abc\") [with regex_constraint::icase] : "<<regex_match("abc", re_2)<<"\n"; // This will match.
    cout<<"regex_match(\"aBC\", \"abc\") [with regex_constraint::icase] : "<<regex_match("aBC", re_2)<<"\n"; // This will match.
    cout<<"regex_match(\"abcd\", \"abc\") [with regex_constraint::icase]: "<<regex_match("abcd", re_2)<<"\n\n"; // This won't match.

    regex re_3 {"abc."}; // '.' is a special character it will match any character except newline. This regex will match for "abca", "abcb", "abcd", ...

    cout<<"regex_match(\"abc\", \"abc.\")  : "<<regex_match("abc", re_3)<<"\n"; // This won't match, there should be a fourth character.
    cout<<"regex_match(\"abcd\", \"abc.\") : "<<regex_match("abcd", re_3)<<"\n"; // This will match.
    cout<<"regex_match(\"abc\\n\", \"abc.\"): "<<regex_match("abc\n", re_3)<<"\n"; // This won't match, the fourth character shouldn't be a newline.
    cout<<"regex_match(\"abc \", \"abc.\") : "<<regex_match("abc ", re_3)<<"\n\n"; // This will match, the fourth character can be a whitespace too.

    regex re_4 {"abc?"}; // '?' is a special character it will match for 0 or 1 of the preceeding character('c'). This regex will match only for "abc", "ab".

    cout<<"regex_match(\"abc\", \"abc?\") : "<<regex_match("abc", re_4)<<"\n"; // This will match.
    cout<<"regex_match(\"ab\", \"abc?\")  : "<<regex_match("ab", re_4)<<"\n"; // This will match .
    cout<<"regex_match(\"abd\", \"abc?\") : "<<regex_match("abd", re_4)<<"\n"; // This won't match.
    cout<<"regex_match(\"abcd\", \"abc?\"): "<<regex_match("abcd", re_4)<<"\n\n"; // This won't match.

    regex re_5 {"abc*"}; // '*' is a special character it will match for 0 or more of the preceeding character('c'). This regex will match for "ab", "abc", "abcc", "abccc", ...

    cout<<"regex_match(\"ab\", \"abc*\")  : "<<regex_match("ab", re_5)<<"\n"; // This will match.
    cout<<"regex_match(\"abc\", \"abc*\") : "<<regex_match("abc", re_5)<<"\n"; // This will match.
    cout<<"regex_match(\"abcc\", \"abc*\"): "<<regex_match("abcc", re_5)<<"\n"; // This will match.
    cout<<"regex_match(\"abd\", \"abc*\") : "<<regex_match("abd", re_5)<<"\n"; // This won't match.
    cout<<"regex_match(\"abcd\", \"abc*\"): "<<regex_match("abcd", re_5)<<"\n\n"; // This won't match.

    regex re_6 {"abc+"}; // '+' is a special character it will match for 1 or more of the preceeding character('c'). This regex will match for "abc", "abcc", "abccc", ...

    cout<<"regex_match(\"ab\", \"abc+\")  : "<<regex_match("ab", re_6)<<"\n"; // This won't match.
    cout<<"regex_match(\"abc\", \"abc+\") : "<<regex_match("abc", re_6)<<"\n"; // This will match.
    cout<<"regex_match(\"abcc\", \"abc+\"): "<<regex_match("abcc", re_6)<<"\n"; // This will match.
    cout<<"regex_match(\"abd\", \"abc+\") : "<<regex_match("abd", re_6)<<"\n"; // This won't match.
    cout<<"regex_match(\"abcd\", \"abc+\"): "<<regex_match("abcd", re_6)<<"\n\n"; // This won't match.

    regex re_7 {"[abc]"}; // "[...]" is a special pattern it will match any character inside []. This regex will match only for "a", "b", "c".

    cout<<"regex_match(\"a\", \"[abc]\") : "<<regex_match("a", re_7)<<"\n"; // This will match.
    cout<<"regex_match(\"b\", \"[abc]\") : "<<regex_match("b", re_7)<<"\n"; // This will match.
    cout<<"regex_match(\"c\", \"[abc]\") : "<<regex_match("c", re_7)<<"\n"; // This will match.
    cout<<"regex_match(\"d\", \"[abc]\") : "<<regex_match("d", re_7)<<"\n"; // This won't match, 'd' is not present inside [...].
    cout<<"regex_match(\"ab\", \"[abc]\"): "<<regex_match("ab", re_7)<<"\n"; // This won't match, it will only match for any one character inside [...].
    cout<<"regex_match(\"\", \"[abc]\")  : "<<regex_match("", re_7)<<"\n\n"; // This won't match, there should be atleast one character common with [...].

    regex re_8 {"[^abc]"}; // "[^...]" is a special pattern it will match any character except the ones inside []. This regex will match for "d", "e", "f", ...

    cout<<"regex_match(\"a\", \"[^abc]\") : "<<regex_match("a", re_8)<<"\n"; // This won't match.
    cout<<"regex_match(\"b\", \"[^abc]\") : "<<regex_match("b", re_8)<<"\n"; // This won't match.
    cout<<"regex_match(\"c\", \"[^abc]\") : "<<regex_match("c", re_8)<<"\n"; // This won't match.
    cout<<"regex_match(\"d\", \"[^abc]\") : "<<regex_match("d", re_8)<<"\n"; // This will match.
    cout<<"regex_match(\"dd\", \"[^abc]\"): "<<regex_match("dd", re_8)<<"\n"; // This won't match, it will only match for one character not inside [...].
    cout<<"regex_match(\"\", \"[^abc]\")  : "<<regex_match("", re_8)<<"\n\n"; // This won't match, there should be atleast one character not common with [...].

    regex re_9 {"abc{3}"}; // "{n}" is a special pattern it will match exactly 'n' instaces of the preceeding character('c'). This regex will match only for "abccc".

    cout<<"regex_match(\"abc\", \"abc{3}\")   : "<<regex_match("abc", re_9)<<"\n"; // This won't match, it will only match for exactly 3 instances of 'c'.
    cout<<"regex_match(\"abccc\", \"abc{3}\") : "<<regex_match("abccc", re_9)<<"\n"; // This will match.
    cout<<"regex_match(\"abcccc\", \"abc{3}\"): "<<regex_match("abcccc", re_9)<<"\n\n"; // This won't match, it will only match for exactly 3 instances of 'c'.

    regex re_10 {"abc{3,}"}; // "{n,}"(should'nt add spaces anywhere) is a special pattern it will match exactly 'n' or more instances of the preceeding character('c'). This regex will match for "abccc", "abcccc", "abccccc", ...

    cout<<"regex_match(\"abc\", \"abc{3,}\")    : "<<regex_match("abc", re_10)<<"\n"; // This won't match, it will only match for atleast 3 instances of 'c'.
    cout<<"regex_match(\"abccc\", \"abc{3,}\")  : "<<regex_match("abccc", re_10)<<"\n"; // This will match.
    cout<<"regex_match(\"abcccc)\", \"abc{3,}\"): "<<regex_match("abcccc", re_10)<<"\n\n"; // This will match.

    regex re_11 {"abc{3,5}"}; // "{n,m}"(shouldn't add spaces anywhere) is a special pattern it will match atleast 'n' and atmost 'm' instances of the preceeding character('c'). This regex will match only for "abccc", "abcccc", "abccccc".

    cout<<"regex_match(\"abcc\", \"abc{3,5}\")    : "<<regex_match("abcc", re_11)<<"\n"; // This won't match.
    cout<<"regex_match(\"abccc\", \"abc{3,5}\")   : "<<regex_match("abccc", re_11)<<"\n"; // This will match.
    cout<<"regex_match(\"abcccc\", \"abc{3,5}\")  : "<<regex_match("abcccc", re_11)<<"\n"; // This will match.
    cout<<"regex_match(\"abccccc\", \"abc{3,5}\") : "<<regex_match("abccccc", re_11)<<"\n"; // This will match.
    cout<<"regex_match(\"abcccccc\", \"abc{3,5}\"): "<<regex_match("abcccccc", re_11)<<"\n\n"; // This won't match.

    regex re_12 {"a|b"}; // '|' is a special character it will match either "a" or "b". This regex will match only for "a", "b".

    cout<<"regex_match(\"\", \"a|b\")  : "<<regex_match("", re_12)<<"\n"; // This won't match, "" is neither "a" or "b".
    cout<<"regex_match(\"a\", \"a|b\") : "<<regex_match("a", re_12)<<"\n"; // This will match.
    cout<<"regex_match(\"b\", \"a|b\") : "<<regex_match("b", re_12)<<"\n"; // This will watch.
    cout<<"regex_match(\"ab\", \"a|b\"): "<<regex_match("ab", re_12)<<"\n\n"; // This won't match, "ab" is neither "a" or "b".

    regex re_13 {"\\[\\]"}; // When trying to match special symbols(in this case '[') use the escape character '\\'(we use it twice, because in order to store '\' we need another escape sequence). This regex will match only for "[]".

    cout<<"regex_match(\"[]\", \"\\[\\]\"): "<<regex_match("[]", re_13)<<"\n\n"; // This will match.

    regex re_14 {"(ab)*"}; // "()" is a special pattern it can be used to group a regular expression. This regex will match for "", "ab", "abab", "ababab", ...

    cout<<"regex_match(\"\", \"(ab)*\")      : "<<regex_match("", re_14)<<"\n"; // This will match.
    cout<<"regex_match(\"ab\", \"(ab)*\")    : "<<regex_match("ab", re_14)<<"\n"; // This will match.
    cout<<"regex_match(\"abab\", \"(ab)*\")  : "<<regex_match("abab", re_14)<<"\n"; // This will match.
    cout<<"regex_match(\"ababab\", \"(ab)*\"): "<<regex_match("ababab", re_14)<<"\n\n"; // This will match.

    regex re_15 {"(a)(b)\\*\\2\\1"}; // "()" groups can be reassigned again by the index of the opening bracket('('). We use the escape sequence with the index value(indexing starts from '1'). This regex will match only for "ab*ba".

/*
    1  2            ------------> How indexing happens.
    (a)(b)\\*\\2\\1 ------------> (a)(b)\\*(b)(a) -> Result.
*/

    cout<<"regex_match(\"ab*ba\", \"(a)(b)\\*\\2\\1\"): "<<regex_match("ab*ba", re_15)<<"\n"; // This will match.
    cout<<"regex_match(\"ab*ab\", \"(a)(b)\\*\\2\\1\"): "<<regex_match("ab*ab", re_15)<<"\n\n"; // This won't match.

    regex re_16 {"[:alpha:]"}; // "[:alpha:]" is a character class. It will will match any alphabet characters. To know more about character classes refer: https://www.cplusplus.com/reference/regex/ECMAScript/

    cout<<"regex_match(\"a\", \"[:alpha:]\"): "<<regex_match("a", re_16)<<"\n"; // This will match.
    cout<<"regex_match(\"1\", \"[:alpha:]\"): "<<regex_match("1", re_16)<<"\n\n"; // This won't match.

    return 0;
}