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
    QString lName = ui->lastname;
    QString fName = ui->fisrtname;
    Client *client = new Client(lName, fName);
}
