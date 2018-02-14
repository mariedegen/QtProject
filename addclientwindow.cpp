#include "addclientwindow.h"
#include "ui_addclientwindow.h"

addClientWindow::addClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClientWindow)
{
    ui->setupUi(this);
}

addClientWindow::~addClientWindow()
{
    delete ui;
}
