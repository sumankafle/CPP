/**
 * @file calculator.cpp
 * @brief Simple calculator using switch-case and user-defined functions.
 *
 * This program performs basic arithmetic operations (addition, subtraction,
 * multiplication, division, modulo) based on user input and allows repeated execution.
 *
 * @author suman
 * @date 2026
 */

#include <iostream>

/**
 * @brief Adds two numbers.
 * @param a First operand
 * @param b Second operand
 * @return Sum of a and b
 */
double add(double a, double b)
{
    return a + b;
}

/**
 * @brief Subtracts two numbers.
 * @param a Minuend
 * @param b Subtrahend
 * @return Difference (a - b)
 */
double subtract(double a, double b)
{
    return a - b;
}

/**
 * @brief Multiplies two numbers.
 * @param a First operand
 * @param b Second operand
 * @return Product of a and b
 */
double multiply(double a, double b)
{
    return a * b;
}

/**
 * @brief Divides two numbers.
 *
 * @param a Dividend
 * @param b Divisor
 * @return Result of a / b
 *
 * @warning Division by zero must be handled by the caller.
 */
double divide(double a, double b)
{
    return a / b;
}

/**
 * @brief Computes modulo of two integers.
 *
 * @param a Dividend (integer)
 * @param b Divisor (integer)
 * @return Remainder of a divided by b
 *
 * @warning Modulo by zero must be handled by the caller.
 */
int modulo(int a, int b)
{
    return a % b;
}

/**
 * @brief Entry point of the program.
 *
 * Runs a loop-based calculator allowing the user to choose
 * arithmetic operations until they decide to exit.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    double var1{};
    double var2{};
    char decision{};
    char continueProgram{'Y'};

    while (continueProgram == 'Y' || continueProgram == 'y')
    {
        std::cout << "Enter first number: ";
        std::cin >> var1;

        std::cout << "Enter second number: ";
        std::cin >> var2;

        std::cout << "\nWhat do you want to do with these numbers?\n";
        std::cout << "+ - add\n";
        std::cout << "- - subtract\n";
        std::cout << "* - multiply\n";
        std::cout << "/ - divide\n";
        std::cout << "% - modulo (integers only)\n";

        std::cin >> decision;

        std::cout << "Decision selected: " << decision << "\n" << std::endl;

        switch (decision)
        {
            case '+':
                std::cout << var1 << " + " << var2 << " = "
                          << add(var1, var2) << std::endl;
                break;

            case '-':
                std::cout << var1 << " - " << var2 << " = "
                          << subtract(var1, var2) << std::endl;
                break;

            case '*':
                std::cout << var1 << " * " << var2 << " = "
                          << multiply(var1, var2) << std::endl;
                break;

            case '/':
                if (var2 != 0.0)
                {
                    std::cout << var1 << " / " << var2 << " = "
                              << divide(var1, var2) << std::endl;
                }
                else
                {
                    std::cout << "Error: Division by zero is not allowed." << std::endl;
                }
                break;

            case '%':
                if (static_cast<int>(var2) != 0)
                {
                    std::cout << static_cast<int>(var1) << " % "
                              << static_cast<int>(var2) << " = "
                              << modulo(static_cast<int>(var1), static_cast<int>(var2))
                              << std::endl;
                }
                else
                {
                    std::cout << "Error: Modulo by zero is not allowed." << std::endl;
                }
                break;

            default:
                std::cout << "Error: Invalid operation selected." << std::endl;
        }

        std::cout << "\nDo you want to continue the program? (Y/N): ";
        std::cin >> continueProgram;
        std::cout << std::endl;
    }
    std::cout << "\nProgram terminated!" << std::endl;
    return 0;
}
