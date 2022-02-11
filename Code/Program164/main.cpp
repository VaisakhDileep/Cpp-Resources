/*
Created by  : Vaisakh Dileep
Date        : 9, February, 2022
Description : This program helps to understand the different trigonometric functions in C++.
*/

#include<iostream>

#include<math.h>

#include<iomanip>

const double pi {3.14159};

using namespace std;

void display_sin_range_0_to_2_pi();

void display_cosine_range_0_to_2_pi();

void display_tan_range_0_to_2_pi();

void display_asin_range_0_to_2_pi();

void display_acos_range_0_to_2_pi();

void display_atan_range_0_to_2_pi();

void display_atan2_range_0_to_2_pi();

int main()
{
// sin(x): Returns the sine of the angle of 'x' radians.

    display_sin_range_0_to_2_pi();

// cos(x): Returns the cosine of the angle of 'x' radians.

    display_cosine_range_0_to_2_pi();

// tan(x): Returns the tangent of the angle of 'x' radians.

    display_tan_range_0_to_2_pi();

// asin(x): Returns the principle value of the arc sine of 'x'(expressed in radians). arc sine is the inverse operation on sine.
//          "asin()" values range from -pi/2 to +pi/2(since the range is only upto 'pi' we do not get the quadrant information).

    display_asin_range_0_to_2_pi();

// acos(x): Returns the principle value of the arc cosine of 'x'(expressed in radians). arc cosine is the inverse operation on cosine.
//          "acos()" values range from 0 to +pi(since the range is only upto 'pi' we do not get the quadrant information).

    display_acos_range_0_to_2_pi();

// atan(x): Returns the principal value of the arc tangent of 'x'(expressed in radians). arc tangent is the inverse operation on tangent.
//          "atan()" values range from -pi/2 to +pi/2(since the range is only upto 'pi' we do not get the quadrant information).

    display_atan_range_0_to_2_pi();

// atan2(x): Returns the principal value of the arc tangent of 'y'/'x'('y' represents the proportion of they y-coordinate, 'x' represents the proportions of the x-coordinate). arc tangent is the inverse operation on tangent.
//           "atan2()" values range from -pi to +pi(since the range is upto '2*pi' we get the quadrant information).

    display_atan2_range_0_to_2_pi();

    return 0;
}

void display_sin_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' interval.

    double radians {0};

    cout<<"sin values ranged from 0 to 2*pi: \n";
    cout<<"--------------------------------- \n";

    while(radians <= (2 * pi + (0.0001)))
    {
        cout<<"sin("<<setw(12)<<left<<radians<<"): "<<sin(radians)<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_cosine_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12};  // '30 deg' interval.

    double radians {};

    cout<<"cosine values ranged from 0 to 2*pi: \n";
    cout<<"------------------------------------ \n";

    while(radians <= (2 * pi + (0.0001)))
    {
        cout<<"cos("<<setw(12)<<left<<radians<<"): "<<cos(radians)<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_tan_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' interval.

    double radians {0};

    cout<<"tan values ranged from 0 to 2*pi: \n";
    cout<<"--------------------------------- \n";

    while(radians <= (2 * pi + (0.0001)))
    {
        cout<<"tan("<<setw(12)<<left<<radians<<"): "<<tan(radians)<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_asin_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' interval.

    double radians {0};

    cout<<"asin values ranged from 0 to 2*pi: \n";
    cout<<"---------------------------------- \n";

    cout<<"First Quadrant: \n";
    while(radians <= (pi / 2 + (0.0001))) // First Quadrant
    {
        cout<<"asin("<<setw(12)<<left<<sin(radians)<<"): "<<asin(sin(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Second Quadrant: \n";
    while(radians <= (pi + (0.0001))) // Second Quadrant
    {
        cout<<"asin("<<setw(12)<<left<<sin(radians)<<"): "<<asin(sin(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Third Quadrant: \n";
    while(radians <= ((static_cast<double>(3) / 2) * pi + (0.0001)))
    {
        cout<<"asin("<<setw(12)<<left<<sin(radians)<<"): "<<asin(sin(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Fourth Quadrant: \n";
    while(radians <= (2 * pi + (0.0001)))
    {
        cout<<"asin("<<setw(12)<<left<<sin(radians)<<"): "<<asin(sin(radians))<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_acos_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' inerval.

    double radians {0};

    cout<<"acos values ranged from 0 to 2*pi: \n";
    cout<<"---------------------------------- \n";

    cout<<"First Quadrant: \n";
    while(radians <= (pi / 2 + (0.0001))) // First Quadrant
    {
        cout<<"acos("<<setw(12)<<left<<cos(radians)<<"): "<<acos(cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Second Quadrant: \n";
    while(radians <= (pi + (0.0001))) // Second Quadrant
    {
        cout<<"acos("<<setw(12)<<left<<cos(radians)<<"): "<<acos(cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Third Quadrant: \n";
    while(radians <= ((static_cast<double>(3) / 2) * pi + (0.0001))) // Third Quadrant
    {
        cout<<"acos("<<setw(12)<<left<<cos(radians)<<"): "<<acos(cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Fourth Quadrant: \n";
    while(radians <= (2 * pi + (0.0001))) // Fourth Quadrant
    {
        cout<<"acos("<<setw(12)<<left<<cos(radians)<<"): "<<acos(cos(radians))<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_atan_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' interval.

    double radians {0};

    cout<<"atan values ranged from 0 to 2*pi: \n";
    cout<<"---------------------------------- \n";

    cout<<"First Quadrant: \n";
    while(radians <= (pi / 2 + (0.0001))) // First Quadrant
    {
        cout<<"atan("<<setw(12)<<left<<tan(radians)<<"): "<<atan(tan(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Second Quadrant: \n";
    while(radians <= (pi + (0.0001))) // Second Quadrant
    {
        cout<<"atan("<<setw(12)<<left<<tan(radians)<<"): "<<atan(tan(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Third Quadrant: \n";
    while(radians <= ((static_cast<double>(3) / 2) * pi + (0.0001))) // Third Quadrant
    {
        cout<<"atan("<<setw(12)<<left<<tan(radians)<<"): "<<atan(tan(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Fourth Quadrant: \n";
    while(radians <= (2 * pi + (0.0001))) // Fourth Quadrant
    {
        cout<<"atan("<<setw(12)<<left<<tan(radians)<<"): "<<atan(tan(radians))<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}

void display_atan2_range_0_to_2_pi()
{
    double interval {(2 * pi) / 12}; // '30 deg' interval.

    double radians {0};

    cout<<"atan2 values ranged from 0 to 2*pi: \n";
    cout<<"----------------------------------- \n";

    cout<<"First Quadrant: \n";
    while(radians <= (pi / 2 + (0.0001))) // First Quadrant
    {
        cout<<"atan2("<<setw(12)<<left<<sin(radians)<<", "<<setw(12)<<left<<cos(radians)<<"): "<<atan2(sin(radians), cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Second Quadrant: \n";
    while(radians <= (pi + (0.0001))) // Second Quadrant
    {
        cout<<"atan2("<<setw(12)<<left<<sin(radians)<<", "<<setw(12)<<left<<cos(radians)<<"): "<<atan2(sin(radians), cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Third Quadrant: \n";
    while(radians <= ((static_cast<double>(3) / 2) * pi + (0.0001)))
    {
        cout<<"atan2("<<setw(12)<<left<<sin(radians)<<", "<<setw(12)<<left<<cos(radians)<<"): "<<atan2(sin(radians), cos(radians))<<"\n";

        radians += interval;
    }
    cout<<"\n";

    cout<<"Fourth Quadrant: \n";
    while(radians <= (2 * pi + (0.0001)))
    {
        cout<<"atan2("<<setw(12)<<left<<sin(radians)<<", "<<setw(12)<<left<<cos(radians)<<"): "<<atan2(sin(radians), cos(radians))<<"\n";

        radians += interval;
    }

    cout<<"\n\n";
}