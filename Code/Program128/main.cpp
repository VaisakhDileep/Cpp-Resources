/*
Created by  : Vaisakh Dileep
Date		: 18, September, 2021
Description : This program helps to understand typedef in C++.
*/

#include<iostream>

using namespace std;

typedef struct car
{
	string car_model;

	string year;
} ford; // Here ford is the alternative name for the "car" structure.

typedef ford mustang; // We could also use typedef like this for the "car" struct.

int main()
{
/*
typedef is a keyword which is used to assign alternative names to already existing datatypes.

Syntax for typedef:
	typedef data_type new_data_type;
*/
	{
		typedef int bananna;

		bananna b {10}; // We can create an int object using "bananna".

		int i {20}; // We can still use "int".

		cout<<"b: "<<b<<"\n";
		cout<<"i: "<<i<<"\n";
	} // typedef only applies in this block.

	car mustang_2021 {"mustang shelby GT500", "2021"};

	cout<<mustang_2021.car_model<<" "<<mustang_2021.year<<"\n";

	ford mustang_2020 {"mustang shelby GT500", "2020"};

	cout<<mustang_2020.car_model<<" "<<mustang_2020.year<<"\n";

	mustang mustang_2019 {"mustang shelby GT500", "2019"};

	cout<<mustang_2019.car_model<<" "<<mustang_2019.year<<"\n";
/*
typedef vs #define:
1. typedef can only provide alternative names to data types, it cannot do the same with values whereas #define can provide alternative names to values as well.
2. typedef is compiler-based, whereas #define is preprocessor-based.
3. typedef is terminated with ';' whereas we don't have to do it for #define.
4. typedef follows scope rules whereas #define do not abide by any scope rules.
5. #define only performs copy-paste for the new defined value, where typedef actually implements the new defined value.
*/

	return 0;
}