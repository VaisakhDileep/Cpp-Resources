/*
Created by  : Vaisakh Dileep
Date        : 14, December, 2020
Description : This program helps to understand namespaces in C++.
*/

#include<iostream>

using namespace std; // This makes the things under the std namespace available without having to prefix "std::".

/*
using std::cout; // "using namespace std;" not only brings in "cin", "cout", "endl" but a lot others which is hard to keep track of. This is a better alternative.
using std::cin;
using std::endl;
*/

namespace first_space // Custom namespace
{
    void func()
    {
        cout<<"Inside first namespace."<<endl;
    }
}

namespace second_space // Custom namespace
{
    void func()
    {
        cout<<"Inside second namespace."<<endl;
    }
}

namespace third_space // namespace definition must be done in global scope, or should be nested inside another namespace.
{
    void func()
    {
        cout<<"Inside third namespace."<<endl;
    }

    namespace nested_third_space
    {
        void func()
        {
            cout<<"Inside nested third namespace."<<endl;
        }
    }
}

// Namespace aliases: It allows us to use alternate name for a namespace.

namespace ts_1 = third_space; // We can now use "ts_1" instead of "third_space".

namespace ts_2 = ::third_space;

namespace nts_1 = third_space::nested_third_space;

namespace nts_2 = ::third_space::nested_third_space;

namespace fourth_space
{
    int ten {10};

    void print_ten(); // This is a function declaration.
}

void fourth_space::print_ten() // This is how to define a function whose declaration is inside a namespace.
{
    cout<<"ten: "<<ten<<"\n"; // Notice here we don't have to use "fourth_space::ten", but can just use "ten".
}

int main()
{
// Namespace: It is a declarative region that provides a scope to the identifiers inside it. They are used to organize code.

    cout<<"Inside main function."<<endl; // See here we don't have to include "std::" anywhere.

    first_space::func(); // '::' is the scope resolution operator.
    second_space::func();

    using namespace second_space; // This makes "func()" default to "second_space" namespace, don't have to include "second_space::".

    func();

    using namespace first_space;

    // func(); // Here the compiler doesn't know which namespace to look at.

    cout<<"\n";

    ts_1::func();
    ts_2::func();

    cout<<"\n";

    nts_1::func();
    nts_2::func();

    cout<<"\n";

    fourth_space::print_ten();

    return 0;
}