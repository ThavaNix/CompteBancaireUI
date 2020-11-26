#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QString>


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

void buttonClicked();
void echoChanged();
void idVerification();
bool slotbConn();
void slotbClose();
void mdpVerification();
private:
QLineEdit *idChamp;
QLineEdit *mdpChamp;
QCheckBox *echoMdp;
QGroupBox *PaveNum;
QLabel *loginAlert;

QPushButton *pavButtons[10];

QPushButton *bConn = new QPushButton("Connexion") ;
QPushButton *bClose = new QPushButton("Fermer");
};
//! [0]

#endif // MAINWINDOW_H
