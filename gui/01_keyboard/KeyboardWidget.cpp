#include "KeyboardWidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Virtual Keyboard");
    resize(1000, 350);

    keytext_en = {
        "~\n`","!\n1","@\n2","#\n3","$\n4","%\n5","^\n6","&\n7",
        "*\n8","(\n9",")\n0","_\n-","+\n=","Backspace",
        "Tab","Q\nq","W\nw","E\ne","R\nr","T\nt","Y\ny","U\nu","I\ni","O\no","P\np",
        "{\n[","}\n]","\\\n|",
        "Caps","A\na","S\ns","D\nd","F\nf","G\ng","H\nh","J\nj","K\nk","L\nl",
        ":\n;","\"\n'",
        "Enter",
        "Shift","Z\nz","X\nx","C\nc","V\nv","B\nb","N\nn","M\nm","<\n,",">\n.","?\n/",
        "Shift",
        "Ctrl","Alt","Space","EN/DE","Alt","Ctrl"
    };

    keytext_de = {
        "°\n^","!\n1","\"\n2","§\n3","$\n4","%\n5","&\n6","/\n7",
        "(\n8",")\n9","=\n0","?\nß","`\n´","Backspace",
        "Tab","Q\nq","W\nw","E\ne","R\nr","T\nt","Z\nz","U\nu","I\ni","O\no","P\np",
        "Ü\nü","+ \n*","#\n'",
        "Caps","A\na","S\ns","D\nd","F\nf","G\ng","H\nh","J\nj","K\nk","L\nl",
        "Ö\nö","Ä\nä",
        "Enter",
        "Shift","Y\ny","X\nx","C\nc","V\nv","B\nb","N\nn","M\nm",";\n,",":\n.","_\n-",
        "Shift",
        "Ctrl","Alt","Space","EN/DE","Alt","Ctrl"
    };

    buildKeyboard();
}

void KeyboardWidget::buildKeyboard()
{
    delete layout();

    auto *mainLayout = new QVBoxLayout(this);

    display = new QLineEdit;
    display->setMinimumHeight(40);
    mainLayout->addWidget(display);

    auto *grid = new QGridLayout;
    const auto &keys = german ? keytext_de : keytext_en;

    int row = 0, col = 0;
    for (const auto &k : keys) {
        QString key = QString::fromStdString(k);
        auto *btn = new QPushButton(key);
        btn->setMinimumSize(60, 50);
        btn->setProperty("key", key);
        btn->setMinimumWidth(key == "Space" ? 300 : 50);
        connect(btn, &QPushButton::clicked, this, &KeyboardWidget::onKeyPressed);

        grid->addWidget(btn, row, col++);
        if (col > 13) { col = 0; row++; }
    }

    mainLayout->addLayout(grid);
}

QString KeyboardWidget::resolveKey(const QString &key)
{
    if (!key.contains("\n"))
        return key;

    auto parts = key.split("\n");
    return (shiftOn ^ capsOn) ? parts.first() : parts.last();
}

void KeyboardWidget::onKeyPressed()
{
    auto *btn = qobject_cast<QPushButton*>(sender());
    QString key = btn->property("key").toString();

    if (key == "Backspace") {
        display->backspace();
    }
    else if (key == "Enter") {
        display->insert("\n");
    }
    else if (key == "Space") {
        display->insert(" ");
    }
    else if (key == "Shift") {
        shiftOn = !shiftOn;
    }
    else if (key == "Caps") {
        capsOn = !capsOn;
    }
    else if (key == "EN/DE") {
        german = !german;
        buildKeyboard();
    }
    else {
        display->insert(resolveKey(key));
        shiftOn = false;
    }
}
