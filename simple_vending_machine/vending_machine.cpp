/**
 * @file vending_machine.cpp
 * @brief Simple vending machine using modern C++17 and OOP
 *
 * Demonstrates:
 *  - Encapsulation and abstraction
 *  - std::array and std::string
 *  - Const-correct member functions
 *  - Clean, safe C++17 coding style
 *
 * @author Suman
 * @date 2026
 */

#include <iostream>
#include <array>
#include <string>
#include <sstream>

/**
 * @class Inventory
 * @brief Manages drinks inside the vending machine
 */
class Inventory {
private:
    /**
     * @struct Drink
     * @brief Represents a single drink item
     */
    struct Drink {
        std::string name;
        double price;
        int quantity;
    };

    /// Fixed-size inventory 
    std::array<Drink, 3> drinks{
        Drink{"Coke",  0.55, 10},
        Drink{"Pepsi", 0.45, 10},
        Drink{"Water", 0.85, 10}
    };

public:
    /**
     * @brief Returns formatted drink menu
     */
    std::string menu() const {
        std::ostringstream out;
        out << "\nAvailable Drinks:\n";
        for (std::size_t i = 0; i < drinks.size(); ++i) {
            out << i << ": " << drinks[i].name
                << " ($" << drinks[i].price << ")\n";
        }
        return out.str();
    }

    /**
     * @brief Sells one unit of a drink
     */
    bool sell(std::size_t index) {
        if (index >= drinks.size() || drinks[index].quantity == 0)
            return false;

        --drinks[index].quantity;
        return true;
    }

    /**
     * @brief Checks if any drink is available
     */
    bool hasStock() const {
        for (const auto& d : drinks) {
            if (d.quantity > 0)
                return true;
        }
        return false;
    }

    /**
     * @brief Returns remaining quantity
     */
    int quantity(std::size_t index) const {
        return (index < drinks.size()) ? drinks[index].quantity : -1;
    }

    /**
     * @brief Returns drink name
     */
    std::string name(std::size_t index) const {
        return (index < drinks.size()) ? drinks[index].name : "Invalid";
    }

    /**
     * @brief Number of selectable drinks
     */
    std::size_t size() const {
        return drinks.size();
    }
};

/**
 * @brief Program entry point
 */
int main() {
    Inventory inventory;
    std::size_t choice{};

    std::cout << "=== Suman Vending Machine ===\n";

    while (inventory.hasStock()) {
        std::cout << inventory.menu();
        std::cout << "Select drink number: ";

        std::cin >> choice;

        if (choice >= inventory.size()) {
            std::cout << "Invalid selection!\n\n";
            continue;
        }

        if (inventory.sell(choice)) {
            std::cout << "Dispensed "
                      << inventory.name(choice)
                      << " (" << inventory.quantity(choice)
                      << " left)\n\n";
        } else {
            std::cout << inventory.name(choice)
                      << " is out of stock.\n\n";
        }
    }

    std::cout << "*** Machine Empty — Thank You ***\n";
    return 0;
}
