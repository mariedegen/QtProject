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
    ui->statusBar->showMessage("Welcome, you just logged.", 4000);
    updateRessourceTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStatusBar * MainWindow::getStatusBar(){
    return ui->statusBar;
}

void MainWindow::on_actionClient_triggered()
{
    AddClientWindow aCw(this);
    aCw.exec();
    updateRessourceTree();
}

void MainWindow::on_actionEmployees_triggered()
{
    AddEmployeeWindow aEw(this);
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
        SearchClient sc(toolbox::capitalize(ui->s_input_name->text()), toolbox::capitalize(ui->s_input_fname->text()), -1, this);
        sc.exec();
    }else {
        SearchClient sc(toolbox::capitalize(ui->s_input_name->text()), toolbox::capitalize(ui->s_input_fname->text()), ui->s_input_id->text().toInt(), this);
        sc.exec();
    }

}

void MainWindow::updateRessourceTree()
{
    Ressource ressource;
    QStandardItemModel * standardModel = ressource.getRessourcesListView() ;

    ui->employeeTree->setModel(standardModel);
    ui->employeeTree->expandAll();
}

void MainWindow::on_delete_ressource_clicked()
{
    QItemSelectionModel *select = ui->employeeTree->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::warning(this, tr("Error"),
                             tr("You need to select something in order to delete! "),
                             QMessageBox::Close);
    }else {

        QModelIndex index = ui->employeeTree->currentIndex();
        QModelIndex index2 = index.sibling(index.row(),1);
        int id = index2.data().toInt();
        Ressource::deleteRessource(id);
        updateRessourceTree();
        ui->statusBar->showMessage("The ressource has been deleted.", 4000);
    }
}

void MainWindow::on_edit_ressource_clicked()
{
    QItemSelectionModel *select = ui->employeeTree->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::warning(this, tr("Error"),
                             tr("You need to select something in order to edit! "),
                             QMessageBox::Close);
    }else {
        QModelIndex index = ui->employeeTree->currentIndex();
        QModelIndex index2 = index.sibling(index.row(),1);
        int id = index2.data().toInt();

        AddEmployeeWindow aEw(this, false, id);
        aEw.exec();
        updateRessourceTree();
        ui->statusBar->showMessage("The ressource has been modified.", 4000);
    }

}

void MainWindow::on_actionExit_triggered()
{
    close();
}
