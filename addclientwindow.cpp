#include "addclientwindow.h"
#include "ui_addclientwindow.h"

addClientWindow::addClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClientWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));

}

addClientWindow::~addClientWindow()
{
    delete ui;
}

void addClientWindow::on_cancel_btn_clicked()
{
    close();
}
