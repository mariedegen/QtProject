#include "view/addemployeewindow.h"
#include <QMessageBox>
#include "model/ressource.h"
#include "controller/toolbox.h"

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
    QString value = ui->type_comboBox->itemText(ui->type_comboBox->currentIndex());
    Type type;
    int idType = type.getIdTypeByName(value);
    Ressource ressource;

    if(ui->firstname_input->text().isEmpty()){
        QMessageBox::warning(this, tr("Error"),
                                       tr("You must fill all the fields ! "),
                                       QMessageBox::Close);
    } else if(ui->lastname_input->text().isEmpty()){
        QMessageBox::warning(this, tr("Error"),
                                       tr("You must fill all the fields ! "),
                                       QMessageBox::Close);
    } else if(value == "Informaticien"){
        if(ui->login_input->text().isEmpty()){
            QMessageBox::warning(this, tr("Error"),
                                           tr("You must fill all the fields ! "),
                                           QMessageBox::Close);
        }
        else if(ui->password_input->text().isEmpty()){
            QMessageBox::warning(this, tr("Error"),
                                           tr("You must fill all the fields ! "),
                                           QMessageBox::Close);
        }else {
            ressource.addRessourceITDB(toolbox::capitalize(ui->firstname_input->text()),toolbox::capitalize(ui->lastname_input->text()), idType,ui->login_input->text(),ui->password_input->text());
            close();
        }
    }else {
        ressource.addRessourceDB(toolbox::capitalize(ui->firstname_input->text()),toolbox::capitalize(ui->lastname_input->text()), idType);
        close();
    }
}

void AddEmployeeWindow::on_type_comboBox_currentIndexChanged()
{
    QString value = ui->type_comboBox->itemText(ui->type_comboBox->currentIndex());
    if(value == "Informaticien"){
        ui->LoginData->setEnabled(true);
    } else {
        ui->LoginData->setEnabled(false);
    }
}
