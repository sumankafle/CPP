/**
 * @file hello_gui_qt_menu.cpp
 * @brief Qt GUI application demonstrating QMainWindow with QLabel and menu bar.
 *
 * This program creates a simple GUI window using QMainWindow. It displays
 * a QLabel with "Hello World" as the central widget and adds a basic
 * File menu with "Open" and "Close" actions.
 *
 * @author Suman
 * @date 2026
 */

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>

/**
 * @brief Custom main window class derived from QMainWindow.
 *
 * This class demonstrates:
 *  - Setting a central widget (QLabel)
 *  - Creating a simple menu bar with actions
 */
class MyWidget : public QMainWindow {
public:
    /**
     * @brief Constructor for MyWidget.
     * @param parent Pointer to the parent widget (default nullptr)
     *
     * Sets the window size and title, adds a QLabel as central widget,
     * and creates a simple File menu.
     */
    MyWidget(QWidget *parent = nullptr) : QMainWindow(parent) {
        this->resize(320, 240);                       ///< Set window size
        this->setWindowTitle("HelloGUI with Qt");     ///< Set window title

        // Create a label and set it as central widget
        QLabel* label = new QLabel("Hello World", this);
        setCentralWidget(label);

        createMenus(); ///< Setup menu bar
    }

private:
    /**
     * @brief Creates the menu bar and adds File menu with actions.
     *
     * Adds "Open" and "Close" actions under File menu.
     */
    void createMenus() {
        QMenuBar *bar = menuBar();               ///< Get menu bar
        QMenu *fileMenu = bar->addMenu(tr("&File")); ///< Add File menu
        fileMenu->addAction(new QAction("Open", this));
        fileMenu->addAction(new QAction("Close", this));
    }
};

/**
 * @brief Program entry point.
 *
 * Initializes the QApplication, creates a MyWidget instance,
 * shows it, and enters the Qt event loop.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return int Exit status
 */
int main(int argc, char* argv[]) {
    QApplication appl(argc, argv); ///< Initialize Qt application

    MyWidget widget; ///< Create main window
    widget.show();   ///< Show window and its child widgets

    return appl.exec(); ///< Start the Qt event loop
}
