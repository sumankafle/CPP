/**
 * @file encapsulation.cpp
 * @brief Demonstrates constructors, destructors, dynamic memory allocation,
 *        and basic encapsulation in C++.
 *
 * This program illustrates:
 * - Object creation and destruction
 * - Dynamic memory allocation using new/delete[]
 * - Use of constructors and destructors
 * - Encapsulation via private data members
 *
 * @author Suman
 * @date 2026
 */

#include <iostream>
using namespace std;

/**
 * @brief Class representing personal details.
 *
 * The class manages an age attribute and dynamically
 * allocated memory to demonstrate constructor and
 * destructor behavior.
 */
class MyDetails
{
private:
    short age;  ///< Stores age value
    int* p;     ///< Pointer to dynamically allocated integer array

public:
    /**
     * @brief Default constructor.
     *
     * - Initializes age to 50
     * - Allocates memory for an integer array
     * - Tracks how many times the constructor is invoked
     */
    MyDetails()
    {
        static int i = 0;
        cout << "This constructor has been just invoked "
             << ++i << " time(s)" << endl;

        age = 50;
        p = new int[10];  // Dynamic memory allocation
    }

    /**
     * @brief Destructor.
     *
     * - Frees dynamically allocated memory
     * - Tracks how many times the destructor is invoked
     */
    ~MyDetails()
    {
        static int j = 0;
        cout << "This Destructor has been just invoked "
             << ++j << " time(s)" << endl;

        delete[] p;  // Release allocated memory
    }

    /**
     * @brief Sets the age value.
     *
     * Ensures age cannot be negative.
     *
     * @param value Age value to set
     */
    void setAge(int value)
    {
        if (value < 0)
            age = 0;
        else
            age = value;
    }

    /**
     * @brief Gets the age value.
     *
     * @return Current age
     */
    short getAge() const
    {
        return age;
    }

        // Delete copy constructor and assignment to prevent double-delete
    MyDetails(const MyDetails&) = delete;
    MyDetails& operator=(const MyDetails&) = delete;
    
};

/**
 * @brief Program entry point.
 *
 * Creates multiple objects of MyDetails to demonstrate
 * constructor and destructor invocation order and
 * object lifetime.
 *
 * @return int Exit status (0 indicates success)
 */
int main()
{
    // Object creation triggers constructor calls
    MyDetails p1;
    MyDetails p2;

    // Set age values
    p1.setAge(-55);  // Will be clamped to 0
    p2.setAge(20);

    // Print age values
    cout << p1.getAge() << endl;
    cout << p2.getAge() << endl;

    // Destructors are automatically called here
    return 0;
}
