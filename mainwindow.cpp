#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/addclientwindow.h"
#include "view/addemployeewindow.h"
#include "view/aboutwindow.h"
#include "view/searchclient.h"
#include "db/initbdd.h"
#include "model/ressource.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    ui->statusBar->showMessage("Welcome, you logged.", 4000);
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
    updateRessourceTree();
}

void MainWindow::on_actionEmployees_triggered()
{
    AddEmployeeWindow aEw;
    aEw.exec();
    updateRessourceTree();
}

void MainWindow::on_aboutaction_triggered()
{
    AboutWindow aW;
    aW.exec();
    updateRessourceTree();
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
    Ressource ressource;
    QStandardItemModel * standardModel = ressource.getRessources() ;

    ui->employeeTree->setModel(standardModel);
    ui->employeeTree->expandAll();
}

void MainWindow::on_delete_ressource_clicked()
{
    QModelIndex index = ui->employeeTree->currentIndex();
    QModelIndex index2 = index.sibling(index.row(),1);
    int id = index2.data().toInt();
    Ressource::deleteRessource(id);
    updateRessourceTree();
    ui->statusBar->showMessage("The ressource has been deleted.", 4000);
}

void MainWindow::on_edit_ressource_2_clicked()
{

}

void MainWindow::on_edit_ressource_clicked()
{
    QModelIndex index = ui->employeeTree->currentIndex();
    QModelIndex index2 = index.sibling(index.row(),1);
    int id = index2.data().toInt();

    AddEmployeeWindow aEw(this, false, id);
    aEw.exec();
    updateRessourceTree();
    ui->statusBar->showMessage("The ressource has been modified.", 4000);
}
