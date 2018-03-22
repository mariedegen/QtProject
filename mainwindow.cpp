#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/addclientwindow.h"
#include "view/addemployeewindow.h"
#include "view/aboutwindow.h"
#include "view/searchclient.h"
#include "db/initbdd.h"
#include "model/ressource.h"
#include <QFileDialog>
#include "model/appointment.h"

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
    qDebug("Test");
    if(ui->s_input_id->text() == ""){
        //SearchClient(QString searchName, QString searchfName, int id, QDate date1, QDate date2 ,QWidget *parent = 0);
        SearchClient sc(
                    toolbox::capitalize(ui->s_input_name->text()),  // searchName
                    toolbox::capitalize(ui->s_input_fname->text()), // searchfName
                    -1,                                             // ID
                    ui->search_date1->date(),                       // Date 1
                    ui->search_date2->date(),                       // Date 2
                    this);
        sc.exec();
    }else {
        SearchClient sc(
                    toolbox::capitalize(ui->s_input_name->text()),  // searchName
                    toolbox::capitalize(ui->s_input_fname->text()), // searchfName
                    ui->s_input_id->text().toInt(),                 // ID
                    ui->search_date1->date(),                       // Date 1
                    ui->search_date2->date(),                       // Date 2
                    this);
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

void MainWindow::on_plan_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Planning"), "",
        tr("(*.txt);;All Files (*)"));

    QFile file(fileName);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }
    QString res = Appointment::getPlanning(ui->dateEdit->date());
    QTextStream out(&file);
    out << res;
    file.flush();
    file.close();
}
