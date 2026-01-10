/**
 * @file relational_operators.cpp
 * @brief Demonstrates the use of relational and logical operators in C++.
 *
 * This program compares two integers using relational operators and
 * prints the boolean results to the console.
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

/**
 * @brief Entry point of the program.
 *
 * Demonstrates relational operators such as equality, inequality,
 * greater-than, less-than, and logical negation.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    std::cout << "Relational Operators!" << std::endl;

    int a = 10;
    int b = 5;

    // TRUE = 1, FALSE = 0
    std::cout << (a == b) << std::endl;  ///< Equal to
    std::cout << (a != b) << std::endl;  ///< Not equal to
    std::cout << (a < b)  << std::endl;  ///< Less than
    std::cout << (a > b)  << std::endl;  ///< Greater than
    std::cout << (a <= b) << std::endl;  ///< Less than or equal to
    std::cout << (a >= b) << std::endl;  ///< Greater than or equal to

    // Logical NOT operator
    std::cout << !(a == b) << std::endl; ///< Equivalent to (a != b)

    return 0;
}
