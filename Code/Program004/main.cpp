/*
Created by  : Vaisakh Dileep
Date        : 15, December, 2020
Description : Input and output stream.
*/

#include<iostream>

using namespace std;

int main()
{
// cout: It is the standard ouput stream(console), we use the stream insertion operator(<<). It can be chained but does not automatically include line breaks.

    cout<<"Prison Mike: I stole. And I robbed. And I kidnapped... the President's son. And held him for ransom."<<endl; // See here we used chaining and explicitly include "endl" to break the line.
    cout<<"Jim: That is quite the rapsheet, Prison Mike."<<endl;
    cout<<"Prison Mike: And I never got caught either!"<<endl;
    cout<<"Jim: Well, you are in prison. But umh."<<endl;

    int data1 {}, data2 {};

// cin: It is the standard input stream(keyboard), we use the stream extraction operator(>>). It can be chained as well.

    cout<<"Enter any two number separated by spaces: "; // spaces will be ignored when extracting.

    cin>>data1>>data2;

    cout<<"The numbers you have entered are "<<data1<<" and "<<data2<<endl;

/*
    cout<<endl; // It will flush the buffer everytime, thereby wasting time.

    cout<<"\n"; // Significantly faster than "endl", does not flush the output.

    cout<<"\n"<<flush; // Equivalent to "endl".
*/

// Consider the following code segment.
    cout<<"Enter the first number: ";

    cin>>data1; // Input "    2    4   " and see what happens.

    cout<<"Enter the second number: ";

    cin>>data2; // From the above input "data2" will automatically get the value '4' because '4' is still in the input buffer.

    cout<<endl<<"First number: "<<data1<<endl;

    cout<<"Second number: "<<data2<<endl<<endl;

// Consider the following code segment.
    double data3 {};

    cout<<"Enter the first number: ";

    cin>>data1; // Input "1.5" and see what happens.

    cout<<"Enter the second number: ";

    cin>>data3; // From the above input "data3" will get the value '0.5' because "data1" only accepts integers.

    cout<<endl<<"First number: "<<data1<<endl;

    cout<<"Second number: "<<data3<<endl;

    return 0;
}