#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclientwindow.h"
#include "addemployeewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("icon/pig.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    addClientWindow aCw;
    aCw.exec();

}

void MainWindow::on_actionEmployees_triggered()
{
    addEmployeeWindow aEw;
    aEw.exec();
}
