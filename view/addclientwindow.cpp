#include "view/addclientwindow.h"
#include "controller/toolbox.h"
#include "mainwindow.h"
#include "model/ressource.h"

AddClientWindow::AddClientWindow(QWidget *parent, bool flag, int idC) :
    QDialog(parent),
    ui(new Ui::addClientWindow),
    idClient(idC),
    isNewClient(flag)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    ui->modifyListRessource->setVisible(false);

    if(!flag){
        //fill the data
        Client c = Client::getClientByID(idC);
        ui->lastnameInput->setText(c.getName());
        ui->firstnameInput->setText(c.getFirstName());
        ui->streetInput->setText(c.getAdress());
        ui->cityInput->setText(c.getTown());
        ui->zipCodeInput->setText(QString::number(c.getZipCode()));
        ui->commentText->setText(c.getDescription());
        ui->dateEdit->setDate(c.getAppointmentDate());
        ui->durationSpinBox->setValue(c.getAppointmentDuration());
        ui->phoneInput->setText(QString::number(c.getPhoneNumber()));
        ui->prioritySpinBox->setValue(c.getPriority());
        QSqlQueryModel * model =  Client::getRessourceByClientID(idC);
        ui->ressourceList->setModel(model);
        ui->ressourceList->show();
        ui->modifyListRessource->setVisible(true);
    }else {
        ui->modifyListRessource->setVisible(false);
        QSqlQueryModel * model = Ressource::getRessourcesAddClient();
        ui->ressourceList->setModel(model);
        ui->ressourceList->show();
    }
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
    QStatusBar* statusBar = ((MainWindow*)parent())->getStatusBar();
    if(this->formIsCompleted()){
        if(isNewClient){
            QModelIndexList list = ui->ressourceList->selectionModel()->selectedIndexes();
            Client::addClientDB(toolbox::capitalize(ui->lastnameInput->text()), toolbox::capitalize(ui->firstnameInput->text()), ui->streetInput->text(), toolbox::capitalize(ui->cityInput->text()), toolbox::capitalize(ui->commentText->toPlainText()), ui->zipCodeInput->text() , ui->phoneInput->text(), ui->dateEdit->date(), ui->durationSpinBox->text(), ui->prioritySpinBox->text(), list);
            statusBar->showMessage("The following client has been added : "+toolbox::capitalize(ui->lastnameInput->text())+ " "+ toolbox::capitalize(ui->firstnameInput->text()),4000);
            close();
        }else{
            //modifier le client
            QItemSelectionModel *select = ui->ressourceList->selectionModel();
            if(select->hasSelection()){
                QModelIndexList list = select->selectedIndexes();
                Client::modifyClientDB(toolbox::capitalize(ui->lastnameInput->text()), toolbox::capitalize(ui->firstnameInput->text()), ui->streetInput->text(), toolbox::capitalize(ui->cityInput->text()), toolbox::capitalize(ui->commentText->toPlainText()), ui->zipCodeInput->text() , ui->phoneInput->text(), ui->dateEdit->date(), ui->durationSpinBox->text(), ui->prioritySpinBox->text(), idClient);
                Client::modifyAppointmentClient(idClient, list);
                close();
            }else{
                Client::modifyClientDB(toolbox::capitalize(ui->lastnameInput->text()), toolbox::capitalize(ui->firstnameInput->text()), ui->streetInput->text(), toolbox::capitalize(ui->cityInput->text()), toolbox::capitalize(ui->commentText->toPlainText()), ui->zipCodeInput->text() , ui->phoneInput->text(), ui->dateEdit->date(), ui->durationSpinBox->text(), ui->prioritySpinBox->text(), idClient);
                close();
            }
        }
    } else {
        QMessageBox::warning(this, tr("Error"),
                             tr("You must fill all the fields ! "),
                             QMessageBox::Close);
    }
}

bool AddClientWindow::formIsCompleted()
{
    // Test if firstname is completed
    if(ui->firstnameInput->text().isEmpty()){
        return false;
    }

    // Test if lastname is completed
    if(ui->lastnameInput->text().isEmpty()){
        return false;
    }

    // Test if street is completed
    if(ui->streetInput->text().isEmpty()){
        return false;
    }
    // Test if city is completed
    if(ui->cityInput->text().isEmpty()){
        return false;
    }

    return true;
}

void AddClientWindow::on_modifyListRessource_clicked()
{
    QSqlQueryModel * model = Ressource::getRessourcesAddClient();
    ui->ressourceList->setModel(model);
    ui->ressourceList->show();
}
