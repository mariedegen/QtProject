#include "view/identificationdialog.h"
#include "ui_identificationdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

IdentificationDialog::IdentificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    //this->setStyleSheet("background-color: #EA80FC");
    connect(ui->connection_btn,SIGNAL(clicked()),this, SLOT(check_authentification()));
}

IdentificationDialog::~IdentificationDialog()
{
    delete ui;
}


void IdentificationDialog::check_authentification()
{
    if(!ui->login_input->text().compare("marie") && !ui->password_input->text().compare("stephane")){
        accept();
    } else {
        QMessageBox::warning(this, "Erreur", "The data entered are wrong.");
    }
}

void IdentificationDialog::on_cancel_btn_clicked()
{
    close();
}
