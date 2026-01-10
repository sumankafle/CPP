/**
 * @file input_output.cpp
 * @brief Demonstrates basic console input and output using std::cin and std::cout.
 *
 * This program:
 * - Reads an integer from the user
 * - Reads a first name and surname
 * - Prints the full name to the console
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>
#include <string>

/**
 * @brief Entry point of the program.
 *
 * Demonstrates user input using std::cin and formatted output using std::cout.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    int a;  ///< Integer variable to store user input

    // Read an integer value from the user
    std::cout << "Enter an integer value for variable a: ";
    std::cin >> a;

    std::string name;     ///< Stores user's first name
    std::string surname;  ///< Stores user's surname

    // Read first name
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Read surname
    std::cout << "Enter your surname: ";
    std::cin >> surname;

    // Output full name
    std::cout << "Your full name is: " << name << " " << surname << std::endl;

    return 0;
}
