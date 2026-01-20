/**
 * @file inheritance_example.cpp
 * @brief Demonstrates inheritance in C++ using a simple Animal-Dog hierarchy.
 *
 * Inheritance allows a class (derived class) to acquire the properties
 * and behaviors (data members and member functions) of another class
 * (base class). This promotes reusability and an "is-a" relationship.
 *
 * Key Terminology:
 * - Superclass/Base class: Animal
 * - Subclass/Derived class: Dog
 * - Reusability: Derived classes reuse existing code in base classes
 *
 * @author Suman
 * @date 2026
 */

#include <iostream>
using namespace std;

/**
 * @brief Superclass representing a generic Animal.
 *
 * Contains behaviors common to all animals such as eating and sleeping.
 */
class Animal {
public:
    /**
     * @brief Make the animal eat.
     */
    void eat() {
        cout << "Animal is eating..." << endl;
    }

    /**
     * @brief Make the animal sleep.
     */
    void sleep() {
        cout << "Animal is sleeping..." << endl;
    }
};

/**
 * @brief Subclass representing a Dog.
 *
 * Inherits all behaviors from Animal and adds its own behavior
 * (barking).
 */
class Dog : public Animal {
public:
    /**
     * @brief Make the dog bark.
     */
    void bark() {
        cout << "Dog is barking!" << endl;
    }
};

/**
 * @brief Program entry point.
 *
 * Demonstrates inheritance by creating a Dog object and calling
 * both inherited and subclass-specific methods.
 *
 * @return int Exit status
 */
int main() {
    // Create a Dog object
    Dog* myDog = new Dog();

    // Call inherited methods from Animal
    myDog->eat();
    myDog->sleep();
    
    // Call Dog-specific method
    myDog->bark();

    delete myDog;
    return 0;
}
