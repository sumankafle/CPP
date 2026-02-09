/**
 * @file mainwindow.h
 * @brief Main window for the Qt coffee demo.
 */
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTimer>
#include "coffee_fsm.h"

class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    CoffeeFSM *m_fsm;
    QComboBox *m_typeCombo;
    QRadioButton *m_mildRadio;
    QRadioButton *m_strongRadio;
    QButtonGroup *m_strengthGroup;
    QCheckBox *m_extraMilk;
    QCheckBox *m_oatsMilk;
    QCheckBox *m_warmWater;
    QPushButton *m_start;
    QPushButton *m_reset;
    QLabel *m_status;
    QLabel *m_tempLabel;
    QTimer *m_tempTimer;
};
