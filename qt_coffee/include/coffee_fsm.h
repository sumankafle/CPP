/**
 * @file coffee_fsm.h
 * @brief Simple coffee state machine API (moc-free).
 */
#pragma once

#include <QString>
#include <QTimer>
#include <functional>

/**
 * @brief CoffeeFSM provides a minimal finite-state-machine for brewing.
 *
 * States: Idle -> Selected -> Brewing -> Done
 */
class CoffeeFSM {
public:
    enum Drink { None, Espresso, Latte, Cappuccino, Americano, Mocha, FlatWhite };
    enum Strength { Mild, Strong };
    enum State { Idle, Selected, Brewing, Done };

    /** Construct the FSM. */
    explicit CoffeeFSM();
    ~CoffeeFSM();

    /** Current selections and state accessors. */
    Drink currentDrink() const { return m_drink; }
    State currentState() const { return m_state; }

    /** Set a callback to receive state name updates (UI-friendly). */
    void setStateCallback(std::function<void(const QString&)> cb) { m_callback = std::move(cb); }

    /* Configuration setters (called by UI) */
    void setCoffeeType(Drink d) { m_drink = d; }
    void setStrength(Strength s) { m_strength = s; }
    void setExtraMilk(bool v) { m_extraMilk = v; }
    void setOatsMilk(bool v) { m_oatsMilk = v; }
    void setWarmWater(bool v) { m_warmWater = v; }
    void setTemperature(int t) { m_temperature = t; }

    /* Actions */
    void selectEspresso();
    void selectLatte();
    void selectCappuccino();
    void startBrew();
    void reset();

private:
    void changeState(State s, const QString &name);

    QTimer m_brewTimer;
    Drink m_drink{None};
    Strength m_strength{Mild};
    bool m_extraMilk{false};
    bool m_oatsMilk{false};
    bool m_warmWater{false};
    int m_temperature{25};
    State m_state{Idle};
    std::function<void(const QString&)> m_callback;
};
