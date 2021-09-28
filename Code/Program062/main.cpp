/*
Created by  : Vaisakh Dileep
Date        : 3, January, 2021
Description : This program helps to understand friends of a class in C++.
*/

#include<iostream>

#include<string>

using namespace std;

// --------------- Wallet ---------------

class Wallet
{
private:
    double cash;

    friend void steal(Wallet &victim);
public:
    Wallet(double amount = 0.0); // Constructor with default value

    ~Wallet(); // Destructor

    double get_cash();
};

Wallet::Wallet(double amount)
{
    cash = amount;
}

Wallet::~Wallet()
{
}

double Wallet::get_cash()
{
    return cash;
}

void steal(Wallet &victim);

void display_cash(Wallet owner);

class ColorB; // Forward declaration --> It refers to the beforehand declaration of the syntax or signature of an identifier, variable, function, class. etc. prior to its usage.

// --------------- ColorA ---------------

class ColorA
{
private:
    string color {"white"};

    friend void swap(ColorA &colorA, ColorB &colorB);
public:
    ColorA(string color = "white"); // Constructor

    string get_color();
};

ColorA::ColorA(string color)
{
    this->color = color;
}

string ColorA::get_color()
{
    return color;
}

// --------------- ColorB ---------------

class ColorB
{
private:
    string color {"black"};

    friend void swap(ColorA &colorA, ColorB &colorB); // Here we define "swap" again for "ColorB" because "color" in "ColorB" is not available to the class "ColorA".
public:
    ColorB(string color = "black"); // Constructor

    string get_color();
};

ColorB::ColorB(string color)
{
    this->color = color;
}

string ColorB::get_color()
{
    return color;
}

class PaintB; // Forward declaration.

// -------------- PaintA --------------

class PaintA
{
private:
    string color {"white"};

    friend class PaintB; // This makes all the members in "PaintA" accessible to the "PaintB" class.
public:
    PaintA(string color = "white"); // Constructor 

    string get_color();
};

PaintA::PaintA(string color)
{
    this->color = color;
}

string PaintA::get_color()
{
    return color;
}

// -------------- PaintB --------------

class PaintB
{
private:
    string color {"black"};
public:
    PaintB(string color = "black"); // Constructor

    string get_color();

    void swap(PaintA &paintA); // Here "PaintB" class can access every members of "PaintA" class.
};

PaintB::PaintB(string color)
{
    this->color = color;
}

string PaintB::get_color()
{
    return color;
}

void PaintB::swap(PaintA &paintA)
{
    string temp {paintA.color};

    paintA.color = color;
    color = temp;
}

void swap(ColorA &colorA, ColorB &colorB);

void display_Color_A(ColorA colorA);
void display_Color_B(ColorB colorB);

void display_Paint_A(PaintA paintA);
void display_Paint_B(PaintB paintB);

int main()
{
/*
Friend: It is a function or class that has access to private class member and that function or class is not a member of the class it is accessing.

Here,
Function: It can be a regular non-member function or it can be a member method of another class.
Class: Another class can have access to private class members.

Note:
1. Friendship is not symmetric: It must be explicitly granted, so if 'A' is a friend of 'B', then 'B' is NOT a friend of 'A'.
2. Friendship is not transitive: It must be explicitly granted, so if 'A' is a friend of 'B' AND 'B' is a friend of 'C', then 'A' is NOT a friend of 'C'.

Friendship is granted and not taken(unlike friendship among friends).
*/

/*
Friend Function: Friend functions are used to access the private and protected data of a class. We declare a friend function using the "friend" keyword inside the body of the class.

Syntax for friend function:
class ClassName
{
    .... .. ....
    friend return_type function_name(arguments);
    .... .. ....
};
*/

/*
Friend Class: When a class is delcared a friend class, all the member functions of the class becomes friend functions to the class.

Syntax for the friend class:
class ClassB; // Forward declaration.

class ClassA
{
    friend class ClassB; // Since "ClassB" is a friend class, we can access all members of "ClassA" from inside "ClassB"(please note that we cannot access members of "ClassB" from inside "ClassA").
    .... .. ....
};

class ClassB
{
    .... .. ....
};
*/

    Wallet Homers_wallet {10'000};

    display_cash(Homers_wallet);

    steal(Homers_wallet);

    display_cash(Homers_wallet); // Notice here that someone has stolen '$100' from Homer's account

    ColorA Purple {"purple"};
    ColorB Violet {"violet"};

    cout<<"\n";

    display_Color_A(Purple);
    display_Color_B(Violet);

    swap(Purple, Violet);

    cout<<"\n";

    display_Color_A(Purple);
    display_Color_B(Violet); // See here we swapped the colors.

    PaintA Peach {"peach"};
    PaintB Pink {"pink"};

    cout<<"\n";

    display_Paint_A(Peach);
    display_Paint_B(Pink);

    Pink.swap(Peach);

    cout<<"\n";

    display_Paint_A(Peach);
    display_Paint_B(Pink);

    cout<<"\n";

    return 0;
}

void steal(Wallet &victim)
{
    victim.cash -= 100;
}

void display_cash(Wallet owner)
{
    cout<<"Cash in Wallet: $"<<owner.get_cash()<<"\n";
}

void swap(ColorA &colorA, ColorB &colorB)
{
    string temp {colorA.color};

    colorA.color = colorB.color;
    colorB.color = temp;
}

void display_Color_A(ColorA colorA)
{
    cout<<"Color A: "<<colorA.get_color()<<"\n";
}

void display_Color_B(ColorB colorB)
{
    cout<<"Color B: "<<colorB.get_color()<<"\n";
}

void display_Paint_A(PaintA paintA)
{
    cout<<"Paint A: "<<paintA.get_color()<<"\n";
}

void display_Paint_B(PaintB paintB)
{
    cout<<"Paint B: "<<paintB.get_color()<<"\n";
}