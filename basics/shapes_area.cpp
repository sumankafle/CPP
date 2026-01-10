/**
 * @file shapes_area.cpp
 * @brief Program to calculate areas of various geometric shapes using a menu-driven approach.
 */

#include <iostream>
#include <limits>   // For input validation
using namespace std;

constexpr double PI = 3.141592653589793;

/** Function declarations */
void showMenu();
void processChoice(int choice);
double areaCircle(double radius);
double areaSquare(double side);
double areaRectangle(double width, double height);
double areaTriangle(double base, double height);
void printArea(double area);

/** Main program */
int main() {
    int choice;
    char cont;

    do {
        showMenu();

        while (!(cin >> choice)) {   // Input validation
            cout << "Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        processChoice(choice);

        cout << "Do you want to continue? (Y/N): ";
        cin >> cont;

    } while (cont == 'Y' || cont == 'y');

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}

/** Display menu options */
void showMenu() {
    cout << "\nSelect a shape to calculate its area:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Square" << endl;
    cout << "3. Rectangle" << endl;
    cout << "4. Triangle" << endl;
    cout << "Enter your choice: ";
}

/** Process menu selection */
void processChoice(int choice) {
    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius: ";
            cin >> radius;
            printArea(areaCircle(radius));
            break;
        }
        case 2: {
            double side;
            cout << "Enter the side length: ";
            cin >> side;
            printArea(areaSquare(side));
            break;
        }
        case 3: {
            double width, height;
            cout << "Enter the width and height: ";
            cin >> width >> height;
            printArea(areaRectangle(width, height));
            break;
        }
        case 4: {
            double base, height;
            cout << "Enter the base and height: ";
            cin >> base >> height;
            printArea(areaTriangle(base, height));
            break;
        }
        default:
            cout << "Invalid choice! Please select a number between 1 and 4." << endl;
    }
}

/** Area calculations */
double areaCircle(double radius) {
    return PI * radius * radius;
}

double areaSquare(double side) {
    return side * side;
}

double areaRectangle(double width, double height) {
    return width * height;
}

double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

/** Print area result */
void printArea(double area) {
    cout << "The area is: " << area << endl;
}
