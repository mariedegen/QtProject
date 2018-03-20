#include "view/addclientwindow.h"

AddClientWindow::AddClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClientWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
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
        Client::addClientDB(ui->lastnameInput->text(), ui->firstnameInput->text(), ui->streetInput->text(), ui->cityInput->text(), ui->commentLbl->text(), ui->zipCodeInput->text() , ui->phoneInput->text(), ui->dateEdit->date(), ui->durationSpinBox->text(), ui->prioritySpinBox->text());
    } else {
        QMessageBox::warning(this, tr("Error"),
                             tr("You must fill all the fields ! "),
                             QMessageBox::Close);
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
