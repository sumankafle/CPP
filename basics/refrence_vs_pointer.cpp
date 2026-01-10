/**
 * @file reference_vs_pointer.cpp
 * @brief Demonstrates the difference between references and pointers in C++.
 *
 * This program shows how:
 * - A reference acts as an alias to a variable
 * - A pointer stores the address of a variable
 * - Modifying the value through either affects the original variable
 *
 * @author suman
 * @date 2026
 */

#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * Creates an integer variable, a reference to it,
 * and a pointer to it. Demonstrates reading and
 * modifying the variable through all three.
 *
 * @return int Program exit status
 */
int main()
{
    int x{ 5 };          ///< Original variable
    int& ref{ x };       ///< Reference (alias) to x
    int* ptr{ &x };      ///< Pointer storing address of x

    // Initial values
    std::cout << x;
    std::cout << ref;          // Access x via reference
    std::cout << *ptr << '\n'; // Access x via pointer

    // Modify x using reference
    ref = 6;
    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << '\n';

    // Modify x using pointer
    *ptr = 7;
    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << '\n';

    return 0;
}
