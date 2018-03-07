#include "view/searchclient.h"
#include "ui_searchclient.h"
#include "db/initbdd.h"
#include <QSqlTableModel>

SearchClient::SearchClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchClient)
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
    //A laisser dans la vue ou à mettre dans le model ??
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("TClient");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("LastName"));
    model->setHeaderData(2, Qt::Horizontal, tr("FirstName"));
    model->setHeaderData(8, Qt::Horizontal, tr("AppointmentDate"));
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->show();


}
