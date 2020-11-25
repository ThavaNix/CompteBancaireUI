#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QString>
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

QGroupBox *echoGroup = new QGroupBox;

PaveNum = new QGroupBox("Utilisez Le Pavé Numerique Pour le MDP");
PaveNum->setStyleSheet("*{font-size : 14px ; color : blue;}");

QLabel *echoLabel = new QLabel(tr("Connexion :"));
loginAlert = new QLabel;

echoLineEdit = new QLineEdit;
echoLineEdit2 = new QLineEdit;
echoLineEdit2->setMaxLength(3);
echoLineEdit->setMaxLength(3);
echoLineEdit2->setDisabled(true);
echoLineEdit2->setVisible(false);

echoCheckBox = new QCheckBox("Masquer");

echoCheckBox->setVisible(false);
echoCheckBox->setCheckState(Qt::Checked);
echoLineEdit->setStyleSheet("*{color : black}");
echoLineEdit2->setStyleSheet("*{color : black}");

echoLineEdit->setPlaceholderText("ID");

echoLineEdit2->setPlaceholderText("MotDePasse");
echoLineEdit2->setEchoMode(QLineEdit::Password);


QGridLayout *echoLayout = new QGridLayout;

echoLayout->addWidget(echoLabel, 0, 0);
echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
echoLayout->addWidget(echoLineEdit2, 2, 0, 1, 2);
echoLayout->addWidget(echoCheckBox,2 , 3);



echoGroup->setLayout(echoLayout);
echoGroup->setStyleSheet("*{font-size : 14px;}");
//! [2]
//! [3]
QGridLayout *layout = new QGridLayout;
layout->addWidget(echoGroup, 0, 0);
layout->addWidget(PaveNum , 1 , 0);

PaveNum->setVisible(false);
setLayout(layout);
setWindowTitle(tr("Fenetre de connexion"));


QGridLayout *pavNum = new QGridLayout;

pavNum->addWidget(B0 , 3 ,1 );
pavNum->addWidget(B1 , 0 , 0);
pavNum->addWidget(B2 , 0 , 1);
pavNum->addWidget(B3 , 0 , 2);
pavNum->addWidget(B4 , 1 , 0);
pavNum->addWidget(B5 , 1 , 1);
pavNum->addWidget(B6 , 1 , 2);
pavNum->addWidget(B7 , 2 , 0);
pavNum->addWidget(B8 , 2 , 1);
pavNum->addWidget(B9 , 2 , 2);
pavNum->addWidget(bConn , 3 , 2);
pavNum->addWidget(bClose , 3 , 0);
pavNum->addWidget(loginAlert ,4 ,1);


loginAlert->setVisible(false);

bConn->setStyleSheet("* { background-color: #5294e2  ; color : black}");
bClose->setStyleSheet("*{background-color: #853934 ; color : black}");
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


connect( bConn , SIGNAL(clicked()),this, SLOT(slotbConn()));

connect( bClose , SIGNAL(clicked()),this, SLOT(slotbClose()));

connect( echoCheckBox , SIGNAL(clicked()),this, SLOT(echoChanged()));

connect(echoLineEdit,SIGNAL(textChanged(QString)),this,SLOT(idVerification()));


//connect(echoLineEdit2,SIGNAL(textChanged(QString)),this,SLOT(mdpVerification()));


}



void MainWindow::buttonClicked()
 {
    QPushButton *button = (QPushButton *)sender();
       int num_button = (button->text()[0].digitValue());


       if(echoLineEdit2->isEnabled())
         {
             echoLineEdit2->setText(echoLineEdit2->text()+QString::number(num_button));
         }
}

void MainWindow::echoChanged()
{
    if(echoCheckBox->isChecked()){
     echoLineEdit2->setEchoMode(QLineEdit::Password);
}
    else if (!echoCheckBox->isChecked()){
     echoLineEdit2->setEchoMode(QLineEdit::Normal);
    }
}

void MainWindow::idVerification(){
    if(echoLineEdit->text()=="000")
    {
        echoLineEdit->setDisabled(true);
        echoLineEdit->setVisible(false);
        echoLineEdit2->setDisabled(false);
        echoLineEdit2->setVisible(true);
        echoCheckBox->setVisible(true);
        PaveNum->setVisible(true);


    }

}

void MainWindow::slotbConn(){



    if (echoLineEdit2->text() == "000")
        {

            loginAlert->setVisible(true);
            loginAlert->setText("Connexion Réussi");
            loginAlert->setStyleSheet("*{color:green}");
        }
        else if (echoLineEdit2->text() != "000"){

        loginAlert->setVisible(true);
          loginAlert->setText("Connexion Refuser" );
          loginAlert->setStyleSheet("*{color:red}");
          echoLineEdit2->clear();
    }


}



void MainWindow::slotbClose(){
this->close();
}
//void MainWindow::mdpVerification(){}





