#include "addemployeewindow.h"
#include "ui_addemployeewindow.h"

addEmployeeWindow::addEmployeeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    //ui->buttonBox->Cancel->
}

addEmployeeWindow::~addEmployeeWindow()
{
    delete ui;
}

void addEmployeeWindow::on_cancel_btn_clicked()
{
    close();
}
