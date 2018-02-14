#include "addemployeewindow.h"
#include "ui_addemployeewindow.h"

addEmployeeWindow::addEmployeeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/pig.png"));
}

addEmployeeWindow::~addEmployeeWindow()
{
    delete ui;
}
