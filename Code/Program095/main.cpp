/*
Created by  : Vaisakh Dileep
Date        : 1, February, 2021
Description : Copy and paste the contents of a file.
*/

#include<iostream>

#include<fstream>

#include<string>

using namespace std;

int main()
{
    ifstream in_file {"Homer.txt"};

    ofstream out_file {"Homer_Copy.txt", ios::app};

    if(!in_file)
    {
        cerr<<"ERROR - Unable to open the file.\n";

        return 1;
    }
    if(!out_file)
    {
        cerr<<"ERROR - Unable to open the file.\n";

        return 1;
    }

    string line {};

    while(getline(in_file, line))
    {
        out_file<<line<<"\n";
    }

    out_file.close();

    char chr {};

    out_file.open("Homer_Copy_Unformatted.txt");

    in_file.clear();
    in_file.seekg(0); // Seek to to the top of the file.

    while(in_file.get(chr))
    {
        out_file.put(chr); // Unformatted copy.
    }

    in_file.close();
    out_file.close();

    return 0;
}