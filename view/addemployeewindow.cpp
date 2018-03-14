#include "view/addemployeewindow.h"

AddEmployeeWindow::AddEmployeeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    setTypesComboBox();
}

AddEmployeeWindow::~AddEmployeeWindow()
{
    delete ui;
}

void AddEmployeeWindow::setTypesComboBox()
{
    // get list Types from BDD
    QSqlQuery list = Type::getListTypes();

    // Add items in ComboBox
    while(list.next()){
        ui->type_comboBox->addItem(list.value(1).toString());
    }
}

void AddEmployeeWindow::on_cancel_btn_clicked()
{
    close();
}

void AddEmployeeWindow::on_ok_btn_clicked()
{
    //TODO
}

void AddEmployeeWindow::on_type_comboBox_currentIndexChanged()
{
    QString value = ui->type_comboBox->itemText(ui->type_comboBox->currentIndex());
    //qDebug() << value;
    if(value == "Informaticien"){
        ui->LoginData->setEnabled(true);
    } else {
        ui->LoginData->setEnabled(false);
    }
}
