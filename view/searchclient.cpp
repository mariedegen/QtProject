#include "view/searchclient.h"
#include "ui_searchclient.h"
#include "db/initbdd.h"
#include <QSqlTableModel>
#include "model/client.h"
#include <QMessageBox>

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
        qDebug()<< idC;
        Client::deleteClient(idC);
        updateViewTable();
    }
}

void SearchClient::on_editclient_btn_clicked()
{
    //TODO
}

void SearchClient::updateViewTable()
{
    QSqlQueryModel *model = Client::getListClientByCriteria(id, name, firstName);
    ui->tableView->setModel(model);
    ui->tableView->show();
}
