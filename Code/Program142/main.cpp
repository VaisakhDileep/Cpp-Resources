/*
Created by  : Vaisakh Dileep
Date        : 14, November, 2021
Description : This program helps to understand std::ratio in C++.
*/

#include<iostream>

#include<ratio> // Inorder to use the std::ratio template.

using namespace std;

int main()
{
// std::ratio template is used to instantiate types that represent a finite rational number denoted by a numerator and a denominator.

/*
Internally the std::ratio template class looks like:
    template<intmax_t N, intmax_t D = 1> class ratio;
*/
    ratio<1, 3> one_third; // ratio object.

    cout<<"one_third : "<<one_third.num<<"/"<<one_third.den<<"\n";

    ratio<2, 8> two_eighth; // if the greatest common divisor(GCD) of the numerator and denominator is not '1', then we divide the numerator and denominator with the GCD value.

    cout<<"two_eighth: "<<two_eighth.num<<"/"<<two_eighth.den<<"\n\n";

// std::ratio has some predefined ratio types:
    cout<<"atto : "<<atto {}.num<<"/"<<atto {}.den<<"\n";
    cout<<"femto: "<<femto{}.num<<"/"<<femto{}.den<<"\n";
    cout<<"pico : "<<pico {}.num<<"/"<<pico {}.den<<"\n";
    cout<<"nano : "<<nano {}.num<<"/"<<nano {}.den<<"\n";
    cout<<"milli: "<<milli{}.num<<"/"<<milli{}.den<<"\n";
    cout<<"centi: "<<centi{}.num<<"/"<<centi{}.den<<"\n";
    cout<<"deci : "<<deci {}.num<<"/"<<deci {}.den<<"\n";
    cout<<"deca : "<<deca {}.num<<"/"<<deca {}.den<<"\n";
    cout<<"hecto: "<<hecto{}.num<<"/"<<hecto{}.den<<"\n";
    cout<<"kilo : "<<kilo {}.num<<"/"<<kilo {}.den<<"\n";
    cout<<"mega : "<<mega {}.num<<"/"<<mega {}.den<<"\n";
    cout<<"giga : "<<giga {}.num<<"/"<<giga {}.den<<"\n";
    cout<<"tera : "<<tera {}.num<<"/"<<tera {}.den<<"\n";
    cout<<"peta : "<<peta {}.num<<"/"<<peta {}.den<<"\n";
    cout<<"exa  : "<<exa  {}.num<<"/"<<exa  {}.den<<"\n";

    return 0;
}