#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QComboBox>
#include<QGridLayout>
#include<QGroupBox>
#include<QLabel>
#include<QLineEdit>
#include <QPushButton>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
//! [1]
QGroupBox *echoGroup = new QGroupBox(tr("Echo"));
QGroupBox *PaveNum =   new QGroupBox( tr("PaveNum"));
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

////////////////////////////////////////
//if (echoLineEdit->hasFocus()){}else
//{
//    qDebug("Identifiant");
//}


/////////////////////////////////////////

echoGroup->setLayout(echoLayout);
//! [2]
//! [3]
QGridLayout *layout = new QGridLayout;
layout->addWidget(echoGroup, 0, 0);// 0,0 définit la position de notre layout
layout->addWidget(PaveNum , 1 , 0);
setLayout(layout);
setWindowTitle(tr("Line Edits"));// définit le titre de l'application


QGridLayout *pavNum = new QGridLayout;
this->B0->setGeometry(50, 100, 100, 50);
pavNum->addWidget(B0 , 0 , 1 );
pavNum->addWidget(B1 , 0 , 2);
pavNum->addWidget(B2 , 0 , 3);
pavNum->addWidget(B3 , 1 , 1);
pavNum->addWidget(B4 , 1 , 2);
pavNum->addWidget(B5 , 1 , 3);
pavNum->addWidget(B6 , 2 , 1);
pavNum->addWidget(B7 , 2 , 2 );
pavNum->addWidget(B8 , 2 , 3);
pavNum->addWidget(B9 , 3 , 2);
PaveNum->setLayout(pavNum);


//! [5]

connect( B0 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B1 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B2 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B3 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B4 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B5 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B6 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B7 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B8 , SIGNAL(clicked()),this, SLOT(buttonClicked()));
connect( B9 , SIGNAL(clicked()),this, SLOT(buttonClicked()));

connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),
this, &MainWindow::echoChanged);
//! [5]
}
//! [3]

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

void MainWindow::buttonClicked()
 {

    QPushButton *button = (QPushButton *)sender() ;
    int num_bouton = (button->text()[0].digitValue());
 if (echoLineEdit2->focusWidget()){
 echoLineEdit2->setText(echoLineEdit2->text()+QString::number(num_bouton));

 }
 else if (echoLineEdit->focusWidget()) {
      echoLineEdit->setText(echoLineEdit->text()+QString::number(num_bouton));
 }


}
