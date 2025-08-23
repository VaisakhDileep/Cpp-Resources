/*
Created by  : Vaisakh Dileep
Date        : 18, December, 2020
Description : Switch statement.
*/

#include<iostream>

using namespace std;

int main()
{
/*
Syntax for switch statements:
switch(integer_control_expr)
{
    case expression_1 : statement_1; break;
    case expression_2 : statement_2; break; --> Here we don't need to put blocks { } for multiple statements, but for defining variables we need to include blocks.
    case expression_3 : statement_3; break;
                .
                .
                .
    case expression_n : statement_n; break; --> If we don't put break, then fall-through occurs and all the statement below it will execute.

    default : statement_default;
}
*/

// Switching using enumeration.
    enum color {red, green, blue}; // Blueprint

    color screen_color {green};

    switch(screen_color)
    {
        case red   : cout<<"RED";
                    break;

        case green : cout<<"GREEN";
                    break;

        case blue  : cout<<"BLUE"; // Suppose we don't handle some of the enumeration types, then compiler will generate a warning asking us to handle it.
                    break;

        default : cout<<"Should never execute !!!"; // Because we have enumerated all the possibilities.
    }

    cout<<"\n";

// Grade Requirement: This program calculates the marks required to achieve the given grade.

    char letter_grade {};

    cout<<"Enter the grade you expect for your exam: ";

    cin>>letter_grade;

    switch(letter_grade) // We can use "char" data type because they are part of the integer data type too.
    {
        case 'a':
        case 'A': cout<<"You need to get 90 marks or above, study really hard.\n";
                break;

        case 'b':
        case 'B': cout<<"You need to get 80 - 89 marks to achieve this grade.\n";
                break;

        case 'c':
        case 'C': cout<<"You need to get 70 - 79 marks to achieve this grade.\n";
                break;

        case 'd':
        case 'D': cout<<"You need to get 60 - 69 marks to achieve this grade, seriously aim higher.\n";
                break;

        case 'f':
        case 'F':
        {
            char confirm {};

            cout<<"Are you sure (Y/N) ?: ";

            cin>>confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                cout<<"OK!. I guess you don't want to study.\n";
            }
            else if(confirm == 'n' || confirm == 'N')
            {
                cout<<"Good. Go Study!\n";
            }
            else
            {
                cout<<"Illegal Choice. Good Bye..\n";
            }

            break;
        }

        default : cout<<"Sorry couldn't recognize that grade.\n";
    }

    return 0;
}
