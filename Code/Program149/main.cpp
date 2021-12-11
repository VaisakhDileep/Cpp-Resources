/*
Created by  : Vaisakh Dileep
Date        : 10, December, 2021
Description : This program helps to understand std::bitset in C++.
*/

#include<iostream>

#include<bitset>

using namespace std;

int main()
{
    bitset<30> bit_array_1 {}; // "std::bitset" helps us to represent bits in a memory efficient way.

    bool bool_array[30] {}; // "bool" or "char" are the smallest data-type we have in C++, but still using them to represent an array of bits is expensive.

    char bool_string[31] {}; // The last "char" element is reserved for '\0'.

    cout<<"sizeof(bit_array_1): "<<(sizeof(bit_array_1) * 8)<<"\n"; // Here notice it's '32' and not '30', this is because C++ cannot allocate memory in bits. Therefore in my computer it is allocated as multiples of 32(in some computer it's allocated as multiples of 64).

    cout<<"sizeof(bool_array) : "<<(sizeof(bool_array) * 8)<<"\n";

    cout<<"sizeof(bool_string): "<<(sizeof(bool_string) * 8)<<"\n\n"; // See here that "std::bitset" is a lot more memory efficient than representing bits as an array of "char" or "bool".

    bit_array_1 = 8; // We can assign an "int" value to a "std::bitset" object. The "int" value will be converted to it's binary representation.

    cout<<"bit_array_1: "<<bit_array_1<<"\n"; // We can use the '<<' operator to display the "std::bitset" object.

    cout<<"bit_array_1: ";
    for(int i {0}; i < bit_array_1.size(); i++) // This is another way of displaying the "std::bitset" object.
    {
        cout<<bit_array_1[i];
    }
    cout<<"\n\n"; // Notice that the two outputs are different. This is because indexing happens from left to right(from '0') in the "std::bitset" but for a binary number the power(place value) is assigned from right to left(from '0').

    bitset<15> bit_array_2 {};

    bit_array_2[0] = 1; // This will set the first bit in the "std::bitset" object.

    cout<<"bit_array_2: "<<bit_array_2<<"\n";

    cout<<"bit_array_2: ";
    for(int i {0}; i < bit_array_2.size(); i++)
    {
        cout<<bit_array_2[i]; // Notice here too the two outputs are different. This is because we are setting the first bit(first bit is the rightmost bit in the "std::bitset" object).
    }
    cout<<"\n\n";

    bit_array_2 = 0; // This will clear "bit_array_2".

    bit_array_2.set(1); // This will set the 'i'th bit from the right.

    cout<<"bit_array_2: "<<bit_array_2<<"\n";

    bit_array_2.set(); // This will set all the bits in the "std::bitset" object.

    cout<<"bit_array_2: "<<bit_array_2<<"\n\n";

    bit_array_2.reset(1); // This will reset the 'i'th bit from the right.

    cout<<"bit_array_2: "<<bit_array_2<<"\n";

    bit_array_2.reset(); // This will reset all the bits in the "std::bitset" object.

    cout<<"bit_array_2: "<<bit_array_2<<"\n\n";

    bit_array_2.flip(1); // This will flip the 'i'th bit from the right.

    cout<<"bit_array_2: "<<bit_array_2<<"\n";

    bit_array_2.flip(); // This will flip all the bits in the "std::bitset" object.

    cout<<"bit_array_2: "<<bit_array_2<<"\n\n";

    cout<<std::boolalpha;

    cout<<"bit_array_2.count(): "<<bit_array_2.count()<<"\n\n"; // This will count the number of set bits in the "std::bitset" object.

    cout<<"bit_array_2.size(): "<<bit_array_2.size()<<"\n\n"; // This will return the size of the "std::bitset" object.

    cout<<"bit_array_2.test(1): "<<bit_array_2.test(1)<<"\n"; // This will check if the 'i'th element from the right is set or not.
    cout<<"bit_array_2.test(0): "<<bit_array_2.test(0)<<"\n\n";

    cout<<"bit_array_2.any(): "<<bit_array_2.any()<<"\n\n"; // This will return "true" if any of the bit in the "std::bitset" object is set.

    bit_array_2.reset(); // This will reset all the bits.

    cout<<"bit_array_2.none(): "<<bit_array_2.none()<<"\n\n";

    bit_array_2.set(); // This will set all the bits.

    cout<<"bit_array_2.all(): "<<bit_array_2.all()<<"\n";

    return 0;
}