/*
Created by  : Vaisakh Dileep
Date        : 24, October, 2021
Description : This program helps to understand padding in structures in C++.
*/

// This program might be different for different os.

#include<iostream>

using namespace std;

// #pragma pack(1) // This will disable padding(structure packing).

struct struct_1
{
    int A;

    char B;

    int C;
};

struct struct_2
{
    char A;

    short int B;
};

struct struct_3
{
    long double A;

    char B;
};

struct inner_struct
{
    char A;

    long double B;
};

struct outer_struct
{
    char A;

    inner_struct B;
};

int main()
{
    cout<<"sizeof(int)          : "<<sizeof(int)<<"\n"; // In my os, it is "4 bytes".
    cout<<"sizeof(char)         : "<<sizeof(char)<<"\n"; // In my os, it is "1 byte".
    cout<<"sizeof(short int)    : "<<sizeof(short int)<<"\n"; // In my os, it is "2 bytes".
    cout<<"sizeof(long long int): "<<sizeof(long long int)<<"\n\n"; // In my os, it is "8 bytes".

/*
1 byte data-type  -> can be assigned to any memory location. egs 0, 1, 2, 3, 4, ...
2 byte data-type  -> can be assigned to memory locations that are a multiple of '2'. egs 0, 2, 4, 6, ...
4 byte data-type  -> can be assigned to memory locations that are a multiple of '4'. egs 0, 4, 8, 16, ...
8 byte data-type  -> can be assigned to memory locations that are a multiple of '8'. egs 0, 8, 16, 24, ...
16 byte data-type -> can be assigned to memory locations that are a multiple of '16'. egs 0, 16, 32, ...
Notice all the data-type size are of the the power of 2.
*/

    struct_1 struct_1_object {0, '_', 0};

    cout<<"sizeof(struct_1_object): "<<sizeof(struct_1_object)<<"\n"; // We would expect it to be "9 bytes", but for my os it is "12 bytes".

/*
struct struct_1 // Internally
{
// current memory offset: 0
    int A; // Since the memory offset(0) is a multiple of the size of int(4), we can place 'A' at 0.

// current memory offset: 4
    char B; // Since the memory offset(4) is a multiple of the size of char(1), we can place 'B' at 4.

// current memory offset: 5
    char B_pad[3]; // We add padding here, so that we get the memory offset as a multiple of 4, so that we can place 'C' at 8.

// current memory offset: 8
    int C; // Since the memory offset(8) is a multiple of the size of int(4), we can place 'C' at 8.

// current memory offset: 8
    // The largest data-type in "struct_1" is int(4), 8 is a multiple of 4, so no need to do anymore padding.

// size of "struct_1" is 8.
};
*/

    struct_2 struct_2_object {'_', 0};

    cout<<"sizeof(struct_2_object): "<<sizeof(struct_2_object)<<"\n";

/*
struct struct_2 // Internally
{
// current memory offset: 0
    char A; // Since the memory offset(0) is a multiple of the size of char(1), we can place 'A' at 0.

// current memory offset: 1
    char A_pad[1]; // We add padding here, so that we get the memory offset as a multiple of 2, so that we can place 'B' at 2.

// current memory offset: 2
    short B; // Since the memory offset(2) is a multiple f the size of short(2), we can place 'B' at 2.

// current memory offset: 4
    // The largest data-type in "struct_2" is short(2), 4 is a multiple of 2, so no need to do anymore padding.

// size of "struct_2" is 4.
}
*/

    struct_3 struct_3_object {0, '_'};

    cout<<"sizeof(struct_3_objects): "<<sizeof(struct_3_object)<<"\n\n";

/*
struct struct_3 // Internally
{
// current memory offset: 0
    long double A; // Since the memory offset(0) is a multiple of the size of long double(16), we can place 'A' at 0.

// current memory offset: 16
    char B; // Since the memory offset(16) is a multiple of the size of char(1), we can place 'B' at 16.

// current memory offset: 17
    // The largest data-type in "struct_2" is long double(16), 17 is not a multiple of 16, therefore we need to add padding to make it a multiple of 16.
    char pad_B[15];

// current memory offset: 32

// size of "struct_3" is 32.
}
*/

    inner_struct inner_struct_object {'_', 0.0};

    cout<<"sizeof(inner_struct_object): "<<sizeof(inner_struct_object)<<"\n";

    outer_struct outer_struct_object {'_', {'_', 0.0}};

    cout<<"sizeof(outer_struct_object): "<<sizeof(outer_struct_object)<<"\n";

/*
Inner structure:
struct inner_struct // Internally
{
// current memory offset: 0
    char A; // Since the memory offset(0) is a multiple of the size of char(1), we can place 'A' at 0.

// current memory offset: 1
    char A_pad[15]; // We add padding here, so that we get the memory offset as a multiple of 16, so that we can place 'B' at 16.

// current memory offset: 16
    long double B; // Since the memory offset(16) is a multiple of the size of long double(16), we can place 'B' at 16.

// current memory offset: 32
    // The largest data-type in "inner_struct" is long double(16), 32 is a multiple of 16, so no need to do anymore padding.

// size of "inner_struct" is 32.
}
*/

/*
Outer structure:
In "inner_struct" the largest data-type is long double(16 bytes), this will be used for alligning "inner_struct" in "outer_struct"(trying to allign with 32 will result in a huge amount of unused word reads).

struct outer_struct // Internally
{
// current memory offset: 0
    char A; // Since the memory offset(0) is a multiple of the size of char(1), we can place 'A' at 0.

// current memory offset: 1
    char A_pad[15]; // We add padding here, so that we get the memory offset as a multiple of 16, so that we can place 'B' at 16.

// current memory offset: 16
    inner_struct B; // Since the memory offset(16) is a multiple of the size of long double(16), we can place 'B' at 16.

// current memory offset: 48
    // The largest data-type in "outer_struct" is long double(16)[from "inner_struct"], 48 is a multiple of 48, so no need to do anymore padding.

// size of "outer_struct" is 48.
}
*/

    return 0;
}