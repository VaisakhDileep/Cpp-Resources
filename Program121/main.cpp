/*
Created by  : Vaisakh Dileep
Date		: 26, July, 2021
Description : This program helps to understand std::pair in C++.
*/

#include<iostream>

#include<utility> // This header file is needed to access "std::pair".

#include<tuple> // For "tie()".

using namespace std;

bool operator<(pair<int, char> &arg_1, pair<int, char> &arg_2) // Similarly we can overload other operators for std::pair<int, char> objects.
{
	if(arg_1.first < arg_2.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	pair<int, string> student_1;

	student_1.first = 77;

	student_1.second = "Mr. Vaisakh Dileep";

	cout<<"ROLL NO: "<<student_1.first<<"\n"<<"Name: "<<student_1.second<<"\n\n";

	pair<int, string> student_2(76, "Mr. Train"); // We can initialize a std::pair object like this.

	cout<<"ROLL NO: "<<student_2.first<<"\n"<<"Name: "<<student_2.second<<"\n\n";

	pair<int, string> student_3 {78, "Mr. Taxi"}; // We can initialize a std::pair object like this too.

	cout<<"ROLL NO: "<<student_3.first<<"\n"<<"Name: "<<student_3.second<<"\n\n";

	pair<int, string> student_4;

	student_4 = make_pair(75, "Mr. Race Car"); // We can assign a std::pair object like this.

	cout<<"ROLL NO: "<<student_4.first<<"\n"<<"Name: "<<student_4.second<<"\n\n";

	pair<int, char> pair_1 {1, 'A'}, pair_2 {26, 'Z'};

	cout<<"[Before Swap] pair_1: {"<<pair_1.first<<", "<<pair_1.second<<"}    pair_2: {"<<pair_2.first<<", "<<pair_2.second<<"}\n";

	pair_1.swap(pair_2); // This will swap the contents of the two std::pair objects.

	cout<<"[After Swap] pair_1: {"<<pair_1.first<<", "<<pair_1.second<<"}    pair_2: {"<<pair_2.first<<", "<<pair_2.second<<"}\n\n";

	int int_var {};

	char char_var {};

	tie(int_var, char_var) = pair_1; // "tie()" is available in the tuple header library. It will bind each variable to the corresponding element in the pair.

	cout<<"int_var : "<<int_var<<"\n"<<"char_var: "<<char_var<<"\n";

	tie(ignore, char_var) = pair_2; // We can use "ignore" if there are no variables to be bound.

	cout<<"pair_1 < pair_2: "<<(pair_1 < pair_2)<<"\n"; // We have overloaded the '<' operator, so that it will work with the std::pair object.

	return 0;
}