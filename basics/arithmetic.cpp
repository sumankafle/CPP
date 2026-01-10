/**
 * @file arithmetic_functions.cpp
 * @brief Demonstrates arithmetic operations using user-defined functions in C++.
 *
 * This program defines separate functions for arithmetic and increment/decrement
 * operations and calls them from main().
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

/**
 * @brief Adds two integers.
 *
 * @param a First operand
 * @param b Second operand
 * @return Sum of a and b
 */
int add(int a, int b)
{
    return a + b;
}

/**
 * @brief Subtracts one integer from another.
 *
 * @param a Minuend
 * @param b Subtrahend
 * @return Difference (a - b)
 */
int subtract(int a, int b)
{
    return a - b;
}

/**
 * @brief Multiplies two integers.
 *
 * @param a First operand
 * @param b Second operand
 * @return Product of a and b
 */
int multiply(int a, int b)
{
    return a * b;
}

/**
 * @brief Divides one integer by another.
 *
 * @param a Dividend
 * @param b Divisor
 * @return Quotient of a / b
 *
 * @warning Division by zero is undefined behavior.
 */
int divide(int a, int b)
{
    return a / b;
}

/**
 * @brief Computes the remainder of integer division.
 *
 * @param a Dividend
 * @param b Divisor
 * @return Remainder of a % b
 */
int modulo(int a, int b)
{
    return a % b;
}

/**
 * @brief Demonstrates pre- and post-increment and decrement operations.
 *
 * @param a Integer value to be modified
 */
void incrementDecrement(int a)
{
    std::cout << "Pre-increment  (++a): " << ++a << std::endl;
    std::cout << "Pre-decrement  (--a): " << --a << std::endl;
    std::cout << "Post-increment (a++): " << a++ << std::endl;
    std::cout << "Post-decrement (a--): " << a-- << std::endl;
     std::cout << "Post-decrement (a--): " << a-- << std::endl;

}

/**
 * @brief Entry point of the program.
 *
 * Calls all arithmetic functions and prints their results.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    int a = 10;
    int b = 50;

    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << multiply(a, b) << std::endl;
    std::cout << "Division: " << divide(a, b) << std::endl;
    std::cout << "Modulo: " << modulo(a, b) << std::endl;

    incrementDecrement(a);

    return 0;
}
