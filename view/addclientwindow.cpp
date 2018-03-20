#include "view/addclientwindow.h"

AddClientWindow::AddClientWindow(QWidget *parent, bool flag, int idR) :
    QDialog(parent),
    ui(new Ui::addClientWindow),
    isNewClient(flag),
    idClient(idR)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    if(!flag){
        Client r = Client::getClientById(idR);
        //insert data
        }
    }
}

AddClientWindow::~AddClientWindow()
{
    delete ui;
}

void AddClientWindow::on_cancel_btn_clicked()
{
    close();
}

void AddClientWindow::on_ok_btn_clicked()
{
    if(this->formIsCompleted()){
        //QString lName = ui->lastname->text();
        //QString fName = ui->firstname->text();
        //Client *client = new Client(lName, fName);
    } else {
        QMessageBox msgBox;
        msgBox.setText("You must fill all the fields !");
        msgBox.exec();
    }
}

bool AddClientWindow::formIsCompleted()
{
    // Test if firstname is completed
    if(ui->firstnameInput->text().isEmpty()){
        return false;
    }

    // Test if lastname is completed
    if(ui->lastnameInput->text().isEmpty()){
        return false;
    }

    // Test if street is completed
    if(ui->streetInput->text().isEmpty()){
        return false;
    }

    // Test if city is completed
    if(ui->cityInput->text().isEmpty()){
        return false;
    }

    return true;
}
