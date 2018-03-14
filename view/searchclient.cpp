#include "view/searchclient.h"
#include "ui_searchclient.h"
#include "db/initbdd.h"
#include <QSqlTableModel>
#include "model/client.h"

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
    //TODO
}

void SearchClient::on_editclient_btn_clicked()
{
    //TODO
}

void SearchClient::updateViewTable()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    Client client;
    QSqlQuery query = client.getListClientByCriteria(id, name, firstName);
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("LastName"));
    model->setHeaderData(2, Qt::Horizontal, tr("FirstName"));
    model->setHeaderData(3, Qt::Horizontal, tr("AppmtDate"));
    ui->tableView->setModel(model);
    ui->tableView->show();
}
