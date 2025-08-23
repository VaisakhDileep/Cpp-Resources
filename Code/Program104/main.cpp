/*
Created by  : Vaisakh Dileep
Date        : 8, February, 2021
Description : Global namespace and named namespace.
*/

#include<iostream>

using namespace std;

void func()
{
    cout<<"::func\n";
}

namespace hidden
{
    void func()
    {
        cout<<"hidden::func\n";
    }
}

int main()
{
    func(); // Here func() with the global namespace is called.

    ::func();

    hidden::func();

    using namespace hidden;

    cout<<"\nAfter using namespace \"hidden\".\n\n";

    //func(); // This will give an error since it is ambiguous, don't know whether to use global namespace or named namespace.

    ::func();

    hidden::func();

    return 0;
}