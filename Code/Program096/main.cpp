/*
Created by  : Vaisakh Dileep
Date        : 4, February, 2021
Description : String stream.
*/

#include<iostream>

#include<string>

#include<sstream> // It is used for declaring a stringstream, istringstream, ostringstream objects.

#include<iomanip>

#include<limits>

using namespace std;

int main()
{
// String stream allows us to read or write from strings in memory. It is mainly used for data validation.
    string enemy_name {};
    string enemy_spawn_location {};
    string enemy_level {};

    string enemy {"Fr.Loutermilch Sybil_High_School 17"};

    istringstream iss {enemy};

    iss>>enemy_name>>enemy_spawn_location>>enemy_level;

    cout<<"Name : "<<enemy_name<<"\n";
    cout<<"Spawn: "<<enemy_spawn_location<<"\n";
    cout<<"Level: "<<enemy_level<<"\n\n";

    ostringstream oss {};

    oss<<"Name: "<<enemy_name<<"\n"<<"Spawn: "<<enemy_spawn_location<<"\n"<<"Level: "<<enemy_level<<"\n\n";

    cout<<oss.str();

// The below piece of code explains how to format an input string:
    string edge {"{10, 2}"}; // Assuming this is the input string.

    int vertex_1 {}, vertex_2 {};

    istringstream edge_iss {edge};

    cout<<"edges_iss.peek(): "<<static_cast<char>(edge_iss.peek())<<"\n"; // peek() returns the next character in the input sequence, without extracting it.

    edge_iss.ignore(); // This will ignore the next character in the input sequence, which is "{".

    edge_iss>>vertex_1;

    edge_iss.ignore(); // This will ignore ','.

    edge_iss>>vertex_2;

    cout<<"vertex 1: "<<vertex_1<<"\n"<<"vertex 2: "<<vertex_2<<"\n\n";

    edge_iss.str(""); // This will clear the "istringstream" object.

// The below piece of code explains how data validation works:
    int value {};

    string user_entry {};

    bool done = false;

    do
    {
        cout<<"Please enter an integer: ";

        cin>>user_entry; // Here suppose we use "value" over here and if the user enters a string then it will give an error, that's why we use "user_entry"[it will never give an error as it will capture anything].

        istringstream validator_iss {user_entry};

        if(validator_iss>>value) // If the "validator_iss" is not an integer then it will fail and the else part is executed.
        {
            done = true;
        }
        else
        {
            cout<<"Sorry, please enter an integer ... \n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This will ignore all that is remaining in the buffer. Suppose if the user enters "10.1", then "10" will be passed to the "user_entry" and "0.1" is still present in the buffer, we need to clear the buffer to avoid this problem.
                                                            // If the user enters "Brooklyn 99", then "Brooklyn" will be captured by "user_entry", but "99" will still remain in the buffer, we need to clear the buffer to avoid this problem(the problem here is that in the next trial "99" will be passed to "user_entry" and evaluated, which may not be what we expected).
    }while(!done);

    cout<<"\n";

    cout<<"Value: "<<value<<"\n";

    return 0;
}