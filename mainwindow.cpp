#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/addclientwindow.h"
#include "view/addemployeewindow.h"
#include "view/aboutwindow.h"
#include "view/searchclient.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/unicorn.png"));
    
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
    SearchClient sc(toolbox::capitalize(ui->s_input_name->text()), toolbox::capitalize(ui->s_input_fname->text()), ui->s_input_id->text().toInt());
    sc.exec();
}
