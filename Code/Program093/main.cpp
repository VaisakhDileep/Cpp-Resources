/*
Created by  : Vaisakh Dileep
Date        : 31, January, 2021
Description : This program helps to understand how to read a text file in C++.
*/

#include<iostream>

#include<fstream> // for fstream and ifstream

#include<string>

#include<iomanip>

using namespace std;

int main()
{
// fstream and ifstream are commonly used for input files. fstream can be used for both input and output.

/*
Procedure for reading a file:
1. Declare an ifstream or fstream object.
2. Connect it to a file on your file system(open it for reading).
3. Read data from the file via the stream.
4. Close the stream.
*/

/*
Syntax for opening a file for reading(fstream):
std::fstream in_file {"my_file.txt", std::ios::in};

For binary mode:
std::fstream in_file {"my_file.txt", std::ios::in | std::ios::binary}; // Notice here we are using "bitwise or" operator, it will enable both "std::ios::in" and "std::ios::binary".
*/

/*
Syntax for opening a file for reading(ifstream):
std::ifstream in_file {"my_file.txt", std::ios::in};

            ..... or .....

std::ifstream in_file {"my_file.txt"}; // Including "std::ios::in" is not necessary when using ifstream.

For binary mode:
std::ifstream in_file {"my_file.txt", std::ios::binary};

            ..... or .....

std::ifstream in_file;
in_file.open(filename); // "in_file.open(filename, std::ios::binary);" for binary mode.
*/

/*
Syntax for formatted read using stream extraction operator(>>):
std::ifstream in_file {"my_file.txt"};

Data_Type data;

in_file>>data;
*/

/*
Syntax for checking if the file was opened successfully:
if(in_file.is_open())
{
    // ..... Code .....
}
else
{
    // Do something to convey that the file hasn't been opened successfully.
}

    ..... or .....

if(in_file)
{
    // ..... Code .....
}
else
{
    // Do something to convey that the file hasn't been opened successfully.
}
*/

/*
Syntax for reading a line using getline from a file:

std::ifstream in_file("my_file.txt");

std::string line {};

std::getline(in_file, line);
*/

/*
Syntax for reading the entire file using getline()[line by line]:
std::ifstream in_file("my_file.txt");

std::string line {};

while(!in_file.eof())
{
    std::getline(in_file, line);

    std::cout<<line<<"\n";
}
in_file.close(); // Close the file

            ..... or .....

std::ifstream in_file("my_file.txt");

std::string line {};

while(std::getline(in_file, line))
{
    std::cout<<line<<"\n";
}
in_file.close(); // Close the file
*/

/*
Syntax for reading the entire file using getc()[character by character] --> unformatted read:
std::ifstream in_file("my_file.txt");

char c;

while(in_file.getc(c))
{
    std::cout<<c;
}
in_file.close(); // Close the file
*/
    ifstream in_file;

    in_file.open("JumpStreet.txt"); // When naming directories make sure only to use alphabets(a-z, A-Z), underscores(_), numbers(0-9).

    if(!in_file)
    {
        cerr<<"ERROR - Unable to open the file.\n";

        return 1; // Here '1' in "return 1" means that we are exiting the problem with some error.
    }

    string line1 {};
    string line2 {};

    int num {};

    while(!in_file.eof()) // "eof" --> end of file
    {
        in_file>>num>>line1>>line2;

        cout<<setw(3)<<left<<num<<line1<<" "<<line2<<"\n"; // Note here that whitespaces are not caught when using formatted read.
    }

// For more information about clear() refer "http://www.cplusplus.com/reference/ios/ios/clear/".

    cout<<"\n";

    in_file.clear();
    in_file.seekg(0); // Move to the top of the file

    while(in_file>>num>>line1>>line2) // This will also work.
    {
        cout<<setw(3)<<left<<num<<line1<<" "<<line2<<"\n";
    }

    in_file.close();

    cout<<"\n";

    in_file.open("Homer.txt");

    while(getline(in_file, line1))
    {
        cout<<line1<<"\n";
    }

    in_file.clear();
    in_file.seekg(0);

    cout<<"\n";

    char chr {};

    while(in_file.get(chr)) // Unformatted read
    {
        cout<<chr; // Notice here that it will read everything like whitespace, newline etc.
    }

    return 0;
}