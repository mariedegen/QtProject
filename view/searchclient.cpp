#include "view/searchclient.h"
#include "ui_searchclient.h"
#include "db/initbdd.h"

SearchClient::SearchClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchClient)
{
    ui->setupUi(this);
    //unable user to change values
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQuery query(db);
    if(query.exec("SELECT * FROM TClient"))
    {
        while(query.next())
        {
            qInfo(query.value(1) .toString().toStdString().c_str());
            qInfo(query.value(2) .toString().toStdString().c_str());
            qInfo(" ");
            //add the value to the tableView
        }
    }
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
