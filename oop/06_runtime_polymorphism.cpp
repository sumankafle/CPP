/**
 * @file runtime_polymorphism.cpp
 * @brief Demonstrates runtime polymorphism in C++ using virtual functions.
 *
 * Runtime polymorphism (also called late binding or dynamic polymorphism)
 * occurs when the function to be called is determined at runtime. This is
 * achieved using virtual functions and function overriding in derived classes.
 *
 * Function overriding happens when a derived class provides a new
 * implementation for a virtual function declared in the base class.
 *
 * @author Suman
 * @date 15/08/2025
 */

#include <iostream>


/**
 * @brief Base class demonstrating a virtual function.
 */

class Base {

public:
    /**
     * @brief Virtual function to be overridden in derived classes.
     */
    virtual void show() {
        std::cout << "Base class show function called." << std::endl;
    }

    /**
     * @brief Virtual destructor for proper cleanup of derived objects.
     */
    virtual ~Base() = default; 

};


/**
 * @brief Derived class overriding the base class function.
 */
class Derived: public Base {

    public:
    /**
     * @brief Overrides Base::display() to provide specific behavior.
     */
    void show() override {
         std::cout << "Derived class function" << std::endl;
    }

};

/**
 * @brief Program entry point.
 *
 * Demonstrates runtime polymorphism by calling an overridden function
 * through a base class pointer pointing to a derived object.
 *
 * @return int Exit status
 */

int main(){

    // Pointer of type Base pointing to Derived object
    Base* basePtr;

    // Derived object
    Derived derivedObj;

    // Point base class pointer to derived object
    basePtr = &derivedObj;

    // Calls Derived::show() due to runtime polymorphism
    basePtr->show();

    return 0;
}