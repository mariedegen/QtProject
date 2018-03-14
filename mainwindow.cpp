#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    updateRessourceTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    AddClientWindow aCw;
    aCw.exec();

}

void MainWindow::on_actionEmployees_triggered()
{
    AddEmployeeWindow aEw;
    aEw.exec();
}

void MainWindow::on_aboutaction_triggered()
{
    AboutWindow aW;
    aW.exec();
}

void MainWindow::on_search_btn_clicked()
{
    if(ui->s_input_id->text() == ""){
        SearchClient sc(toolbox::capitalize(ui->s_input_name->text()), toolbox::capitalize(ui->s_input_fname->text()), -1);
        sc.exec();
    }else {
        SearchClient sc(toolbox::capitalize(ui->s_input_name->text()), toolbox::capitalize(ui->s_input_fname->text()), ui->s_input_id->text().toInt());
        sc.exec();
    }
}

void MainWindow::updateRessourceTree()
{
    QSqlDatabase db = InitBDD::getDatabaseInstance();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(db);

    query.prepare("SELECT * FROM TClient;");
    query.exec();

    model->setQuery(query);

    ui->employeeTree->setModel(model);
    ui->employeeTree->show();
}
