/**
 * @file function_call.cpp
 * @brief Demonstrates function definition and function calls in C++.
 *
 * This program shows how control flow moves from the caller function
 * (`main`) to a user-defined function (`doPrint`) and then returns back
 * to the caller after execution.
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream> // for std::cout

/**
 * @brief Prints a message indicating execution inside doPrint().
 *
 * This function is called from main() and demonstrates how a function
 * is executed when control is transferred from the caller.
 *
 * @note This function does not take parameters and does not return a value.
 */
void doPrint()
{
    std::cout << "In doPrint()\n";
}

/**
 * @brief Entry point of the program.
 *
 * Prints messages before and after calling the user-defined function
 * doPrint(), demonstrating function call flow.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    std::cout << "Starting main()\n";

    // Call to user-defined function; control transfers to doPrint()
    doPrint();

    // Execution resumes here after doPrint() finishes
    std::cout << "Ending main()\n";

    return 0;
}
