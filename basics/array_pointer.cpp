/**
 * @file array_pointer.cpp
 * @brief Demonstrates array access using pointers and pointer arithmetic.
 *
 * This program shows different ways to:
 * - Point to array elements using a pointer
 * - Modify array values via dereferencing
 * - Use pointer arithmetic to traverse an array
 *
 * @author suman
 * @date 2025/08/09
 */

#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * Uses an integer pointer to access and modify
 * elements of an integer array.
 *
 * @return int Program exit status
 */
int main()
{
    int numbers[5];   ///< Integer array with 5 elements
    int* ptr;         ///< Pointer to integer

    // Pointer points to the first element of the array
    ptr = numbers;
    *ptr = 10;        // numbers[0] = 10

    // Move pointer to the next element
    ptr++;
    *ptr = 20;        // numbers[1] = 20

    // Point to the third element explicitly
    ptr = &numbers[2];
    *ptr = 30;        // numbers[2] = 30

    // Point to the fourth element using pointer arithmetic
    ptr = numbers + 3;
    *ptr = 40;        // numbers[3] = 40

    // Point to the fifth element
    ptr = numbers + 4;
    *ptr = 50;        // numbers[4] = 50

    // Print array elements
    std::cout << "Array elements are: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << ", ";
    }

    return EXIT_SUCCESS;
}
