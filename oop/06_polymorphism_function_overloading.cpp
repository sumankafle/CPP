/**
 * @file polymorphism_function_overloading.cpp
 * @brief Demonstrates compile-time polymorphism using function overloading.
 *
 * Polymorphism means "many forms". In C++, compile-time polymorphism
 * is achieved using function overloading, where multiple functions
 * share the same name but differ in parameter type or count.
 *
 * This example shows how the same function name `add()` behaves
 * differently for integer and floating-point values.
 *
 * @author Suman
 * @date 16/08/2025
 */

#include <iostream>


/**
 * @brief Class demonstrating function overloading.
 *
 * The same function name `add()` is overloaded to work with
 * different data types.
 */

class functionOverloading {
public:
    /**
     * @brief Adds two integer values.
     *
     * @param a First integer
     * @param b Second integer
     */
    int add(int a, int b) {
        return a + b;
    }           
    /**
     * @brief Adds two double values.
     *
     * @param a First double
     * @param b Second double
     */
    double add(double a, double b) {
        return a + b;
    }
};

/**
 * @brief Program entry point.
 *
 * Demonstrates compile-time polymorphism by calling
 * overloaded functions with different parameter types.
 *
 * @return int Exit status
 */
int main() {
    functionOverloading obj;

    // Call the integer version
    int intResult = obj.add(5, 10);
    std::cout << "Sum of integers: " << intResult << std::endl;

    // Call the double version
    double doubleResult = obj.add(5.5, 10.3);
    std::cout << "Sum of doubles: " << doubleResult << std::endl;

    return 0;
}