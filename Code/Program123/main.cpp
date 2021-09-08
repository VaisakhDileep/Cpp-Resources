/*
Created by  : Vaisakh Dileep
Date		: 11, August, 2021
Description : This program helps to understand positive infinity and negative infinity in C++.
*/

#include<iostream>

#include<limits>

using namespace std;

int main()
{
// For more information refer: https://en.cppreference.com/w/cpp/types/numeric_limits/infinity

	double positive_infinity {numeric_limits<double>::infinity()}; // +infinity

	double negative_infinity {-numeric_limits<double>::infinity()}; // -infinity

	cout<<"positive_infinity: "<<positive_infinity<<"\n"; // inf

	cout<<"positive_infinity + 1: "<<(positive_infinity + 1)<<"\n"; // inf

	cout<<"positive_infinity - 1: "<<(positive_infinity - 1)<<"\n"; // inf

	cout<<"positive_infinity + positive_infinity: "<<(positive_infinity + positive_infinity)<<"\n"; // inf

	cout<<"positive_infinity - positive_infinity: "<<(positive_infinity - positive_infinity)<<"\n\n"; // nan

	cout<<"negative_infinity: "<<negative_infinity<<"\n"; // -inf

	cout<<"negative_infinity + 1: "<<(negative_infinity + 1)<<"\n"; // -inf

	cout<<"negative_infinity - 1: "<<(negative_infinity - 1)<<"\n"; // -inf

	cout<<"negative_infinity + negative_infinity: "<<(negative_infinity + negative_infinity)<<"\n"; // -inf

	cout<<"negative_infinity - negative_infinity: "<<(negative_infinity - negative_infinity)<<"\n\n"; // nan

	cout<<"positive_infinity + negative_infinity: "<<(positive_infinity + negative_infinity)<<"\n"; // nan

	return 0;
}