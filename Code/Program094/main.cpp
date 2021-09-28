/*
Created by  : Vaisakh Dileep
Date        : 1, February, 2021
Description : This program helps to understand how to write to a text file in C++.
*/

#include<iostream>

#include<fstream> // For fstream and ofstream

#include<string>

using namespace std;

int main()
{
/*
Procedure for writing to a file:
1. Declare a fstream or ofstream object.
2. Connect it to a file on the system(open it for writing).
3. Write data to the file via the stream.
4. Close the stream(very important when writing, since it will flush out any unwritten data).
*/

// By default output files will be overwritten(truncated) and if the file doesn't exist then a new file is created.

/*
Syntax for opening a file for writing(fstream):
std::fstream out_file {"my_file.txt", std::ios::out};

for binary mode:
std::fstream out_file {"my_file.txt", std::ios::out | std::ios::binary}; // Here "bitwise or" is used, it will enable both "std::ios::out" and "std::ios::binary".
*/

/*
Syntax for opening a file for writing(ofstream):
std::ofstream out_file {"my_file.txt", std::ios::out};

            ..... or .....

std::ofstream out_file {"my_file.txt"}; // Including "std::ios::out" is not necessary when using ofstream.

For binary mode:
std::ofstream out_file {"my_file.txt", std::ios::binary};

            ..... or .....

std::ofstream out_file;
out_file.open("my_file.txt"); // out_file.open("my_file.txt", std::ios::binary); --> For binary mode.
*/

/*
Syntax for opening a file to truncate(discard contents):
std::ofstream out_file {"my_file.txt", std::ios::trunc}; // This is by default so don't have to include "std::ios::trunc".
*/

/*
Syntax for opening a file for appending:
std::ofstream out_file {"my_file.txt", std::ios::app};
*/

/*
Syntax for opening a file and seeking to the end of the file:
std::ofstream out_file {"my_file.txt", std::ios::ate};
*/

/*
Difference between std::ios::ate and std::ios::app:
In std::ios::app, you can only write at the end, but ios::ate reads and writes at the end of the file by default. However, with ios::ate you can seek freely in the file, but with ios::app you always write at the end, no matter what position you set for the writing pointer.
*/

/*
Syntax for checking if a file was opened successfully:
if(out_file.is_open())
{
    // ..... Code .....
}
else
{
    // Do something to convey that the file hasn't been opened successfully.
}
*/

/*
Syntax for formatted write using stream insertion operator(<<):
Data_Type data;

out_file<<data;
*/
    ofstream out_file;

    out_file.open("Date.txt", ios::app);

    if(!out_file)
    {
        cerr<<"ERROR - Unable to open the file.\n";

        return 1;
    }

    string date {};

    cout<<"Enter today's date: ";

    getline(cin, date);

    out_file<<date<<"\n";

    out_file.close();

    return 0;
}