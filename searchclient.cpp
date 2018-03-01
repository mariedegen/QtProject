#include "searchclient.h"
#include "ui_searchclient.h"

SearchClient::SearchClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchClient)
{
    ui->setupUi(this);
    //unable user to change values
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
