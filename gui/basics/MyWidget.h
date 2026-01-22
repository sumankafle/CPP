#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QObject>

class MyWidget : public QMainWindow {
    Q_OBJECT
public:
  MyWidget(QWidget *parent = NULL) : QMainWindow(parent) {
    this->resize(320, 240);
    this->setWindowTitle("HelloGUI with Qt");
    counter = 0;
    label = new QLabel("Hello World", this);
    label->setGeometry(120, 20, 150, 30);
    QPushButton* button = new QPushButton( "Increment", this);
    button->setGeometry(120, 50, 150, 30);
    createMenus();
    QObject::connect(button, &QPushButton::clicked, this, &MyWidget::onButtonClicked);
  }

public slots:
  void onButtonClicked() {
      counter++;
      label->setText(QString("Click #%1").arg(counter));
  }

private:
  void createMenus() {
    QMenuBar *bar = menuBar();
    QMenu *fileMenu = bar->addMenu(tr("&File"));
    fileMenu->addAction(new QAction("Open", this));
    fileMenu->addAction(new QAction("Close", this));
  }
private:
  int counter;
  QLabel* label;
};

#endif // MYWIDGET_H