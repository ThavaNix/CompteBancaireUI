#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QWidget
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
QPushButton *B0 = new QPushButton("0");

public slots:
void echoChanged(int);
int EcireDansMDP();
void buttonClicked();

private:
QLineEdit *echoLineEdit;
QLineEdit *echoLineEdit2;
};
//! [0]

#endif // MAINWINDOW_H
