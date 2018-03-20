#include "view/addemployeewindow.h"
#include <QMessageBox>
#include "model/ressource.h"
#include "model/compte.h"
#include "controller/toolbox.h"
#include "mainwindow.h"

AddEmployeeWindow::AddEmployeeWindow(QWidget *parent, bool flag, int idR) :
    QDialog(parent),
    ui(new Ui::addEmployeeWindow),
    isNewRessource(flag),
    idRessource(idR)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    setTypesComboBox();
    if(!flag){
        Ressource r = Ressource::getRessourceById(idR);
        ui->lastname_input->setText(r.getLastname());
        ui->firstname_input->setText(r.getFirstname());

        ui->type_comboBox->setCurrentIndex(ui->type_comboBox->findText((r.getType().getLabel())));
        if(r.getType().getLabel() == "Informaticien") {
            Compte t = Compte::getCompteByIdRessource(idR);
            ui->login_input->setText(t.getLogin());
            ui->password_input->setText(t.getPassword());
        }
    }

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
    int idType = Type::getIdTypeByName(value);
    QStatusBar* statusBar = ((MainWindow*)parent())->getStatusBar();

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
            if(isNewRessource){
                Ressource::addRessourceITDB(toolbox::capitalize(ui->firstname_input->text()),toolbox::capitalize(ui->lastname_input->text()), idType,ui->login_input->text(),ui->password_input->text());
                statusBar->showMessage("The following ressource has been added : " + toolbox::capitalize(ui->firstname_input->text())+ " "+toolbox::capitalize(ui->lastname_input->text()),4000);
            }else{
                Ressource::modifyRessource(idRessource, toolbox::capitalize(ui->lastname_input->text()),toolbox::capitalize(ui->firstname_input->text()), idType,ui->login_input->text(),ui->password_input->text());
                statusBar->showMessage("The following ressource has been modified : " + toolbox::capitalize(ui->firstname_input->text())+ " "+toolbox::capitalize(ui->lastname_input->text()),4000);
            }
            close();

        }
    }else {
        if(isNewRessource){
            Ressource::addRessourceDB(toolbox::capitalize(ui->firstname_input->text()),toolbox::capitalize(ui->lastname_input->text()), idType);
            statusBar->showMessage("The following ressource has been added : " + toolbox::capitalize(ui->firstname_input->text())+ " "+toolbox::capitalize(ui->lastname_input->text()),4000);
        }else{
             Ressource::modifyRessource(idRessource, toolbox::capitalize(ui->lastname_input->text()),toolbox::capitalize(ui->firstname_input->text()), idType,ui->login_input->text(),ui->password_input->text());
            statusBar->showMessage("The following ressource has been modified : " + toolbox::capitalize(ui->firstname_input->text())+ " "+toolbox::capitalize(ui->lastname_input->text()),4000);
        }
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
