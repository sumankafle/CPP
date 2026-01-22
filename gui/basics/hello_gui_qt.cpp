/**
 * @file hello_gui_qt.cpp
 * @brief Simple Qt GUI application displaying "Hello World".
 *
 * This program demonstrates a basic Qt GUI application. It creates
 * a main window using QWidget and displays a QLabel with the
 * text "Hello World".
 *
 * @author Suman
 * @date 22/01/2026
 */

#include <QApplication>
#include <QLabel>
#include <QWidget>

/**
 * @brief Custom widget class derived from QWidget.
 *
 * This class creates a window with a fixed size and a QLabel
 * displaying "Hello World".
 */
class MyWidget : public QWidget {
public:
    /**
     * @brief Constructor for MyWidget.
     * @param parent Pointer to the parent QWidget (default is nullptr)
     *
     * Initializes the widget size, window title, and adds a QLabel.
     */
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        this->resize(320, 240);                ///< Set window size
        this->setWindowTitle("HelloGUI with Qt"); ///< Set window title

        // Create a label with text "Hello World"
        QLabel* label = new QLabel("Hello World", this);
        label->move(100, 100); ///< Optional: move label to center-ish
    }
};

/**
 * @brief Program entry point.
 *
 * Initializes the QApplication, creates a MyWidget instance,
 * shows it, and enters the main event loop.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return int Exit status
 */
int main(int argc, char* argv[]) {
    QApplication appl(argc, argv); ///< Initialize Qt application

    MyWidget widget;  ///< Create main widget
    widget.show();    ///< Show the widget

    return appl.exec(); ///< Execute application event loop
}
