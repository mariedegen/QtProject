#include "view/addemployeewindow.h"
#include "ui_addemployeewindow.h"
#include <QDebug>

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

void AddEmployeeWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString value = ui->comboBox->itemText(ui->comboBox->currentIndex());
    qDebug() << value;
    if(value == "Computer scientist"){
        ui->groupBox_3->setEnabled(true);
    } else {
        ui->groupBox_3->setEnabled(false);
    }
}
