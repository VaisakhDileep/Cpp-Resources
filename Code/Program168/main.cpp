/*
Created by  : Vaisakh Dileep
Date        : 18, September, 2022
Description : This program helps to understand single responsibility principle in C++.
*/

#include<iostream>

#include<fstream>

#include<vector>

using namespace std;

/*
The different design principles are:
1. Single Responsibilty Principle
2. Open-Closed Principle
3. Liskov Substitution Principle
4. Interface Segregation Principle
5. Dependency Inversion Principle

These principles are also known as SOLID principles.
*/

// Single Responsibilty Principle states that each class has only one responsibility and therefore only one reason to change.

class Journal
{
    string journal_title {};

    vector<string> entries {};

public:
    Journal(const string &title): journal_title {title} {}

    void add_entry(const string &entry) // Adding entries is the sole responsibilty of a Journal, therefore this function is required.
    {
        static int line_count = 1;

        entries.push_back(to_string(line_count) + " : " + entry);

        line_count++;
    }

    void save_journal(const string &file_name) // Saving journal contents elsewhere is not the requirement of the journal class. Therefore not required to include this function inside the journal class.
    {
        ofstream out_file {file_name};

        for(unsigned long long i {0}; i < entries.size(); i++)
        {
            if(i == entries.size() - 1)
            {
                out_file<<entries[i];
            }
            else
            {
                out_file<<entries[i]<<"\n";
            }
        }
    }
};

class Journal_2
{
public:
    string journal_title {};

    vector<string> entries {};

    Journal_2(const string &title): journal_title {title} {}

    void add_entry(const string &entry)
    {
        static int line_count = 1;

        entries.push_back(to_string(line_count) + " : " + entry);

        line_count++;
    }
};

class Persistence_Manager
{
public:
    void save_journal(const Journal_2 &journal, const string &file_name)
    {
        ofstream out_file {file_name};

        for(unsigned long long i {0}; i < journal.entries.size(); i++)
        {
            if(i == journal.entries.size() - 1)
            {
                out_file<<journal.entries[i];
            }
            else
            {
                out_file<<journal.entries[i]<<"\n";
            }
        }
    }
}; // Here we have moved saving the journal contents to a different class. This will prevent the journal class from changing if we want to change the save-mechanism.

int main()
{
    Journal movie_journal {"Movie Journal"};

    movie_journal.add_entry("The Platform");
    movie_journal.add_entry("Ted");
    movie_journal.add_entry("Ted 2");

    movie_journal.save_journal("movie_journal.txt");

    Journal_2 series_journal {"Series Journal"};

    series_journal.add_entry("Breaking Bad");
    series_journal.add_entry("Better Call Saul");

    Persistence_Manager {}.save_journal(series_journal, "series_journal.txt");

    return 0;
}