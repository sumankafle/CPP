/**
 * @file abstraction.cpp
 * @brief Demonstrates abstraction in C++ using abstract classes and pure virtual functions.
 *
 * Abstraction is the process of hiding implementation details and exposing only
 * the essential features of an object. This example uses an abstract base class
 * `Vehicle` with pure virtual functions to define a common interface for all vehicles.
 * The derived class `Car` provides concrete implementations of the abstract methods.
 *
 * @author Suman
 * @date 16/08/2025
 */

#include <iostream>
using namespace std;

/**
 * @brief Abstract base class representing a generic Vehicle.
 *
 * Abstraction is achieved using pure virtual functions:
 * - accelerate() and brake() must be implemented by derived classes.
 * The class can also provide concrete functions that are common to all vehicles.
 */
class Vehicle {
public:
    /**
     * @brief Pure virtual function to accelerate the vehicle.
     */
    virtual void accelerate() = 0;

    /**
     * @brief Pure virtual function to apply brakes.
     */
    virtual void brake() = 0;

    /**
     * @brief Starts the engine of the vehicle.
     *
     * Concrete function shared by all derived vehicles.
     */
    void startEngine() {
        cout << "Engine started!" << endl;
    }

    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~Vehicle() = default;
};

/**
 * @brief Concrete class representing a Car.
 *
 * Inherits from Vehicle and provides implementations for abstract methods.
 */
class Car : public Vehicle {
public:
    /**
     * @brief Accelerates the car.
     */
    void accelerate() override {
        cout << "Car: Pressing gas pedal..." << endl;
    }

    /**
     * @brief Applies brakes to the car.
     */
    void brake() override {
        cout << "Car: Applying brakes..." << endl;
    }
};

/**
 * @brief Program entry point.
 *
 * Demonstrates abstraction by using a base class pointer
 * to control a derived object (Car) without knowing its implementation details.
 *
 * @return int Exit status
 */
int main() {
    // Pointer to abstract base class
    Vehicle* myCar = new Car();

    // Call concrete and abstract methods through base-class pointer
    myCar->startEngine();  // Concrete method from Vehicle
    myCar->accelerate();   // Calls Car's implementation
    myCar->brake();        // Calls Car's implementation

    // Cleanup
    delete myCar;
    return 0;
}
