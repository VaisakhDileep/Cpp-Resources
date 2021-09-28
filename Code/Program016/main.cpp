/*
Created by  : Vaisakh Dileep
Date        : 19, December, 2020
Description : This program helps to understand break and continue statement in C++.
*/

#include<iostream>

#include<vector>

using namespace std;

int main()
{
//continue: No further statements in the body of the loop is executed. Control immediately goes directly to the beginning of the loop for the next iteration.

// break: No further statements in the body of the loop is executed, loop is immediately terminated. Control immediately goes to the statement following the loop construct.

    vector<int> values {1, 2, -1, 3, -1, -99, 7, 8, 10};

    for(auto val : values)
    {
        if(val == -99)
            break;

        else if(val == -1)
            continue;

        else
            cout<<val<<" ";
    }

    cout<<"\n";

    return 0;
}