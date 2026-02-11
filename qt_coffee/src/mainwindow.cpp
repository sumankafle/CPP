/**
 * @file mainwindow.cpp
 * @brief GUI implementation wiring UI controls to the FSM.

#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *w = new QWidget(this);
    auto *grid = new QGridLayout(w);

    m_typeCombo = new QComboBox();
    m_typeCombo->addItem("Espresso");
    m_typeCombo->addItem("Latte");
    m_typeCombo->addItem("Cappuccino");
    m_typeCombo->addItem("Americano");
    m_typeCombo->addItem("Mocha");
    m_typeCombo->addItem("FlatWhite");

    m_mildRadio = new QRadioButton("Mild");
    m_strongRadio = new QRadioButton("Strong");
    m_strengthGroup = new QButtonGroup(this);
    m_strengthGroup->addButton(m_mildRadio);
    m_strengthGroup->addButton(m_strongRadio);
    m_mildRadio->setChecked(true);
    m_strengthGroup->setExclusive(true);

    m_extraMilk = new QCheckBox("Extra Milk");
    m_oatsMilk = new QCheckBox("Oats Milk");
    m_warmWater = new QCheckBox("Warm Water");

    m_start    = new QPushButton("Start Brew");
    m_reset    = new QPushButton("Reset");

    m_status = new QLabel("State: Idle");
    m_tempLabel = new QLabel("Temp: -- °C");
    m_tempLabel->setAlignment(Qt::AlignCenter);
    m_status->setAlignment(Qt::AlignCenter);

    grid->addWidget(new QLabel("Type:"), 0, 0);
    grid->addWidget(m_typeCombo, 0, 1, 1, 2);

    grid->addWidget(m_mildRadio, 1, 0);
    grid->addWidget(m_strongRadio, 1, 1);

    grid->addWidget(m_extraMilk, 2, 0);
    grid->addWidget(m_oatsMilk, 2, 1);
    grid->addWidget(m_warmWater, 2, 2);

    grid->addWidget(m_start,    3, 1);
    grid->addWidget(m_reset,    4, 1);
    grid->addWidget(m_status,   5, 0, 1, 3);
    grid->addWidget(m_tempLabel,6,0,1,3);

    setCentralWidget(w);
    resize(480, 200);

    m_fsm = new CoffeeFSM();

    // wire UI to FSM configuration
    connect(m_typeCombo, &QComboBox::currentTextChanged, this, [this](const QString &t){
        if(t == "Espresso") { m_fsm->setCoffeeType(CoffeeFSM::Espresso); m_fsm->selectEspresso(); }
        else if(t == "Latte") { m_fsm->setCoffeeType(CoffeeFSM::Latte); m_fsm->selectLatte(); }
        else if(t == "Cappuccino") { m_fsm->setCoffeeType(CoffeeFSM::Cappuccino); m_fsm->selectCappuccino(); }
        else if(t == "Americano") { m_fsm->setCoffeeType(CoffeeFSM::Americano); m_fsm->selectEspresso(); }
        else if(t == "Mocha") { m_fsm->setCoffeeType(CoffeeFSM::Mocha); m_fsm->selectEspresso(); }
        else if(t == "FlatWhite") { m_fsm->setCoffeeType(CoffeeFSM::FlatWhite); m_fsm->selectEspresso(); }
    });

    connect(m_mildRadio, &QRadioButton::toggled, this, [this](bool checked){ if(checked) m_fsm->setStrength(CoffeeFSM::Mild); });
    connect(m_strongRadio, &QRadioButton::toggled, this, [this](bool checked){ if(checked) m_fsm->setStrength(CoffeeFSM::Strong); });

    connect(m_extraMilk, &QCheckBox::toggled, this, [this](bool v){ m_fsm->setExtraMilk(v); });
    connect(m_oatsMilk, &QCheckBox::toggled, this, [this](bool v){ m_fsm->setOatsMilk(v); });
    connect(m_warmWater, &QCheckBox::toggled, this, [this](bool v){ m_fsm->setWarmWater(v); });

    connect(m_start, &QPushButton::clicked, this, [this]{ m_fsm->startBrew(); });
    connect(m_reset, &QPushButton::clicked, this, [this]{ m_fsm->reset(); });

    // route FSM state updates to a queued slot on the GUI thread
    m_fsm->setStateCallback([this](const QString &s){
        QTimer::singleShot(0, this, [this, s]{ onStateChanged(s); });
    });

    // temperature simulation
    m_tempTimer = new QTimer(this);
    connect(m_tempTimer, &QTimer::timeout, this, [this]{
        static int t = 25;
        t += (rand() % 7) - 3; if(t < 20) t = 20; if(t > 95) t = 95;
        m_tempLabel->setText(QString("Temp: %1 °C").arg(t));
        m_fsm->setTemperature(t);
    });
    m_tempTimer->start(1000);

    // initialize FSM from UI defaults
    const QString initType = m_typeCombo->currentText();
    if(initType == "Espresso") { m_fsm->setCoffeeType(CoffeeFSM::Espresso); m_fsm->selectEspresso(); }
    else if(initType == "Latte") { m_fsm->setCoffeeType(CoffeeFSM::Latte); m_fsm->selectLatte(); }
    else if(initType == "Cappuccino") { m_fsm->setCoffeeType(CoffeeFSM::Cappuccino); m_fsm->selectCappuccino(); }
    else if(initType == "Americano") { m_fsm->setCoffeeType(CoffeeFSM::Americano); m_fsm->selectEspresso(); }
    else if(initType == "Mocha") { m_fsm->setCoffeeType(CoffeeFSM::Mocha); m_fsm->selectEspresso(); }
    else if(initType == "FlatWhite") { m_fsm->setCoffeeType(CoffeeFSM::FlatWhite); m_fsm->selectEspresso(); }

    if(m_mildRadio->isChecked()) m_fsm->setStrength(CoffeeFSM::Mild);
    if(m_strongRadio->isChecked()) m_fsm->setStrength(CoffeeFSM::Strong);
    m_fsm->setExtraMilk(m_extraMilk->isChecked());
    m_fsm->setOatsMilk(m_oatsMilk->isChecked());
    m_fsm->setWarmWater(m_warmWater->isChecked());
}

void MainWindow::onStateChanged(const QString &s)
{
    QString drinkName;
    switch(m_fsm->currentDrink()){
    case CoffeeFSM::Espresso: drinkName = "Espresso"; break;
    case CoffeeFSM::Latte: drinkName = "Latte"; break;
    case CoffeeFSM::Cappuccino: drinkName = "Cappuccino"; break;
    case CoffeeFSM::Americano: drinkName = "Americano"; break;
    case CoffeeFSM::Mocha: drinkName = "Mocha"; break;
    case CoffeeFSM::FlatWhite: drinkName = "FlatWhite"; break;
    default: drinkName = ""; break;
    }
    QString s2 = s;
    if(m_fsm->currentDrink() != CoffeeFSM::None) s2 += " (" + drinkName + ")";
    m_status->setText(QString("State: %1").arg(s2));
}
