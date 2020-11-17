#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QComboBox>
#include<QGridLayout>
#include<QGroupBox>
#include<QLabel>
#include<QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
//! [1]
QGroupBox *echoGroup = new QGroupBox(tr("Echo"));
QLabel *echoLabel = new QLabel(tr("Mode:"));
QComboBox *echoComboBox = new QComboBox;
echoComboBox->addItem(tr("Normal"));
echoComboBox->addItem(tr("Password"));
echoComboBox->addItem(tr("PasswordEchoOnEdit"));
echoComboBox->addItem(tr("No Echo"));
echoLineEdit = new QLineEdit;
echoLineEdit2 = new QLineEdit;

echoLineEdit->setPlaceholderText("ID");

echoLineEdit2->setPlaceholderText("MotDePasse");
//! [1]
//! [2]
QGridLayout *echoLayout = new QGridLayout;

echoLayout->addWidget(echoLabel, 0, 0);
echoLayout->addWidget(echoComboBox, 0, 1);
echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
echoLayout->addWidget(echoLineEdit2, 2, 0, 1, 2);
this->B0->setGeometry(50, 100, 100, 50);
echoLayout->addWidget(B0);
echoGroup->setLayout(echoLayout);
//! [2]
//! [3]
QGridLayout *layout = new QGridLayout;
layout->addWidget(echoGroup, 0, 0);// 0,0 définit la position de notre layout
setLayout(layout);
setWindowTitle(tr("Line Edits"));// définit le titre de l'application

connect(B0, SIGNAL(clicked()),this, SLOT(buttonClicked()));

//! [5]
connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),
this, &MainWindow::echoChanged);
//! [5]
}
//! [3]
//!
//!
//!
//!
//!
//!
//!
//!
//!
//! [4]
void MainWindow::echoChanged(int index)
{
switch (index) {
case 0:
echoLineEdit->setEchoMode(QLineEdit::Normal);
break;
case 1:
echoLineEdit->setEchoMode(QLineEdit::Password);
break;
case 2:
echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
break;
case 3:
echoLineEdit->setEchoMode(QLineEdit::NoEcho);
break;
}

}
int MainWindow::EcireDansMDP(){
return 0;
}
void MainWindow::buttonClicked()
 {
     QPushButton *button = (QPushButton *)sender();
     emit digitClicked(button->text()[0].digitValue());
 }
