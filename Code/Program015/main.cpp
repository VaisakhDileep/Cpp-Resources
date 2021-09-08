/*
Created by  : Vaisakh Dileep
Date		: 19, December, 2020
Description : This program helps to understand do-while loops in C++.
*/

#include<iostream>

using namespace std;

int main()
{
/*
Syntax for do-while loop:

do
{
	statement(s);
}while(expression); --> include semicolon at the end of the do-while loop. It will be executed at least once.
*/
	int input {};

	do
	{
		cout<<"Enter 9: ";

		cin>>input;
	}while(input != 9);

// Mystery Box:
	char choice {};

	do
	{
		cout<<"----------------------------------\n";
		cout<<"1. Mystery Box 1.\n";
		cout<<"2. Mystery Box 2.\n";
		cout<<"3. Mystery Box 3.\n";
		cout<<"4. Quit.\n";

		cout<<"Enter your choice: ";

		cin>>choice;

		if (choice == '1')
			cout<<"Congratulations, you can restart your life.\n";

		else if (choice == '2')
			cout<<"Congratulations, you get a second life.\n";

		else if (choice == '3')
			cout<<"Congratulations, you get a million dollars.\n";

		else if(choice == '4')
			cout<<"Good Bye .....\n";

		else
			cout<<"Invalid Choice.....\n";
	}while(choice != '4');

	return 0;
}