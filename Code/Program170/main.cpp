/*
Created by  : Vaisakh Dileep
Date        : 7, November, 2022
Description : Enum class.
*/

#include<iostream>

using namespace std;

int main() {
    {
        enum Two_Values_1 {ONE, TWO};
        // enum Two_Values_2 {TWO, THREE}; // This will create an error since when using enum, we cannot use values present in another enum, in this case "TWO".

        // int ONE = 1; // This will create an error since we cannot use a variable name same as any enum value, in this case "ONE".

        enum Two_Colours {YELLOW, BLUE};

        Two_Values_1 tw1 = ONE;

        Two_Colours tc = YELLOW;

        if(tw1 == tc) { // This will compare tw1(ONE which is '0') and tc(YELLOW which is '0').
            cout << "ONE and YELLOW are equal!\n"; // This shouldn't have executed since ONE and YELLOW are meant to distinguishable.
        } // We do get a warning.
        else {
            cout << "ONE and YELLOW are not equal!\n";
        }

        enum Single_Value {SINGLE};

        Single_Value sv = SINGLE;

        cout << "sizeof(sv): " << sizeof(sv) << "\n\n"; // Here size of enum is '4' .The size of enum is the size of the underlying integer type that can hold the biggest enumerated value. It stars from 4 bytes(int), compiler chooses a bigger type as required.
    }

// enum class(scoped enumerations) make enumerations strongly scoped and strongly typed. class enumerations don't allow implicit conversion to int and doesn't compare enumerators from different enumerations.

/*
Syntax for enum class:
    enum class enum_demo { enumerator_1, enumerator_2, enumerator_3 ....}; // Declaration

    enum_demo enum_demo_object = enum_demo::enumerator_1;

*/
    {
        enum class Two_Values_1 {ONE, TWO};
        enum class Two_Values_2 {TWO, THREE}; // This will not create an error for enum class.

        int ONE = 1; // This will not create an error for enum class.

        enum class Two_Colours {YELLOW, BLUE};

        Two_Values_1 tw1 = Two_Values_1::ONE;

        Two_Colours tc = Two_Colours::YELLOW;

/*
        if(tw1 == tc) {
            cout << "ONE and YELLOW are equal!\n";
        }
        else {
            cout << "ONE and YELLOW are not equal!\n";
        }
*/ // This will create an error since we cannot compare two enum class objects.

        if(tw1 == Two_Values_1::ONE) { // This is possible too.
            cout << "tw1 is ONE!\n";
        }

        enum class Single_Value : char {SINGLE}; // We have the freedom to change the underlying type of enum class. It may be any integral data type such as char, short or unsigned int etc.

        Single_Value sv = Single_Value::SINGLE;

        cout << "sizeof(sv): " << sizeof(sv) << "\n";
    }

    return 0;
}