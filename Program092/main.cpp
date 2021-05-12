/*
Created by  : Vaisakh Dileep
Date		: 28, January, 2021
Description : This program helps to understand streams and stream manipulators in C++.
*/

#include<iostream> // ostream, istream, iostream are declared in this header file.

#include<iomanip> // For resetiosflags()

#include<string>

using namespace std;

void ruler()
{
	cout<<"123456789012345678901234567890\n";
}

int main()
{
/*
C++ uses streams as interface between the program and input/output devices.
Stream is independent of the actual device. Input stream provides data to the program. Output stream receives data from the program.
Refer "C++InputStreamVsOutputStream.png" in "Additional Resources".
*/

/*
Some of the common header files for streams:
1. iostream --> Provides definitions for formatted input and output from/to streams.
2. fstream  --> Provides definitions for formatted input and output from/to file streams.
3. iomanip  --> Provides definitions for manipulators used to format stream I/O.
*/

/*
Some of the commonly used stream classes:
1. ios          --> Provides basic support for formatted and unformatted I/O operations. It provides a base class for most other classes.
2. ifstream     --> Provides high-level input operations on file based streams.
3. ofstream     --> Provides high-level output operations on file based streams.
4. fstream      --> Provides for high-level I/O operations on file based streams. They are derived from ofstream and ifstream.
5. stringstream --> Provides for high-level I/O operations on memory based strings. Derived from istringstream and ostringstream.
*/

/*
Some of the global stream objects[initialized before main executes]:
1. cin  --> Standard input stream - by default it is connected to the standard input device(keyboard). It is an instance of istream.
2. cout --> Standard output stream - by default it is connected to the standard output device(console). It is an instance of ostream.
3. cerr --> Standard error stream - by default it is connected to the standard error device(console). It is an instance of ostream[unbuffered].
4. clog --> Standard log stream - by default it is connected to the standard log device(console). It is an instance of ostream[unbuffered].
*/

/*
Stream manipulators: Streams have useful member functions to control formatting, they can be used for input and output streams. The time of the effect on the stream varies.
They can be member functions or manipulators.
std::cout.width(10); // member function
std::cout<<std::setw(10); // manipulator
*/

// Stream manipulators for Boolean types:
	cout<<"\n:::::Default way of displaying Boolean:::::\n";
	cout<<"10 == 10: "<<(10 == 10)<<"\n";
	cout<<"10 != 10: "<<(10 != 10)<<"\n";

	cout<<"\n:::::Using std::boolalpha for displaying Boolean:::::\n";
	cout<<boolalpha; // std::boolalpha
	cout<<"10 == 10: "<<(10 == 10)<<"\n";
	cout<<"10 != 10: "<<(10 != 10)<<"\n";

	cout<<"\n:::::Using std::noboolalpha for displaying Boolean:::::\n";
	cout<<noboolalpha; // std::noboolalpha
	cout<<"10 == 10: "<<(10 == 10)<<"\n";
	cout<<"10 != 10: "<<(10 != 10)<<"\n";

	cout<<"\n:::::Using std::cout.setf(std::ios::boolalpha) for displaying Boolean:::::\n";
	cout.setf(ios::boolalpha); // std::cout.setf(std::ios::boolalpha);
	cout<<"10 == 10: "<<(10 == 10)<<"\n";
	cout<<"10 != 10: "<<(10 != 10)<<"\n";

	cout<<"\n:::::Resetting flags:::::\n";
	cout<<resetiosflags(ios::boolalpha); // Set to default value(0, 1)
	cout<<"10 == 10: "<<(10 == 10)<<"\n";
	cout<<"10 != 10: "<<(10 != 10)<<"\n";

// Stream manipulation for Integer types:
	int num {255};

	cout<<"\n:::::Setting base for displaying Integers:::::\n";
	cout<<"std::dec: "<<dec<<num<<"\n"; // std::dec
	cout<<"std::hex: "<<hex<<num<<"\n"; // std::hex
	cout<<"std::oct: "<<oct<<num<<"\n"; // std::oct

	cout<<"\n:::::Using std::showbase for displaying Integers:::::\n";
	cout<<showbase; // std::showbase
	cout<<"std::dec: "<<dec<<num<<"\n";
	cout<<"std::hex: "<<hex<<num<<"\n";
	cout<<"std::oct: "<<oct<<num<<"\n"; // Notice here we can distinguish octal from decimal, unlike the earlier version.

	cout<<"\n:::::Using std::noshowbase for displaying Integers:::::\n";
	cout<<noshowbase; // std::noshowbase
	cout<<"std::dec: "<<dec<<num<<"\n";
	cout<<"std::hex: "<<hex<<num<<"\n";
	cout<<"std::oct: "<<oct<<num<<"\n";

	cout<<"\n:::::Using std::uppercase for displaying Integers:::::\n";
	cout<<uppercase; // std::uppercase
	cout<<"std::dec: "<<dec<<num<<"\n";
	cout<<"std::hex: "<<hex<<num<<"\n"; // Notice here it is in uppercase.
	cout<<"std::oct: "<<oct<<num<<"\n";

	int positive_num {255};
	int negative_num {-255};

	cout<<"\n:::::Using std::showpos for displaying Integers:::::\n";
	cout<<showpos; // std::showpos
	cout<<"std::dec: "<<dec<<positive_num<<"\n"; // Notice here '+' sign is added at the start.
	cout<<"std::hex: "<<hex<<positive_num<<"\n";
	cout<<"std::oct: "<<oct<<positive_num<<"\n\n";

	cout<<"std::dec: "<<dec<<negative_num<<"\n";
	cout<<"std::hex: "<<hex<<negative_num<<"\n";
	cout<<"std::oct: "<<oct<<negative_num<<"\n";

	cout<<"\n:::::Using std::noshowpos for displaying Integers:::::\n";
	cout<<noshowpos; // std::noshowpos
	cout<<"std::dec: "<<dec<<positive_num<<"\n"; // Notice here '+' sign is removed at the start.
	cout<<"std::hex: "<<hex<<positive_num<<"\n";
	cout<<"std::oct: "<<oct<<positive_num<<"\n\n";

	cout<<"std::dec: "<<dec<<negative_num<<"\n";
	cout<<"std::hex: "<<hex<<negative_num<<"\n";
	cout<<"std::oct: "<<oct<<negative_num<<"\n";

	cout<<"\n:::::Using std::setf() for displaying Integers:::::\n";
	cout.setf(ios::showbase);
	cout.setf(ios::uppercase);
	cout.setf(ios::showpos);
	cout<<"std::dec: "<<dec<<num<<"\n";
	cout<<"std::hex: "<<hex<<num<<"\n";
	cout<<"std::oct: "<<oct<<num<<"\n";

	cout<<"\n:::::Resetting flags:::::\n";
	cout<<resetiosflags(ios::basefield); // Reset it back to dec.
	cout<<resetiosflags(ios::showbase);
	cout<<resetiosflags(ios::showpos);
	cout<<resetiosflags(ios::uppercase);
	cout<<"Integer Number: "<<num<<"\n";

// Stream manipulation for Floating types:
	double float_num1 {1234567};
	double float_num2 {1234.5678};
	double float_num3 {123456789.987654321};

	cout<<"\n:::::Default way for displaying Floating point numbers:::::\n";
	cout<<"Floating Number 1: "<<float_num1<<"\n"; // If the number of digits before the decimal point is greater than '6', then it is rounded and displayed in scientific notation.
	cout<<"Floating Number 2: "<<float_num2<<"\n"; // By default the precision is '6' and the rest of value is rounded.
	cout<<"Floating Number 3: "<<float_num3<<"\n";

	cout<<"\n:::::Using std::setprecision(10) for displaying Floating point numbers:::::\n";
	cout<<setprecision(10); // std::setprecision(9)
	cout<<"Floating Number 1: "<<float_num1<<"\n";
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num3<<"\n";

	cout<<"\n:::::Using std::setprecision(2) and std::fixed for displaying Floating point numbers:::::\n";
	cout<<setprecision(2)<<fixed; // std::setprecision(2), std::fixed
	cout<<"Floating Number 1: "<<float_num1<<"\n"; // std::fixed will fix the floating point number, precision happens after the decimal point(trailing zeros are added).
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num3<<"\n";

	cout<<"\n:::::Using std::setprecision(3) and std::scientific for displaying Floating point numbers:::::\n";
	cout.unsetf(ios::fixed); // This will revert to default(which is not fixed)
	cout<<setprecision(3)<<scientific;
	cout<<"Floating Number 1: "<<float_num1<<"\n"; // Notice here we are explicitly calling scientific.
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num3<<"\n";

	cout<<"\n:::::Using std::showpos and std::uppercase for displaying Floating point numbers:::::\n";
	cout<<showpos<<uppercase; // std::showpos, std::uppercase
	cout<<"Floating Number 1: "<<float_num1<<"\n"; // Here 'e' is capitalized for scientific notations. + sign is added for positive numbers.
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num2<<"\n";

	cout<<"\n:::::Using std::showpoint for displaying Floating point numbers:::::\n";
	cout<<showpoint; // std::showpoint
	cout<<setprecision(8); // Trailing zeroes will be added after the precision is reached.
	cout<<fixed;
	cout<<"Floating Number 1: "<<float_num1<<"\n";
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num3<<"\n";

// For more information about stream flags refer : "https://www.cs.nmsu.edu/~rth/cs/cs177/streamio.html" and "http://www.cplusplus.com/reference/ios/ios_base/fmtflags/"
	cout<<"\n:::::Resetting flags:::::\n";
	cout.unsetf(ios::scientific | ios::fixed); // This will reset all flags[bitwise or].
	//          ..... or .....
	cout<<resetiosflags(ios::floatfield); // This will reset all flags(scientific|fixed).
	cout<<setprecision(6);
	cout<<resetiosflags(ios::showpos);
	cout<<"Floating Number 1: "<<float_num1<<"\n";
	cout<<"Floating Number 2: "<<float_num2<<"\n";
	cout<<"Floating Number 3: "<<float_num3<<"\n";

// Using align and fill --> Note: These flags don't persist like the above ones.
	string Brooklyn {"Brooklyn"};
	int NineNine {99};

	cout<<"\n:::::Default way of displaying:::::\n";
	ruler();
	cout<<Brooklyn<<NineNine<<"\n";

	cout<<"\n:::::Using std::setw():::::\n";
	ruler();
	cout<<setw(10)<<Brooklyn<<setw(10)<<NineNine<<"\n"; // By default it is right aligned.

	cout<<"\n:::::Using std::left:::::\n";
	ruler();
	cout<<setw(10)<<left<<Brooklyn<<setw(10)<<left<<NineNine<<"\n";

	cout<<"\n:::::Using std::right:::::\n";
	ruler();
	cout<<setw(10)<<right<<Brooklyn<<setw(10)<<right<<NineNine<<"\n"; // It is not necessary to include "right" since it is default.

	cout<<"\n:::::Using std::setfill():::::\n";
	ruler();
	cout<<setw(10)<<setfill('.')<<Brooklyn<<setw(10)<<NineNine<<"\n\n"; // "std::setfill()" will persist(it will work only if "setw()" is enabled).

	return 0;
}