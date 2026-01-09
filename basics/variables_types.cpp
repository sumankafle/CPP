/**
 * @file basic_variables.cpp
 * @brief Demonstrates declaration, initialization, and usage of various C++ data types.
 *
 * This program shows:
 * - Integer, short, float, double, char, string, boolean, and unsigned types
 * - Printing values and addresses of variables
 * - String concatenation
 * - Boolean behavior in C++
 * - Usage of const variables
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

using namespace std;

/**
 * @brief Entry point of the program.
 *
 * Demonstrates usage of different fundamental C++ data types and prints
 * values, memory addresses, and combined string outputs.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    // Integer variables (4 bytes typically)
    int a = 10, b = 35;
    cout << "Value of a : " << a << " Address of a : " << &a << endl;
    cout << "Value of b : " << b << " Address of b : " << &b << endl;

    // Short integer (2 bytes typically)
    short s = 20;
    cout << "Value of s : " << s << endl;

    // Floating point numbers
    float f1 = 20.03f;        ///< 4 bytes
    double d1 = 50.55416416;  ///< 8 bytes
    cout << "Value of f1 : " << f1 << endl;
    cout << "Value of d1 : " << d1 << endl;

    // Character variable
    char c1 = 'A';
    cout << "Value of char1 : " << c1 << endl;

    // String variables
    string s1 = "Hello SKe";
    string s2 = "Welcome to CPP !";
    cout << s1 << endl;
    cout << s2 << endl;

    // Concatenate strings
    string combineStrings = s1 + ", " + s2;
    cout << combineStrings << endl;

    // Boolean values
    bool b1 = true; // TRUE is 1, FALSE is 0
    cout << "b1 = " << b1 << endl;

    b1 = 1515; // Non-zero values are considered true
    cout << "b1 = " << b1 << endl;

    b1 = -445; // Negative values are also true
    cout << "b1 = " << b1 << endl;

    b1 = 0; // Zero is false
    cout << "b1 = " << b1 << endl;

    // Unsigned short (positive range only)
    unsigned short int u1 = 60445;
    cout << "Unsigned short u1 = " << u1 << endl;

    // Constant string
    const string myname = "SKe";
    cout << "Constant string myname = " << myname << endl;

    return 0;
}
