#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <vector>

class KeyboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardWidget(QWidget *parent = nullptr);

private slots:
    void onKeyPressed();

private:
    void buildKeyboard();
    QString resolveKey(const QString &key);

    QLineEdit *display;

    bool shiftOn = false;
    bool capsOn  = false;
    bool german  = false;

    std::vector<std::string> keytext_en;
    std::vector<std::string> keytext_de;
};

#endif
