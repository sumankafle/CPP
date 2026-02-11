/**
 * @file cash_exchange_machine_oop_documented.cpp
 * @author Suman
 * @date 2026-02-11
 *
 * @brief Fully OOP-based Cash Exchange Machine using State Pattern.
 *
 * @details
 * This implementation demonstrates ALL major OOP concepts:
 *
 * 1. Encapsulation
 * 2. Abstraction
 * 3. Inheritance
 * 4. Polymorphism
 * 5. Composition
 * 6. State Design Pattern
 * 7. Smart Pointers (RAII)
 * 8. STL containers
 * 9. Exception Handling
 * 10. Const correctness
 *
 * Machine accepts: 5, 10, 20, 50, 100 EUR
 * Exchanges into smaller denominations.
 *
 * @usage
 * g++ -std=c++17 cash_exchange_machine_oop_documented.cpp -o machine
 * ./machine
 */

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>

/* ============================================================
   ENUM CLASS  →  TYPE SAFETY + STRONG ENUMERATION
   OOP Concept: Strong typing / Scoped enum
   ============================================================ */

/**
 * @enum Denomination
 * @brief Represents valid Euro denominations.
 */
enum class Denomination {
    EUR_5   = 5,
    EUR_10  = 10,
    EUR_20  = 20,
    EUR_50  = 50,
    EUR_100 = 100
};

/* ============================================================
   INTERFACE (ABSTRACTION)
   OOP Concept Applied: Abstraction + Polymorphism
   ============================================================ */

/**
 * @class IMachineState
 * @brief Pure abstract base class (Interface).
 *
 * OOP Concept:
 * - Abstraction → Defines WHAT to do, not HOW
 * - Polymorphism → Derived classes override behavior
 */
class IMachineState {
public:

    /**
     * @brief Virtual destructor.
     * Required for polymorphic base classes.
     */
    virtual ~IMachineState() = default;

    /**
     * @brief Insert money event.
     */
    virtual void insertMoney(int amount) = 0;

    /**
     * @brief Exchange event.
     */
    virtual void exchange() = 0;

    /**
     * @brief Returns state name.
     */
    virtual const char* name() const = 0;
};

/* Forward declarations to resolve circular dependencies */
class IdleState;
class HasMoneyState;

/* ============================================================
   CASH INVENTORY
   OOP Concept Applied: Encapsulation
   ============================================================ */

/**
 * @class CashInventory
 * @brief Manages machine cash storage.
 *
 * OOP Concept:
 * - Encapsulation → Internal map is private
 * - Responsibility separation (SRP)
 */
class CashInventory {
private:

    /// Encapsulated internal storage (STL container)
    std::map<int, int> storage_;

public:

    /**
     * @brief Constructor
     *
     * Initializes machine with default money.
     */
    CashInventory() {
        storage_[5] = 20;
        storage_[10] = 20;
        storage_[20] = 20;
        storage_[50] = 10;
        storage_[100] = 5;
    }

    /**
     * @brief Checks availability.
     * @param value denomination
     * @return true if available
     *
     * OOP Concept: Const correctness
     */
    bool hasDenomination(int value) const {
        return storage_.count(value) && storage_.at(value) > 0;
    }

    /**
     * @brief Add money to inventory.
     */
    void add(int value) {
        storage_[value]++;
    }

    /**
     * @brief Remove money from inventory.
     *
     * Demonstrates exception handling.
     */
    void remove(int value) {
        if (!hasDenomination(value))
            throw std::runtime_error("Denomination unavailable.");
        storage_[value]--;
    }

    /**
     * @brief Getter for inspection.
     */
    const std::map<int,int>& data() const {
        return storage_;
    }
};

/* ============================================================
   FORWARD DECLARATION
   Needed because states reference the machine.
   ============================================================ */
class CashExchangeMachine;

/* ============================================================
   CONTEXT CLASS
   OOP Concepts:
   - Composition (owns inventory)
   - State Pattern
   - Smart Pointer ownership
   ============================================================ */

/**
 * @class CashExchangeMachine
 * @brief Context of State Pattern.
 *
 * OOP Concept:
 * - Composition → owns CashInventory
 * - Aggregation → interacts with states
 * - RAII → unique_ptr manages state memory
 */
class CashExchangeMachine {

private:

    int insertedAmount_{0};   ///< Encapsulated data member

    CashInventory inventory_; ///< Composition

    /**
     * Smart pointer for state ownership.
     *
     * OOP Concept:
     * - RAII
     * - Unique ownership semantics
     */
    std::unique_ptr<IMachineState> state_;

public:

    /**
     * @brief Constructor
     */
    CashExchangeMachine();

    /**
     * @brief Change state (State Pattern core).
     */
    void setState(std::unique_ptr<IMachineState> newState) {
        state_ = std::move(newState);
    }

    /**
     * @brief Delegate insert to current state.
     *
     * OOP Concept:
     * - Polymorphism
     */
    void insertMoney(int amount) {
        state_->insertMoney(amount);
    }

    /**
     * @brief Delegate exchange to current state.
     */
    void exchange() {
        state_->exchange();
    }

    void addInserted(int amount) {
        insertedAmount_ += amount;
    }

    int getInserted() const {
        return insertedAmount_;
    }

    void resetInserted() {
        insertedAmount_ = 0;
    }

    CashInventory& inventory() {
        return inventory_;
    }

    void printInventory() const {
        std::cout << "\nInventory:\n";
        for (const auto& [denom, count] : inventory_.data()) {
            std::cout << denom << " EUR : " << count << "\n";
        }
    }

    void printState() const {
        std::cout << "[State: " << state_->name() << "] "
                  << "[Inserted: " << insertedAmount_ << " EUR]\n";
    }
};

/* Forward-declared state classes - fully defined after constructor */

class IdleState : public IMachineState {

private:
    CashExchangeMachine& machine_;

public:

    explicit IdleState(CashExchangeMachine& m)
        : machine_(m) {}

    void insertMoney(int amount) override;
    void exchange() override;
    const char* name() const override { return "IdleState"; }
};

class HasMoneyState : public IMachineState {

private:
    CashExchangeMachine& machine_;

public:

    explicit HasMoneyState(CashExchangeMachine& m)
        : machine_(m) {}

    void insertMoney(int amount) override;
    void exchange() override;
    const char* name() const override { return "HasMoneyState"; }
};

/* ============================================================
   CONTEXT CONSTRUCTOR IMPLEMENTATION
   ============================================================ */

CashExchangeMachine::CashExchangeMachine() {
    state_ = std::make_unique<IdleState>(*this);
}

/* ============================================================
   STATE METHOD IMPLEMENTATIONS
   (Now that both classes are fully defined)
   ============================================================ */

void IdleState::insertMoney(int amount) {

    if (amount != 5 && amount != 10 &&
        amount != 20 && amount != 50 &&
        amount != 100)
        throw std::invalid_argument("Invalid denomination.");

    // Validate max insert limit
    if (machine_.getInserted() + amount > 500)
        throw std::invalid_argument("Insert limit exceeded (max 500 EUR).");

    machine_.addInserted(amount);
    machine_.inventory().add(amount);

    // State transition
    machine_.setState(std::make_unique<HasMoneyState>(machine_));
}

void IdleState::exchange() {
    std::cout << "Insert money first.\n";
}

void HasMoneyState::insertMoney(int amount) {
    if (amount != 5 && amount != 10 &&
        amount != 20 && amount != 50 &&
        amount != 100)
        throw std::invalid_argument("Invalid denomination.");

    // Validate max insert limit
    if (machine_.getInserted() + amount > 500)
        throw std::invalid_argument("Insert limit exceeded (max 500 EUR).");

    machine_.addInserted(amount);
    machine_.inventory().add(amount);
}

void HasMoneyState::exchange() {

    int amount = machine_.getInserted();
    int remaining = amount;

    std::vector<int> denoms = {50, 20, 10, 5};

    std::cout << "\nExchanging " << amount << " EUR:\n";

    for (int d : denoms) {
        while (remaining >= d &&
               machine_.inventory().hasDenomination(d)) {
            machine_.inventory().remove(d);
            remaining -= d;
            std::cout << "Dispensed: " << d << " EUR\n";
        }
    }

    if (remaining > 0) {
        std::cerr << "ERROR: Could not fully exchange. "
                  << remaining << " EUR remaining (insufficient denominations).\n";
        throw std::runtime_error("Partial exchange - denominations unavailable.");
    }

    std::cout << "Exchange completed successfully.\n";
    machine_.resetInserted();

    // Transition back to Idle
    machine_.setState(std::make_unique<IdleState>(machine_));
}

/* ============================================================
   MAIN FUNCTION
   ============================================================ */

int main() {

    try {

        CashExchangeMachine machine;

        std::cout << "=== Cash Exchange Machine ===";
        machine.printState();
        machine.printInventory();

        std::cout << "\n--- Insert 100 EUR ---\n";
        machine.insertMoney(100);
        machine.printState();
        machine.exchange();
        machine.printState();
        machine.printInventory();

        std::cout << "\n--- Insert 20 EUR + 10 EUR ---\n";
        machine.insertMoney(20);
        machine.printState();
        machine.insertMoney(10);
        machine.printState();
        machine.exchange();
        machine.printState();
        machine.printInventory();

        std::cout << "\n--- Test: Insert 600 EUR (should fail - exceeds limit) ---\n";
        machine.insertMoney(100);
        machine.insertMoney(100);
        machine.insertMoney(100);
        machine.insertMoney(100);
        machine.insertMoney(100);
        machine.printState();
        std::cout << "--- Attempting to insert another 100 EUR (total would be 600 EUR) ---\n";
        machine.insertMoney(100);
    }
    catch (const std::exception& e) {
        std::cerr << "[EXCEPTION] " << e.what() << "\n";
    }

    return 0;
}
