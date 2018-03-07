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
    QString nom = "Ricardo";
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT id, nom, prenom, daterdv FROM TClient where nom = ?");
    query->bindValue(0,nom);
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("LastName"));
    model->setHeaderData(2, Qt::Horizontal, tr("FirstName"));
    model->setHeaderData(3, Qt::Horizontal, tr("AppmtDate"));
    ui->tableView->setModel(model);
    ui->tableView->show();
}
