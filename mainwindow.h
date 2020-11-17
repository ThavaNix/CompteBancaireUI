#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QWidget
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);

public slots:
void echoChanged(int);
private:
QLineEdit *echoLineEdit;
};
//! [0]

#endif // MAINWINDOW_H
