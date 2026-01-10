/**
 * @file data_type_sizes.cpp
 * @brief Prints the size of fundamental C++ data types in bytes.
 *
 * This program demonstrates:
 * - How to use `sizeof` to determine memory size of types
 * - How to use `CHAR_BIT` to find the number of bits in a byte
 * - How to align output nicely with `std::setw` and `std::left`
 *
 * @author suman
 * @date 2025/08/09
 */

#include <iomanip>   // For std::setw and std::left
#include <iostream>  // For std::cout
#include <climits>   // For CHAR_BIT
#include <cstdint>   // for fast and least types

/**
 * @brief Entry point of the program.
 *
 * Prints the number of bits in a byte and the size in bytes
 * of common fundamental C++ data types.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // Left justify all output

    // Print the size of various fundamental data types
    std::cout << std::setw(16) << "bool:"        << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:"        << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:"       << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:"         << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:"        << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:"   << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:"       << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:"      << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n\n";

    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n\n";

    return 0;
}
