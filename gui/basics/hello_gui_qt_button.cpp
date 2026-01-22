/**
 * @file hello_gui_qt_button.cpp
 * @brief Qt GUI application demonstrating QMainWindow with QLabel, QPushButton, and menu bar.
 *
 * This program creates a simple Qt GUI window using QMainWindow. It displays
 * a QLabel with "Hello World" text, adds a QPushButton, and creates a File menu
 * with "Open" and "Close" actions.
 *
 * Demonstrates basic OOP concepts in Qt:
 * - Inheritance (MyWidget derives from QMainWindow)
 * - Encapsulation (private createMenus method)
 * - Widgets (QLabel, QPushButton)
 * - Menu bar with QAction
 *
 * @author Suman
 * @date 2026
 */

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>

/**
 * @brief Custom main window class derived from QMainWindow.
 *
 * Creates a window with a QLabel, a QPushButton, and a basic File menu.
 */
class MyWidget : public QMainWindow {
public:
    /**
     * @brief Constructor for MyWidget.
     * @param parent Pointer to parent QWidget (default nullptr)
     *
     * Initializes window size, title, adds QLabel and QPushButton, and creates menu bar.
     */
    MyWidget(QWidget *parent = nullptr) : QMainWindow(parent) {
        this->resize(320, 240);                       ///< Set window size
        this->setWindowTitle("HelloGUI with Qt");     ///< Set window title

        // Create QLabel
        QLabel* label = new QLabel("Hello World", this);
        label->setGeometry(120, 20, 150, 30);         ///< Set label position and size

        // Create QPushButton
        QPushButton* button = new QPushButton("Click Me", this);
        button->setGeometry(120, 50, 150, 30);        ///< Set button position and size

        createMenus();                                ///< Setup menu bar
    }

private:
    /**
     * @brief Creates the menu bar with File menu and actions.
     *
     * Adds "Open" and "Close" actions under the File menu.
     */
    void createMenus() {
        QMenuBar *bar = menuBar();                      ///< Get menu bar
        QMenu *fileMenu = bar->addMenu(tr("&File"));    ///< Add File menu
        fileMenu->addAction(new QAction("Open", this)); ///< Add Open action
        fileMenu->addAction(new QAction("Close", this));///< Add Close action
    }
};

/**
 * @brief Program entry point.
 *
 * Initializes QApplication, creates a MyWidget instance,
 * shows it, and executes the Qt event loop.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return int Exit status
 */
int main(int argc, char* argv[]) {
    QApplication appl(argc, argv); ///< Initialize Qt application

    MyWidget widget; ///< Create main window
    widget.show();   ///< Show window and all child widgets

    return appl.exec(); ///< Start Qt event loop
}
