/*
Created by  : Vaisakh Dileep
Date        : 23, January, 2021
Description : Unique_ptr.
*/

#include<iostream>

#include<vector>

#include<memory> // This header file is used for implementing smart pointers.

using namespace std;

class Test
{
private:
    int data;
public:
    Test() // No-args constructor
        : data {0}
    {
        cout<<"No-args constructor called for Test.\n";
    }

    Test(int data) // Overloaded constructor
        : data {data}
    {
        cout<<"Overloaded constructor called for Test ["<<data<<"]\n";
    }

    ~Test() // Destructor
    {
        cout<<"Destructor called for Test ["<<data<<"]\n";
    }

    int get_data() const
    {
        return data;
    }
};

int main()
{
/*
Problems with raw pointers:
1. Uninitialized(wild) pointers
2. Memory leaks
3. Dangling pointers --> One pointer pointing to somewhere that has already been deallocated.
4. Not exception safe
*/

/*
RAII - Resource Acquisition is Initialization, RAII objects are allocated on the stack.
Resource Acquisition --> Open a file, Allocated memory, Acquire a lock.
Is initialization --> The resource is acquired in a constructor.
Resource relinquishing --> Happens in the destructor. Close the file, Deallocates the memory, Release the lock.
*/

/*
Smart pointers are objects, they can only point to heap-allocated memory. They automatically call delete when no longer needed. They adhere to RAII principles.

C++ smart pointers are:
1. unique pointers(unique_ptr)
2. shared pointers(shared_ptr)
3. weak pointers(weak_ptr)
4. auto pointers(auto_ptr) --> This is deprecated.

Smart pointers are defined by class templates.

Smart pointers overload the following operators:
1. Dereference(*)
2. Member selection(->)

Note: Pointer arithemetics is not supported(++, --).

We can use custom deleters in smart pointers.
*/

/*
Syntax for using smart pointers:
std::smart_pointer<some_class> ptr = ....
ptr->method()
cout<<*ptr<<endl; // Smart pointers will be destroyed automatically when no longer needed.
*/

/*
unique_ptr<T>: It points to an object of the type "T" on the heap.

Properties of unique_ptr:
1. It is unique-there can only be one unique_ptr<T> pointing to an object on the heap.
2. It has clear ownership unlike raw pointers.
3. It cannot be assigned or copied.
4. It can be moved.
5. When the pointer is destroyed, what it points to is automatically destroyed.
*/
    unique_ptr<Test> test_1 {new Test {100}}; // Here it is automatically deallocated since it is a smart pointer, also notice that we are passing "new Test {100}" as arguments to the constructor.

    cout<<"Test 1: "<<test_1->get_data()<<"\n";

    // unique_ptr<Test> test_0 = new Test {100}; // This will give an error.

    unique_ptr<Test> test_2 = make_unique<Test> (200); // Here overloaded constructor is called. "make_unique<> ()" returns a "unique_ptr". "make_unique" is kind of exception safe.

    cout<<"Test 2: "<<test_2->get_data()<<"\n";

    auto test_3 = make_unique<Test> (300); // See here we can use "auto".

    cout<<"Test 3: "<<test_3->get_data()<<"\n";

    cout<<"Test 3 is pointing to: "<<test_3.get()<<"\n"; // .get() will return a pointer(this will help if we want to assign to a raw pointer).

    // test_3 = test_2; // This will give an error because "unique_ptr" cannot be assigned. They have clear ownership.

    test_3 = move(test_2); // This will move "test_2" to "test_3", "test_2" is now a "nullptr".

    if(!test_2) // If used in an if statement it checks if it is initialized or not.
    {
        cout<<"Test 2 is a null pointer.\n";
    }

    Test *test_4 = test_3.get(); // This is possible but not recommended.

    cout<<"Test 4: "<<test_4->get_data()<<"\n";

    test_1.reset(); // "test_1" is now a null pointer.

    if(!test_1)
    {
        cout<<"Test 1 is a null pointer.\n";
    }

    vector<unique_ptr<Test>> test_vector;

    test_vector.push_back(make_unique<Test> (700));
    test_vector.push_back(make_unique<Test> (800));
    test_vector.push_back(move(test_3)); // Use move() when using push_back(), otherwise it might crash.
    // test_vector.push_back(test_4); // This will give an error because vector can only hold "unique_ptr".

/*
    for(auto test : test_vector)
    {
        cout<<test->get_data()<<"\n"; // This won't compile because we can't copy "unique_ptr".
    }
*/

    cout<<"\n";

    for(auto &test : test_vector)
    {
        cout<<"Data: "<<test->get_data()<<"\n"; // This will work because we are passing by reference.
    }

    cout<<"\n";

    return 0;
}