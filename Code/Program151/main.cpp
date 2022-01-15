/*
Created by  : Vaisakh Dileep
Date        : 14, December, 2021
Description : This program helps to understand the different ways to create a thread in C++.
*/

#include<iostream>

#include<thread>

using namespace std;

void function_1(int x, int *y, int &z, int &&l)
{
    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<*y<<"\n";

    cout<<"z: "<<z<<"\n";

    cout<<"l: "<<l<<"\n\n";

    (*y)++;

    z++;
}

class functor
{
public:
    void operator()(int x, int *y, int &z)
    {
        cout<<"x: "<<x<<"\n";

        cout<<"y: "<<*y<<"\n";

        cout<<"z: "<<z<<"\n\n";

        (*y)++;

        z++;
    }
};

class class_1
{
public:
    void function(int x, int *y, int &z)
    {
        cout<<"x: "<<x<<"\n";

        cout<<"y: "<<*y<<"\n";

        cout<<"z: "<<z<<"\n\n";

        (*y)++;

        z++;
    }
};

class class_2
{
public:
    static void function(int x, int *y, int &z)
    {
        cout<<"x: "<<x<<"\n";

        cout<<"y: "<<*y<<"\n";

        cout<<"z: "<<z<<"\n\n";

        (*y)++;

        z++;
    }
};

int main()
{
// Creating a thread using function pointer:
    int x {10}, y {20}, z {30};

    cout<<"thread 1: \n";

    thread t1 {function_1, x, &y, std::ref(z), std::move(40)}; // Inorder to pass a variable by reference we have to use "std::ref()". The first parameter is the function name followed by the list of parameters.
                                                               // Inorder to pass a r-value, we have to use "std::move()".

    t1.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

// Creating a thread using lambda expression:
    auto lambda_function = [](int x, int *y, int &z) -> void {
        cout<<"x: "<<x<<"\n";

        cout<<"y: "<<(*y)<<"\n";

        cout<<"z: "<<z<<"\n\n";

        (*y)++;

        z++;
    };

    cout<<"thread 2: \n";

    thread t2 {lambda_function, x, &y, std::ref(z)}; // The first parameter is the lambda name followed by the list of parameters.

    t2.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

    cout<<"thread 3: \n";

    thread t3 {[](int x, int *y, int &z) -> void {
        cout<<"x: "<<x<<"\n";

        cout<<"y: "<<(*y)<<"\n";

        cout<<"z: "<<z<<"\n\n";

        (*y)++;

        z++;
    }, x, &y, std::ref(z)}; // The first parameter is the lambda function followed by the list of parameters.

    t3.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

// Creating a thread using function objects(functors):
    cout<<"thread 3: \n";

    thread t4 {functor(), x, &y, std::ref(z)}; // The first parameter is the functor object followed by the list of parameters. Note we don't have to create an object here.

    t4.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

// Creating a thread using non-static member method:
    cout<<"thread 4: \n";

    class_1 class_1_object {};

    thread t5 {class_1::function, &class_1_object, x, &y, std::ref(z)}; // The first parameter is the address of the member method. The second parameter is the address of the created object(since for the method to be created we need to create the object first). The rest are the parameters to be passed to the function.
    // Note: We can also use "&class_1::function" instead of "class_1::function".

    t5.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

// Creating a thread using static member method:
    cout<<"thread 5: \n";

    thread t6 {class_2::function, x, &y, std::ref(z)}; // The first parameter is the address of the member method followed by the list of parameters. Note we don't have to create an object here because static member methods can be invoked from the class defintion itself.

    t6.join();

    cout<<"x: "<<x<<"\n";

    cout<<"y: "<<y<<"\n";

    cout<<"z: "<<z<<"\n\n";

    return 0;
}