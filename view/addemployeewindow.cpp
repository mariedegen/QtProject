#include "view/addemployeewindow.h"
#include "ui_addemployeewindow.h"

AddEmployeeWindow::AddEmployeeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    //ui->buttonBox->Cancel->
}

AddEmployeeWindow::~AddEmployeeWindow()
{
    delete ui;
}

void AddEmployeeWindow::on_cancel_btn_clicked()
{
    close();
}

void AddEmployeeWindow::on_ok_btn_clicked()
{
    //TODO
}
