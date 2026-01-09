/**
 * @file variable_demo.cpp
 * @brief Demonstrates basic variable declaration, initialization, memory address access, and re-assignment in C++.
 *
 * This program shows how to declare an integer variable, print its value and address,
 * and reassign a new value. It also includes comments about variable naming rules.
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * Demonstrates:
 * - Integer variable declaration and initialization
 * - Printing variable value and memory address
 * - Reassigning a new value to the variable
 * - Basic rules for naming variables in C++
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    // Declaring an integer variable 'a', allocates 4 bytes 
    int a = 4;

    // Print the value of a
    std::cout << a << std::endl;

    // Print the memory address of a
    std::cout << &a << std::endl;

    /**
     * Variable naming rules:
     * 1. Variables cannot have the same name within the same scope.
     * 2. Variable names cannot start with a number.
     * 3. Variable names should not contain spaces.
     * 4. Variable names should be self-descriptive.
     * 5. Variable names cannot contain special characters or keywords.
     */

    // Re-initialize variable a with a new value
    a = 10;

    // Print the new value of a
    std::cout << a << std::endl;

    // Print the memory address of a (same as before since memory location is unchanged)
    std::cout << &a << std::endl;

    return 0;
}
