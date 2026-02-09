/**
 * @file coffee_fsm.cpp
 * @brief Implementation of the minimal coffee finite-state-machine.
 */
#include "../include/coffee_fsm.h"
#include <QString>
#include <QObject>
#include <algorithm>

CoffeeFSM::CoffeeFSM() {
    m_brewTimer.setSingleShot(true);
    QObject::connect(&m_brewTimer, &QTimer::timeout, [this]{
        changeState(Done, "Done");
    });
    changeState(Idle, "Idle");
}

CoffeeFSM::~CoffeeFSM() = default;

void CoffeeFSM::changeState(State s, const QString &name){
    m_state = s;
    if(m_callback) m_callback(name);
}

void CoffeeFSM::selectEspresso(){ m_drink = Espresso; changeState(Selected, "Selected"); }
void CoffeeFSM::selectLatte(){ m_drink = Latte; changeState(Selected, "Selected"); }
void CoffeeFSM::selectCappuccino(){ m_drink = Cappuccino; changeState(Selected, "Selected"); }
void CoffeeFSM::startBrew(){
    if(m_drink != None){
        if(m_state != Selected) changeState(Selected, "Selected");
        int base = 3000; // ms
        int extra = 0;
        if(m_extraMilk) extra += 1000;
        if(m_oatsMilk) extra += 1200;
        if(m_warmWater) extra += 500;
        if(m_strength == Strong) extra += 1500;
        int duration = std::max(1000, base + extra - (m_temperature > 80 ? 500 : 0));
        changeState(Brewing, "Brewing");
        m_brewTimer.start(duration);
    }
}
void CoffeeFSM::reset(){ m_brewTimer.stop(); m_drink = None; m_extraMilk = false; m_oatsMilk = false; m_warmWater = false; m_strength = Mild; changeState(Idle, "Idle"); }
