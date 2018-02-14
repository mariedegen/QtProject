#include "identificationdialog.h"
#include "ui_identificationdialog.h"
#include "mainwindow.h"
#include "QMessageBox"

IdentificationDialog::IdentificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/pig.png"));

    //Quit the window when the cancel_btn is clicked on
    connect(ui->cancel_btn,SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->connection_btn,SIGNAL(clicked()),this, SLOT(check_authentification()));
}

IdentificationDialog::~IdentificationDialog()
{
    delete ui;
}


void IdentificationDialog::check_authentification()
{
    if(ui->login_input->text().compare("marie") && ui->password_input->text().compare("stephane")){
        MainWindow *window = new MainWindow();
        window->show();
    } else if(!ui->login_input->text().compare("marie") || !ui->password_input->text().compare("stephane")){
        QMessageBox::warning(this, "Erreur", "The data entered are wrong.");
    }
}

