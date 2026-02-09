/**
 * @file main.cpp
 * @brief Entry point for the Qt coffee demo (CMake-friendly layout).
 */
#include <QApplication>
#include "../include/mainwindow.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
