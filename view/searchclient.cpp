#include "view/searchclient.h"
#include "ui_searchclient.h"
#include "db/initbdd.h"
#include <QSqlTableModel>
#include "model/client.h"
#include <QMessageBox>
#include "addclientwindow.h"
#include "mainwindow.h"

SearchClient::SearchClient(QString searchName, QString searchfName, int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchClient),
    name(searchName),
    firstName(searchfName),
    id(id)
{
    ui->setupUi(this);
    updateViewTable();
}

SearchClient::~SearchClient()
{
    delete ui;
}

void SearchClient::on_deleteclient_btn_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::warning(this, tr("Error"),
                             tr("You need to select something to delete! "),
                             QMessageBox::Close);
    }else{
        //something is selected
        int idC = select->selectedRows(0).value(0).data().toInt();
        Client::deleteClient(idC);
        updateViewTable();

        QStatusBar* statusBar = ((MainWindow*)parent())->getStatusBar();
        statusBar->showMessage("The Client has been deleted",4000);
    }
}

void SearchClient::on_editclient_btn_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::warning(this, tr("Error"),
                             tr("You need to select something to delete! "),
                             QMessageBox::Close);
    }else{
        //something is selected
        int idC = select->selectedRows(0).value(0).data().toInt();
        AddClientWindow aCw((QWidget*)this->parent(), false, idC);
        aCw.exec();
        updateViewTable();
        QStatusBar* statusBar = ((MainWindow*)parent())->getStatusBar();
        statusBar->showMessage("The client has been modified.",4000);
    }
}

void SearchClient::updateViewTable()
{
    QSqlQueryModel *model = Client::getListClientByCriteria(id, name, firstName);
    ui->tableView->setModel(model);
    ui->tableView->show();

    QStatusBar* statusBar = ((MainWindow*)parent())->getStatusBar();
    if(name != NULL || firstName != NULL){
            statusBar->showMessage("You have searched for : " + name + firstName + ".",4000);
    }else if (id != -1){
        statusBar->showMessage("You have searched for a client with " + QString::number(id) +" as ID.",4000);
    }
}
