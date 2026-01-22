/**
 * @file hello_gui_qt_click_counter.cpp
 * @brief Qt GUI application with QLabel, QPushButton, menu bar, and click counter.
 *
 * This program demonstrates:
 * - Object-oriented programming with Qt (inheritance from QMainWindow)
 * - Signals and slots for interactive GUI
 * - Incrementing a counter on button click and updating a QLabel
 * - Creating a File menu with Open and Close actions
 *
 * @author Suman
 * @date 2026
 */
#include<QApplication>
#include "MyWidget.h"

/**
 * @brief Entry point of the application
 *
 * Initializes QApplication, creates MyWidget, and enters the Qt event loop.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return int Exit status
 */
int main(int argc, char* argv[]) {
    QApplication appl(argc, argv); ///< Initialize Qt application

    MyWidget widget; ///< Create main window
    widget.show();   ///< Show the window

    return appl.exec(); ///< Start event loop
}

