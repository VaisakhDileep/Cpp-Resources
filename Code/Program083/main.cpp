/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2021
Description : Weak_ptr.
*/

#include<iostream>

#include<memory>

using namespace std;

// ------------------------------ Class A and B ------------------------------

class B; // Forward declaration

class A
{
private:
    shared_ptr<B> B_ptr;
public:
    A()
    {
        cout<<"Constructor for A called.\n";
    }

    ~A()
    {
        cout<<"Destructor for A called.\n";
    }

    void set_B(shared_ptr<B> &b)
    {
        B_ptr = b;
    }
};

class B
{
private:
    shared_ptr<A> A_ptr;
public:
    B()
    {
        cout<<"Constructor for B called.\n";
    }

    ~B()
    {
        cout<<"Destructor for B called.\n";
    }

    void set_A(shared_ptr<A> &a)
    {
        A_ptr = a;
    }
};

// ------------------------------ Modified Class A and Class B ------------------------------

class modified_B; // Forward declaration

class modified_A
{
private:
    shared_ptr<modified_B> modified_B_ptr;
public:
    modified_A()
    {
        cout<<"Constructor for modified_A called.\n";
    }

    ~modified_A()
    {
        cout<<"Destructor called for modified_A called.\n";
    }

    void set_B(shared_ptr<modified_B> &b)
    {
        modified_B_ptr = b;
    }
};

class modified_B
{
private:
    weak_ptr<modified_A> modified_A_ptr; // Notice here we are using weak pointer.
public:
    modified_B()
    {
        cout<<"Constructor called for modified_B called.\n";
    }

    ~modified_B()
    {
        cout<<"Destructor called for modified_B called.\n";
    }

    void set_A(shared_ptr<modified_A> &a)
    {
        modified_A_ptr = a;
    }
};

int main()
{
/*
weak_ptr<T>: It provides a non-owning "weak" reference.
Properties of weak_ptr:
1. It does not participate in owning relationship.
2. Always created from a shared_ptr.
3. Does not increment or decrement reference use count.
4. Used to prevent strong reference cycles which could prevent objects from being deleted.
*/

/*
Circular or Cyclic Reference:
It happens when:
1. A refers to B(A has a shared_ptr<B>)
2. B refers to A(B has a shared_ptr<A>)

Strong ownership prevents heap deallocation.
*/
    {
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();

        a->set_B(b);
        b->set_A(a);
    } // Destructor is not called here, because of circular reference.

    cout<<"\n";

    {
        shared_ptr<modified_A> modified_a = make_shared<modified_A>();
        shared_ptr<modified_B> modified_b = make_shared<modified_B>();

        modified_a->set_B(modified_b);
        modified_b->set_A(modified_a);

        cout<<"\n";
    } // Destructor is called here, because we are using "weak_ptr" for class B.

    cout<<"\n";

    return 0;
}