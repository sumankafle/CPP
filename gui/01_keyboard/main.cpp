#include <QApplication>
#include "KeyboardWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    KeyboardWidget widget;
    widget.show();

    return app.exec();
}
