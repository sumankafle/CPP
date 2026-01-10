/**
 * @file pointer_example_1.cpp
 * @brief Demonstrates basic pointer usage in C++.
 *
 * This program shows:
 * - How to declare a pointer
 * - How to store addresses of variables in a pointer
 * - How to modify variable values using dereferencing
 *
 * @author suman
 * @date 2025/08/09
 */

#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * Uses a single integer pointer to:
 * - Point to two different variables
 * - Assign values indirectly using dereferencing
 *
 * @return int Program exit status
 */
int main()
{
    int firstVar, secondVar;   ///< Integer variables
    int* myPointer;            ///< Pointer to an integer

    // Point to firstVar
    myPointer = &firstVar;
    std::cout << "Address of firstVar : " << &firstVar << std::endl;

    // Assign value to firstVar via pointer
    *myPointer = 10;

    // Point to secondVar
    myPointer = &secondVar;
    std::cout << "Address of secondVar: " << &secondVar << std::endl;

    // Assign value to secondVar via pointer
    *myPointer = 20;

    // Print final values
    std::cout << "Value of firstVar is:  " << firstVar << std::endl;
    std::cout << "Value of secondVar is: " << secondVar << std::endl;

    return EXIT_SUCCESS;
}
